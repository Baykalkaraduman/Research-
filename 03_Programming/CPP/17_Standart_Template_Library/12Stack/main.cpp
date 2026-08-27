/**
 * @file container_adaptors_stack.cpp
 * @brief Demonstration of std::stack (Container Adaptor).
 * 
 * A Container Adaptor does not implement a new data structure from scratch. 
 * Instead, it "adapts" an existing sequence container (like deque, vector, or list)
 * by restricting its interface to enforce a specific behavior.
 * 
 * For std::stack, it enforces LIFO (Last-In, First-Out) behavior. 
 * Iterators are intentionally disabled—you can only access the top element.
 */

#include <iostream>
#include <stack>
#include <vector>
#include <list>

/**
 * @brief Displays a stack by repeatedly reading and popping the top element.
 * 
 * @tparam T The type of elements stored in the stack.
 * @param s The stack passed strictly by VALUE. 
 * 
 * @warning Passing by value is CRITICAL here. Since stacks do not support iterators, 
 * the only way to read all elements is to destroy the stack via pop(). 
 * By passing by value, we only destroy the local copy, preserving the original stack 
 * in the calling function.
 */
template <typename T>
void display(std::stack<T> s) {
    std::cout << "[ ";
    while (!s.empty()) {
        T elem = s.top(); // Read the top element (O(1))
        s.pop();          // Remove the top element (O(1))
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    // 1. Default Stack
    // By default, std::stack uses a std::deque as its underlying container.
    std::stack<int> s;
    
    // 2. Customizing the underlying container
    // We can explicitly tell the stack to use a vector or list instead.
    // This is useful for optimizing memory locality (vector) vs dynamic node allocation (list).
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::list<int>> s2;
    std::stack<int, std::deque<int>> s3;
    
    // Pushing elements onto the stack. 
    // The last element pushed (5) will be the first one to be popped.
    for (int i: {1,2,3,4,5}) 
        s.push(i);
        
    display(s); // Output conceptually shows from top to bottom: 5 4 3 2 1

    s.push(100);
    display(s); // Top is now 100
    
    s.pop(); // Removes 100
    s.pop(); // Removes 5
    display(s); // Top is now 4
    
    // Standard idiom to clear a stack, as there is no .clear() method in std::stack
    while (!s.empty())
        s.pop();
        
    display(s); // Empty stack
    
    std::cout << "Size: " << s.size() << std::endl; // Output: 0
    
    s.push(10);
    display(s);
    
    // .top() returns a reference, meaning we can modify the top element directly
    // without popping and re-pushing.
    s.top() = 100;
    display(s); // Top is now modified to 100
    
    return 0;
}
