#ifndef _MYSTRING_H_
#define _MYSTRING_H_

//=====================================================================
// MyString Class
//=====================================================================
//
// This class is a simplified implementation of std::string.
//
// Purpose
// -------
// Learn:
//
// • Classes and Objects
// • Dynamic Memory Allocation
// • Constructors
// • Destructor
// • Deep Copy
// • Rule of Three
// • Operator Overloading
//
// Throughout this project we gradually extend this class until it
// behaves similarly to the standard C++ std::string class.
//
//=====================================================================

class MyString
{
private:

    //-----------------------------------------------------------------
    // Data Member (Attribute)
    //-----------------------------------------------------------------
    //
    // Pointer to a dynamically allocated C-style string.
    //
    // Example:
    //
    //      "Physics"
    //
    // Memory
    //
    // str
    //  |
    //  v
    // +---+---+---+---+---+---+---+----+
    // | P | h | y | s | i | c | s | \0 |
    // +---+---+---+---+---+---+---+----+
    //
    // Since this memory is allocated with new[],
    // our class becomes responsible for deleting it.
    //

    char *str;



public:

//=====================================================================
// Constructors & Destructor
//=====================================================================

    //-----------------------------------------------------------------
    // No-Args Constructor
    //-----------------------------------------------------------------
    //
    // Creates an empty string.
    //
    // Example
    //
    //      MyString s;
    //

    MyString();


    //-----------------------------------------------------------------
    // Overloaded Constructor
    //-----------------------------------------------------------------
    //
    // Creates a MyString from a C-style string.
    //
    // Example
    //
    //      MyString name{"Larry"};
    //

    MyString(const char *s);


    //-----------------------------------------------------------------
    // Copy Constructor
    //-----------------------------------------------------------------
    //
    // Creates a completely independent copy.
    //
    // Performs a Deep Copy.
    //
    // Example
    //
    //      MyString second{first};
    //

    MyString(const MyString &source);


    //-----------------------------------------------------------------
    // Destructor
    //-----------------------------------------------------------------
    //
    // Releases dynamically allocated memory.
    //
    // Automatically called whenever an object
    // leaves its scope.
    //

    ~MyString();



//=====================================================================
// Member Functions
//=====================================================================

    //-----------------------------------------------------------------
    // Display Function
    //-----------------------------------------------------------------
    //
    // Prints both the string and its length.
    //
    // Example
    //
    //      Larry : 5
    //
    // Notice:
    //
    // const means this function promises
    // not to modify the object.
    //

    void display() const;



//=====================================================================
// Getter Functions
//=====================================================================

    //-----------------------------------------------------------------
    // Returns the length of the stored string.
    //
    // Example:
    //
    // "Physics"
    //
    // returns
    //
    //      7
    //

    int get_length() const;



    //-----------------------------------------------------------------
    // Returns a read-only pointer
    // to the internal C-style string.
    //
    // Returning const char*
    // prevents outside code from modifying
    // our internal memory directly.
    //

    const char *get_str() const;

};

#endif      // _MYSTRING_H_