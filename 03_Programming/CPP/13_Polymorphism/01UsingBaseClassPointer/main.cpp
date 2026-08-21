/**
 * ============================================================================
 * FILE: polymorphism_example.cpp
 * DESCRIPTION: Demonstrates the core concepts of dynamic polymorphism in C++.
 * It illustrates how base class pointers can be used to manage derived class 
 * objects dynamically at runtime, the necessity of virtual functions for 
 * dynamic binding, and the critical role of virtual destructors in memory management.
 * ============================================================================
 */

// This is a compleated code which allows us to see the effects of virtual constructors functions and destructors
// So there are no notes on that subjects but the code shows what we can do 
// Details of these subjects are given in next codes  
#include <iostream>
#include <vector>

/**
 * ============================================================================
 * CLASS: Account (Base Class)
 * Represents the generic interface for all account types.
 * ============================================================================
 */
class Account {
public:
    // The 'virtual' keyword tells the compiler to use dynamic binding (late binding).
    // When called via a base class pointer, the program will look up the actual 
    // object type at runtime and call the appropriate overridden function.
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    
    // A virtual destructor is crucial when dealing with polymorphic base classes.
    // It ensures that when a derived object is deleted via a base class pointer,
    // the derived class's destructor is called first, preventing memory leaks.
    virtual ~Account() {}
};

/**
 * ============================================================================
 * CLASSES: Checking, Savings, Trust (Derived Classes)
 * These classes inherit from Account and provide their own specific 
 * implementations of the withdraw() function.
 * ============================================================================
 */
class Checking : public Account {
public:
    // Overrides the base class virtual function. 
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {}
};

class Savings : public Account {
public:
    // Overrides the base class virtual function.
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {}
};

class Trust : public Account {
public:
    // Overrides the base class virtual function.
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    // Note: No explicit destructor is defined here. The compiler will generate 
    // a default destructor, which will correctly act as a virtual destructor 
    // because the base class destructor is virtual.
};

int main() {

    std::cout << "\n ==== Pointers ==== " << std::endl;
    
    // Upcasting: Storing addresses of derived class objects inside base class pointers.
    // This dynamic allocation happens on the Heap.
    Account* p1 = new Account();
    Account* p2 = new Checking();
    Account* p3 = new Savings();
    Account* p4 = new Trust();

    // Dynamic Binding in action.
    // Even though p1, p2, p3, and p4 are all of type 'Account*', the program 
    // routes the call to the correct derived class method at runtime.
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    std::cout << "\n ==== Array ==== " << std::endl;
    
    // Storing polymorphic pointers in a raw array.
    // This allows us to process different object types uniformly in a loop.
    Account* array[] = {p1, p2, p3, p4};
    for(auto i = 0; i < 4; ++i)
        array[i]->withdraw(1000); // Late binding applies here as well.

    std::cout << "\n === Array ==== " << std::endl;
    
    // Reassigning an array element. array[0] now points to the Trust object.
    array[0] = p4;
    for (auto i=0; i<4; ++i)
        array[i]->withdraw(1000);

    std::cout << "\n === Vector ==== " << std::endl;
    
    // Storing polymorphic pointers in a std::vector.
    // This is the standard, modern C++ approach for managing collections 
    // of polymorphic objects dynamically.
    std::vector<Account*> accounts {p1,p2,p3,p4};
    for(auto acc_ptr : accounts)
        acc_ptr->withdraw(1000); // The correct overridden function is called for each type.

    std::cout << "\n === Vector ==== " << std::endl;
    
    // Adding the same pointer (p4) multiple times to the vector.
    // The vector now holds multiple references to the exact same 'Trust' object in memory.
    accounts.push_back(p4);
    accounts.push_back(p4);
    for (auto acc_ptr: accounts)
        acc_ptr->withdraw(1000);

    std::cout << "\n === Clean up ==== " << std::endl;
    
    // Freeing the dynamically allocated memory on the Heap to prevent memory leaks.
    // Thanks to the 'virtual ~Account()' destructor, deleting these base class 
    // pointers will correctly trigger the destructors of the derived classes 
    // (Checking, Savings, Trust) before destroying the base Account object.
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}