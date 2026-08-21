// ============================================================
// Section 15
// Copy / Move Operations with Inheritance
// ============================================================
//
// This example demonstrates:
//
//     1. Base class copy constructor
//     2. Base class copy assignment operator
//     3. Derived class copy constructor
//     4. Derived class copy assignment operator
//     5. Base class move constructor
//     6. Base class move assignment operator
//     7. Derived class move constructor
//     8. Derived class move assignment operator
//
// The most important idea:
//
// A Derived object contains:
//
//     Base part
//         +
//     Derived-specific part
//
// Therefore, when copying or moving a Derived object,
// BOTH parts must be handled.
//
// ============================================================

#include <iostream>

using namespace std;


// ============================================================
// BASE CLASS
// ============================================================

class Base {

private:

    int value;


public:

    // ========================================================
    // Base No-Args Constructor
    // ========================================================
    //
    // Creates a Base object with:
    //
    //     value = 0
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
        cout << "Base overloaded constructor" << endl;
    }


    // ========================================================
    // Base Copy Constructor
    // ========================================================
    //
    // This creates a NEW Base object from an existing Base
    // object.
    //
    // Example:
    //
    //     Base b{100};
    //     Base b1{b};
    //
    // b1 is a NEW object.
    //
    // The Base part of b is copied into b1.
    //
    Base(const Base &other)
        : value{other.value}
    {
        cout << "Base copy constructor" << endl;
    }


    // ========================================================
    // Base Move Constructor
    // ========================================================
    //
    // A move constructor creates a NEW object from a temporary
    // or movable object.
    //
    // In this example Base only contains an int.
    //
    // int does not own dynamically allocated memory, so there
    // is no real resource transfer necessary.
    //
    // We still implement the move constructor here so that
    // the complete inheritance pattern is visible.
    //
    Base(Base &&other) noexcept
        : value{other.value}
    {
        cout << "Base move constructor" << endl;
    }


    // ========================================================
    // Base Copy Assignment Operator
    // ========================================================
    //
    // This is different from the copy constructor.
    //
    // Copy constructor:
    //
    //     Base b1{b};
    //
    // creates a NEW object.
    //
    //
    // Copy assignment:
    //
    //     b1 = b;
    //
    // assigns to an EXISTING object.
    //
    Base &operator=(const Base &rhs)
    {
        cout << "Base copy assignment operator" << endl;


        // ----------------------------------------------------
        // Self-assignment protection
        // ----------------------------------------------------
        //
        // Example:
        //
        //     b = b;
        //
        // We do not need to copy an object into itself.
        //
        if (this == &rhs)
            return *this;


        // Copy Base's own data.
        //
        // rhs.value belongs to another Base object.
        //
        // We can access it because we are inside Base.
        //
        value = rhs.value;


        // Return the current object.
        //
        // Returning *this allows expressions such as:
        //
        //     a = b = c;
        //
        return *this;
    }


    // ========================================================
    // Base Move Assignment Operator
    // ========================================================
    //
    // This assigns an existing Base object from another
    // movable Base object.
    //
    Base &operator=(Base &&rhs) noexcept
    {
        cout << "Base move assignment operator" << endl;


        // Protect against:
        //
        //     b = std::move(b);
        //
        if (this == &rhs)
            return *this;


        // Base contains only an int.
        //
        // Therefore moving simply means copying the int value.
        //
        value = rhs.value;


        return *this;
    }


    // ========================================================
    // Base Destructor
    // ========================================================
    //
    // Called when the Base part of an object is destroyed.
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
// Derived contains:
//
//     Base part
//         +
//     doubled_value
//
// Therefore every copy/move operation must take care of BOTH.
//
// ============================================================

class Derived : public Base {

private:

    int doubled_value;


public:

    // ========================================================
    // Derived No-Args Constructor
    // ========================================================
    //
    // Base{} initializes the Base part.
    //
    // doubled_value is initialized separately because it
    // belongs to Derived.
    //
    Derived()
        : Base{},
          doubled_value{0}
    {
        cout << "Derived no-args constructor" << endl;
    }


    // ========================================================
    // Derived Overloaded Constructor
    // ========================================================
    //
    // Base{x}
    //
    // initializes the Base part.
    //
    // doubled_value{x * 2}
    //
    // initializes the Derived-specific part.
    //
    Derived(int x)
        : Base{x},
          doubled_value{x * 2}
    {
        cout << "Derived overloaded constructor" << endl;
    }


    // ========================================================
    // Derived Copy Constructor
    // ========================================================
    //
    // This creates a NEW Derived object from another Derived
    // object.
    //
    // Example:
    //
    //     Derived d{100};
    //     Derived d1{d};
    //
    //
    // IMPORTANT:
    //
    // A Derived object contains a Base part.
    //
    // Therefore we must explicitly copy the Base part:
    //
    //     Base(other)
    //
    // This calls:
    //
    //     Base copy constructor
    //
    //
    // Then:
    //
    //     doubled_value{other.doubled_value}
    //
    // copies the Derived-specific member.
    //
    Derived(const Derived &other)
        : Base(other),
          doubled_value{other.doubled_value}
    {
        cout << "Derived copy constructor" << endl;
    }


