/***********************************************************************
 * ShallowCopy.cpp
 *
 * Topic:
 *      Shallow Copy
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Compiler-generated Copy Behavior
 * 2. Shallow Copy
 * 3. Shared Pointer Ownership
 * 4. Double Deletion
 * 5. Why Deep Copy is Necessary
 *
 * NOTE:
 * This program intentionally crashes.
 * The goal is to understand WHY it crashes.
 ***********************************************************************/

#include <iostream>

//==============================================================
// Shallow Class
//==============================================================

class Shallow
{
private:

    int *data;

public:

    // Constructor
    Shallow(int value);

    // Copy Constructor (Shallow Copy)
    Shallow(const Shallow &source);

    // Destructor
    ~Shallow();

    // Utilities
    void set_data_value(int value)
    {
        *data = value;
    }

    int get_data_value() const
    {
        return *data;
    }
};

//==============================================================
// Constructor
//==============================================================

Shallow::Shallow(int value)
{
    data = new int;

    *data = value;

    std::cout
        << "Constructor allocated memory\n";
}

//==============================================================
// Copy Constructor
//==============================================================

// BAD IMPLEMENTATION
// Only the pointer is copied.
// Both objects now point to the SAME heap memory.

Shallow::Shallow(const Shallow &source)

    : data{source.data}
{
    std::cout
        << "Copy Constructor (Shallow Copy)\n";
}

//==============================================================
// Destructor
//==============================================================

Shallow::~Shallow()
{
    std::cout
        << "Destructor releasing memory\n";

    delete data;
}

//==============================================================
// Helper Function
//==============================================================

// Passing by value automatically creates a copy.

void display_shallow(Shallow object)
{
    std::cout
        << "Stored value : "
        << object.get_data_value()
        << "\n";
}

/*
-------------------------------------------------------------

obj1

data -----> Heap

↓

display_shallow(obj1)

↓

Copy Constructor

↓

Temporary Object

data -----> SAME Heap

-------------------------------------------------------------

Temporary object destroyed

↓

delete data

↓

Heap freed

-------------------------------------------------------------

obj1 still points to freed memory

↓

Destructor(obj1)

↓

delete data again

↓

Double Delete

↓

Program Crash

-------------------------------------------------------------
*/

int main()
{
    std::cout << "\n========== Object Creation ==========\n\n";

    Shallow obj1{100};

    std::cout << "\n========== Pass By Value ==========\n\n";

    display_shallow(obj1);

    std::cout << "\n========== Explicit Copy ==========\n\n";

    Shallow obj2{obj1};

    obj2.set_data_value(1000);

    return 0;
}