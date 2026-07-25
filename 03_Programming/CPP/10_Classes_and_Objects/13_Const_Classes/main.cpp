/***********************************************************************
 * ConstInClasses.cpp
 *
 * Topic:
 *      Const Member Functions
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. const Objects
 * 2. const Member Functions
 * 3. const References
 * 4. Read-only Member Functions
 * 5. Const Correctness
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

    //==========================================================
    // Getter
    //==========================================================

    // The const keyword guarantees that this function
    // does not modify the object.
    // Therefore it can safely be called on const objects.

    std::string get_name() const
    {
        return name;
    }

    //==========================================================
    // Setter
    //==========================================================

    // Setters modify the object,
    // therefore they cannot be const.

    void set_name(const std::string &name_val)
    {
        name = name_val;
    }

    //==========================================================
    // Constructors
    //==========================================================

    Player();

    Player(std::string name_val);

    Player(std::string name_val,
           int health_val,
           int xp_val);
};

//==============================================================
// Constructors
//==============================================================

// Delegating Constructor

Player::Player()

    : Player{"None", 0, 0}
{
}

// Delegating Constructor

Player::Player(std::string name_val)

    : Player{name_val, 0, 0}
{
}

// Main Constructor

Player::Player(std::string name_val,
               int health_val,
               int xp_val)

    : name{name_val},
      health{health_val},
      xp{xp_val}
{
}

//==============================================================
// Helper Function
//==============================================================

// The object is passed by const reference.
// No copy is created.
// The function promises not to modify the object.

void display_player_name(const Player &player)
{
    std::cout
        << player.get_name()
        << '\n';
}

//==============================================================
// Main
//==============================================================

int main()
{
    const Player villain{"Villain", 100, 55};

    Player hero{"Hero", 100, 15};

    // ERROR
    // villain.set_name("Super Villain");

    std::cout
        << villain.get_name()
        << '\n';

    std::cout
        << hero.get_name()
        << '\n';

    display_player_name(villain);

    display_player_name(hero);

    return 0;
}