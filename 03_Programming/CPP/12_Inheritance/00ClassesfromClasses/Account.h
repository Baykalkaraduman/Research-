#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

#pragma once

//============================================================
// BASE CLASS
//============================================================
//
// Account is our BASE (PARENT) class.
//
// A base class contains the common attributes and
// functionality that derived classes can inherit.
//
// Example:
//
//      Account
//         ↑
//         |
//   Savings_Account
//
// Savings_Account will inherit the public members
// of Account.
//
class Account
{
public:

    //========================================================
    // Data Members
    //========================================================

    double balance;

    std::string name;


    //========================================================
    // Member Functions
    //========================================================

    void deposit(double amount);

    void withdraw(double amount);


    //========================================================
    // Constructor / Destructor
    //========================================================

    Account();

    ~Account();
};

#endif