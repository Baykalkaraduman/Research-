/**
 * @file sequence_containers_deque.cpp
 * @brief Demonstration of std::deque and STL algorithms.
 * 
 * In computational science, std::deque (Double-Ended Queue) is vital for 
 * "sliding window" algorithms, time-series data streams (like DAQ systems), 
 * and rolling buffers. Unlike std::vector, it allows O(1) insertions and 
 * deletions at BOTH the front and the back, as its memory is managed in chunks 
 * rather than a single contiguous block.
 */

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

/**
 * @brief Generic template function to display any deque.
 * 
 * @tparam T The type of elements stored in the deque.
 * @param d A constant reference to the deque to avoid expensive copying.
 */
template <typename T>
void display(const std::deque<T> &d) {
    std::cout << "[";
    for (const auto &elem: d)
        std::cout << elem << " ";
    std::cout <<  "]"<< std::endl;
}

/**
 * @brief Demonstrates initialization, assignment, and element access.
 */
void test1() {
    std::cout << "\nTest1 =========================" << std::endl;

    std::deque<int> d {1,2,3,4,5};
    display(d);
    
    // Reassignment completely replaces the deque's contents
    d = {2,4,5,6};
    display(d);
    
    // Fill constructor: creates a deque with 10 elements, all initialized to 100.
    std::deque<int> d1 (10, 100);    
    display(d1);
    
    // Element access is O(1), just like std::vector.
    d[0]  = 100;     // Fast, unchecked direct access (Use in critical physics loops)
    d.at(1) = 200;   // Safe, bounds-checked access (Throws std::out_of_range)
    display(d);
}

/**
 * @brief Demonstrates O(1) front and back modifications.
 * 
 * @note This is the core strength of std::deque. In a std::vector, push_front 
 * or pop_front would require shifting every single element in memory O(N).
 */
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;

    std::deque<int> d {0,0,0};
    display(d);
    
    // O(1) insertion at the back
    d.push_back(10);
    d.push_back(20);
    display(d);
    
    // O(1) insertion at the front
    d.push_front(100);
    d.push_front(200);
    display(d);
    
    std::cout << "Front: " << d.front() << std::endl; // Access first element
    std::cout << "Back : " << d.back() << std::endl;  // Access last element
    std::cout << "Size  : " << d.size() << std::endl; 
    
    // O(1) removal from both ends
    d.pop_back();
    d.pop_front();
    display(d);
}

/**
 * @brief Demonstrates complex routing logic based on numerical properties.
 */
void test3() {
    // Insert all even numbers into the back of a deque and all 
    // odd numbers into the front.
    std::cout << "\nTest3 =========================" << std::endl;
    
    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    // Simulating a data splitter (e.g., separating signal from noise events)
    for (const auto &elem: vec) {
        if (elem % 2 == 0)
            d.push_back(elem);  // Evens go to the back
        else
            d.push_front(elem); // Odds go to the front
    }
    display(d);
}

/**
 * @brief Demonstrates how push direction affects the final sequence order.
 */
void test4() {
    // push front vs. back ordering
    std::cout << "\nTest4 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    // Pushing to the front sequentially reverses the original order.
    // Equivalent to a Last-In-First-Out (LIFO) stack build.
    for (const auto &elem: vec) {
        d.push_front(elem);
    }    
    display(d);
    
    // clear() empties the container but keeps the chunk structure in memory
    d.clear();
    
     // Pushing to the back maintains the original order.
     // Equivalent to a First-In-First-Out (FIFO) queue build.
     for (const auto &elem: vec) {
        d.push_back(elem);
    }
    display(d);
}

/**
 * @brief Demonstrates STL algorithms with front_inserter and back_inserter.
 * 
 * @note std::front_inserter ONLY works with containers that support push_front() 
 * natively, like std::deque or std::list. You cannot use it on std::vector!
 */
void test5() {
    // Same as test4 using std::copy (which is safer and cleaner than manual loops)
    std::cout << "\nTest5 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
    std::deque<int> d;
    
    // std::front_inserter pushes each copied element to the front, reversing the data.
    std::copy(vec.begin(), vec.end(), std::front_inserter(d));
    display(d);
    
    d.clear();
    
    // std::back_inserter pushes each copied element to the back, maintaining order.
    std::copy(vec.begin(), vec.end(), std::back_inserter(d));
    display(d);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
