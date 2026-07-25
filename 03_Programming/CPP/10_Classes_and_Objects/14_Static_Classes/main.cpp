/***********************************************************************
 * StaticMembers.cpp
 *
 * Topic:
 *      Static Data Members and Static Member Functions
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Static Class Variables
 * 2. Static Member Functions
 * 3. Shared Class State
 * 4. Object Lifetime
 ***********************************************************************/

#include <iostream>
#include "Player.h"

//==============================================================
// Helper Function
//==============================================================

// This function demonstrates that a static member function
// can be called without creating any Player object.

void display_active_players()
{
    std::cout
        << "Active Players: "
        << Player::get_num_players()
        << '\n';
}

//==============================================================
// Main
//==============================================================

int main()
{
    display_active_players();

    Player hero{"Hero"};

    display_active_players();

    {
        Player emir{"Emir"};

        display_active_players();

    }   // emir goes out of scope here

    display_active_players();

    Player *enemy = new Player{"Enemy", 100, 100};

    display_active_players();

    delete enemy;

    display_active_players();

    return 0;
}