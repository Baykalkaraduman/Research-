#include <iostream>
#include <string>

using namespace std;

int main() {

    string letter_grade {};
    int grade {};

    cout << "Enter your exam grade (0-100): ";
    cin >> grade;

    // -------------------------------------------------
    // Validate the input first
    // -------------------------------------------------

    if (grade < 0 || grade > 100) {
        cout << "Invalid grade entered!" << endl;
        return 0;                        // Added
    }

    // -------------------------------------------------
    // Determine the letter grade
    // -------------------------------------------------

    if (grade >= 80) {
        letter_grade = "AA";
    }
    else if (grade >= 75) {
        letter_grade = "BA";
    }
    else if (grade >= 70) {
        letter_grade = "BB";
    }
    else if (grade >= 60) {
        letter_grade = "CB";
    }
    else if (grade >= 50) {
        letter_grade = "CC";
    }
    else {
        letter_grade = "FF";
    }

    cout << "\nNumeric Grade : " << grade << endl;
    cout << "Letter Grade  : " << letter_grade << endl;

    // -------------------------------------------------
    // Determine whether the student passed
    // -------------------------------------------------

    if (letter_grade == "FF") {
        cout << "Status        : FAILED" << endl;
        cout << "You need to repeat this course." << endl;
    }
    else {
        cout << "Status        : PASSED" << endl;
        cout << "Congratulations!" << endl;
    }

    // -------------------------------------------------
    // Added:
    // Demonstration of nested if statements
    // -------------------------------------------------

    if (letter_grade != "FF") {                     // Added

        if (grade >= 90) {                          // Added
            cout << "Excellent performance!" << endl;
        }
        else if (grade >= 80) {                     // Added
            cout << "Very good performance!" << endl;
        }

    }

    return 0;
}