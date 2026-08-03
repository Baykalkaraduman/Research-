#include <iostream>
#include <cstring>

#include "MyString.h"

//=====================================================================
// No-Args Constructor
//=====================================================================
//
// Purpose
// -------
// Creates an EMPTY MyString object.
//
// Example:
//
//      MyString s;
//
// After construction:
//
//      str
//       |
//       v
//     +----+
//     | \0 |
//     +----+
//
// Notice:
//
// We DO NOT leave str as nullptr.
//
// Why?
//
// Because many member functions later call:
//
//      strlen(str)
//      strcpy(...)
//      strcmp(...)
//
// Those C library functions EXPECT a VALID C-style string.
//
// If str were nullptr:
//
//      strlen(nullptr);
//
// would immediately cause Undefined Behavior.
//
// Therefore every MyString object should ALWAYS contain
// a valid C-string, even if that string is empty.
//
// This idea is called:
//
//      "Always keep the object in a valid state."
//
// Many modern C++ classes follow exactly the same philosophy.
//
MyString::MyString()
    : str{nullptr}        // Initialize the pointer before entering
                          // the constructor body.
{
    // Allocate memory for exactly one character.
    //
    // Why one?
    //
    // Because an empty C-string still needs
    // the null terminator.

    str = new char[1];

    // Store the null terminator.
    //
    // Memory now contains:
    //
    // +----+
    // | \0 |
    // +----+
    //
    // Therefore:
    //
    // strlen(str) == 0

    *str = '\0';
}



//=====================================================================
// Overloaded Constructor
//=====================================================================
//
// Purpose
// -------
// Creates a MyString object from a C-style string.
//
// Example:
//
//      MyString name{"Larry"};
//
// Memory:
//
// source:
//
//      "Larry"
//
// becomes
//
//      +---+---+---+---+---+----+
//      | L | a | r | r | y | \0 |
//      +---+---+---+---+---+----+
//
// allocated dynamically.
//
// Every MyString object owns its own memory.
//
MyString::MyString(const char *s)
    : str{nullptr}
{
    //-----------------------------------------------------------------
    // nullptr Check
    //-----------------------------------------------------------------
    //
    // A user may accidentally write
    //
    //      MyString x{nullptr};
    //
    // Instead of crashing,
    // we simply create an empty string.
    //
    // This makes our class safer.
    //
    if (s == nullptr)
    {
        str = new char[1];

        *str = '\0';
    }
    else
    {
        //-----------------------------------------------------------------
        // strlen()
        //-----------------------------------------------------------------
        //
        // strlen() counts visible characters.
        //
        // Example:
        //
        //      "Physics"
        //
        // Memory:
        //
        // P h y s i c s \0
        //
        // strlen() returns
        //
        //      7
        //
        // NOT 8.
        //
        // Therefore we MUST allocate one extra byte
        // for '\0'.
        //

        str = new char[std::strlen(s) + 1];

        //-----------------------------------------------------------------
        // strcpy()
        //-----------------------------------------------------------------
        //
        // Copy every character,
        // including the null terminator.
        //
        // Before:
        //
        // s
        //  |
        //  v
        // "Larry"
        //
        // After:
        //
        // s -----------> "Larry"
        //
        // str ---------> "Larry"
        //
        // Different memory.
        // Same contents.
        //

        std::strcpy(str, s);
    }
}
//=====================================================================
// Copy Constructor
//=====================================================================
//
// Purpose
// -------
// Creates a NEW object using another existing object.
//
// Example:
//
//      MyString first{"Physics"};
//
//      MyString second{first};
//
// The compiler sees:
//
//      MyString second(first);
//
// and automatically calls the copy constructor.
//
//
//=====================================================================
// Why do we need a Copy Constructor?
//=====================================================================
//
// Imagine we simply copied the pointer:
//
//      this->str = source.str;
//
// Memory:
//
//      source.str
//            |
//            +-----------------+
//                              |
//      this->str --------------+
//
// Both objects now point to EXACTLY
// the same memory.
//
// When the first object dies:
//
//      delete[] str;
//
// the memory disappears.
//
// The second object STILL points to that
// deleted memory.
//
// This is called:
//
//      Dangling Pointer
//
// Later...
//
// second's destructor also executes:
//
//      delete[] str;
//
// BOOM.
//
// Double delete.
//
// Undefined Behavior.
//
// This is called a
//
//      Shallow Copy
//
// and is one of the most common mistakes
// beginners make with dynamic memory.
//
//
//=====================================================================
// Deep Copy
//=====================================================================
//
// Instead of copying the pointer itself,
// we allocate NEW memory.
//
// Then we copy every character.
//
// Memory becomes:
//
//      source.str -------> "Physics"
//
//      this->str --------> "Physics"
//
// Same contents.
//
// Different addresses.
//
// Now every object owns its own memory.
//
// When one object dies,
// the other one remains perfectly valid.
//
MyString::MyString(const MyString &source)
    : str{nullptr}
{
    //-----------------------------------------------------------------
    // Allocate NEW memory
    //-----------------------------------------------------------------
    //
    // We DO NOT want both objects sharing memory.
    //
    // Therefore we allocate our own character array.
    //

    str = new char[std::strlen(source.str) + 1];



    //-----------------------------------------------------------------
    // Copy characters
    //-----------------------------------------------------------------
    //
    // strcpy copies the complete C-string,
    // including '\0'.
    //
    // Before:
    //
    // source
    //
    //      +----------------------------+
    //      | P h y s i c s \0           |
    //      +----------------------------+
    //
    // After:
    //
    // source
    //
    //      +----------------------------+
    //      | P h y s i c s \0           |
    //      +----------------------------+
    //
    // this
    //
    //      +----------------------------+
    //      | P h y s i c s \0           |
    //      +----------------------------+
    //
    // Same text.
    //
    // Completely different memory.
    //

    std::strcpy(str, source.str);



    //-----------------------------------------------------------------
    // Final Result
    //-----------------------------------------------------------------
    //
    // source
    //
    //      str -----> "Physics"
    //
    // this
    //
    //      str -----> "Physics"
    //
    // Different addresses.
    //
    // Both objects can safely destroy themselves.
    //

    std::cout 
        << "Copy Constructor Used"
        << std::endl;
}
//=====================================================================
// Destructor
//=====================================================================
//
// Purpose
// -------
// Release every resource that this object owns.
//
// Our class allocated dynamic memory using:
//
//      new[]
//
// Therefore we MUST eventually release that memory using:
//
//      delete[]
//
// If we forget this,
// every MyString object would leak memory.
//
//
//
// Lifetime Example
// ----------------
//
// {
//      MyString first{"Physics"};
//
// }   <----- Scope ends here.
//
// Compiler automatically calls:
//
//      first.~MyString();
//
// Memory:
//
//      before:
//
//          str -----> "Physics"
//
//      after:
//
//          memory released.
//
//
//=====================================================================
// Rule of Three
//=====================================================================
//
// Any class that manages dynamic memory usually needs:
//
//      1. Destructor
//      2. Copy Constructor
//      3. Copy Assignment Operator
//
// We already have:
//
// ✔ Destructor
// ✔ Copy Constructor
//
// Next chapter:
//
//      Copy Assignment Operator
//
// will complete the Rule of Three.
//
MyString::~MyString()
{
    // Release the dynamically allocated character array.
    //
    // delete[] is REQUIRED because the memory
    // was allocated using new[].

    delete [] str;

    // After the destructor finishes,
    // this object no longer exists.
}



