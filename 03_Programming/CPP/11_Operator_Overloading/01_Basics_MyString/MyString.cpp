#include <iostream>
#include <cstring>

#include "MyString.h"

//==============================================================
// No-Args Constructor
//==============================================================

MyString::MyString()
    : str{nullptr}          // Initialize the pointer before entering the constructor body.
{
    // We always want our object to contain a VALID C-string.
    // Even an empty string must contain the null terminator.

    str = new char[1];      // Allocate memory for one character.

    *str = '\0';            // Store the null terminator.
                             // Now str points to an empty C-style string ("").
}

//==============================================================
// Overloaded Constructor
//==============================================================

MyString::MyString(const char *s)
    : str{nullptr}
{
    // If the user passes nullptr instead of a string,
    // create an empty string instead of crashing.

    if (s == nullptr)
    {
        str = new char[1];

        *str = '\0';
    }
    else
    {
        // strlen() returns the number of visible characters.
        //
        // Example:
        // "Larry"
        //
        // L a r r y \0
        // 1 2 3 4 5 6
        //
        // strlen("Larry") == 5
        //
        // Therefore we allocate one extra byte for '\0'.

        str = new char[std::strlen(s) + 1];

        // Copy the entire C-string into our own memory.
        //
        // This creates an independent copy.
        //
        // s ---------> "Larry"
        //
        // str -------> "Larry"

        std::strcpy(str, s);
    }
}

//==============================================================
// Copy Constructor
//==============================================================

MyString::MyString(const MyString &source)
    : str{nullptr}
{
    // source already owns its own dynamic memory.
    //
    // We DO NOT want:
    //
    // source.str ------
    //                  \
    //                   > same memory
    //                  /
    // this->str -------
    //
    // because both objects would delete the same memory.
    //
    // Instead we perform a DEEP COPY.

    str = new char[std::strlen(source.str) + 1];

    // Copy every character into our newly allocated memory.

    std::strcpy(str, source.str);

    // Result:
    //
    // source.str -----> "Larry"
    //
    // this->str ------> "Larry"
    //
    // Two different memory locations,
    // same contents.
}

//==============================================================
// Destructor
//==============================================================

MyString::~MyString()
{
    // Every object is responsible for freeing
    // the memory it allocated.

    delete [] str;

    // After this function returns,
    // the object's lifetime ends.
}

//==============================================================
// Display
//==============================================================

void MyString::display() const
{
    // Print the stored string
    // together with its current length.

    std::cout
        << str
        << " : "
        << get_length()
        << std::endl;
}

//==============================================================
// Getters
//==============================================================

int MyString::get_length() const
{
    // strlen() counts characters
    // until the null terminator.

    return std::strlen(str);
}

const char *MyString::get_str() const
{
    // Return the address of the internal C-string.
    //
    // Notice:
    // Returning const char*
    // prevents outside code from modifying our string directly.

    return str;
}