#include "Savings_Account.h"


//============================================================
// Savings_Account Constructor
//============================================================
//
// Because Savings_Account is derived from Account,
// creating a Savings_Account object involves TWO constructors:
//
//      1. Account constructor
//      2. Savings_Account constructor
//
// The base constructor runs FIRST.
//
// Then the derived constructor runs.
//
Savings_Account::Savings_Account()
    : int_rate{41.5}
{
}


//============================================================
// Savings_Account Destructor
//============================================================
//
// When a Savings_Account object is destroyed:
//
//      1. Savings_Account destructor runs
//      2. Account destructor runs
//
// Destruction happens in the reverse order of construction.
//
Savings_Account::~Savings_Account()
{
}


//============================================================
// Savings_Account::deposit
//============================================================
//
// Savings_Account has its own deposit() function.
//
// This function has the same name and parameter list as
// Account::deposit().
//
// At this stage:
//
//      Savings_Account::deposit()
//
// hides the base-class version when called through a
// Savings_Account object.
//
// This is NOT yet runtime polymorphism.
//
// Virtual functions and override will come later.
//
void Savings_Account::deposit(double amount)
{
    std::cout << "Savings Account deposit called with "
              << amount
              << std::endl;
}


//============================================================
// Savings_Account::withdraw
//============================================================
//
// Same idea as deposit().
//
// Savings_Account provides its own implementation.
//
void Savings_Account::withdraw(double amount)
{
    std::cout << "Savings Account withdraw called with "
              << amount
              << std::endl;
}