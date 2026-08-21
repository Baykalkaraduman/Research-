// ============================================================
// Section 15
// Base Class Initialization
// ============================================================
//
// This example demonstrates how a Derived class explicitly
// initializes its Base class.
//
// The important idea is:
//
//     Derived constructor
//             |
//             v
//     Base class initialization
//             |
//             v
//     Derived member initialization
//             |
//             v
//     Derived constructor body
//
// IMPORTANT:
//
// A Base class is ALWAYS constructed before the Derived class.
//
// The Base constructor is selected through the Derived
// constructor's initialization list.
//
// ============================================================

#include <iostream>

using namespace std;


// ============================================================
// BASE CLASS
// ============================================================
//
// Base owns:
//
//     int value
//
// value is private, so Derived cannot directly access it.
//
// Therefore, if Derived wants to initialize value,
// it must call one of Base's constructors.
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
    // This constructor initializes:
    //
    //     value = 0
    //
    // The initializer list is used to initialize the member
    // before the constructor body begins.
    //
    Base()
        : value{0}
    {
        cout << "Base no-args constructor" << endl;
    }


    // ========================================================
    // Base Overloaded Constructor
    // ========================================================
    //
    // This constructor allows the caller to provide the
    // initial value of the Base class.
    //
    // Example:
    //
    //     Base b{100};
    //
    // results in:
    //
    //     value = 100
    //
    Base(int x)
        : value{x}
    {
        cout << "Base (int) overloaded constructor" << endl;
    }


    // ========================================================
    // Base Destructor
    // ========================================================
    //
    // This is called when the Base part of the object
    // is destroyed.
    //
    // For a Derived object, this destructor runs AFTER
    // the Derived destructor.
    //
    ~Base()
    {
        cout << "Base destructor" << endl;
    }
};


// ============================================================
// DERIVED CLASS
// ============================================================
//
// Derived inherits from Base:
//
//     class Derived : public Base
//
// A Derived object therefore contains:
//
//     Base subobject
//          +
//     Derived members
//
// ============================================================

class Derived : public Base {

private:

    // --------------------------------------------------------
    // Derived-specific member
    // --------------------------------------------------------
    //
    // This member belongs to Derived, not Base.
    //
    int doubled_value;


public:

    // ========================================================
    // Derived No-Args Constructor
    // ========================================================
    //
    // Notice:
//
//     : Base{}, doubled_value{0}
//
// We are explicitly telling C++:
//
//     1. Construct the Base part using Base()
//     2. Initialize doubled_value with 0
//     3. Execute the Derived constructor body
//
// The order is important.
//
// Construction order:
//
//     Base()
//       ↓
//     doubled_value{0}
//       ↓
//     Derived constructor body
//
// ========================================================

    Derived()
        : Base{},
          doubled_value{0}
    {
        cout << "Derived no-args constructor" << endl;
    }


    // ========================================================
    // Derived(int) Constructor
    // ========================================================
    //
    // This is the important example in this lesson.
//
//     Derived(int x)
//         : Base{x},
//           doubled_value{x * 2}
//
//
//
// Base{x}
//
// means:
//
//     "Use Base's int constructor to initialize
//      the Base part of this Derived object."
//
//
//
// doubled_value{x * 2}
//
// initializes the Derived-specific member.
//
//
//
// Therefore:
//
//     Derived d{1000};
//
// produces:
//
//     Base::value       = 1000
//     Derived::doubled_value = 2000
//
// ========================================================

    Derived(int x)
        : Base{x},
          doubled_value{x * 2}
    {
        cout << "Derived (int) constructor" << endl;
    }


    // ========================================================
    // Derived Destructor
    // ========================================================
    //
    // Destruction happens in the reverse order of construction.
//
//     1. Derived destructor
//     2. Base destructor
//
// ========================================================

    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }
};


// ============================================================
// MAIN
// ============================================================

int main()
{

    // ========================================================
    // Test 1: Derived default construction
    // ========================================================
    //
    // Uncomment this block to observe:
    //
    //     Base no-args constructor
    //     Derived no-args constructor
    //
    /*
    cout << "\n=== Creating Derived with no arguments ===\n";

    Derived d;
    */


    // ========================================================
    // Test 2: Derived construction with an integer
    // ========================================================
    //
    // This calls:
    //
    //     Derived(int)
    //
    // Inside its initialization list:
    //
    //     Base{x}
    //
    // selects:
    //
    //     Base(int)
    //
    // With x = 1000:
    //
    //     Base::value = 1000
    //
    //     Derived::doubled_value = 2000
    //
    cout << "\n=== Creating Derived with an integer ===\n";

    Derived d{1000};


    // ========================================================
    // Construction order
    // ========================================================
    //
    // The output should demonstrate:
    //
    //     Base (int) overloaded constructor
    //     Derived (int) constructor
    //
    // Base ALWAYS comes first.
    //


    cout << "\n=== End of main ===\n";

    // When d goes out of scope:
    //
    //     Derived destructor
    //     Base destructor
    //
    // Notice that destruction is the reverse of construction.

    return 0;
}