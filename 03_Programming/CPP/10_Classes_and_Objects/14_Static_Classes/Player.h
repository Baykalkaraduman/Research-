#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <string>

//==============================================================
// Player Class
//==============================================================

class Player
{
private:

    // Shared by every Player object.
    // Only one copy exists for the entire class.

    static int num_players;

    std::string name;
    int health;
    int xp;

public:

    //==========================================================
    // Getters
    //==========================================================

    std::string get_name() const
    {
        return name;
    }

    int get_health() const
    {
        return health;
    }

    int get_xp() const
    {
        return xp;
    }

    //==========================================================
    // Constructors
    //==========================================================

    Player(std::string name_val = "None",
           int health_val = 0,
           int xp_val = 0);

    Player(const Player &source);

    ~Player();

    //==========================================================
    // Static Member Function
    //==========================================================

    // Since this function belongs to the class itself,
    // it can only directly access static members.

    static int get_num_players();
};

#endif