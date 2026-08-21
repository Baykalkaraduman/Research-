#include <iostream>

using namespace std;


// ============================================================
// BASE CLASS
// ============================================================
//
// Base is the parent (base) class.
//
// It owns:
//
//     int value
//
// Derived will inherit from Base.
//
// IMPORTANT:
// Base's constructors are responsible for constructing
// the Base part of a Derived object.
//
// ============================================================

class Base {

private:

    int value;


public:

    // ========================================================
    // Base No-Args Constructor
    // ========================================================
    //
    // This constructor initializes the Base part of an object
    // with value = 0.
    //
    // When a Derived object is created, the Base constructor
    // is called FIRST.
    //
    Base()
        : value{0}
    {
        cout << "Base no-args Constructor Called\n";
    }


    // ========================================================
    // Base Overloaded Constructor
    // ========================================================
    //
    // This constructor allows us to create a Base object
    // with a specific value.
    //
    // Example:
    //
    //     Base b{100};
    //
    // gives:
    //
    //     value = 100
    //
    Base(int x)
        : value{x}
    {
        cout << "Base overloaded Constructor Called\n";
    }


    // ========================================================
    // Base Destructor
    // ========================================================
    //
    // The destructor is called when the Base part of the
    // object is destroyed.
    //
    // IMPORTANT:
    //
    // For a Derived object:
    //
    //     Derived destructor runs FIRST
    //     Base destructor runs SECOND
    //
    ~Base()
    {
        cout << "Base Destructor Called\n";
    }
};


// ============================================================
// DERIVED CLASS
// ============================================================
//
// Derived inherits publicly from Base:
//
//     class Derived : public Base
//
// Therefore a Derived object contains:
//
//     Base part
//         +
//     Derived part
//
// ============================================================

class Derived : public Base {

    // ========================================================
    // Constructor Inheritance
    // ========================================================
    //
    // Normally, constructors are NOT inherited automatically.
    //
    // This line explicitly tells C++:
    //
    //     "Make Base's constructors available
    //      when constructing Derived objects."
    //
    // However, this does NOT mean that Derived suddenly gets
    // a constructor that knows how to initialize every member
    // declared inside Derived.
    //
    using Base::Base;


private:

    // --------------------------------------------------------
    // Derived-specific member
    // --------------------------------------------------------
    //
    // This member belongs only to Derived.
    //
    int doubled_value;


public:

    // ========================================================
    // Derived No-Args Constructor
    // ========================================================
    //
    // This is a constructor defined specifically for Derived.
    //
    // Notice that we do NOT explicitly write:
    //
    //     Base()
    //
    // in the initializer list.
    //
    // Because Base is not mentioned, C++ automatically calls
    // Base's no-args constructor.
    //
    // Construction order:
    //
    //     1. Base()
    //     2. doubled_value{0}
    //     3. Derived constructor body
    //
    Derived()
        : doubled_value{0}
    {
        cout << "Derived no-args Constructor Called\n";
    }


    // ========================================================
    // Derived Overloaded Constructor
    // ========================================================
    //
    // This constructor is specifically defined by Derived.
    //
    // We explicitly call:
    //
    //     Base{x}
    //
    // to tell C++ which Base constructor should construct
    // the Base portion of this Derived object.
    //
    // At the same time we initialize:
    //
    //     doubled_value{x * 2}
    //
    // Construction order:
    //
    //     1. Base(x)
    //     2. doubled_value{x * 2}
    //     3. Derived constructor body
    //
    Derived(int x)
        : Base{x},
          doubled_value{x * 2}
    {
        cout << "Derived overloaded Constructor Called\n";
    }


    // ========================================================
    // Derived Destructor
    // ========================================================
    //
    // When a Derived object is destroyed:
    //
    //     1. Derived destructor runs
    //     2. Base destructor runs
    //
    // This is the REVERSE of construction order.
    //
    ~Derived()
    {
        cout << "Derived Destructor Called\n";
    }
};


// ============================================================
// MAIN
// ============================================================

int main()
{

    // ========================================================
    // TEST 1
    // ========================================================
    //
    // Creating a Base object.
    //
    // Only Base's constructor is involved.
    //
    /*
    Base b;
    */


    // ========================================================
    // TEST 2
    // ========================================================
    //
    // Creating a Base object using the overloaded constructor.
    //
    /*
    Base b{100};
    */


    // ========================================================
    // TEST 3
    // ========================================================
    //
    // Creating a Derived object with no arguments.
    //
    // Expected order:
    //
    //     Base no-args Constructor
    //     Derived no-args Constructor
    //
    /*
    Derived d;
    */


    // ========================================================
    // TEST 4
    // ========================================================
    //
    // Creating a Derived object with an integer.
    //
    Derived d{1000};
    //
    // Construction order:
    //
    //     Base{1000}
    //         ↓
    //     doubled_value{2000}
    //         ↓
    //     Derived constructor body
    //
    // Expected output:
    //
    //     Base overloaded Constructor Called
    //     Derived overloaded Constructor Called
    //
    // When main() finishes:
    //
    //     Derived Destructor Called
    //     Base Destructor Called
    //
    // Notice the reverse order.


    cout << "\nEnd of main()\n";

    return 0;
}