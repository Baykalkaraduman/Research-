/***********************************************************************
 * StructAndFriends.cpp
 *
 * Topics
 * ------------------------------------------------------------
 * 1. struct
 * 2. friend function
 * 3. friend class
 ***********************************************************************/

#include <iostream>
#include <string>

//==============================================================
// STRUCT
//==============================================================

// In C++, a struct is almost identical to a class.
// The only major difference is:
//
// struct  -> members are public by default.
// class   -> members are private by default.

struct Point
{
    double x;
    double y;

    void display() const
    {
        std::cout
            << "("
            << x
            << ", "
            << y
            << ")"
            << '\n';
    }
};

//==============================================================
// Forward Declaration
//==============================================================

class Player;

class PlayerPrinter
{
public:
    void print(const Player &p);
};

//==============================================================
// CLASS
//==============================================================

class Player
{
private:

    std::string name;
    int health;

public:

    Player(std::string n,
           int h)
        : name{n},
          health{h}
    {
    }

    // Friend Function

    friend void display_player(const Player &p);

    // Friend Class

    friend class PlayerPrinter;
};

//==============================================================
// Friend Function
//==============================================================

void display_player(const Player &p)
{
    std::cout
        << "Player: "
        << p.name
        << " | Health: "
        << p.health
        << '\n';
}

//==============================================================
// Friend Class
//==============================================================

void PlayerPrinter::print(const Player &p)
{
    std::cout
        << "[Friend Class] "
        << p.name
        << " has "
        << p.health
        << " HP"
        << '\n';
}

//==============================================================
// Main
//==============================================================

int main()
{
    std::cout
        << "===== STRUCT =====\n";

    Point p{3.5, 8.2};

    p.display();

    std::cout
        << "\n===== FRIEND FUNCTION =====\n";

    Player hero{"Hero", 100};

    display_player(hero);

    std::cout
        << "\n===== FRIEND CLASS =====\n";

    PlayerPrinter printer;

    printer.print(hero);

    return 0;
}