    // ========================================================
    // Derived Move Constructor
    // ========================================================
    //
    // This creates a NEW Derived object from a movable
    // Derived object.
    //
    // Again, the Derived object contains TWO parts:
    //
    //     Base part
    //     Derived part
    //
    // Therefore we move/copy both parts.
    //
    Derived(Derived &&other) noexcept
        : Base(std::move(other)),
          doubled_value{other.doubled_value}
    {
        cout << "Derived move constructor" << endl;
    }


    // ========================================================
    // Derived Copy Assignment Operator
    // ========================================================
    //
    // Example:
    //
    //     Derived d{100};
    //     Derived d1;
    //
    //     d1 = d;
    //
    //
    // d1 already exists.
    //
    // Therefore this is assignment, NOT construction.
    //
    Derived &operator=(const Derived &rhs)
    {
        cout << "Derived copy assignment operator" << endl;


        // ----------------------------------------------------
        // Self-assignment protection
        // ----------------------------------------------------
        //
        if (this == &rhs)
            return *this;


        // ----------------------------------------------------
        // Assign the Base part
        // ----------------------------------------------------
        //
        // This is VERY important.
        //
        // rhs contains:
        //
        //     Base part
        //     doubled_value
        //
        // If we only wrote:
        //
        //     doubled_value = rhs.doubled_value;
        //
        // we would copy only the Derived part.
        //
        // The Base part would remain unchanged.
        //
        // Therefore we explicitly call Base's assignment
        // operator:
        //
        Base::operator=(rhs);


        // ----------------------------------------------------
        // Assign Derived-specific members
        // ----------------------------------------------------
        //
        doubled_value = rhs.doubled_value;


        return *this;
    }


    // ========================================================
    // Derived Move Assignment Operator
    // ========================================================
    //
    // This assigns an existing Derived object from another
    // movable Derived object.
    //
    Derived &operator=(Derived &&rhs) noexcept
    {
        cout << "Derived move assignment operator" << endl;


        // ----------------------------------------------------
        // Self-assignment protection
        // ----------------------------------------------------
        //
        if (this == &rhs)
            return *this;


        // ----------------------------------------------------
        // Move the Base part
        // ----------------------------------------------------
        //
        // Call Base's move assignment operator.
        //
        Base::operator=(std::move(rhs));


        // ----------------------------------------------------
        // Move Derived-specific data
        // ----------------------------------------------------
        //
        // doubled_value is an int.
        //
        // Therefore there is no dynamically allocated resource
        // to steal.
        //
        doubled_value = rhs.doubled_value;


        return *this;
    }


    // ========================================================
    // Derived Destructor
    // ========================================================
    //
    // Destruction order:
    //
    //     Derived destructor
    //          ↓
    //     Base destructor
    //
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
    // 1. BASE COPY CONSTRUCTOR
    // ========================================================

    cout << "\n=== Base Copy Constructor ==================\n";

    Base b{100};

    // b1 does not exist before this line.
    //
    // Therefore this is CONSTRUCTION.
    //
    // Base copy constructor is called.
    //
    Base b1{b};


    // ========================================================
    // 2. BASE COPY ASSIGNMENT
    // ========================================================

    cout << "\n=== Base Copy Assignment ===================\n";

    // b2 already exists.
    //
    Base b2;

    // Therefore this is ASSIGNMENT.
    //
    // Base copy assignment operator is called.
    //
    b2 = b1;


    // ========================================================
    // 3. DERIVED COPY CONSTRUCTOR
    // ========================================================

    cout << "\n=== Derived Copy Constructor ================\n";

    Derived d{100};

    // d1 does not exist before this line.
    //
    // Therefore this is CONSTRUCTION.
    //
    // Expected:
    //
    //     Base copy constructor
    //     Derived copy constructor
    //
    Derived d1{d};


    // ========================================================
    // 4. DERIVED COPY ASSIGNMENT
    // ========================================================

    cout << "\n=== Derived Copy Assignment =================\n";

    // d2 already exists.
    //
    Derived d2;

    // Therefore this is ASSIGNMENT.
    //
    // Expected:
    //
    //     Derived copy assignment operator
    //         ↓
    //     Base copy assignment operator
    //
    // Then Derived's own member is assigned.
    //
    d2 = d1;


    // ========================================================
    // 5. DERIVED MOVE CONSTRUCTOR
    // ========================================================

    cout << "\n=== Derived Move Constructor =================\n";

    Derived source{500};

    // std::move() converts source into an rvalue reference.
    //
    // A NEW object is being created.
    //
    // Therefore this is MOVE CONSTRUCTION.
    //
    // Expected:
    //
    //     Base move constructor
    //     Derived move constructor
    //
    Derived moved{std::move(source)};


    // ========================================================
    // 6. DERIVED MOVE ASSIGNMENT
    // ========================================================

    cout << "\n=== Derived Move Assignment ==================\n";

    Derived destination;

    // destination already exists.
    //
    // Therefore this is MOVE ASSIGNMENT.
    //
    // Expected:
    //
    //     Derived move assignment operator
    //         ↓
    //     Base move assignment operator
    //
    destination = std::move(moved);


    // ========================================================
    // END OF MAIN
    // ========================================================
    //
    // Objects are destroyed in reverse order.
    //
    // For each Derived object:
    //
    //     Derived destructor
    //          ↓
    //     Base destructor
    //
    cout << "\n=== End of main =============================\n";

    return 0;
}