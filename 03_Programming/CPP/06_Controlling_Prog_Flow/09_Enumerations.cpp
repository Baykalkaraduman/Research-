#include <iostream>

using namespace std;

/*
====================================================
                Enumerations (enum)
====================================================

An enumeration (enum) is a user-defined data type that
contains a fixed set of named integral constants.

Instead of using "magic numbers" like

0
1
2
3

we can give meaningful names to values.

Enums improve:

- readability
- maintainability
- type safety (especially enum class)

Enumerations are commonly used with switch statements.
*/

int main() {

    /*
    ------------------------------------------------
    Example 1 : Declaring an Enumeration
    ------------------------------------------------
    */

    enum Direction {
        left,
        right,
        front,
        back
    };

    Direction heading {left};

    cout << "========== Example 1 ==========\n";

    switch (heading) {

        case left:
            cout << "Going left!" << endl;
            break;

        case right:
            cout << "Going right!" << endl;
            break;

        case front:
            cout << "Going forward!" << endl;
            break;

        case back:
            cout << "Going backward!" << endl;
            break;

        default:
            cout << "Standing still." << endl;
    }

    /*
    ------------------------------------------------
    Example 2 : Underlying Integer Values
    ------------------------------------------------
    */

    cout << "\n========== Example 2 ==========\n";

    cout << "left  = " << left << endl;
    cout << "right = " << right << endl;
    cout << "front = " << front << endl;
    cout << "back  = " << back << endl;

    // Added:
    // Every enumerator receives an integer value.
    // By default they start from zero.

    /*
    ------------------------------------------------
    Example 3 : Custom Values
    ------------------------------------------------
    */

    enum Status {

        success = 200,
        warning = 300,
        error = 500

    };

    Status code {error};

    cout << "\n========== Example 3 ==========\n";

    cout << "Error code = " << code << endl;

    /*
    ------------------------------------------------
    Example 4 : Comparing Enums
    ------------------------------------------------
    */

    cout << "\n========== Example 4 ==========\n";

    if (heading == left)
        cout << "Robot starts moving left." << endl;

    /*
    ------------------------------------------------
    Example 5 : Enum Variables
    ------------------------------------------------
    */

    heading = front;

    cout << "\n========== Example 5 ==========\n";

    switch (heading) {

        case front:
            cout << "Heading changed to FRONT." << endl;
            break;

        default:
            cout << "Different direction." << endl;
    }

    /*
    ------------------------------------------------
    Example 6 : enum class (Modern C++)          // Added
    ------------------------------------------------
    */

    enum class Color {

        Red,
        Green,
        Blue

    };

    Color paint {Color::Green};

    cout << "\n========== Example 6 ==========\n";

    if (paint == Color::Green)
        cout << "Selected color is Green." << endl;

    /*
    enum class is preferred in Modern C++ because

    - avoids name collisions
    - provides stronger type safety

    We'll study it in more detail later.
    */

    return 0;
}