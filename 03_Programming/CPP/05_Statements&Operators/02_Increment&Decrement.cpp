//============================================================
// Topic      : Increment and Decrement Operators
//
// Description:
// This program demonstrates how the increment (++)
// and decrement (--) operators work in C++.
//
// Topics Covered:
//
// • Prefix Increment
// • Postfix Increment
// • Prefix Decrement
// • Postfix Decrement
// • Differences between Prefix and Postfix
//
// Author : Emir Karaduman
//============================================================

#include <iostream>

int main()
{
    //========================================================
    // Introduction
    //========================================================

    /*
        Increment (++) increases a variable by one.

        Decrement (--) decreases a variable by one.

        They work with

        • integers
        • floating-point numbers
        • pointers
        • iterators

        (Added)
        They cannot be applied to constants.
    */

    int counter {10};
    int result {};

    //========================================================
    // Example 1
    // Basic Increment
    //========================================================

    std::cout << "========== Example 1 ==========\n\n";

    std::cout << "Initial counter = "
              << counter
              << '\n';

    counter = counter + 1;

    std::cout << "After counter = counter + 1 : "
              << counter
              << '\n';

    counter++;

    std::cout << "After counter++ : "
              << counter
              << '\n';

    ++counter;

    std::cout << "After ++counter : "
              << counter
              << "\n\n";

    /*
        At this point

        counter = 13
    */

    //========================================================
    // Example 2
    // Prefix Increment
    //========================================================

    counter = 10;

    std::cout << "========== Example 2 ==========\n\n";

    result = ++counter;

    std::cout << "Counter = "
              << counter
              << '\n';

    std::cout << "Result  = "
              << result
              << "\n\n";

    /*
        Prefix

            ++counter

        Step 1

            increment

        Step 2

            return new value
    */

    //========================================================
    // Example 3
    // Postfix Increment
    //========================================================

    counter = 10;
    result = 0;

    std::cout << "========== Example 3 ==========\n\n";

    result = counter++;

    std::cout << "Counter = "
              << counter
              << '\n';

    std::cout << "Result  = "
              << result
              << "\n\n";

    /*
        Postfix

            counter++

        Step 1

            return old value

        Step 2

            increment afterwards
    */

    //========================================================
    // Example 4
    // Prefix Inside an Expression
    //========================================================

    counter = 10;

    result = ++counter + 10;

    std::cout << "========== Example 4 ==========\n\n";

    std::cout << "Counter = "
              << counter
              << '\n';

    std::cout << "Result  = "
              << result
              << "\n\n";

    /*
        ++counter

        becomes

            11

        therefore

            11 + 10 = 21
    */

    //========================================================
    // Example 5
    // Postfix Inside an Expression
    //========================================================

    counter = 10;

    result = counter++ + 10;

    std::cout << "========== Example 5 ==========\n\n";

    std::cout << "Counter = "
              << counter
              << '\n';

    std::cout << "Result  = "
              << result
              << "\n\n";

    /*
        counter++

        first returns

            10

        then increments

        therefore

            result = 20

            counter = 11
    */

    //========================================================
    // Added Example 6
    // Prefix Decrement
    //========================================================

    counter = 10;

    result = --counter;

    std::cout << "========== Example 6 ==========\n\n";

    std::cout << "Counter = "
              << counter
              << '\n';

    std::cout << "Result  = "
              << result
              << "\n\n";

    //========================================================
    // Added Example 7
    // Postfix Decrement
    //========================================================

    counter = 10;

    result = counter--;

    std::cout << "========== Example 7 ==========\n\n";

    std::cout << "Counter = "
              << counter
              << '\n';

    std::cout << "Result  = "
              << result
              << "\n\n";

    //========================================================
    // Added Example 8
    // Floating Point Variables
    //========================================================

    double temperature {21.5};

    std::cout << "========== Example 8 ==========\n\n";

    std::cout << "Temperature = "
              << temperature
              << '\n';

    temperature++;

    std::cout << "After increment = "
              << temperature
              << "\n\n";

    /*
        ++ and -- are not limited to integers.
    */

    //========================================================
    // Best Practice
    //========================================================

    /*
        Added

        Prefer

            ++counter

        instead of

            counter++

        whenever you do not need the old value.

        This becomes especially important when working
        with iterators in STL containers.
    */

    std::cout << "Program finished successfully.\n";

    return 0;
}