//=====================================================================
// Display
//=====================================================================
//
// Purpose
// -------
// Print the contents of the object.
//
// Example:
//
//      Larry : 5
//
// String      Length
//
// Notice:
//
// display() is declared const.
//
// This guarantees that displaying an object
// never changes its data.
//
void MyString::display() const
{
    std::cout
        << str
        << " : "
        << get_length()
        << std::endl;
}



//=====================================================================
// Getter Functions
//=====================================================================
//
// Getter functions provide READ-ONLY access
// to private data.
//
// Notice:
//
// Every getter is declared const.
//
// That tells the compiler:
//
//      "I promise not to modify this object."
//
// Therefore getters can also be called on
// const objects.
//

int MyString::get_length() const
{
    //-----------------------------------------------------------------
    // strlen()
    //-----------------------------------------------------------------
    //
    // Counts visible characters
    // until '\0'.
    //
    // Example:
    //
    // "Physics"
    //
    // returns
    //
    //      7
    //

    return std::strlen(str);
}



const char *MyString::get_str() const
{
    //-----------------------------------------------------------------
    // Why return const char* ?
    //-----------------------------------------------------------------
    //
    // We want outside code to READ the string.
    //
    // We DO NOT want outside code to modify
    // our internal memory directly.
    //
    // Therefore:
    //
    //      const char*
    //
    // is much safer than
    //
    //      char*
    //
    // because this prevents statements such as
    //
    //      myString.get_str()[0] = 'X';
    //
    // from compiling.
    //

    return str;
}



/**********************************************************************
 *
 * Summary
 *
 * This file introduced the foundations required before implementing
 * operator overloading.
 *
 * Implemented so far:
 *
 * ✔ No-Args Constructor
 * ✔ Overloaded Constructor
 * ✔ Copy Constructor (Deep Copy)
 * ✔ Destructor
 * ✔ display()
 * ✔ Getters
 *
 *
 * Concepts Learned
 * ------------------------------------------------------------
 *
 * • Dynamic Memory Allocation
 * • C-Style Strings
 * • Deep Copy
 * • Object Ownership
 * • Resource Management
 * • RAII (Resource Acquisition Is Initialization)
 * • Rule of Three (Partially Completed)
 *
 *
 * Next Step
 * ------------------------------------------------------------
 *
 * Copy Assignment Operator
 *
 * After that we will implement:
 *
 *      operator=
 *
 * which completes the Rule of Three and prepares the class for
 * full operator overloading.
 *
 *********************************************************************/