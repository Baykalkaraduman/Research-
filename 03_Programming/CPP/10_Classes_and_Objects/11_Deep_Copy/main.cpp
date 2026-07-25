/***********************************************************************
 * DeepCopy.cpp
 *
 * Topic:
 *      Deep Copy
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Deep Copy
 * 2. Copy Constructor
 * 3. Dynamic Memory Allocation
 * 4. Independent Resource Ownership
 * 5. Safe Object Copying
 *
 * Unlike Shallow Copy,
 * every copied object allocates its own memory.
 ***********************************************************************/

#include <iostream>

//==============================================================
// Deep Class
//==============================================================

class Deep
{
private:

    int *data;

public:

    // Constructor
    Deep(int value);

    // Copy Constructor (Deep Copy)
    Deep(const Deep &source);

    // Destructor
    ~Deep();

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

Deep::Deep(int value)
{
    data = new int;

    *data = value;

    std::cout
        << "Constructor allocated memory\n";
}

//==============================================================
// Copy Constructor
//==============================================================

// GOOD IMPLEMENTATION
// Allocate NEW memory.
// Copy the VALUE stored in the source object.

Deep::Deep(const Deep &source)

    : Deep{*source.data}
{
    std::cout
        << "Copy Constructor (Deep Copy)\n";
}

//==============================================================
// Destructor
//==============================================================

Deep::~Deep()
{
    std::cout
        << "Destructor releasing memory\n";

    delete data;
}

//==============================================================
// Helper Function
//==============================================================

// Passing by value creates a completely independent object.

void display_deep(Deep object)
{
    std::cout
        << "Stored value : "
        << object.get_data_value()
        << '\n';
}

/*
-------------------------------------------------------------

obj1

data -----> Heap(100)

↓

Copy Constructor

↓

Temporary Object

data -----> NEW Heap(100)

-------------------------------------------------------------

Temporary object destroyed

↓

Deletes ONLY its own heap

-------------------------------------------------------------

obj1 still owns its own heap safely.

-------------------------------------------------------------
*/

int main()
{
    std::cout << "\n========== Object Creation ==========\n\n";

    Deep obj1{100};

    std::cout << "\n========== Pass By Value ==========\n\n";

    display_deep(obj1);

    std::cout << "\n========== Explicit Copy ==========\n\n";

    Deep obj2{obj1};

    obj2.set_data_value(1000);

    std::cout << "\nobj1 value : "
              << obj1.get_data_value()
              << '\n';

    std::cout << "obj2 value : "
              << obj2.get_data_value()
              << '\n';

    return 0;
}