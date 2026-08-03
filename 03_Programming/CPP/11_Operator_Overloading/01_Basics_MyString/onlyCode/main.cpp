/***********************************************************************
 * Operator Overloading Basics
 *
 * At this stage we are simply testing our custom string class.
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. No-Args Constructor
 * 2. Overloaded Constructor
 * 3. Copy Constructor
 * 4. Deep Copy
 ***********************************************************************/

#include <iostream>

#include "MyString.h"

int main()
{
    //==========================================================
    // Constructors
    //==========================================================

    MyString empty;

    MyString larry{"Larry"};

    MyString stooge{larry};

    //==========================================================
    // Display Objects
    //==========================================================

    empty.display();

    larry.display();

    stooge.display();

    return 0;
}