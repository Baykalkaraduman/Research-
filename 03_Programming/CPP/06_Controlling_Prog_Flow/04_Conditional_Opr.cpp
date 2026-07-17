#include <iostream>
using namespace std;

/*
    Conditional (Ternary) Operator

    Syntax:

        (condition) ? value_if_true : value_if_false;

    The conditional operator is a compact alternative to simple if-else statements
    that assign or print different values depending on a condition.
*/

int main() {

    cout << "========== Example 1 : Even or Odd ==========\n";

    int num {};

    cout << "Enter an integer: ";
    cin >> num;

    // Traditional if-else
    if (num % 2 == 0)
        cout << num << " is even.\n";
    else
        cout << num << " is odd.\n";

    cout << "----------------------------------------\n";

    // Equivalent ternary operator
    cout << num << " is "
         << ((num % 2 == 0) ? "even" : "odd")
         << endl;

    cout << "\n========== Example 2 : Larger Number ==========\n";

    int num1 {}, num2 {};

    cout << "Enter two integers separated by spaces: ";
    cin >> num1 >> num2;

    if (num1 != num2) {

        cout << "Larger number : "
             << ((num1 > num2) ? num1 : num2)
             << endl;

        cout << "Smaller number: "
             << ((num1 < num2) ? num1 : num2)
             << endl;

    } else {

        cout << "Both numbers are equal." << endl;

    }

    // ======================================================
    // Added: Store result inside a variable
    // ======================================================

    cout << "\n========== Example 3 : Assigning Values ==========\n";

    int age {};

    cout << "Enter your age: ";
    cin >> age;

    string status = (age >= 18) ? "Adult" : "Minor";

    cout << "Status: " << status << endl;

    // ======================================================
    // Added: Finding Maximum of Three Numbers
    // ======================================================

    cout << "\n========== Example 4 : Maximum of Three ==========\n";

    int a {}, b {}, c {};

    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    int maximum = (a > b)
                    ? ((a > c) ? a : c)
                    : ((b > c) ? b : c);

    cout << "Largest number = " << maximum << endl;

    // ======================================================
    // Added: Using Conditional Operator with Floating Numbers
    // ======================================================

    cout << "\n========== Example 5 : Pass / Fail ==========\n";

    double grade {};

    cout << "Enter exam grade: ";
    cin >> grade;

    cout << ((grade >= 50.0)
                ? "Congratulations! You passed."
                : "Unfortunately, you failed.")
         << endl;

    return 0;
}