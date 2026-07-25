/***********************************************************************
 * DeclareClassObjects.cpp
 *
 * Topic:
 *      Declaring Classes and Creating Objects
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Defining a class
 * 2. Attributes (Data Members)
 * 3. Member Function Declarations
 * 4. Creating Objects
 * 5. Arrays of Objects
 * 6. Vectors of Objects
 * 7. Dynamically Allocating Objects
 *
 ***********************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//==============================================================
// Player Class
//==============================================================

class Player
{
    //==========================================================
    // Attributes (Data Members)
    //==========================================================

    string name {"Player"};
    int health {100};
    int xp {3};

    //==========================================================
    // Member Function Declarations
    //==========================================================

    void talk(string text);
    bool is_dead();
};

//==============================================================
// Account Class
//==============================================================

class Account
{
    //==========================================================
    // Attributes
    //==========================================================

    string name {"Account"};
    double balance {0.0};

    //==========================================================
    // Member Function Declarations
    //==========================================================

    bool deposit(double amount);
    bool withdraw(double amount);
};

//==============================================================
// Main
//==============================================================

int main()
{
    //----------------------------------------------------------
    // Creating Objects
    //----------------------------------------------------------

    Player frank;
    Player emir;

    //----------------------------------------------------------
    // Array of Objects
    //----------------------------------------------------------

    Player players[]
    {
        frank,
        emir
    };

    //----------------------------------------------------------
    // Vector of Objects
    //----------------------------------------------------------

    vector<Player> player_vector;

    player_vector.push_back(frank);
    player_vector.push_back(emir);

    //----------------------------------------------------------
    // Dynamic Object Allocation
    //----------------------------------------------------------

    Player *enemy {nullptr};

    enemy = new Player;

    // The object now exists on the Heap.
    // 'enemy' stores the address of that object.

    //----------------------------------------------------------
    // Release Heap Memory
    //----------------------------------------------------------

    delete enemy;
    enemy = nullptr;

    //----------------------------------------------------------

    cout << "Program finished successfully." << endl;

    return 0;
}