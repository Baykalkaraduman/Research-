/***********************************************************************
 * main.cpp
 *
 * Demonstration of the Copy Assignment Operator.
 *
 * This example also shows the difference between
 *
 *      Copy Constructor
 *
 * and
 *
 *      Copy Assignment Operator.
 *
 ***********************************************************************/

#include <iostream>
#include <vector>

#include "Mystring.h"

using namespace std;

int main()
{
    cout << "===============================" << endl;
    cout << "Basic Copy Assignment" << endl;
    cout << "===============================" << endl;

    /*
        Constructor

            "Hello"

        is created.
    */

    Mystring a{"Hello"};

    /*
        Empty string

        ""

        is created.
    */

    Mystring b;

    /*
        Copy Assignment

        b already exists.

        Therefore

        operator=

        is called.

        Equivalent to

            b.operator=(a);
    */

    b = a;

    /*
        Here

            "This is a test"

        is first converted into

        a temporary Mystring object.

        Then

        operator=

        copies that temporary object into b.

        Equivalent to

            b.operator=("This is a test");
    */

    b = "This is a test";



    cout << endl;
    cout << "===============================" << endl;
    cout << "Constructors vs Assignment" << endl;
    cout << "===============================" << endl;

    Mystring empty;

    Mystring larry{"Larry"};

    /*
        Copy Constructor

        because

        stooge

        is being CREATED.
    */

    Mystring stooge{larry};

    Mystring stooges;

    /*
        Copy Assignment

        because

        empty

        already exists.
    */

    empty = stooge;

    empty.display();

    larry.display();

    stooge.display();

    empty.display();



    cout << endl;
    cout << "===============================" << endl;
    cout << "Assignment from C-String" << endl;
    cout << "===============================" << endl;

    stooges = "Larry, Moe, and Curly";

    stooges.display();



    cout << endl;
    cout << "===============================" << endl;
    cout << "Vector Demonstration" << endl;
    cout << "===============================" << endl;

    /*
        Every push_back()

        constructs a temporary Mystring
        from a C-string.
    */

    vector<Mystring> stooges_vec;

    stooges_vec.push_back("Larry");

    stooges_vec.push_back("Moe");

    stooges_vec.push_back("Curly");



    cout << endl;
    cout << "========== Loop 1 ==========" << endl;

    /*
        Read-only iteration.

        const reference

        avoids unnecessary copying.
    */

    for (const Mystring &s : stooges_vec)
        s.display();



    cout << endl;
    cout << "========== Loop 2 ==========" << endl;

    /*
        Non-const reference.

        Every element already exists.

        Therefore

        Copy Assignment Operator

        is called three times.
    */

    for (Mystring &s : stooges_vec)
        s = "Changed";



    cout << endl;
    cout << "========== Loop 3 ==========" << endl;

    /*
        Verify the assignment.

        Every object now stores

            "Changed"
    */

    for (const Mystring &s : stooges_vec)
        s.display();



    cout << endl;
    cout << "===============================" << endl;
    cout << "End of Program" << endl;
    cout << "===============================" << endl;

    /*
        At this point

        every object's destructor

        will execute automatically.

        Since Mystring follows the Rule of Three,

        every dynamically allocated string will be released safely.
    */

    return 0;
}