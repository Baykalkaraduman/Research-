/***********************************************************************
 * ImplementingMethods1.cpp
 *
 * Topic:
 *      Implementing Member Methods Outside the Class
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Inline Member Functions
 * 2. Member Function Declarations
 * 3. Member Function Definitions
 * 4. Scope Resolution Operator (::)
 * 5. Encapsulation
 *
 ***********************************************************************/

#include <iostream>
#include <string>

using namespace std;

//==============================================================
// Account Class
//==============================================================

class Account
{
private:

    //----------------------------------------------------------
    // Attributes
    //----------------------------------------------------------

    string name;
    double balance {0.0};

public:

    //----------------------------------------------------------
    // Inline Member Functions
    //----------------------------------------------------------

    void set_balance(double bal)
    {
        balance = bal;
    }

    double get_balance()
    {
        return balance;
    }

    //----------------------------------------------------------
    // Member Function Declarations
    //----------------------------------------------------------

    void set_name(string n);
    string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

//==============================================================
// Member Function Definitions
//==============================================================

void Account::set_name(string n)
{
    name = n;
}

string Account::get_name()
{
    return name;
}

bool Account::deposit(double amount)
{
    // Future improvement:
    // Verify that amount > 0 before depositing.

    balance += amount;
    return true;
}

bool Account::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        return true;
    }

    return false;
}

//==============================================================
// Main
//==============================================================

int main()
{
    Account emir_account;

    emir_account.set_name("Emir's Account");
    emir_account.set_balance(1000.0);

    cout << "Account Owner : "
         << emir_account.get_name()
         << endl;

    cout << "Current Balance : $"
         << emir_account.get_balance()
         << endl;

    cout << "\n------------------------------\n";

    if (emir_account.deposit(200.0))
        cout << "Deposit successful.\n";
    else
        cout << "Deposit failed.\n";

    cout << "Balance : $"
         << emir_account.get_balance()
         << endl;

    cout << "\n------------------------------\n";

    if (emir_account.withdraw(500.0))
        cout << "Withdrawal successful.\n";
    else
        cout << "Insufficient funds.\n";

    cout << "Balance : $"
         << emir_account.get_balance()
         << endl;

    cout << "\n------------------------------\n";

    if (emir_account.withdraw(1500.0))
        cout << "Withdrawal successful.\n";
    else
        cout << "Insufficient funds.\n";

    cout << "Final Balance : $"
         << emir_account.get_balance()
         << endl;

    return 0;
}