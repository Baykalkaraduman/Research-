#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str;      // pointer to a char[] that hold a C-style string
public:
    Mystring();                                                          // No-args constructor
    Mystring(const char *s);                                      // Overloaded constructor
    Mystring(const Mystring &source);                     // Copy constructor
    Mystring( Mystring &&source);                          // Move constructiror
    ~Mystring();                                                      // Destructor
    
    Mystring &operator=(const Mystring &rhs);    // Copy assignment
    Mystring &operator=(Mystring &&rhs);          // Move assignment

    /*
    ==============================================================
                            Unary Minus Operator
    ==============================================================

    Overloads the unary '-' operator.

    Purpose

        Converts every alphabetic character
        in the string into lowercase.

    Example

        Mystring name{"LARRY"};

        Mystring lower = -name;

        lower

            "larry"

    Notice

        The original object is NOT modified.

        A completely new Mystring object
        is returned.

    Because this function does not modify
    the current object,

    it is marked

        const
    */

    Mystring operator-() const;



    /*
    ==============================================================
                        Concatenation Operator
    ==============================================================

    Overloads the '+' operator.

    Purpose

        Concatenates two Mystring objects.

    Example

        Mystring first{"Hello"};
        Mystring second{" World"};

        Mystring sentence = first + second;

    Result

        "Hello World"

    This function returns a completely new
    Mystring object.

    Neither operand is modified.

    Because the current object remains unchanged,

    this function is also marked

        const
    */

    Mystring operator+(const Mystring &rhs) const;



    /*
    ==============================================================
                        Equality Operator
    ==============================================================

    Overloads the '==' operator.

    Purpose

        Compares the contents of two strings.

    Returns

        true

            if both strings contain exactly
            the same characters.

        false

            otherwise.

    Example

        if (a == b)
            ...

    Notice

        The comparison is performed using

            strcmp()

        instead of comparing pointer addresses.

    The current object is not modified,

    therefore this function is marked

        const.
    */

    bool operator==(const Mystring &rhs) const;
    
    void display() const;

    int get_length() const;                                        // getters
    const char *get_str() const;
};

#endif // _MYSTRING_H_
