/***********************************************************************
 * Account.cpp
 *
 * Account Class Implementation
 *
 ***********************************************************************/

#include "Account.h"

//==============================================================
// Member Function Definitions
//==============================================================

void Account::set_name(std::string n)
{
    name = n;
}

std::string Account::get_name()
{
    return name;
}

bool Account::deposit(double amount)
{
    if (amount < 0)
        return false;

    balance += amount;

    return true;
}

bool Account::withdraw(double amount)
{
    if (amount > balance)
        return false;

    balance -= amount;

    return true;
}