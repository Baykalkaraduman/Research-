/**
 * ============================================================================
 * FILE: interfaces_complete.cpp
 * DESCRIPTION: 
 * Solves the static binding problem by introducing an Interface (I_Printable).
 * In C++, an interface is simply an Abstract Base Class with ONLY pure virtual 
 * functions. By overloading operator<< ONCE for the interface, and delegating 
 * the logic to a virtual print() method, we achieve polymorphic printing.
 * ============================================================================
 */

#include <iostream>

/**
 * ============================================================================
 * INTERFACE: I_Printable
 * Any class that inherits from this MUST implement the print() method.
 * 'I_' prefix is a common naming convention for Interfaces.
 * ============================================================================
 */
class I_Printable {
    // Only ONE global friend function is needed for the entire hierarchy!
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
public:
    // Pure virtual function delegates the printing logic to derived classes.
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() {};
};

// Global operator<< implementation
std::ostream &operator<<(std::ostream &os, const I_Printable &obj) {
    // POLYMORPHISM MAGIC: 
    // 'obj' is passed by reference. Calling the virtual print() method 
    // triggers dynamic binding. It routes to the correct derived class at runtime.
    obj.print(os);
    return os;
}

/**
 * ============================================================================
 * CLASS: Account
 * Inherits the I_Printable interface, forcing it to implement print().
 * ============================================================================
 */
class Account : public I_Printable {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    
    // Fulfills the I_Printable contract
    virtual void print(std::ostream &os) const override {
        os << "Account display";
    }
    virtual ~Account() {  }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    
    // Overrides the print method for dynamic binding
    virtual void print(std::ostream &os) const override {
        os << "Checking display";
    }
    virtual ~Checking() {  }
};

class Savings: public Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Savings display";
    }
    virtual ~Savings() {  }
};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override {
        os << "Trust display";
    }
    virtual ~Trust() {  }
};

/**
 * ============================================================================
 * CLASS: Dog (Unrelated Class)
 * Demonstrates the extreme power of Interfaces. 'Dog' has nothing to do with 
 * 'Account', but by inheriting I_Printable, it seamlessly integrates with 
 * our polymorphic printing system.
 * ============================================================================
 */
class Dog : public I_Printable {
public:
    virtual void print(std::ostream &os) const override {
        os << "Woof woof";
    } 
};

// A generic function demonstrating reference polymorphism with the interface
void print(const I_Printable &obj) {
    std::cout << obj << std::endl;
}

int main() {
    
    Dog *dog = new Dog();
    // Dynamically binds to Dog::print()
    std::cout << *dog << std::endl;  
    
    // Passing to a generic function
    print(*dog);
    
    Account *p1 = new Account();
    // Dynamically binds to Account::print()
    std::cout << *p1 << std::endl;
        
    Account *p2 = new Checking();
    // SUCCESS: Because operator<< now delegates to the virtual print() method,
    // the V-Table correctly routes this to Checking::print().
    std::cout << *p2 << std::endl;  
        
    delete p1;
    delete p2;
    delete dog;
    return 0;
}