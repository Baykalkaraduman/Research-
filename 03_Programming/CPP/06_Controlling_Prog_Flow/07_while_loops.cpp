#include <iostream>

using namespace std;

//======================================================
// While Loops
//======================================================
//
// A while loop repeatedly executes a block of code
// as long as its condition remains true.
//
// A while loop is called a PRE-TEST LOOP because the
// condition is evaluated BEFORE the loop body executes.
//
// General Syntax:
//
// while(condition)
// {
//     statements;
// }
//
// If the condition is false initially,
// the loop body will never execute.
//
//======================================================

int main() {

    //==================================================
    // Example 1 - Countdown
    //==================================================

    cout << "========== Example 1 : Countdown ==========\n";

    int num{};

    cout << "Enter a positive integer to start the countdown: ";
    cin >> num;

    while (num > 0) {
        cout << num << endl;
        --num;
    }

    cout << "Blastoff!\n\n";

    //==================================================
    // Example 2 - Count Up
    //==================================================

    cout << "========== Example 2 : Count Up ==========\n";

    int limit{};

    cout << "Enter a positive integer: ";
    cin >> limit;

    int counter{1};

    while (counter <= limit) {
        cout << counter << endl;
        ++counter;
    }

    //==================================================
    // Example 3 - Input Validation
    //==================================================

    cout << "\n========== Example 3 : Input Validation ==========\n";

    int number{};

    cout << "Enter an integer between 1 and 100: ";
    cin >> number;

    while (number < 1 || number > 100) {
        cout << "Invalid input. Try again: ";
        cin >> number;
    }

    cout << "Thank you!\n";

    //==================================================
    // Example 4 - Boolean Flag
    //==================================================

    cout << "\n========== Example 4 : Boolean Flag ==========\n";

    bool done{false};
    int value{};

    while (!done) {

        cout << "Enter a number between 1 and 5: ";
        cin >> value;

        if (value >= 1 && value <= 5) {
            cout << "Accepted.\n";
            done = true;
        }
        else {
            cout << "Invalid input.\n";
        }
    }

    //==================================================
    // Example 5 - Sentinel Controlled Loop
    // Added
    //==================================================

    cout << "\n========== Example 5 : Sentinel Value ==========\n";

    cout << "Enter numbers (-1 to stop).\n";

    int input{};
    int sum{0};

    cin >> input;

    while (input != -1) {

        sum += input;

        cin >> input;
    }

    cout << "Sum = " << sum << endl;

    //==================================================
    // Example 6 - Running Average
    // Added
    //==================================================

    cout << "\n========== Example 6 : Running Average ==========\n";

    double value_sum{0};
    int count{0};

    cout << "Enter positive numbers (0 to stop): ";

    double value{};
    cin >> value;

    while (value != 0) {

        value_sum += value;
        ++count;

        cin >> value;
    }

    if (count != 0)
        cout << "Average = " << value_sum / count << endl;
    else
        cout << "No numbers entered.\n";

    //==================================================
    // Example 7 - Infinite Loop
    // Added
    //==================================================

    cout << "\n========== Example 7 : Infinite Loop ==========\n";

    cout << "This loop would run forever:\n\n";

    /*
    while(true)
    {
        cout << "Running forever..." << endl;
    }
    */

    cout << "(Commented out to prevent the program from hanging.)\n";

    return 0;
}