/***********************************************************************
 * MoveConstructor.cpp
 *
 * Topic:
 *      Move Constructor
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Move Semantics
 * 2. Move Constructor
 * 3. Rvalue References (&&)
 * 4. Resource Ownership Transfer
 * 5. std::vector Reallocation
 *
 * Unlike Deep Copy,
 * a Move Constructor transfers ownership instead of copying data.
 ***********************************************************************/

#include <iostream>
#include <vector>

//==============================================================
// Move Class
//==============================================================

class Move
{
private:

    int *data;

public:

    // Constructor
    Move(int value);

    // Copy Constructor (Deep Copy)
    Move(const Move &source);

    // Move Constructor
    Move(Move &&source) noexcept;

    // Destructor
    ~Move();

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

Move::Move(int value)
{
    data = new int;

    *data = value;

    std::cout
        << "Constructor for: "
        << value
        << '\n';
}

//==============================================================
// Copy Constructor
//==============================================================

// Creates a completely independent copy.

Move::Move(const Move &source)

    : Move{*source.data}
{
    std::cout
        << "Copy Constructor (Deep Copy): "
        << *data
        << '\n';
}

//==============================================================
// Move Constructor
//==============================================================

// Transfers ownership of the resource.
// No new memory is allocated.

Move::Move(Move &&source) noexcept

    : data{source.data}
{
    // Remove ownership from the source object.
    source.data = nullptr;

    std::cout
        << "Move Constructor - moved resource: "
        << *data
        << '\n';
}

//==============================================================
// Destructor
//==============================================================

Move::~Move()
{
    if (data != nullptr)
    {
        std::cout
            << "Destructor releasing: "
            << *data
            << '\n';
    }
    else
    {
        std::cout
            << "Destructor releasing nullptr\n";
    }

    delete data;
}

//==============================================================
// Main
//==============================================================

int main()
{
    std::vector<Move> vec;

    // Every push_back receives a temporary object (rvalue).
    // std::vector therefore prefers the Move Constructor.

    vec.push_back(Move{10});
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});

    return 0;
}