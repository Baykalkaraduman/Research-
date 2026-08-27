/**
 * @file container_adaptors_priority_queue.cpp
 * @brief Demonstration of std::priority_queue (Container Adaptor).
 * 
 * In computational science, priority queues are the backbone of Discrete Event 
 * Simulations (DES), scheduling algorithms, and graph algorithms like Dijkstra's 
 * or A* pathfinding. 
 * 
 * Instead of strictly following FIFO (First-In, First-Out), a priority queue 
 * ensures that the "largest" or "highest priority" element is always at the top. 
 * Under the hood, it is typically implemented as a Max-Heap array structure, 
 * offering O(1) access to the top element and O(log N) for insertions/deletions.
 */

#include <iostream>
#include <queue>

/**
 * @brief Custom class representing an entity (e.g., a simulation node).
 */
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) 
        : name{name}, age{age}  {}
        
    /**
     * @brief Overloaded less-than operator (CRITICAL for Priority Queues).
     * 
     * @note std::priority_queue uses std::less<T> by default to maintain the Max-Heap 
     * property. Therefore, it relies exclusively on operator< to decide which 
     * element bubbles up to the top. 
     * 
     * In this implementation, comparison is based on the 'name' alphabetically, 
     * NOT the age. The "largest" name (closest to Z) will be prioritized.
     */
    bool operator<(const Person &rhs) const {
        // return this->age < rhs.age; // If active, oldest person would be at the top
        return this->name < rhs.name;  // Lexicographical string comparison
    }
    
    /**
     * @brief Overloaded equality operator.
     * (Not strictly used by priority_queue, but good practice for completeness).
     */
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

/**
 * @brief Stream insertion operator for printing Person objects.
 */
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

/**
 * @brief Displays a priority queue by repeatedly reading and popping the top element.
 * 
 * @tparam T The type of elements stored in the priority queue.
 * @param pq The priority queue passed strictly by VALUE. 
 * 
 * @warning Container Adaptors (stack, queue, priority_queue) DO NOT have iterators.
 * To read the queue, we must dismantle it using pop(). Passing by value ensures 
 * we only destroy our local copy, leaving the original queue intact in the caller.
 */
template <typename T>
void display(std::priority_queue<T> pq)  {
    std::cout << "[ ";
    while (!pq.empty()) {
        T elem = pq.top(); // O(1) access to the highest priority element
        pq.pop();          // O(log N) removal, rebalances the heap automatically
        std::cout << elem << " ";
    }
    std::cout <<  "]" << std::endl;
}

/**
 * @brief Demonstrates a primitive type Max-Heap.
 */
void  test1() {
    std::cout << "\nTest1 =========================" << std::endl;

    // By default, this creates a Max-Heap of integers.
    std::priority_queue<int> pq;
    for (int i : {3,5,7,12,23,12,4,100,0, 3,5,7})
        pq.push(i); // O(log N) insertion per element
        
    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl; // Will be 100
        
    // Elements are printed in strictly descending order (100, 23, 12, 12, 7...)
    display(pq);
    
    pq.pop(); // Removes the 100. The next highest (23) bubbles up to the top.
    display(pq);
}

/**
 * @brief Demonstrates a custom object Max-Heap.
 */
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;

    std::priority_queue<Person> pq;
    pq.push(Person{"A", 10});
    pq.push(Person{"B", 1});
    pq.push(Person{"C", 14});
    pq.push(Person{"D", 18});  
    pq.push(Person{"E", 7});  
    pq.push(Person{"F", 27});
    
    // The queue uses Person::operator<, which compares names.
    // 'F' is lexicographically greater than 'A', so "F:27" will be at the top, 
    // followed by E, D, C, B, A.
    display(pq);
}

int main() {
    test1();
    test2();
    return 0;
}
