/**
 * ============================================================================
 * FILE: custom_deleters.cpp
 * DESCRIPTION: 
 * Demonstrates how to use Custom Deleters with std::shared_ptr. 
 * By default, smart pointers call 'delete' on the raw pointer. A custom 
 * deleter overrides this behavior, allowing you to execute specific cleanup 
 * logic (like closing files, releasing hardware resources, or calling C-style 
 * free() functions) just before the object is destroyed.
 * ============================================================================
 */

#include <iostream>
#include <memory>

/**
 * ============================================================================
 * CLASS: Test
 * A simple noisy class to track object construction and destruction.
 * ============================================================================
 */
class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    
    // The standard destructor will still be called automatically by the custom deleter 
    // when we invoke 'delete ptr'.
    ~Test() { std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

/**
 * ============================================================================
 * FUNCTION: my_deleter
 * A traditional function that matches the required signature for a custom deleter.
 * It takes a raw pointer to the managed object.
 * ============================================================================
 */
void my_deleter(Test *ptr) {
    std::cout << "\tUsing my custom function deleter" << std::endl;
    // CRITICAL: We MUST explicitly delete the pointer here, or memory will leak!
    delete ptr;
}

int main() {

    {
        // =========================================================
        // 1. CUSTOM DELETER USING A FUNCTION POINTER
        // =========================================================
        // Note: We CANNOT use std::make_shared when using a custom deleter.
        // We must use the raw 'new' operator and pass the deleter as the 2nd argument.
        std::shared_ptr<Test> ptr1 {new Test{100}, my_deleter };
        
    } // ptr1 goes out of scope. my_deleter(ptr1.get()) is called automatically.

    std::cout << "====================" << std::endl;
    
    {
        // =========================================================
        // 2. CUSTOM DELETER USING A LAMBDA EXPRESSION (Modern C++)
        // =========================================================
        // This is the preferred, inline way to write custom deleters.
        // It keeps the cleanup logic directly next to the allocation logic.
        std::shared_ptr<Test> ptr2 (new Test{1000}, 
            [] (Test *ptr)  {
                std::cout << "\tUsing my custom lambda deleter" << std::endl;
                // Again, do not forget to free the memory!
                delete ptr;
            });
            
    } // ptr2 goes out of scope. The lambda function is called automatically.
    
    return 0;
}