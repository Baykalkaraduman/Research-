#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

#pragma once

//============================================================
// DERIVED CLASS
//============================================================
//
// Savings_Account is derived from Account.
//
// Syntax:
//
//      class Derived : public Base
//
// Therefore:
//
//      Savings_Account : public Account
//
// means:
//
//      Savings_Account IS-A Account
//
// The derived class automatically receives the accessible
// members of the base class.
//
// In our example:
//
//      Account
//          balance
//          name
//          deposit()
//          withdraw()
//
// are inherited by:
//
//      Savings_Account
//
// In addition, Savings_Account has its own:
//
//      int_rate
//
// and its own constructors/destructor.
//
class Savings_Account : public Account
{
public:

    //========================================================
    // Derived-Class Specific Data
    //========================================================

    // This member belongs specifically to Savings_Account.
    //
    // It does NOT come from Account.
    //
    double int_rate;


    //========================================================
    // Constructors / Destructor
    //========================================================

    Savings_Account();

    ~Savings_Account();


    //========================================================
    // Member Functions
    //========================================================
    //
    // These functions have the same names as the functions
    // in Account.
    //
    // At this stage, we are demonstrating that the derived
    // class can provide its own implementation.
    //
    // IMPORTANT:
    //
    // These are NOT polymorphic overrides yet.
    //
    // We have not introduced virtual functions.
    //
    void deposit(double amount);

    void withdraw(double amount);


private:

};

#endif