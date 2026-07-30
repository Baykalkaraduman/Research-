#include <iostream>
#include <cstring>
#include "Mystring.h"

/***********************************************************************
 * MyString.cpp
 *
 * This file contains the implementation of the Mystring class.
 *
 * Since Mystring owns dynamically allocated memory,
 * it follows the Rule of Five.
 *
 * Rule of Five
 *
 * 1) Constructor
 * 2) Destructor
 * 3) Copy Constructor
 * 4) Copy Assignment Operator
 * 5) Move Constructor
 * 6) Move Assignment Operator
 *
 * Every function exists for one reason:
 *
 *      safely managing dynamic memory.
 *
 **********************************************************************/



//==============================================================
// No-Arguments Constructor
//==============================================================

/*
    Creates an empty string.

    Memory Layout

        str
         │
         ▼

        +----+
        | \0 |
        +----+

    Even an empty C-string occupies one byte because
    every C-string must end with '\0'.
*/

Mystring::Mystring()
    : str{nullptr}
{
    /*
        Allocate one character.

        That character stores only

            '\0'
    */

    str = new char[1];

    *str = '\0';
}



//==============================================================
// Overloaded Constructor
//==============================================================

/*
    Constructs a Mystring object from a C-style string.

    Example

        Mystring name{"Larry"};

    Parameter

        s

    points to

        L a r r y \0
*/

Mystring::Mystring(const char *s)
    : str{nullptr}
{
    /*
        Protect against

            Mystring obj{nullptr};

        Without this check,

            strlen(nullptr)

        would immediately crash the program.
    */

    if (s == nullptr)
    {
        str = new char[1];

        *str = '\0';
    }
    else
    {
        /*
            strlen()

            counts visible characters only.

            Example

                "Larry"

            returns

                5

            NOT

                6

            because '\0' is not included.
        */

        str = new char[std::strlen(s) + 1];

        /*
            strcpy()

            copies every character

            INCLUDING

            the null terminator.
        */

        std::strcpy(str, s);
    }
}



//==============================================================
// Copy Constructor
//==============================================================

/*
    Called whenever a NEW object is initialized
    from another existing object.

    Example

        Mystring a{"Hello"};

        Mystring b{a};

    or

        Mystring b = a;

    The purpose is to perform a

            Deep Copy.

    Every Mystring object owns its own
    dynamically allocated memory.
*/

Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
    /*
        Never do

            str = source.str;

        because both objects would point to the
        same allocation.

        When both destructors execute,

            delete[]

        would run twice.

        This is called

            Double Delete.
    */

    str = new char[std::strlen(source.str) + 1];

    std::strcpy(str, source.str);

    std::cout << "Copy constructor used" << std::endl;
}



//==============================================================
// Move Constructor
//==============================================================

/*
    Called whenever a NEW object is initialized
    from a temporary object (r-value).

    Example

        Mystring a{Mystring{"Hello"}};

    Unlike the Copy Constructor,

    NO new memory is allocated.

    Instead,

    ownership of the existing allocation
    is transferred to the new object.

    This makes moving significantly faster
    than copying.
*/

Mystring::Mystring(Mystring &&source) noexcept
    : str{source.str}
{
    /*
        Both objects currently point to
        the same allocation.

                source
                   │
                   ▼

        +----------------------+
        | H | e | l | l | o |\0|
        +----------------------+
                   ▲
                   │
                 this

        We must prevent source from deleting
        that memory.
    */

    source.str = nullptr;

    /*
        The moved-from object is now safe.

        Its destructor will execute

            delete[] nullptr;

        which is perfectly valid.
    */

    std::cout << "Move constructor used" << std::endl;
}

//==============================================================
// Destructor
//==============================================================

/*
    Every constructor that allocates memory

            new[]

    MUST eventually release that memory using

            delete[]

    Constructor

            new[]

                ↓

    Destructor

            delete[]

    If delete[] is forgotten,

    every object leaks memory.

    Since every Mystring object owns exactly one
    dynamically allocated character array,

    every Mystring object is responsible for deleting it.
*/

Mystring::~Mystring()
{
    /*
        Printing the pointer's content helps us understand
        the order in which destructors are executed.

        After a Move Constructor or Move Assignment,

        the moved-from object contains

            nullptr

        Therefore we can easily observe
        which object still owns the resource.
    */

    if (str == nullptr)
    {
        std::cout << "Calling destructor for Mystring : nullptr"
                  << std::endl;
    }
    else
    {
        std::cout << "Calling destructor for Mystring : "
                  << str
                  << std::endl;
    }

    /*
        delete[] automatically checks whether

            str == nullptr

        Therefore

            delete[] nullptr;

        is completely safe.
    */

    delete[] str;
}



