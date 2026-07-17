#include <iostream>
using namespace std;

/*
===========================================================
                 DO-WHILE LOOPS
===========================================================

A do-while loop is called a POST-TEST loop.

Unlike a while loop, the loop body executes first,
then the condition is checked.

Therefore, a do-while loop ALWAYS executes at least once.

General Syntax

do
{
    statements;
}
while(condition);

Notice the semicolon after while(condition)!

===========================================================
*/

int main() {

    cout << "========== Example 1 : Simple Menu ==========\n";

    char selection {};

    do {

        cout << "\n=========================================\n";
        cout << "1. Do This\n";
        cout << "2. Do That\n";
        cout << "3. Do Something Else\n";
        cout << "Q. Quit\n";
        cout << "=========================================\n";

        cout << "Enter your selection: ";
        cin >> selection;

        if (selection == '1')
            cout << "\nExecuting option 1...\n";

        else if (selection == '2')
            cout << "\nExecuting option 2...\n";

        else if (selection == '3')
            cout << "\nExecuting option 3...\n";

        else if (selection == 'q' || selection == 'Q')
            cout << "\nClosing program...\n";

        else
            cout << "\nInvalid selection. Try again.\n";

    } while (selection != 'q' && selection != 'Q');



    cout << "\n========== Example 2 : Password Attempt ==========\n";

    // ---------------- Added ----------------
    // A do-while loop is ideal because the user
    // must enter the password at least once.

    int password {};

    do {

        cout << "Enter password (1234): ";
        cin >> password;

        if (password != 1234)
            cout << "Wrong password!\n";

    } while (password != 1234);

    cout << "Access Granted!\n";



    cout << "\n========== Example 3 : Positive Number ==========\n";

    // ---------------- Added ----------------

    int number {};

    do {

        cout << "Enter a positive integer: ";
        cin >> number;

    } while (number <= 0);

    cout << "You entered: " << number << endl;



    cout << "\n========== Example 4 : Countdown ==========\n";

    // ---------------- Added ----------------

    int counter {5};

    do {

        cout << counter << endl;
        --counter;

    } while (counter > 0);

    cout << "Blastoff!!" << endl;



    return 0;
}