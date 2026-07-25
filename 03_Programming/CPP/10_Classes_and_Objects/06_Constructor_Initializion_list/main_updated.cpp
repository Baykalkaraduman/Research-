/***********************************************************************
 * ConstructorInitialization.cpp
 *
 * Topic:
 *      Constructor Initialization Lists
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Constructor Initialization Lists
 * 2. Initialization vs Assignment
 * 3. Constructor Overloading
 * 4. Efficient Object Construction
 ***********************************************************************/

#include <iostream>
#include <string>

//==============================================================
// Player Class
//==============================================================

class Player
{
private:

    // IMPORTANT:
    // Members are initialized in the order they are declared,
    // NOT in the order they appear in the initialization list.

    std::string name;
    int health;
    int xp;

public:

    //----------------------------------------------------------
    // Constructors
    //----------------------------------------------------------

    Player();

    Player(std::string name_val);

    Player(std::string name_val,
           int health_val,
           int xp_val);

    //----------------------------------------------------------
    // Utility Function
    //----------------------------------------------------------

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

Player::Player()
    : name{"None"},
      health{0},
      xp{0}
{
    std::cout << "Default Constructor Called\n";
}

//==============================================================
// One-Argument Constructor
//==============================================================

Player::Player(std::string name_val)
    : name{name_val},
      health{0},
      xp{0}
{
    std::cout << "One-Argument Constructor Called\n";
}

//==============================================================
// Three-Argument Constructor
//==============================================================

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
BAD (Assignment)

Player::Player()
{
    name = "None";
    health = 0;
    xp = 0;
}

The data members are created first.

After they already exist,
new values are assigned to them.

-------------------------------------------------------------
GOOD (Initialization)

Player::Player()
    : name{"None"},
      health{0},
      xp{0}
{

}

The data members are initialized directly.

No unnecessary assignments occur.

This is the preferred style in Modern C++.
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