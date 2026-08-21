/**
 * ============================================================================
 * FILE: shared_ptr_example.cpp
 * DESCRIPTION: 
 * Demonstrates the mechanics of std::shared_ptr, including reference counting, 
 * shared ownership, scope-based destruction, and polymorphic behavior.
 * The code is divided into 3 parts to be easily traced via a debugger.
 * ============================================================================
 */

#include <iostream>
#include <memory>   // Required for smart pointers
#include <vector>

// Note: These headers are assumed to contain the definitions for the polymorphic 
// Account hierarchy (Account, Checking_Account, Savings_Account, Trust_Account).
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

/**
 * ============================================================================
 * CLASS: Test
 * A simple class to track when objects are created and destroyed in memory.
 * ============================================================================
 */
class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data {data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

/**
 * ============================================================================
 * FUNCTION: func
 * Demonstrates pass-by-value with shared_ptr.
 * When passed by value, a COPY of the shared_ptr is made, which increments 
 * the use_count by 1 for the duration of the function.
 * ============================================================================
 */
void func(std::shared_ptr<Test> p) {
    std::cout << "Inside func - Use count: " << p.use_count() << std::endl;
}

int main() {
   
    // ========================================================================
    // PART 1: Basic Reference Counting (use_count & reset)
    // ========================================================================
    std::cout << "\n=== PART 1: Basic Reference Counting ===" << std::endl;
    
    // Initializing with raw 'new' (Valid, but make_shared is preferred)
    std::shared_ptr<int> p1 {new int {100} };
    std::cout << "Use count of p1: " << p1.use_count() << std::endl;        // 1
   
    // Copying p1 into p2 creates SHARED OWNERSHIP.
    std::shared_ptr<int> p2 { p1 };           
    std::cout << "Use count of p1: " << p1.use_count() << std::endl;        // 2

    // reset() nullifies p1 and decrements the counter.
    p1.reset();   
    std::cout << "Use count of p1 (after reset): " << p1.use_count() << std::endl; // 0 
    std::cout << "Use count of p2: " << p2.use_count() << std::endl;               // 1
    
    // ========================================================================
    // PART 2: Scope Blocks and Pass-By-Value
    // ========================================================================
    std::cout << "\n=== PART 2: Scopes and Functions ===" << std::endl;
    
    // make_shared is the safest and most efficient way to create a shared_ptr
    std::shared_ptr<Test> ptr = std::make_shared<Test>(100); 
    
    // Calling func(ptr) by value. Inside func, use_count becomes 2. 
    // When func exits, it drops back to 1.
    func(ptr);
    std::cout << "Use count after func: " << ptr.use_count() << std::endl; // 1

    { // --- SCOPE 1 START ---
        std::shared_ptr<Test> ptr1 = ptr; // Copy created
        std::cout << "Use count inside Scope 1: " << ptr.use_count() << std::endl; // 2
        
        { // --- SCOPE 2 START ---
            std::shared_ptr<Test> ptr2 = ptr; // Another copy created
            std::cout << "Use count inside Scope 2: " << ptr.use_count() << std::endl; // 3
            
            // We reset 'ptr' here. 'ptr' itself becomes nullptr (use_count 0),
            // BUT the managed Test object is NOT destroyed because ptr1 and ptr2 
            // still point to it (actual object use_count drops to 2).
            ptr.reset();
        } // --- SCOPE 2 END --- (ptr2 goes out of scope, object use_count drops to 1)
        
        // At this point, 'ptr' is empty. It will show 0.
        std::cout << "Use count of ptr inside Scope 1 (after reset): " << ptr.use_count() << std::endl; // 0      
        // However, ptr1 still owns the object.
        std::cout << "Use count of ptr1: " << ptr1.use_count() << std::endl; // 1

    } // --- SCOPE 1 END --- (ptr1 goes out of scope, object use_count drops to 0 -> DESTRUCTOR CALLED)
    
    std::cout << "Use count of ptr at the end: " << ptr.use_count() << std::endl; // 0

    // ========================================================================
    // PART 3: Polymorphism and Collections
    // ========================================================================
    std::cout << "\n=== PART 3: Polymorphism and Vectors ===" << std::endl;
    
    // Creating derived class objects but managing them via Base class pointers.
    std::shared_ptr<Account> acc1 = std::make_shared<Trust_Account>("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 = std::make_shared<Checking_Account>("Moe", 5000);
    std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>("Curly", 6000);
    
    // Storing shared_ptrs in a vector
    std::vector<std::shared_ptr<Account>> accounts;
    
    // Pushing them into the vector creates COPIES of the shared_ptrs.
    // The use_count for each object will increase from 1 to 2.
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    
    // Iterating by reference (&) to avoid making unnecessary copies 
    // and artificially inflating the use_count.
    for (const auto &acc : accounts) {
        std::cout << *acc << std::endl; // Polymorphic printing via interface
        std::cout << "Use count inside loop: " << acc.use_count() << std::endl; // Will be 2
    }
    
    std::cout << "==========================================" << std::endl;
    
    // Upon exiting main(), 'accounts' and acc1, acc2, acc3 go out of scope.
    // The use_counts drop to 0, and all dynamically allocated objects are destroyed safely.
    return 0;
}