/**
 * ============================================================================
 * FILE: main.cpp
 * DESCRIPTION: 
 * Demonstrates the powerful combination of Smart Pointers and Constructor Exceptions.
 * If the constructor of Checking_Account throws an IllegalBalanceException, 
 * std::make_unique guarantees that any memory allocated for the object is safely 
 * and automatically deallocated. Zero memory leaks!
 * ============================================================================
 */

#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"

using namespace std;

int main() {
    // =========================================================
    // EXCEPTION HANDLING & SMART POINTERS
    // =========================================================
    try {
        // We attempt to instantiate a Checking_Account dynamically.
        // We pass a negative balance (-10.0), which will trigger the exception
        // inside the Checking_Account/Account constructor.
        std::unique_ptr<Account> moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
        
        // This line is SKIPPED because the constructor above throws an exception.
        std::cout << *moes_account << std::endl;
    }
    // Catching the exact custom exception by CONST REFERENCE.
    catch (const IllegalBalanceException &ex)
    {
        // The error is handled gracefully. 
        // Because the constructor threw an exception, 'moes_account' was never 
        // fully created. The C++ runtime safely cleans up the raw memory 
        // allocated by std::make_unique.
        std::cerr << "Couldn't create account - negative balance" << std::endl;
    }
    
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}