#include <cstring>      // strlen(), strcpy()
#include <iostream>     // std::cout
#include "Mystring.h"

/***********************************************************************
 * MyString.cpp
 *
 * This file contains the implementation of every member function
 * declared inside MyString.h.
 *
 * Up to this point our class demonstrates the complete
 * Rule of Three:
 *
 * 1) Constructor
 * 2) Copy Constructor
 * 3) Copy Assignment Operator
 * 4) Destructor
 *
 * Why?
 *
 * Because MyString owns a dynamically allocated resource.
 *
 *              MyString Object
 *              -------------------------
 *              char *str
 *                   │
 *                   ▼
 *          +----------------------+
 *          | H | e | l | l | o |\0|
 *          +----------------------+
 *
 * Since memory is allocated manually using "new[]",
 * we are also responsible for copying and destroying it correctly.
 *
 **********************************************************************/



//==============================================================
// No-Arguments Constructor
//==============================================================

/*
    This constructor creates an EMPTY string.

    Instead of allowing str to stay nullptr forever,
    we allocate one character and store '\0'.

    Why?

    Because every function in this class expects "str"
    to point to a VALID C-string.

    A C-string is NOT simply an array of characters.

    It MUST end with

        '\0'

    Example:

        ""

        +----+
        | \0 |
        +----+

    Even an empty string still occupies one byte.
*/

Mystring::Mystring()
    : str{nullptr}          // Initialize pointer before constructor body executes.
{
    /*
        Allocate memory for ONE character.

        That one character will hold

            '\0'

        Nothing else.
    */

    str = new char[1];

    /*
        Dereference the pointer.

        Before:

            str
             │
             ▼
            [ ? ]

        After:

            str
             │
             ▼
            ['\0']

        The object now owns a valid empty string.
    */

    *str = '\0';
}



//==============================================================
// Overloaded Constructor
//==============================================================

/*
    This constructor creates a MyString object
    from a normal C-style string.

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
        The user may accidentally write

            Mystring obj{nullptr};

        Without this check,

            strlen(nullptr)

        would immediately crash the program.

        Therefore we convert nullptr
        into an empty string.
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

            counts characters

            UNTIL

            '\0'

            Example

                "Larry"

            Memory

            +---+---+---+---+---+----+
            | L | a | r | r | y | \0 |
            +---+---+---+---+---+----+

            strlen()

            returns

                5

            NOT

                6

            because '\0' is NOT counted.
        */

        /*
            We therefore allocate

            strlen() + 1

            to leave room for the null terminator.
        */

        str = new char[std::strlen(s) + 1];

        /*
            strcpy()

            copies every character,

            INCLUDING

            the null terminator.

            Before

            s
            │
            ▼

            "Larry"

            str
            │
            ▼

            ???????

            After

            s
            │
            ▼

            "Larry"

            str
            │
            ▼

            "Larry"

            Notice

            They contain the SAME characters,

            but NOT the same memory.
        */

        std::strcpy(str, s);
    }
}



//==============================================================
// Copy Constructor
//==============================================================

/*
    The Copy Constructor is automatically called whenever

    1)

        Mystring b{a};

    2)

        Mystring b = a;

    3)

        pass-by-value

    4)

        return-by-value
        (unless copy elision occurs)

    ------------------------------------------------------------

    The purpose of the Copy Constructor is NOT to copy the pointer.

    It copies THE RESOURCE.

    This is called "Deep Copy".
*/

Mystring::Mystring(const Mystring &source)
    : str{nullptr}
{
    /*
        Imagine source contains

                source

                   │
                   ▼

            +----------------------+
            | H | e | l | l | o |\0|
            +----------------------+

        BAD IDEA

            str = source.str;

        Result

                source.str
                     │
                     ▼

            +----------------------+
            | H | e | l | l | o |\0|
            +----------------------+
                     ▲
                     │
                  this->str

        Now TWO objects own

        ONE allocation.

        When both destructors execute,

        delete[]

        runs twice.

        This is called

            Double Delete

        and usually crashes the program.

        Therefore NEVER copy raw pointers directly.
    */

    /*
        Instead, allocate completely new memory.
    */

    str = new char[std::strlen(source.str) + 1];

    /*
        Copy every character

        from source

        into OUR OWN memory.

        Result

            source

                 │
                 ▼

        +----------------------+
        | H | e | l | l | o |\0|
        +----------------------+


            this

                 │
                 ▼

        +----------------------+
        | H | e | l | l | o |\0|
        +----------------------+

        Same contents

        Different memory.

        This is exactly what

        Deep Copy

        means.
    */

    std::strcpy(str, source.str);
}
//==============================================================
// Destructor
//==============================================================

