#ifndef MYSTRING_H
#define MYSTRING_H

#pragma once

/***********************************************************************
 * MyString
 *
 * A simple string class used to demonstrate:
 *  - Constructors
 *  - Copy Constructor
 *  - Destructor
 *
 * Internally the class stores a dynamically allocated
 * C-style string.
 ***********************************************************************/

class MyString
{
private:

    // Pointer to a dynamically allocated C-style string.
    char *str;

public:

    //==========================================================
    // Constructors / Destructor
    //==========================================================

    MyString();                             // No-args constructor

    MyString(const char *s);                // Overloaded constructor

    MyString(const MyString &source);       // Copy constructor

    ~MyString();                            // Destructor

    //==========================================================
    // Utility Functions
    //==========================================================

    void display() const;

    int get_length() const;

    const char *get_str() const;
};

#endif