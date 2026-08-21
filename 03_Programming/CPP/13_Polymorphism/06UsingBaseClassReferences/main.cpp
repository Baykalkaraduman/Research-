/**
 * ============================================================================
 * FILE: base_class_references_polymorphism.cpp
 * DESCRIPTION: 
 * Demonstrates dynamic polymorphism in C++ using Base Class References.
 * While polymorphism is commonly taught using pointers, references (&) provide 
 * a cleaner and safer syntax (no null pointer risks or manual memory management) 
 * while perfectly preserving dynamic binding and V-Table lookups.
 * ============================================================================
 */

#include <iostream>

/**
 * ============================================================================
 * CLASS: Account (Base Class)
 * Represents the root of the banking hierarchy.
 * ============================================================================
 */
// This class uses dynamic polymorphism for the withdraw method
// We'll learn about virtual functions in the next video
class Account {
public:
    // The 'virtual' keyword enables dynamic binding (late binding).
    // It allows C++ to route the function call to the actual object type
    // even when accessed through a base class reference.
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    
    // Virtual destructor guarantees safe cleanup of derived class resources.
    virtual ~Account() {  }
};

/**
 * ============================================================================
 * CLASSES: Checking, Savings, Trust (Derived Classes)
 * These classes inherit from Account and override the withdraw method.
 * ============================================================================
 */
class Checking: public Account  {
public:
    // Implicitly overrides the base class virtual withdraw method.
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {  }
};

class Savings: public Account  {
public:
    // Implicitly overrides the base class virtual withdraw method.
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    // Implicitly overrides the base class virtual withdraw method.
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

/**
 * ============================================================================
 * FUNCTION: do_withdraw
 * Demonstrates Polymorphism via Function Parameters.
 * 
 * CRITICAL CONCEPT: 
 * The parameter is passed by reference: 'Account &account'.
 * If it were passed by value ('Account account'), C++ would trigger "Object Slicing",
 * cutting off the derived parts and calling Account::withdraw every time.
 * Using a reference maintains the object's true identity for the V-Table lookup.
 * ============================================================================
 */
void do_withdraw(Account &account, double amount) {
    // Dynamic binding executes here based on the ACTUAL object passed in.
    account.withdraw(amount);
}

int main() {

    // =========================================================
    // 1. POLYMORPHISM USING DIRECT REFERENCES
    // =========================================================
    Account a;
    
    // ref is a reference to an Account object.
    Account &ref = a;
    ref.withdraw(1000);         // Resolves to Account::withdraw

    Trust t;
    
    // ref1 is an Account reference, but it binds to a Trust object.
    // Because withdraw() is virtual, the compiler looks at the actual 
    // object in memory (Trust) and executes the correct method.
    Account &ref1 = t;
    ref1.withdraw(1000);        // Resolves to Trust::withdraw

    // =========================================================
    // 2. POLYMORPHISM VIA FUNCTION CALLS
    // =========================================================
    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;
   
    // Passing different derived objects into a function expecting a Base reference.
    // The C++ compiler safely handles the upcasting to 'Account&' implicitly,
    // and dynamic binding ensures the correct overridden methods are called.
   
    do_withdraw(a1, 1000);       // Resolves to Account::withdraw
    do_withdraw(a2, 2000);       // Resolves to Savings::withdraw
    do_withdraw(a3, 3000);       // Resolves to Checking::withdraw
    do_withdraw(a4, 4000);       // Resolves to Trust::withdraw

    return 0;
}