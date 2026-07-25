/***********************************************************************
 * Account.h
 *
 * Account Class Declaration
 *
 ***********************************************************************/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
private:

    //----------------------------------------------------------
    // Attributes
    //----------------------------------------------------------

    std::string name;
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

    void set_name(std::string n);
    std::string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif