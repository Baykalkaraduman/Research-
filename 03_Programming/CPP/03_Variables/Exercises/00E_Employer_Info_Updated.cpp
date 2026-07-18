#include <iostream>     // Provides standard input and output functionality.
#include <string>       // Allows us to use the std::string data type.

// Avoid using 'using namespace std;' in large projects.
// For educational purposes it is acceptable,
// but later we will write std::cout explicitly.
using namespace std;

int main()
{
    // --------------------------------------------------
    // Employee Name
    // --------------------------------------------------

    // Declare a string variable to store the employee's name.
    string employee_name;
    string employee_surname;

    cout << "Hello new employee!" << endl;
    cout << "What is your full name? ";

    // Read the user's name from the keyboard.
    cin >> employee_name >> employee_surname;

    cout << endl;

    cout << "Welcome " << employee_name << employee_surname << "!" << endl;

    // --------------------------------------------------
    // Employee Department
    // --------------------------------------------------
    string Department;
    cout << "Which department did you appied for? ";
    cin >> Department;
    cout << "Hello again " << employee_name << " from " << Department << " department";
    // --------------------------------------------------
    // Employee Age
    // --------------------------------------------------

    // Declare an integer variable.
    // Here we initialize it with 18.
    // This value will immediately be replaced after user input,
    // so the initialization is not actually necessary.
    int age {18};

    cout << endl;
    cout << "Please enter your age: ";

    cin >> age;

    cout << age
         << " is a great age to start working!"
         << endl;

    // --------------------------------------------------
    // Working Days
    // --------------------------------------------------

    int working_days {3};

    cout << endl;
    cout << "How many days per week do you want to work? ";

    cin >> working_days;

    // --------------------------------------------------
    // Salary Calculation
    // --------------------------------------------------

    // Daily wage.
    double wage {3200.50};

    double monthly_salary = wage * working_days * 4;

    cout << endl;
    cout << "Your estimated monthly salary is "
         << monthly_salary
         << " TL."
         << endl;

    return 0;
}