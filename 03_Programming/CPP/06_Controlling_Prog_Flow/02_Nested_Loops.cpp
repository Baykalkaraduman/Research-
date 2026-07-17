/*
============================================================
Nested Loops
============================================================

Nested loops are loops placed inside another loop.

They are commonly used when working with:

- 2D arrays
- Multi-dimensional vectors
- Tables
- Matrices
- Patterns
- Histograms

Execution order:

Outer Loop
    └── Inner Loop executes completely
Outer Loop continues
    └── Inner Loop executes completely
...

The inner loop always finishes before the outer loop moves
to its next iteration.
============================================================
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << "================ Multiplication Table ================\n" << endl;

    // ----------------------------------------------------
    // Example 1 : Nested loops
    // Multiplication table
    // ----------------------------------------------------

    for (int row {1}; row <= 10; ++row) {

        for (int column {1}; column <= 10; ++column) {
            cout << row << " x " << column
                 << " = "
                 << row * column
                 << endl;
        }

        cout << "----------------------------------------" << endl;
    }

    cout << endl;

    // ----------------------------------------------------
    // Example 2 : Histogram
    // ----------------------------------------------------

    cout << "================ Histogram ================\n" << endl;

    int number_of_values {};

    cout << "How many values would you like to enter? ";
    cin >> number_of_values;

    vector<int> data {};

    // Read all values

    for (int i {1}; i <= number_of_values; ++i) {

        int value {};

        cout << "Enter value " << i << ": ";
        cin >> value;

        data.push_back(value);
    }

    cout << "\nHistogram\n" << endl;

    // Display histogram

    for (const auto &value : data) {          // Added

        cout << value << " | ";

        for (int i {1}; i <= value; ++i) {

            if (i % 5 == 0)
                cout << "|";                  // Added
            else
                cout << "*";                  // Added
        }

        cout << endl;
    }

    cout << endl;

    // ----------------------------------------------------
    // Example 3 : Nested Vector Traversal
    // Added
    // ----------------------------------------------------

    cout << "================ Matrix ================\n" << endl;

    vector<vector<int>> matrix
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for (const auto &row : matrix) {

        for (const auto &element : row) {
            cout << element << " ";
        }

        cout << endl;
    }

    cout << endl;

    return 0;
}