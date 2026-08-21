#include <iostream>

#include "Account.h"
#include "Savings_Account.h"

using namespace std;


int main()
{

    //========================================================
    // Creating a Base-Class Object
    //========================================================
    //
    // Account is our BASE CLASS.
    //
    // This object contains only the Account part.
    //
    cout << "\n=== Account ==================================\n";

    Account acc{};


    // Account's own member functions
    //
    // deposit() and withdraw() belong directly to Account.
    //
    acc.deposit(2000.0);
    acc.withdraw(500.0);


    //========================================================
    // Base-Class Object on the Heap
    //========================================================
    //
    // We can also dynamically allocate a base-class object.
    //
    Account *p_acc{nullptr};

    p_acc = new Account{};

    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);

    // Since we used new, we must use delete.
    //
    // new      -> delete
    // new[]    -> delete[]
    //
    delete p_acc;


    //========================================================
    // Creating a Derived-Class Object
    //========================================================
    //
    // Savings_Account is derived from Account.
    //
    // Therefore a Savings_Account object contains:
    //
    //      Account part
    //          +
    //      Savings_Account part
    //
    cout << "\n=== Savings Account ==========================\n";

    Savings_Account sav_acc{};


    //========================================================
    // Inherited / Derived Member Functions
    //========================================================
    //
    // Savings_Account has its own deposit() and withdraw().
    //
    // Therefore these calls use:
    //
    //      Savings_Account::deposit()
    //      Savings_Account::withdraw()
    //
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500.0);


    //========================================================
    // Derived-Class Object on the Heap
    //========================================================

    Savings_Account *p_sav_acc{nullptr};

    p_sav_acc = new Savings_Account{};

    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);

    delete p_sav_acc;


    cout << "\n==============================================\n";

    return 0;
}