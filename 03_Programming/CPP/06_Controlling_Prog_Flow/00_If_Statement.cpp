#include <iostream>

using namespace std;

int main() {

    cout << "========== IF STATEMENTS ==========\n" << endl;

    const int minimum {10};
    const int maximum {100};

    int number {};

    cout << "Enter a number between "
         << minimum << " and "
         << maximum << ": ";

    cin >> number;

    cout << endl;

    // --------------------------------------------------
    // Example 1
    // --------------------------------------------------

    if (number >= minimum) {

        cout << "========== Example 1 ==========" << endl;

        int difference {number - minimum};

        cout << number
             << " is greater than or equal to "
             << minimum << endl;

        cout << "Difference = "
             << difference
             << endl;
    }

    cout << endl;

    // --------------------------------------------------
    // Example 2
    // --------------------------------------------------

    if (number <= maximum) {

        cout << "========== Example 2 ==========" << endl;

        int difference {maximum - number};

        cout << number
             << " is less than or equal to "
             << maximum
             << endl;

        cout << "Difference = "
             << difference
             << endl;
    }

    cout << endl;

    // --------------------------------------------------
    // Example 3
    // --------------------------------------------------

    if (number >= minimum && number <= maximum) {

        cout << "========== Example 3 ==========" << endl;

        cout << number
             << " is inside the interval ["
             << minimum
             << ", "
             << maximum
             << "]"
             << endl;

    } else {

        cout << "========== Example 3 ==========" << endl;

        cout << number
             << " is outside the interval."
             << endl;
    }

    cout << endl;

    // --------------------------------------------------
    // Example 4
    // --------------------------------------------------

    if (number == minimum || number == maximum) {

        cout << "========== Example 4 ==========" << endl;

        cout << number
             << " lies exactly on one of the boundaries."
             << endl;
    }

    cout << endl;

    // --------------------------------------------------
    // Example 5 (Added)
    // --------------------------------------------------

    if (number % 2 == 0) {

        cout << "========== Example 5 ==========" << endl;

        cout << number
             << " is an even number."
             << endl;
    }

    cout << endl;

    // --------------------------------------------------
    // Example 6 (Added)
    // --------------------------------------------------

    if (number < 0) {

        cout << "========== Example 6 ==========" << endl;

        cout << "Negative numbers are also valid integers."
             << endl;
    }

    cout << endl;

    // --------------------------------------------------
    // Example 7 (Added)
    // --------------------------------------------------

    if (number >= minimum && number <= maximum) {

        cout << "The number passed validation." << endl;

        cout << "It is now safe to continue processing."
             << endl;
    }

    return 0;
}