/***********************************************************************
 * PublicAndPrivate.cpp
 *
 * Topic:
 *      Public vs Private Access Specifiers
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. private Members
 * 2. public Members
 * 3. Data Hiding
 * 4. Member Function Access
 * 5. Encapsulation Introduction
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

    //----------------------------------------------------------
    // Private Attributes
    //----------------------------------------------------------

    string name {"Player"};
    int health {100};
    int xp {0};

public:

    //----------------------------------------------------------
    // Public Member Functions
    //----------------------------------------------------------

    void talk(string text_to_say)
    {
        cout << name
             << " says: \""
             << text_to_say
             << "\""
             << endl;
    }

    bool is_dead();
};

//==============================================================
// Main
//==============================================================

int main()
{
    Player emir;

    //----------------------------------------------------------
    // These statements are NOT allowed.
    // The attributes are private.
    //----------------------------------------------------------

    // emir.name = "Emir";
    // emir.health = 100;
    // emir.xp = 41;

    // cout << emir.health << endl;

    //----------------------------------------------------------
    // This works because talk() is public.
    //----------------------------------------------------------

    emir.talk("Hi there!");

    return 0;
}