/**
 * @file iterators_demo.cpp
 * @brief Demonstration of C++ STL Iterators.
 * 
 * This file explores various types of iterators provided by the C++ Standard Template Library.
 * Iterators act like pointers, allowing us to traverse, access, and manipulate elements 
 * inside STL containers (like std::vector, std::list, std::map) in a uniform way.
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

/**
 * @brief Utility function to display a vector of integers.
 * 
 * @param vec A constant reference to the vector.
 * @note This uses a range-based for loop, which under the hood is 
 * implemented using standard iterators (begin() and end()).
 */
void display(const std::vector<int> &vec) {
    std::cout << "[ ";
    for (auto const &i: vec) {
        std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Demonstrates Random Access Iterators and Iterator Arithmetic.
 * 
 * std::vector supports random access iterators, meaning we can move the iterator
 * forward or backward by arbitrary steps (e.g., it += 2) just like raw pointers.
 */
void test1() {
    std::cout << "\n=============================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    
    // auto deduces the type as std::vector<int>::iterator
    auto it = nums1.begin();            // point to the first element (1)
    std::cout << *it << std::endl;

    it++;                               // move to the next element (2)
    std::cout << *it << std::endl;      

    it += 2;                            // jump two elements forward (4)
    std::cout << *it << std::endl;

    it -= 2;                            // jump two elements backward (2)
    std::cout << *it << std::endl;

    // nums1.end() points to the memory location strictly AFTER the last element.
    // Subtracting 1 points it to the actual last element (5).
    it = nums1.end() - 1;               
    std::cout << *it << std::endl;
}

/**
 * @brief Demonstrates basic traversal and element modification using iterators.
 */
void test2() {
    std::cout << "\n=============================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};

    // Explicitly defining the iterator type
    std::vector<int>::iterator it = nums1.begin();
    
    // Traverse until the iterator reaches the end() sentinel
    while (it != nums1.end()) {
        std::cout << *it << std::endl; // Dereference to read the value
        it++;                          // Move to the next element
    }
    
    // Reset iterator to the beginning to modify elements
    it = nums1.begin();
    while (it != nums1.end()) {
        *it = 0;                       // Dereference to write/change the value
        it++;
    }

    display(nums1); // Output will be [ 0 0 0 0 0 ]
}

/**
 * @brief Demonstrates const_iterator for read-only access.
 * 
 * const_iterators are used when we want to traverse a container 
 * but guarantee that the elements will not be modified.
 */
void test3() {
    std::cout << "\n=============================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};

    // const_iterator prevents modification of the underlying element
    std::vector<int>::const_iterator it1 = nums1.begin();
    // Alternatively, use cbegin(): auto it1 = nums1.cbegin();
    
    while (it1 != nums1.end()) {
        std::cout << *it1 << std::endl;
        it1++;
    }
    
    it1 = nums1.begin();
    while (it1 != nums1.end()) {
        // *it1 = 0;   // COMPILER ERROR: Assignment of read-only location
        it1++;
    }
}

/**
 * @brief Demonstrates reverse iterators and iterators with different STL containers.
 */
void test4() {
    std::cout << "\n=============================" << std::endl;
    
    // 1. Reverse Iterator with std::vector
    std::vector<int> vec {1, 2, 3, 4};
    // rbegin() points to the last element. rend() points to the element before the first.
    auto it1  = vec.rbegin();       
    while (it1 != vec.rend()) {
        std::cout << *it1 << std::endl; // Prints 4, 3, 2, 1
        it1++; // Moving a reverse iterator "forward" actually goes backward in the container
    }

    // 2. Const Reverse Iterator with std::list
    std::list<std::string> name {"Larry", "Moe", "Curly"};
    // crbegin() = const reverse begin
    auto it2 = name.crbegin();      // Points to "Curly"
    std::cout << *it2 << std::endl;
    it2++;                          // Points to "Moe"
    std::cout << *it2 << std::endl;

    // 3. Iterator with std::map
    std::map<std::string, std::string> favorites {
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };
    
    auto it3 = favorites.begin();   // Iterator over a map yields std::pair<const Key, Value>
    while (it3 != favorites.end()) {
        // Use the arrow operator (->) to access members of the pair
        std::cout << it3->first << " : " << it3->second << std::endl;
        it3++;
    }
}

/**
 * @brief Demonstrates iterating over a specific subset (sub-range) of a container.
 */
void test5() {
    std::cout << "\n=============================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Start pointing to the 3rd element (index 2)
    auto start = vec.begin() + 2;
    
    // Finish pointing to the 3rd element from the end (acts as our custom end sentinel)
    auto finish = vec.end() - 3;
    
    // Loop strictly inside the [start, finish) range
    while (start != finish) {
        std::cout << *start << std::endl;
        start++;
    }
}

int main() {
    // Uncomment the tests you want to run
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    
    return 0;
}
