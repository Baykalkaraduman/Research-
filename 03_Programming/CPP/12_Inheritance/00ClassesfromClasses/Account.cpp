#include "Account.h"


//============================================================
// Account Constructor
//============================================================
//
// This constructor initializes the BASE CLASS.
//
// When a Savings_Account object is created,
// the Account constructor is also involved.
//
// Constructor order is:
//
//      Base constructor
//          ↓
//      Derived constructor
//
// We will see this clearly when running the program.
//
Account::Account()
    : balance{0.0},
      name{"The Account"}
{
}


//============================================================
// Account Destructor
//============================================================
//
// This destructor belongs to the base class.
//
// For a derived object, destruction happens in the
// opposite order of construction:
//
//      Derived destructor
//          ↓
//      Base destructor
//
Account::~Account()
{
}


//============================================================
// Account::deposit
//============================================================
//
// This is the base-class implementation of deposit().
//
void Account::deposit(double amount)
{
    std::cout << "Account deposit called with "
              << amount
              << std::endl;
}


//============================================================
// Account::withdraw
//============================================================
//
// This is the base-class implementation of withdraw().
//
void Account::withdraw(double amount)
{
    std::cout << "Account withdraw called with "
              << amount
              << std::endl;
}