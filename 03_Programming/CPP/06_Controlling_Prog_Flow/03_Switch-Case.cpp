/*
============================================================
Switch Statement
============================================================

A switch statement provides an alternative to long
if-else-if chains when testing the same variable against
multiple constant values.

Advantages
----------
- Cleaner syntax
- Easier to read
- Usually faster than many if-else statements

Limitations
-----------
- Works only with integral types, char, enum (and some
  modern C++ enum classes).
- Cannot test ranges like:
      x > 10
      score <= 50

For ranges, use if-else statements instead.
============================================================
*/

#include <iostream>

using namespace std;

int main() {

    char letter_grade {};

    cout << "Which letter grade are you expecting? ";
    cin >> letter_grade;

    switch(letter_grade) {

        //--------------------------------------------------
        // Grade A
        //--------------------------------------------------

        case 'A':
        case 'a':
            cout << "Excellent! Aim for 80 or above." << endl;
            break;

        //--------------------------------------------------
        // Grade B
        //--------------------------------------------------

        case 'B':
        case 'b':
            cout << "You need at least 70." << endl;
            break;

        //--------------------------------------------------
        // Grade C
        //--------------------------------------------------

        case 'C':
        case 'c':
            cout << "You need at least 60." << endl;
            break;

        //--------------------------------------------------
        // Grade D
        //--------------------------------------------------

        case 'D':
        case 'd':
            cout << "You need at least 50." << endl;
            break;

        //--------------------------------------------------
        // Grade F
        //--------------------------------------------------

        case 'F':
        case 'f':
        {
            // Added
            // Variables declared inside a case should be
            // enclosed in braces.

            char confirmation {};

            cout << "Are you sure? (Y/N): ";
            cin >> confirmation;

            switch(confirmation) {                     // Added

                case 'Y':
                case 'y':
                    cout << "Then it's time to study harder!" << endl;
                    break;

                case 'N':
                case 'n':
                    cout << "Great! Keep working and you'll improve." << endl;
                    break;

                default:
                    cout << "Invalid response." << endl;
            }

            break;
        }

        //--------------------------------------------------
        // Invalid input
        //--------------------------------------------------

        default:
            cout << "Please enter A, B, C, D or F." << endl;
    }

    return 0;
}