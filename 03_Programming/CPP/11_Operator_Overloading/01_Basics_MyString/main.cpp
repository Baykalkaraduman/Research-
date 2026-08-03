/***********************************************************************
 *
 * Operator Overloading Basics
 *
 * Before implementing operator overloading, we first verify that
 * MyString correctly manages dynamically allocated memory.
 *
 * In this program we test:
 *
 * 1. No-Args Constructor
 * 2. Overloaded Constructor
 * 3. Copy Constructor
 * 4. Deep Copy
 * 5. Destructor
 * 6. Getter Functions
 *
 * Once these features work correctly, our class is ready for
 * Copy Assignment, Move Semantics and Operator Overloading.
 *
 ***********************************************************************/

#include <iostream>

#include "MyString.h"

using namespace std;

int main() {

    cout << "=====================================================\n";
    cout << "        MyString Constructor Demonstration\n";
    cout << "=====================================================\n\n";



    //=========================================================
    // No-Args Constructor
    //=========================================================
    //
    // Creates an empty string.
    //
    // Memory:
    //
    //      str -----> "\0"
    //

    MyString empty;



    //=========================================================
    // Overloaded Constructor
    //=========================================================
    //
    // Creates a MyString object from a C-style string.
    //
    // Memory:
    //
    //      str -----> "Larry"
    //

    MyString larry{"Larry"};



    //=========================================================
    // Copy Constructor
    //=========================================================
    //
    // Creates a completely independent object.
    //
    // Deep Copy:
    //
    //      larry.str  --------> "Larry"
    //
    //      stooge.str -------> "Larry"
    //
    // Different memory.
    // Same contents.
    //

    MyString stooge{larry};



    cout << "\n";
    cout << "=====================================================\n";
    cout << "               Display Function Test\n";
    cout << "=====================================================\n\n";



    //-----------------------------------------------------------------
    // Display every object.
    //-----------------------------------------------------------------

    empty.display();

    larry.display();

    stooge.display();



    cout << "\n";
    cout << "=====================================================\n";
    cout << "                 Getter Function Test\n";
    cout << "=====================================================\n\n";



    //-----------------------------------------------------------------
    // get_length()
    //-----------------------------------------------------------------

    cout << "Larry length : "
         << larry.get_length()
         << endl;



    //-----------------------------------------------------------------
    // get_str()
    //-----------------------------------------------------------------

    cout << "Larry string : "
         << larry.get_str()
         << endl;



    cout << "\n";
    cout << "=====================================================\n";
    cout << " End of Program\n";
    cout << "=====================================================\n\n";



    //-----------------------------------------------------------------
    // Notice
    //-----------------------------------------------------------------
    //
    // At this point no destructor has been called yet.
    //
    // When main() finishes,
    // objects leave their scope in reverse order:
    //
    //      stooge
    //      larry
    //      empty
    //
    // The compiler automatically calls:
    //
    //      ~MyString()
    //
    // for each object.
    //
    // This demonstrates the importance of writing
    // a proper destructor whenever dynamic memory
    // is involved.
    //

    return 0;
}