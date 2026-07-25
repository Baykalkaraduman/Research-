/***********************************************************************
 * CopyConstructor.cpp
 *
 * Topic:
 *      Copy Constructors
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Copy Constructor
 * 2. Pass-by-Value
 * 3. Object Copying
 * 4. Delegating Copy Constructor
 ***********************************************************************/

#include <iostream>
#include <string>

//==============================================================
// Player Class
//==============================================================

class Player
{
private:

    std::string name;
    int health;
    int xp;

public:

    // Constructor
    Player(std::string name_val = "None",
           int health_val = 0,
           int xp_val = 0);

    // Copy Constructor
    Player(const Player &source);

    // Destructor
    ~Player();

    // Getters
    std::string get_name() const { return name; }
    int get_health() const { return health; }
    int get_xp() const { return xp; }
};

//==============================================================
// Constructor
//==============================================================

Player::Player(std::string name_val,
               int health_val,
               int xp_val)
    : name{name_val},
      health{health_val},
      xp{xp_val}
{
    std::cout << "Constructor called for "
              << name << '\n';
}

//==============================================================
// Copy Constructor
//==============================================================

// The new object is initialized using another existing object.

Player::Player(const Player &source)

    // Delegating to the main constructor
    : Player{source.name,
             source.health,
             source.xp}
{
    std::cout
        << "Copy Constructor called for "
        << source.name << '\n';
}

//==============================================================
// Destructor
//==============================================================

Player::~Player()
{
    std::cout
        << "Destructor called for "
        << name << '\n';
}

//==============================================================
// Helper Function
//==============================================================

// Passing by value creates a copy of the object.

void display_player(Player player)
{
    std::cout << "\nPlayer Information\n";
    std::cout << "------------------\n";

    std::cout << "Name   : "
              << player.get_name() << '\n';

    std::cout << "Health : "
              << player.get_health() << '\n';

    std::cout << "XP     : "
              << player.get_xp() << "\n\n";
}

/*
-------------------------------------------------------------

Copy Constructor Syntax

Player(const Player &source);

-------------------------------------------------------------

Why const?

The source object should never be modified.

-------------------------------------------------------------

Why pass by reference?

Passing by value would itself require another copy.

That would recursively call the copy constructor forever.

-------------------------------------------------------------
*/

int main()
{
    std::cout << "\n========== Original Object ==========\n\n";

    Player empty;

    std::cout << "\n========== Copy Construction ==========\n\n";

    Player copied_player{empty};

    std::cout << "\n========== Pass By Value ==========\n\n";

    display_player(empty);

    std::cout << "\n========== More Objects ==========\n\n";

    Player emir{"Emir"};

    Player hero{"Hero", 100};

    Player villain{"Villain", 100, 12};

    return 0;
}