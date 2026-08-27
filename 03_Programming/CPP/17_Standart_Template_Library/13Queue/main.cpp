/**
 * @file container_adaptors_queue.cpp
 * @brief Demonstration of std::queue (Container Adaptor).
 * 
 * In computational science and software engineering, std::queue enforces 
 * a FIFO (First-In, First-Out) data structure. It is heavily utilized in 
 * event-driven simulations (processing events in the order they occurred), 
 * task scheduling for multithreaded environments, and data stream buffering.
 * 
 * Like std::stack, it is an adaptor (typically wrapping a std::deque) 
 * and intentionally disables iterators to strictly enforce FIFO constraints.
 */

#include <iostream>
#include <queue>

/**
 * @brief Displays a queue by repeatedly reading the front element and popping it.
 * 
 * @tparam T The type of elements stored in the queue.
 * @param q The queue passed strictly by VALUE. 
 * 
 * @warning Just like with std::stack, passing by value is CRITICAL here. 
 * Since queues do not support iterators, the only way to read all elements 
 * is to dismantle the queue using pop(). By passing by value, we only destroy 
 * the local copy, keeping the caller's queue intact.
 */
template <typename T>
void display(std::queue<T> q) {
    std::cout << "[ ";
    while (!q.empty()) {
        T elem = q.front(); // Read the element at the front of the queue (O(1))
        q.pop();            // Remove the front element (O(1))
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    // By default, std::queue uses a std::deque as its underlying container,
    // allowing efficient O(1) insertions at the back and removals at the front.
    std::queue<int> q;
    
    // Pushing elements into the queue.
    // In a physics simulation, this could represent new collision events 
    // being appended to an event processing pipeline.
    for (int i: {1,2,3,4,5}) 
        q.push(i);
        
    display(q); // Output conceptually shows front to back: 1 2 3 4 5
    
    std::cout << "Front: " << q.front() << std::endl; // The oldest element (1)
    std::cout << "Back:  " << q.back() << std::endl;  // The newest element (5)

    // push() always adds to the BACK of the queue.
    q.push(100);
    display(q);

    // pop() always removes from the FRONT of the queue.
    q.pop(); // Removes 1
    q.pop(); // Removes 2
    display(q); // Remaining: 3 4 5 100
    
    // Standard idiom to clear a queue (as it lacks a .clear() method)
    while (!q.empty())
        q.pop();
        
    display(q);

    std::cout << "Size: " << q.size() << std::endl; // Output: 0
    
    // Repopulating the queue
    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;
    
    // Both front() and back() return references.
    // This allows us to modify the oldest and newest elements directly in memory
    // without needing to pop and re-push them.
    q.front() = 5;      // Changes 10 to 5
    q.back() = 5000;    // Changes 1000 to 5000
    
    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back:  " << q.back() << std::endl;
    
    return 0;
}
