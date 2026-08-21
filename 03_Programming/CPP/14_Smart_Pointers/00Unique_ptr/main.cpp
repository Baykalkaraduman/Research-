/**
 * ============================================================================
 * FILE: unique_ptr_example.cpp
 * DESCRIPTION: 
 * Demonstrates the core concepts of std::unique_ptr in Modern C++.
 * Covers initialization (new vs make_unique), exclusive ownership (move semantics), 
 * dynamic polymorphism with smart pointers, and using unique_ptr within 
 * Standard Template Library (STL) containers.
 * ============================================================================
 */

#include <iostream>
#include <memory>   // CRITICAL: Required for smart pointers
#include <vector>

// Note: These headers are assumed to contain the definitions for the polymorphic 
// Account hierarchy (Account, Checking_Account, Savings_Account, Trust_Account).
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

/**
 * ============================================================================
 * CLASS: Test
 * A simple noisy class to visualize object construction and destruction.
 * This proves that unique_ptr automatically calls the destructor when it goes 
 * out of scope.
 * ============================================================================
 */
class Test {
private:
    int data;
public:
    Test() : data{0} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    Test(int data) : data{data} { std::cout << "Test constructor (" << data << ")" << std::endl; }
    int get_data() const { return data; }
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

using namespace std;

int main() {

    // =========================================================
    // 1. RAW POINTER VS UNIQUE POINTER
    // =========================================================
    
    // Raw Pointer example (Error prone: Requires manual deletion)
    // Test *t1 = new Test{1000};
    // delete t1;

    // Unique Pointer initialized with raw 'new' (C++11 style)
    // We are creating a unique_ptr named 't1' that owns a Test object.
    // No 'delete' line is needed; the memory is freed automatically.
    std::unique_ptr<Test> t1 {new Test{100}}; 

    // Unique Pointer initialized with std::make_unique (C++14 style - BEST PRACTICE)
    // make_unique safely allocates memory and wraps it in a unique_ptr in one step.
    std::unique_ptr<Test> t2 = std::make_unique<Test>(1000); 

    // =========================================================
    // 2. EXCLUSIVE OWNERSHIP & MOVE SEMANTICS
    // =========================================================
    
    std::unique_ptr<Test> t3;
    
    // We CANNOT copy or assign unique_pointers (e.g., t3 = t1 is a COMPILER ERROR).
    // A unique_ptr exclusively owns its memory. To transfer ownership, we MUST 
    // use std::move(). This transfers the memory address to t3 and nullifies t1.
    t3 = std::move(t1);
    
    if (!t1) {
        std::cout << "t1 is nullptr" << std::endl; // This will execute
    }

    // =========================================================
    // 3. POLYMORPHISM WITH UNIQUE POINTERS
    // =========================================================
    
    // std::make_unique handles upcasting perfectly. We create a Checking_Account,
    // but manage it through a unique_ptr of the Base class (Account).
    std::unique_ptr<Account> a1 = std::make_unique<Checking_Account>("Moe", 5000);
    std::cout << *a1 << std::endl; // Dereferencing works exactly like a raw pointer
    a1->deposit(5000);             // Arrow operator works exactly like a raw pointer
    std::cout << *a1 << std::endl;

    // =========================================================
    // 4. UNIQUE POINTERS IN STL CONTAINERS (std::vector)
    // =========================================================
    
    std::vector<std::unique_ptr<Account>> accounts;

    // We can push unique_ptrs directly into the vector using make_unique.
    accounts.push_back(make_unique<Checking_Account>("James", 1000));
    accounts.push_back(make_unique<Savings_Account>("Billy", 4000, 5.2));
    accounts.push_back(make_unique<Trust_Account>("Bobby", 5000, 5.8));

    // CRITICAL ITERATION RULE:
    // We MUST iterate using a reference (&). If we use 'const auto acc', 
    // the loop tries to COPY the unique_ptr out of the vector, causing an error.
    for (const auto &acc : accounts) {
        std::cout << *acc << std::endl; 
        // Virtual functions and overloaded operators work dynamically via V-Table
    }

    // At the end of main(), 'accounts', 't3', 't2', and 'a1' go out of scope.
    // Every single dynamically allocated object is automatically and safely destroyed.
    return 0;
}