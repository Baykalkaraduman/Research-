/***********************************************************************
 * DefaultConstructors.cpp
 *
 * Topic:
 *      Default Constructors
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Compiler-Generated Default Constructor
 * 2. User-Defined Default Constructor
 * 3. Overloaded Constructors
 * 4. Object Initialization
 * 5. Getter and Setter Functions
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
    // Setter
    //----------------------------------------------------------

    void set_name(string name_val)
    {
        name = name_val;
    }

    //----------------------------------------------------------
    // Getter
    //----------------------------------------------------------

    string get_name()
    {
        return name;
    }

    //----------------------------------------------------------
    // Default Constructor
    //----------------------------------------------------------

    // If we define no constructor,
    // the compiler generates one automatically.
    // Here we define our own constructor so every player
    // starts with meaningful values.

    Player()
    {
        name = "Nameless";
        health = 100;
        xp = 4;

        cout << "Default Constructor Called" << endl;
    }

    //----------------------------------------------------------
    // Overloaded Constructor
    //----------------------------------------------------------

    Player(string name_val,
           int health_val,
           int xp_val)
    {
        name = name_val;
        health = health_val;
        xp = xp_val;

        cout << "Overloaded Constructor Called" << endl;
    }
};

//==============================================================
// Main
//==============================================================

int main()
{
    cout << "\n========== Default Constructor ==========\n" << endl;

    Player hero;

    hero.set_name("Blue Masked Spirit");

    cout << hero.get_name() << endl;

    cout << "\n========== Overloaded Constructor ==========\n" << endl;

    Player emir("Emir", 222, 12);

    cout << emir.get_name() << endl;

    return 0;
}