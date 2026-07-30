#include <iostream>
#include <cstring>
#include <cctype>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str)+ 1];
        std::strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment operator
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment operator
Mystring &Mystring::operator=( Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

//==============================================================
// Equality Operator (==)
//==============================================================

/*
    Overloads the equality operator.

    Example

        Mystring first{"Frank"};
        Mystring second{"Frank"};

        if (first == second)

    Instead of comparing memory addresses,

        first.str == second.str

    which would compare POINTERS,

    we compare the actual characters stored
    inside both strings.

    Therefore,

        strcmp()

    is used.
*/

bool Mystring::operator==(const Mystring &rhs) const
{
    /*
        strcmp()

        returns

            0

        when both strings are identical.

        Example

            "Hello"

                vs

            "Hello"

        returns

            0

        Any non-zero value means
        the strings are different.
    */

    return (std::strcmp(str, rhs.str) == 0);
}



//==============================================================
// Unary Minus Operator (-)
//==============================================================

/*
    Overloads the unary minus operator.

    Example

        Mystring name{"LARRY"};

        Mystring lower = -name;

    Result

        lower

            "larry"

    The original object

        name

    remains unchanged.

    A completely NEW Mystring object
    is returned.
*/

Mystring Mystring::operator-() const
{
    /*
        Allocate temporary memory.

        We cannot modify

            str

        because this function is

            const.

        Therefore we create a temporary copy.
    */

    char *buffer = new char[std::strlen(str) + 1];

    /*
        Copy every character from the
        original string.
    */

    std::strcpy(buffer, str);

    /*
        Convert every character
        to lowercase.

        strlen(buffer)

        tells us how many visible
        characters exist.
    */

    for (size_t i = 0; i < std::strlen(buffer); i++)
    {
        /*
            tolower()

            converts

                'A'

            into

                'a'

            whenever possible.

            Characters that are already
            lowercase remain unchanged.
        */

        buffer[i] = std::tolower(buffer[i]);
    }

    /*
        Construct a NEW Mystring object
        from the modified C-string.
    */

    Mystring temp{buffer};

    /*
        buffer was allocated using

            new[]

        therefore we must release it.
    */

    delete[] buffer;

    /*
        Return the temporary object.

        Because temp is a local object,

        modern C++ will usually invoke

            Return Value Optimization (RVO)

        or

            Move Constructor

        instead of performing a deep copy.
    */

    return temp;
}



//==============================================================
// Concatenation Operator (+)
//==============================================================

/*
    Overloads the addition operator.

    Example

        Mystring first{"Hello"};
        Mystring second{" World"};

        Mystring result = first + second;

    Result

        "Hello World"

    Neither operand is modified.

    A completely NEW object is returned.
*/

Mystring Mystring::operator+(const Mystring &rhs) const
{
    /*
        Determine the total number
        of visible characters.

        Example

            "Hello"

                +

            " World"

        requires

            strlen(str)

                +

            strlen(rhs.str)

                +

            one extra byte for '\0'
    */

    char *buffer = new char[
        std::strlen(str)
        + std::strlen(rhs.str)
        + 1];

    /*
        Copy the left operand.

            buffer

        now contains

            "Hello"
    */

    std::strcpy(buffer, str);

    /*
        Append the right operand.

            strcat()

        starts writing exactly where
        the first string ends.

        Result

            "Hello World"
    */

    std::strcat(buffer, rhs.str);

    /*
        Construct a new Mystring object
        using the concatenated C-string.
    */

    Mystring temp{buffer};

    /*
        Free temporary memory.

        The Mystring constructor already
        created its own deep copy.
    */

    delete[] buffer;

    /*
        Return the newly created object.

        Modern compilers usually perform

            Move Construction

        or

            Return Value Optimization (RVO)

        here.
    */

    return temp;
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring::get_length() const { return std::strlen(str); }
 
 // string getter
 const char *Mystring::get_str() const { return str; }








