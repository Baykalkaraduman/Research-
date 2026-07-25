/***********************************************************************
 * DelegatingConstructors.cpp
 *
 * Topic:
 *      Delegating Constructors
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Constructor Delegation
 * 2. Constructor Reuse
 * 3. Avoiding Code Duplication
 * 4. Initialization Order
 ***********************************************************************/

#include <iostream>
#include <string>

//==============================================================
// Player Class
//==============================================================

class Player
{
private:

    // Members are initialized in declaration order.

    std::string name;
    int health;
    int xp;

public:

    Player();

    Player(std::string name_val);

    Player(std::string name_val,
           int health_val,
           int xp_val);

    void display() const
    {
        std::cout
            << "Name   : " << name << '\n'
            << "Health : " << health << '\n'
            << "XP     : " << xp << "\n\n";
    }
};

//==============================================================
// Default Constructor
//==============================================================

// Delegates to the three-argument constructor.

Player::Player()
    : Player{"None", 0, 0}
{
    std::cout << "Default Constructor Called\n";
}

//==============================================================
// One-Argument Constructor
//==============================================================

// Delegates to the three-argument constructor.

Player::Player(std::string name_val)
    : Player{name_val, 0, 0}
{
    std::cout << "One-Argument Constructor Called\n";
}

//==============================================================
// Three-Argument Constructor
//==============================================================

// This constructor performs the real initialization.

Player::Player(std::string name_val,
               int health_val,
               int xp_val)
    : name{name_val},
      health{health_val},
      xp{xp_val}
{
    std::cout << "Three-Argument Constructor Called\n";
}

/*
-------------------------------------------------------------

Without Delegation

Player()
{
    name = "None";
    health = 0;
    xp = 0;
}

Player(string name)
{
    this->name = name;
    health = 0;
    xp = 0;
}

Player(string name,int health,int xp)
{
    ...
}

Notice that

health = 0;

xp = 0;

appear multiple times.

-------------------------------------------------------------

With Delegation

Player()

    : Player{"None",0,0}

{

}

Player(string name)

    : Player{name,0,0}

{

}

Player(string name,int health,int xp)

    : name{name},
      health{health},
      xp{xp}

{

}

Only one constructor performs initialization.

Every other constructor simply forwards the work.

// Both the default constructor and the one-argument constructor
// delegate their work to this constructor.
//
// This constructor performs all member initialization.
//
// After this constructor finishes,
// execution returns to the delegating constructor.

-------------------------------------------------------------
*/

//==============================================================
// Main
//==============================================================

int main()
{
    std::cout << "\n========== Default Constructor ==========\n\n";

    Player empty;

    empty.display();

    std::cout << "========== One-Argument Constructor ==========\n\n";

    Player emir{"Emir"};

    emir.display();

    std::cout << "========== Three-Argument Constructor ==========\n\n";

    Player villain{"Villain", 100, 15};

    villain.display();

    return 0;
}