/*
    Every constructor that allocates memory

            new[]

    MUST eventually release that memory using

            delete[]

    This is one of the most important rules of manual
    memory management.

    Constructor

        new[]

            ↓

    Destructor

        delete[]

    ------------------------------------------------------------

    If delete[] is forgotten,

    every object leaves memory behind after it dies.

    This is called

            Memory Leak.

    ------------------------------------------------------------

    Since every Mystring object owns exactly one dynamically
    allocated character array,

    every Mystring object must destroy that array before
    it disappears.
*/

Mystring::~Mystring()
{
    /*
        delete[]

        releases the dynamically allocated character array.

        Before

            str
             │
             ▼

        +----------------------+
        | H | e | l | l | o |\0|
        +----------------------+

        After

            Memory returned to the operating system.

        The object itself is also about to disappear.
    */

    delete [] str;
}



//==============================================================
// Copy Assignment Operator
//==============================================================

/*
    The Copy Assignment Operator is called whenever

        an already existing object

    receives another object's value.

    Example

        Mystring a{"Hello"};
        Mystring b{"World"};

        b = a;

    Important

    b already exists.

    Therefore

    the Copy Constructor CANNOT be used.

    Instead,

    operator=

    performs the copying.

    ------------------------------------------------------------

    Difference

    Copy Constructor

        Creates a NEW object.

    Copy Assignment

        Reuses an EXISTING object.

    ------------------------------------------------------------

    Example

        Mystring a{"Hello"};

        Mystring b;

        b = a;

    Timeline

        Constructor for b

                ↓

        operator=(a)

    NOT

        Copy Constructor.
*/

Mystring &Mystring::operator=(const Mystring &rhs)
{
    std::cout << "Copy Assignment Operator" << std::endl;

    /*
        Self Assignment Protection

        Consider

            str = str;

        or

            a = a;

        Without this check,

        the following happens

            delete[] str;

        Now

            rhs.str

        points to deleted memory,

        because rhs and this are actually
        the SAME object.

        The next line

            strlen(rhs.str)

        would access invalid memory.

        Result

            Undefined Behaviour

        Therefore,

        always protect against self assignment.
    */

    if (this == &rhs)
        return *this;

    /*
        Step 1

        Destroy the old resource.

        Current object

            this

            │

            ▼

        +----------------------+
        | O | l | d |\0|
        +----------------------+

        becomes

            freed memory.
    */

    delete [] str;

    /*
        Step 2

        Allocate enough memory for rhs.

        rhs

            "Hello"

        strlen()

            returns

                5

        therefore

            allocate

                6
    */

    str = new char[std::strlen(rhs.str) + 1];

    /*
        Step 3

        Copy every character.

        Before

            rhs

                │
                ▼

        "Hello"

            this

                │
                ▼

        ???????

        After

            rhs

                │
                ▼

        "Hello"

            this

                │
                ▼

        "Hello"

        Again,

        this is

        Deep Copy.
    */

    std::strcpy(str, rhs.str);

    /*
        Step 4

        Return the current object.

        Why?

        So expressions like

            a = b = c;

        become possible.

        Evaluation

            b.operator=(c)

                    returns

                    b

                        ↓

            a.operator=(b)

        Since operator=

        returns a reference,

        no unnecessary copies are created.
    */

    return *this;
}



//==============================================================
// Display Function
//==============================================================

/*
    Convenience function used throughout the examples.

    Prints

        String

            :

        Length

    Example

        Larry : 5
*/

void Mystring::display() const
{
    std::cout
        << str
        << " : "
        << get_length()
        << std::endl;
}



//==============================================================
// Getters
//==============================================================

/*
    Returns the number of visible characters.

    Example

        "Larry"

    returns

        5

    because

        '\0'

    is not counted.
*/

int Mystring::get_length() const
{
    return std::strlen(str);
}

/*
    Returns the address of the internal C-string.

    Notice

        const char*

    instead of

        char*

    This prevents outside code from modifying
    the internal character array directly.

    Example

        const char *text = obj.get_str();

    is allowed.

    But

        text[0] = 'X';

    is forbidden.

    This helps preserve encapsulation.
*/

const char *Mystring::get_str() const
{
    return str;
}


/***********************************************************************

                    Rule of Three Summary

    Mystring owns dynamic memory.

    Therefore it MUST define

        ✓ Destructor

        ✓ Copy Constructor

        ✓ Copy Assignment Operator

    This is called

                    Rule of Three.

    Later,

    when Move Constructor and Move Assignment
    are added,

    the class will follow

                    Rule of Five.

***********************************************************************/