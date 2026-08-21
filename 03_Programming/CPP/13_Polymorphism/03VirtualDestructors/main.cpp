#include <iostream>

// This class uses dynamic polymorphism for the withdraw method
class Account {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }

    // This is a VIRTUAL DESTRUCTOR.
    //
    // The destructor is virtual because Account is designed
    // to be used polymorphically.
    //
    // This means we may have:
    //
    //     Account *ptr = new Savings();
    //
    // and later:
    //
    //     delete ptr;
    //
    // Since ptr is an Account pointer but the actual object
    // is a Savings object, C++ needs to make sure that the
    // correct destructor chain is called.
    //
    // With a virtual destructor:
    //
    //     ~Savings()
    //          ↓
    //     ~Account()
    //
    // Both destructors are called.
    //
    // This is important when a Derived class owns resources
    // that must be released when the object is destroyed.

    virtual ~Account() { std::cout << "Account:: destructor" << std::endl; }
};

class Checking: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }

    // Derived destructor.
    //
    // Because the Base destructor is virtual, this destructor
    // participates in the virtual destruction mechanism.
    //
    // If we have:
    //
    //     Account *ptr = new Checking();
    //
    // and execute:
    //
    //     delete ptr;
    //
    // C++ first calls:
    //
    //     Checking::~Checking()
    //
    // and then:
    //
    //     Account::~Account()
    //
    virtual ~Checking() { std::cout << "Checking:: destructor" << std::endl; }

};

class Savings: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Savings::withdraw" << std::endl;
    }

    // Derived destructor.
    //
    // This destructor is called before Account's destructor
    // when a Savings object is destroyed through an Account
    // pointer.
    //
    // Example:
    //
    //     Account *ptr = new Savings();
    //     delete ptr;
    //
    // Destruction order:
    //
    //     Savings destructor
    //     Account destructor
    //
    virtual ~Savings() { std::cout << "Savings:: destructor" << std::endl; }

};

class Trust: public Account  {
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }

    // Derived destructor.
    //
    // Because Account has a virtual destructor, deleting
    // a Trust object through an Account pointer correctly
    // invokes the Trust destructor first.
    //
    // Example:
    //
    //     Account *ptr = new Trust();
    //     delete ptr;
    //
    // Destruction order:
    //
    //     Trust destructor
    //     Account destructor
    //
    virtual ~Trust() { std::cout << "Trust:: destructor" << std::endl; }

};

int main() {

    std::cout << "\n === Pointers ==== " << std::endl;

    // p1 points to an actual Account object.
    Account *p1 = new Account();

    // p2 is an Account pointer,
    // but the actual object is Savings.
    //
    // This is a polymorphic relationship.
    Account *p2 = new Savings();

    // p3 is an Account pointer,
    // but the actual object is Checking.
    Account *p3 = new Checking();

    // p4 is an Account pointer,
    // but the actual object is Trust.
    Account *p4 = new Trust();
    
    
    //==========================================================
    // Virtual Functions
    //==========================================================

    // Because withdraw() is virtual, C++ looks at the
    // actual object type at runtime.
    //
    // p1 -> Account
    // p2 -> Savings
    // p3 -> Checking
    // p4 -> Trust

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    

    std::cout << "\n === Clean up ==== " << std::endl;

    //==========================================================
    // Virtual Destructors
    //==========================================================

    // p1 points directly to an Account object.
    //
    // Therefore:
    //
    //     Account destructor
    //
    // is called.
    delete p1;


    // p2 is an Account pointer,
    // but it points to a Savings object.
    //
    // Because Account::~Account() is virtual,
    // C++ knows that the actual object is Savings.
    //
    // Therefore the destruction order is:
    //
    //     Savings destructor
    //     Account destructor
    //
    delete p2;


    // p3 points to a Checking object.
    //
    // Destruction order:
    //
    //     Checking destructor
    //     Account destructor
    //
    delete p3;


    // p4 points to a Trust object.
    //
    // Destruction order:
    //
    //     Trust destructor
    //     Account destructor
    //
    delete p4;
        
    return 0;
}