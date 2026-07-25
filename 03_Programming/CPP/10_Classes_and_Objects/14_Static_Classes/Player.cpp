#include "Player.h"

//==============================================================
// Static Member Definition
//==============================================================

// Static members must be defined exactly once
// outside the class.

int Player::num_players{0};

//==============================================================
// Constructors
//==============================================================

Player::Player(std::string name_val,
               int health_val,
               int xp_val)

    : name{name_val},
      health{health_val},
      xp{xp_val}
{
    ++num_players;
}

// Copy Constructor

Player::Player(const Player &source)

    : Player{source.name,
             source.health,
             source.xp}
{
}

//==============================================================
// Destructor
//==============================================================

Player::~Player()
{
    --num_players;
}

//==============================================================
// Static Member Function
//==============================================================

int Player::get_num_players()
{
    return num_players;
}