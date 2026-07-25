/***********************************************************************
 * AccessingClassObjects.cpp
 *
 * Topic:
 *      Accessing Class Objects
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. public Access Specifier
 * 2. Accessing Attributes
 * 3. Calling Member Functions
 * 4. Dot Operator (.)
 * 5. Arrow Operator (->)
 * 6. Accessing Objects Through Pointers
 *
 ***********************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//==============================================================
// Player Class
//==============================================================

class Player
{
public:

    //----------------------------------------------------------
    // Attributes
    //----------------------------------------------------------

    string name;
    int health;
    int xp;

    //----------------------------------------------------------
    // Member Functions
    //----------------------------------------------------------

    void talk(string text_to_say)
    {
        cout << name << " says: \"" << text_to_say << "\"" << endl;
    }

    bool is_dead();
};

//==============================================================
// Account Class
//==============================================================

class Account
{
public:

    //----------------------------------------------------------
    // Attributes
    //----------------------------------------------------------

    string name {"Account"};
    double balance {0.0};

    //----------------------------------------------------------
    // Member Functions
    //----------------------------------------------------------

    bool deposit(double money_in)
    {
        balance += money_in;

        cout << "Depositing: +$"
             << money_in
             << endl;

        return true;
    }

    bool withdraw(double money_out)
    {
        balance -= money_out;

        cout << "Withdrawing: -$"
             << money_out
             << endl;

        return true;
    }
};

//==============================================================
// Main
//==============================================================

int main()
{
    //----------------------------------------------------------
    // Accessing an Object Using the Dot Operator (.)
    //----------------------------------------------------------

    Player emir;

    emir.name = "Emir";
    emir.health = 100;
    emir.xp = 41;

    emir.talk("Hi there!");

    cout << endl;

    //----------------------------------------------------------
    // Accessing an Object Through a Pointer
    //----------------------------------------------------------

    Player *enemy {new Player};

    // Traditional notation

    (*enemy).name = "Enemy";
    (*enemy).health = 100;

    // Preferred notation

    enemy->xp = 42;

    enemy->talk("I will destroy you!");

    cout << endl;

    //----------------------------------------------------------
    // Working with Another Class
    //----------------------------------------------------------

    Account emir_account;

    emir_account.name = "Emir's Account";
    emir_account.balance = 5200.0;

    emir_account.deposit(850.0);
    emir_account.withdraw(800.0);

    cout << "\nCurrent Balance: $"
         << emir_account.balance
         << endl;

    //----------------------------------------------------------
    // Release Heap Memory
    //----------------------------------------------------------

    delete enemy;
    enemy = nullptr;

    return 0;
}