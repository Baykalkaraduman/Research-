/***********************************************************************
 * ConstructorsWithDefaultValues.cpp
 *
 * Topic:
 *      Constructors with Default Arguments
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Default Constructor Arguments
 * 2. Constructor Overloading Alternative
 * 3. Constructor Initialization Lists
 * 4. Flexible Object Creation
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

    // One constructor handles every possible case.
    Player(std::string name_val = "None",
           int health_val = 0,
           int xp_val = 0);

    void display() const
    {
        std::cout
            << "Name   : " << name << '\n'
            << "Health : " << health << '\n'
            << "XP     : " << xp << "\n\n";
    }
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
    std::cout << "Constructor Called\n";
}

/*
-------------------------------------------------------------

Without Default Arguments

Player();

Player(string);

Player(string,int);

Player(string,int,int);

-------------------------------------------------------------

With Default Arguments

Player(string name = "None",
       int health = 0,
       int xp = 0);

One constructor handles every situation.

-------------------------------------------------------------
*/

/*
Using default arguments allows a single constructor
to replace several overloaded constructors.

This reduces code duplication and keeps the class simpler.

However, default arguments are not appropriate for every class.
Some classes require completely different initialization logic.
*/

int main()
{
    std::cout << "\n========== Default Values ==========\n\n";

    Player empty;

    empty.display();

    std::cout << "========== Name Only ==========\n\n";

    Player emir{"Emir"};

    emir.display();

    std::cout << "========== Name + Health ==========\n\n";

    Player garlic_farmer{"Greg", 100};

    garlic_farmer.display();

    std::cout << "========== Full Constructor ==========\n\n";

    Player villain{"Villain", 200, 15};

    villain.display();

    return 0;
}