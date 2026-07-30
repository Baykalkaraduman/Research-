/***********************************************************************
 *
 *              Operator Overloading Demonstration
 *
 * This program demonstrates three overloaded operators
 * implemented inside the Mystring class.
 *
 *      ==
 *      unary -
 *      +
 *
 * Every operation creates or compares Mystring objects
 * exactly as built-in types do.
 *
 ***********************************************************************/

#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    cout << "=====================================================\n";
    cout << "Equality Operator (==)\n";
    cout << "=====================================================\n\n";

    Mystring larry{"Larry"};
    Mystring moe{"Moe"};

    /*
        The overloaded == operator compares
        the CONTENTS of both strings.

        It does NOT compare pointer addresses.
    */

    if (larry == moe)
        cout << "Larry and Moe are equal\n";
    else
        cout << "Larry and Moe are different\n";



    Mystring larry2{"Larry"};

    if (larry == larry2)
        cout << "Larry and Larry are equal\n";
    else
        cout << "Larry and Larry are different\n";



    cout << "\n=====================================================\n";
    cout << "Unary Minus Operator (-)\n";
    cout << "=====================================================\n\n";

    /*
        The unary minus operator converts
        every character into lowercase.

        A NEW object is returned.

        The original object remains unchanged.
    */

    Mystring upper{"THIS IS A TEST"};

    Mystring lower = -upper;

    cout << "Original : ";
    upper.display();

    cout << "Lowercase: ";
    lower.display();



    cout << "\n=====================================================\n";
    cout << "Concatenation Operator (+)\n";
    cout << "=====================================================\n\n";

    /*
        The + operator concatenates
        two Mystring objects.

        Neither operand changes.

        A completely new object
        is returned.
    */

    Mystring first{"Hello"};
    Mystring second{" World"};

    Mystring sentence = first + second;

    cout << "First : ";
    first.display();

    cout << "Second: ";
    second.display();

    cout << "Result: ";
    sentence.display();



    cout << "\n=====================================================\n";
    cout << "Operator Chaining\n";
    cout << "=====================================================\n\n";

    /*
        Operators may be chained together.

        Execution order

            1) first + second

        returns

            Mystring{"Hello World"}

        Then

            + "!!!"

        is executed on that temporary object.

        Finally,

        the result is assigned to

            excited
    */

    Mystring excited = first + second + Mystring{"!!!"};

    excited.display();



    cout << "\n=====================================================\n";
    cout << "End of Program\n";
    cout << "=====================================================\n";

    /*
        When main() finishes,

        every Mystring object is destroyed.

        Observe the console output carefully.

        You will see

            • Destructor calls
            • Move Constructor calls
            • Temporary objects disappearing

        Watching this output is one of the best ways
        to understand object lifetime in C++.
    */

    return 0;
}