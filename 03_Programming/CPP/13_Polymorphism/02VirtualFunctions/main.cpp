// Section 16
// Virtual Functions

#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
class Account {
public:
    // 'virtual' tells C++ that this function can be overridden
    // by derived classes and that the correct version should
    // be selected at runtime when accessed through a Base pointer
    // or reference.
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
};

class Checking : public Account {
public:
    // This function overrides Account::withdraw().
    //
    // Because Account::withdraw() is virtual, a Base pointer
    // pointing to a Checking object can call this version.
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
};

class Savings : public Account {
public:
    // This function overrides Account::withdraw().
    //
    // The function has the same name and parameter list as
    // the virtual function in the Base class.
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }
};

class Trust : public Account {
public:
    // This function overrides Account::withdraw().
    //
    // At runtime, C++ can determine that the actual object
    // is a Trust object and call this implementation.
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
};

int main() {

    //==========================================================
    // Creating Base Class Pointers
    //==========================================================

    std::cout << "\n === Pointers ==== " << std::endl;

    // p1 points to an actual Account object.
    Account *p1 = new Account();

    // p2 has type Account*, but it points to a Savings object.
    //
    // This is one of the key ideas behind polymorphism:
    //
    //     Base pointer -> Derived object
    //
    Account *p2 = new Savings();

    // p3 is an Account pointer pointing to a Checking object.
    Account *p3 = new Checking();

    // p4 is an Account pointer pointing to a Trust object.
    Account *p4 = new Trust();


    //==========================================================
    // Calling Virtual Functions
    //==========================================================

    // p1 points to an Account object.
    //
    // Therefore Account::withdraw() is called.
    p1->withdraw(1000);

    // p2 is an Account*,
    // but the actual object is Savings.
    //
    // Because withdraw() is virtual,
    // C++ calls Savings::withdraw().
    p2->withdraw(1000);

    // p3 is an Account*,
    // but the actual object is Checking.
    //
    // Because withdraw() is virtual,
    // C++ calls Checking::withdraw().
    p3->withdraw(1000);

    // p4 is an Account*,
    // but the actual object is Trust.
    //
    // Because withdraw() is virtual,
    // C++ calls Trust::withdraw().
    p4->withdraw(1000);


    //==========================================================
    // Clean Up
    //==========================================================

    std::cout << "\n === Clean up ==== " << std::endl;

    // Release the dynamically allocated Account object.
    delete p1;

    // Release the dynamically allocated Savings object.
    delete p2;

    // Release the dynamically allocated Checking object.
    delete p3;

    // Release the dynamically allocated Trust object.
    delete p4;

    return 0;
}