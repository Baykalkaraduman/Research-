/***********************************************************************
 * main.cpp
 *
 * Demonstrates using the Account class.
 *
 ***********************************************************************/

#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
    Account emir_account;

    emir_account.set_name("Emir's Account");
    emir_account.set_balance(1000.0);

    cout << "Owner   : "
         << emir_account.get_name()
         << endl;

    cout << "Balance : $"
         << emir_account.get_balance()
         << endl;

    cout << "\n-----------------------------\n";

    if (emir_account.deposit(200.0))
        cout << "Deposit successful.\n";
    else
        cout << "Deposit failed.\n";

    cout << "Balance : $"
         << emir_account.get_balance()
         << endl;

    cout << "\n-----------------------------\n";

    if (emir_account.withdraw(500.0))
        cout << "Withdrawal successful.\n";
    else
        cout << "Insufficient funds.\n";

    cout << "Balance : $"
         << emir_account.get_balance()
         << endl;

    cout << "\n-----------------------------\n";

    if (emir_account.withdraw(1500.0))
        cout << "Withdrawal successful.\n";
    else
        cout << "Insufficient funds.\n";

    cout << "Final Balance : $"
         << emir_account.get_balance()
         << endl;

    return 0;
}