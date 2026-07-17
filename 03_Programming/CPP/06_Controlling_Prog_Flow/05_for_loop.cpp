/*
============================================================
FOR LOOPS
------------------------------------------------------------
A for loop is used when we know approximately how many times
a block of code should execute.

General syntax:

for(initialization; condition; update)
{
    statements;
}

Execution order

1. Initialization (runs only once)
2. Condition
3. Loop body
4. Update
5. Back to step 2

============================================================
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "================ Example 1 ================\n";

    // Counting from 0 to 10

    for (int i{0}; i <= 10; ++i)
    {
        cout << i << endl;
    }

    cout << "\n================ Example 2 ================\n";

    // Increasing by 2

    for (int i{1}; i <= 10; i += 2)
    {
        cout << i << endl;
    }

    cout << "\n================ Example 3 ================\n";

    // Countdown

    for (int i{10}; i > 0; --i)
    {
        cout << i << endl;
    }

    cout << "Blastoff!!\n";

    cout << "\n================ Example 4 ================\n";

    // Searching multiples of 15

    for (int i{10}; i <= 100; i += 10)
    {
        if (i % 15 == 0)
        {
            cout << i << endl;
        }
    }

    cout << "\n================ Example 5 ================\n";

    // Multiple control variables

    for (int i{1}, j{5}; i <= 10; ++i, ++j)
    {
        cout << i << " + " << j
             << " = "
             << i + j
             << endl;
    }

    cout << "\n================ Example 6 ================\n";

    // Print numbers as a table

    for (int i{1}; i <= 100; ++i)
    {
        cout << i;

        if (i % 10 == 0)
            cout << endl;
        else
            cout << " ";
    }

    cout << "\n================ Example 7 ================\n";

    // Same program using the conditional operator

    for (int i{1}; i <= 100; ++i)
    {
        cout << i << ((i % 10 == 0) ? "\n" : " ");
    }

    cout << "\n================ Example 8 ================\n";

    // Iterating through a vector

    vector<int> numbers {10,20,30,40,50};

    cout << "Vector size = "
         << numbers.size()
         << endl;

    // size() returns size_t (unsigned integer)

    for (size_t i{0}; i < numbers.size(); ++i)      // Added
    {
        cout << "numbers[" << i << "] = "
             << numbers[i]
             << endl;
    }

    cout << "\n================ Example 9 ================\n";   // Added

    // Sum every element

    int sum{0};

    for (size_t i{0}; i < numbers.size(); ++i)
    {
        sum += numbers[i];
    }

    cout << "Sum = " << sum << endl;

    cout << "\n================ Example 10 ================\n";  // Added

    // Finding the maximum value manually

    int largest = numbers[0];

    for (size_t i{1}; i < numbers.size(); ++i)
    {
        if (numbers[i] > largest)
            largest = numbers[i];
    }

    cout << "Largest element = "
         << largest
         << endl;

    cout << "\n================ Example 11 ================\n";  // Added

    // Empty loop

    for (int i{0}; i < 5; ++i)
    {
        // nothing
    }

    cout << "Loop finished." << endl;

    cout << "\n================ Example 12 ================\n";  // Added

    // Scope demonstration

    for (int i{0}; i < 3; ++i)
    {
        cout << i << " ";
    }

    cout << endl;

    // cout << i;      // ERROR
    // i only exists inside the loop.

    return 0;
}