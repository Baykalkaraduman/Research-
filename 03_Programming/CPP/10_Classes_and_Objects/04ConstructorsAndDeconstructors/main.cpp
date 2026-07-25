/***********************************************************************
 * ConstructorsAndDestructors.cpp
 *
 * Topic:
 *      Constructors and Destructors
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Default Constructor
 * 2. Overloaded Constructors
 * 3. Object Initialization
 * 4. Constructor Invocation
 * 5. Destructor
 * 6. Stack vs Heap Objects
 *
 ***********************************************************************/

#include <iostream>
#include <string>

using namespace std;

//==============================================================
// Player Class
//==============================================================

class Player
{
private:

    string name;
    int health;
    int xp;

public:

    //----------------------------------------------------------
    // Member Functions
    //----------------------------------------------------------

    void set_name(string name_val)
    {
        name = name_val;
    }

    //----------------------------------------------------------
    // Constructors
    //----------------------------------------------------------

    // Default Constructor
    Player()
    {
        name = "None";
        health = 100;
        xp = 0;

        cout << "Default Constructor Called" << endl;
    }

    // One-Argument Constructor
    Player(string name)
    {
        this->name = name;
        health = 100;
        xp = 0;

        cout << "One-Argument Constructor Called" << endl;
    }

    // Three-Argument Constructor
    Player(string name, int health, int xp)
    {
        this->name = name;
        this->health = health;
        this->xp = xp;

        cout << "Three-Argument Constructor Called" << endl;
    }

    //----------------------------------------------------------
    // Destructor
    //----------------------------------------------------------

    ~Player()
    {
        cout << "Destructor called for "
             << name
             << endl;
    }
};

//==============================================================
// Main
//==============================================================

int main()
{
    cout << "\n========== Stack Objects ==========\n" << endl;

    {
        Player slayer;
        slayer.set_name("Slayer");
    }

    cout << endl;

    {
        Player emir("Emir");

        Player hero;

        hero.set_name("Hero");

        Player villain("Villain", 100, 12);
    }

    cout << "\n========== Heap Objects ==========\n" << endl;

    Player *enemy {new Player("Enemy")};

    Player *level_boss {new Player("Level Boss", 250, 50)};

    delete enemy;
    delete level_boss;

    return 0;
}