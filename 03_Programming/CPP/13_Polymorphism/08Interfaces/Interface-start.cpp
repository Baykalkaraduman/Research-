/**
 * ============================================================================
 * FILE: interfaces_start.cpp
 * DESCRIPTION: 
 * Demonstrates the problem with non-polymorphic operator overloading.
 * Friend functions (like operator<<) CANNOT be virtual. Therefore, when you 
 * pass a Base class pointer (Account*) pointing to a Derived object (Checking), 
 * the compiler statically binds to the Base class's operator<<. 
 * Dynamic binding fails for the print stream.
 * ============================================================================
 */

#include <iostream>

class Account  {
    // friend functions are NOT member functions, so they cannot be 'virtual'.
    // This creates a static binding trap.
    friend std::ostream &operator<<(std::ostream &os, const Account &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual ~Account() {  }
};

std::ostream &operator<<(std::ostream &os, const Account &acc) {
    os << "Account display";
    return os;
}

class Checking: public Account  {
    friend std::ostream &operator<<(std::ostream &os, const Checking &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {  }
};

std::ostream &operator<<(std::ostream &os, const Checking &acc) {
    os << "Checking display";
    return os;
}

class Savings: public Account {
    friend std::ostream &operator<<(std::ostream &os, const Savings &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {  }
};

std::ostream &operator<<(std::ostream &os, const Savings &acc) {
    os << "Savings display";
    return os;
}
class Trust: public Account  {
    friend std::ostream &operator<<(std::ostream &os, const Trust &acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {  }
};

std::ostream &operator<<(std::ostream &os, const Trust &acc) {
    os << "Trust display";
    return os;
}

int main() {
    Account *p1 = new Account();
    std::cout << *p1 << std::endl; // Outputs: "Account display" (Correct)

    Account *p2 = new Checking();
    // THE FLAW: 
    // p2 is an Account*. Even though it points to a Checking object,
    // operator<< is not virtual. It statically binds to Account's friend function.
    std::cout << *p2 << std::endl; // Outputs: "Account display" (INCORRECT - Expected Checking)
   
    delete p1;  
    delete p2;
    return 0;
}