//==============================================================
// Copy Assignment Operator
//==============================================================

/*
    Called whenever an EXISTING object receives
    another EXISTING object.

    Example

        Mystring a{"Hello"};
        Mystring b{"World"};

        b = a;

    Unlike the Copy Constructor,

    b already exists.

    Therefore,

    we must first destroy its old memory,
    then create a completely new copy.
*/

Mystring &Mystring::operator=(const Mystring &rhs)
{
    std::cout << "Using Copy Assignment Operator"
              << std::endl;

    /*
        Protect against

            a = a;

        Without this check we would

            delete[] str;

        and then immediately attempt to copy
        from deleted memory.

        That results in Undefined Behaviour.
    */

    if (this == &rhs)
        return *this;

    /*
        Step 1

        Destroy the old resource.
    */

    delete[] str;

    /*
        Step 2

        Allocate enough memory
        for the new string.
    */

    str = new char[std::strlen(rhs.str) + 1];

    /*
        Step 3

        Deep copy every character.
    */

    std::strcpy(str, rhs.str);

    /*
        Returning *this allows

            a = b = c;

        to work correctly.
    */

    return *this;
}



//==============================================================
// Move Assignment Operator
//==============================================================

/*
    Called whenever an EXISTING object receives
    a TEMPORARY object (r-value).

    Example

        obj = Mystring{"Hello"};

    Instead of copying characters,

    ownership of the dynamic memory
    is transferred directly.
*/

Mystring &Mystring::operator=(Mystring &&rhs) noexcept
{
    std::cout << "Using Move Assignment Operator"
              << std::endl;

    /*
        Self-assignment protection.

        Rare for move semantics,
        but still considered good practice.
    */

    if (this == &rhs)
        return *this;

    /*
        Free the resource currently owned
        by this object.
    */

    delete[] str;

    /*
        Steal the pointer.

        Notice

        NO

            new[]

        NO

            strcpy()

        NO

            character copying

        Only the pointer is copied.
    */

    str = rhs.str;

    /*
        Leave the moved-from object
        in a valid empty state.

        This prevents a Double Delete.
    */

    rhs.str = nullptr;

    return *this;
}

//==============================================================
// Display Function
//==============================================================

/*
    Displays the current string together
    with its length.

    Example

        Larry : 5

    Notice

    display() is marked as

        const

    because displaying an object should never
    modify that object.
*/

void Mystring::display() const
{
    /*
        get_length()

        returns the number of visible characters.

        strlen()

        does NOT count the null terminator.
    */

    std::cout << str
              << " : "
              << get_length()
              << std::endl;
}



//==============================================================
// Getter : get_length()
//==============================================================

/*
    Returns the number of visible characters
    stored inside the string.

    Example

        "Hello"

    Memory

        H e l l o \0

    strlen()

    returns

        5

    NOT

        6

    because '\0' is not counted.
*/

int Mystring::get_length() const
{
    return std::strlen(str);
}



//==============================================================
// Getter : get_str()
//==============================================================

/*
    Returns the internal C-style string.

    Notice

        const char *

    instead of

        char *

    This prevents external code from modifying
    the internal character array directly.

    Example

        const char *p = obj.get_str();

    Reading

        p

    is allowed.

    Modifying

        *p = 'A';

    is NOT allowed.
*/

const char *Mystring::get_str() const
{
    return str;
}



/***********************************************************************
 *
 *                      Rule of Five Summary
 *
 * Because Mystring owns dynamic memory,
 * it must correctly manage that resource.
 *
 * Constructor
 *      Creates the resource.
 *
 * Destructor
 *      Releases the resource.
 *
 * Copy Constructor
 *      Creates an independent copy of another object.
 *
 * Copy Assignment Operator
 *      Replaces an existing object's resource with
 *      a deep copy of another object's resource.
 *
 * Move Constructor
 *      Transfers ownership of a temporary object's
 *      resource into a newly created object.
 *
 * Move Assignment Operator
 *      Transfers ownership of a temporary object's
 *      resource into an existing object.
 *
 * Copy Operations
 *
 *      Allocate memory
 *      Copy every character
 *
 * Move Operations
 *
 *      Transfer ownership
 *      No allocation
 *      No strcpy()
 *      Much faster
 *
 * This implementation follows the Rule of Five and
 * safely manages dynamically allocated memory without
 * memory leaks or double deletion.
 *
 **********************************************************************/