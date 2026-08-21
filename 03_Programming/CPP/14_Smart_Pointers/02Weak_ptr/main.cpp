/**
 * ============================================================================
 * FILE: weak_ptr_example.cpp
 * DESCRIPTION: 
 * Demonstrates the Circular Reference problem that occurs with shared_ptrs 
 * and how to resolve it using std::weak_ptr. A weak_ptr observes an object 
 * managed by a shared_ptr without increasing its reference count (use_count).
 * ============================================================================
 */

#include <iostream>
#include <memory>

using namespace std;

class B;    // Forward declaration required because A relies on B, and B relies on A.

/**
 * ============================================================================
 * CLASS: A
 * Holds a STRONG reference (shared_ptr) to B.
 * ============================================================================
 */
class A {
    std::shared_ptr<B> b_ptr;
public:
    void set_B(std::shared_ptr<B> &b) {
        b_ptr = b; // Increases B's use_count by 1
    }
    A() { cout << "A Constructor" << endl; }
    ~A() { cout << "A Destructor" << endl; } // Will only run if A's use_count hits 0
};

/**
 * ============================================================================
 * CLASS: B
 * Holds a WEAK reference (weak_ptr) to A.
 * If this were a shared_ptr, A and B would keep each other alive forever.
 * ============================================================================
 */
class B {
    // CRITICAL FIX: Make this weak to break the strong circular reference.
    // It observes A, but does NOT increase A's use_count.
    std::weak_ptr<A> a_ptr;     
public:
    void set_A(std::shared_ptr<A> &a) {
        a_ptr = a; // A's use_count remains unchanged!
    }
    B() { cout << "B Constructor" << endl; }
    ~B() { cout << "B Destructor" << endl; } // Will only run if B's use_count hits 0
};

int main() {
    
    // =========================================================
    // CIRCULAR REFERENCE RESOLUTION IN ACTION
    // =========================================================
    
    // 1. Create a and b
    shared_ptr<A> a = make_shared<A>(); // A's use_count = 1
    shared_ptr<B> b = make_shared<B>(); // B's use_count = 1
    
    // 2. Link a to b
    a->set_B(b); // b is passed, B's use_count becomes 2 (owned by 'b' in main, and 'b_ptr' in 'a')
    
    // 3. Link b to a
    b->set_A(a); // a is passed, A's use_count remains 1 (because 'a_ptr' in B is a weak_ptr)
    
    // 4. End of main() - Scope Destruction Sequence:
    // - 'b' goes out of scope: B's use_count drops from 2 to 1 (not destroyed yet).
    // - 'a' goes out of scope: A's use_count drops from 1 to 0. 
    // - A is destroyed ("A Destructor" prints).
    // - As A is destroyed, its member 'b_ptr' is also destroyed.
    // - B's use_count drops from 1 to 0.
    // - B is destroyed ("B Destructor" prints).
    
    // Result: NO MEMORY LEAK!
    return 0;
}