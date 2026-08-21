/**
 * ============================================================================
 * FILE: IllegalBalanceException.h
 * DESCRIPTION: 
 * Defines a custom exception class for handling invalid account balances.
 * Using include guards (#ifndef, #define, #endif) prevents double-inclusion 
 * errors during compilation.
 * ============================================================================
 */

#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException
{
public:
    // explicitly instructing the compiler to generate the default constructor 
    // and destructor. This is a clean, modern C++ practice for empty classes.
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__