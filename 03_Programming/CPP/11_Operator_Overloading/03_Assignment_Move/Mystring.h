#ifndef _MYSTRING_H_
#define _MYSTRING_H_

/***********************************************************************
 * MyString.h
 *
 * This file contains the declaration of the Mystring class.
 *
 * Notice that this file only declares WHAT the class can do.
 *
 * The actual implementation of every member function is located
 * inside MyString.cpp.
 *
 * Separation of declaration and implementation is one of the
 * fundamental ideas of professional C++ programming.
 ***********************************************************************/



/*
    Include Guards

    Imagine two files both include

        MyString.h

    Without these include guards the compiler would read
    the same class definition multiple times and generate errors.

    The first inclusion defines

        _MYSTRING_H_

    Every later inclusion simply skips this file.
*/



//==============================================================
// MyString Class
//==============================================================

class Mystring
{
private:

    /*
        Pointer to a dynamically allocated C-style string.

        Example

            str

             │

             ▼

        +----------------------+
        | H | e | l | l | o |\0|
        +----------------------+

        Notice

        The object DOES NOT store characters directly. Instead, it stores the ADDRESS of dynamically allocated memory.
    */

    char *str;



public:

    //==========================================================
    // Constructors / Destructor
    //==========================================================

    /*
        Creates

            ""

        (empty string)
    */

    Mystring();

    /*
        Creates a Mystring object from

            const char*

        Example

            Mystring name{"Larry"};
    */

    Mystring(const char *s);

    /*
        Copy Constructor

        Creates a NEW object

        by copying another object.

        Example

            Mystring a{"Hello"};

            Mystring b{a};
    */

    Mystring(const Mystring &source);

    /*
        Destructor

        Responsible for releasing dynamically allocated memory.
    */

    /*
    Move Constructor

    Called whenever a NEW object is initialized
    from a temporary (r-value) object.

    Example

        Mystring b{Mystring{"Hello"}};

    Instead of copying every character,
    ownership of the dynamically allocated memory
    is transferred to the new object.

    This avoids unnecessary allocations and copies.
*/
Mystring(Mystring &&source) noexcept;

    ~Mystring();



    //==========================================================
    // Copy Assignment Operator
    //==========================================================

    /*
        Called when assigning one existing object to another.

        Example

            a = b;

        NOT

            Mystring a{b};

        The returned reference allows

            a = b = c;

        to work correctly.
    */

    Mystring &operator=(const Mystring &rhs);

    /*
    Move Assignment Operator

    Called whenever an EXISTING object receives
    a temporary (r-value) object.

    Example

        obj = Mystring{"Hello"};

    The existing resource owned by obj is released,
    then ownership of the temporary object's memory
    is transferred directly.

    No character copying occurs.

    Returning a reference allows expressions such as

        a = b = Mystring{"Hello"};
*/
    Mystring &operator=(Mystring &&rhs) noexcept;


    //==========================================================
    // Utility Functions
    //==========================================================

    /*
        Prints

            string : length

        Example

            Larry : 5
    */

    void display() const;



    //==========================================================
    // Getters
    //==========================================================

    /*
        Returns

        number of visible characters.
    */

    int get_length() const;

    /*
        Returns

        the internal C-style string.

        Notice

            const char*

        protects the internal data from modification.
    */

    const char *get_str() const;
};

#endif