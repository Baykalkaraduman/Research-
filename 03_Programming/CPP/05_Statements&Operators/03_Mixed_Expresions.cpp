//============================================================
// Topic      : Mixed Expressions and Type Conversion
//
// Description:
// This program demonstrates how C++ handles expressions
// involving different data types.
//
// Topics Covered:
//
// • Integer Division
// • Floating-Point Division
// • Implicit Type Conversion
// • Explicit Type Conversion
// • static_cast
//
// Author : Emir Karaduman
//============================================================

#include <iostream>

int main()
{
    //========================================================
    // Problem Statement
    //========================================================
    /*
        Ask the user to enter three integers.

        Then calculate

        • their sum
        • their average

        while demonstrating different ways of performing
        type conversion.
    */

    int num1 {};
    int num2 {};
    int num3 {};

    int total {};

    const int COUNT {3};

    double average {};

    //========================================================
    // User Input
    //========================================================

    std::cout << "Enter three integers separated by spaces: ";

    std::cin >> num1
             >> num2
             >> num3;

    //========================================================
    // Calculate the Sum
    //========================================================

    total = num1 + num2 + num3;

    //========================================================
    // Integer Division
    //========================================================

    /*
        Since both operands are integers,

            total / COUNT

        performs integer division.

        Example

            total = 10

            10 / 3

        becomes

            3

        instead of

            3.333...
    */

    average = total / COUNT;

    std::cout << "\nAverage using integer division : "
              << average
              << '\n';

    //========================================================
    // Old-Style C Cast
    //========================================================

    /*
        This converts total into a double.

        Although it works,

        old-style casts are discouraged in Modern C++.
    */

    average = (double)total / COUNT;

    std::cout << "Average using C-style cast     : "
              << average
              << '\n';

    //========================================================
    // Modern C++ Conversion
    //========================================================

    /*
        static_cast is the preferred way of converting
        one data type into another.

        It is safer, clearer, and easier for the compiler
        to check.

        Syntax

            static_cast<new_type>(expression)
    */

    average = static_cast<double>(total) / COUNT;

    std::cout << "Average using static_cast      : "
              << average
              << "\n\n";

    //========================================================
    // Display Results
    //========================================================

    std::cout << "Numbers Entered : "
              << num1 << ", "
              << num2 << ", "
              << num3 << '\n';

    std::cout << "Total           : "
              << total << '\n';

    std::cout << "Average         : "
              << average << "\n\n";

    //========================================================
    // Added Example
    //========================================================

    /*
        Only one operand needs to become a double.

        These are equivalent.
    */

    std::cout << "10 / 4 = "
              << 10 / 4
              << '\n';

    std::cout << "10.0 / 4 = "
              << 10.0 / 4
              << '\n';

    std::cout << "10 / 4.0 = "
              << 10 / 4.0
              << '\n';

    std::cout << "static_cast<double>(10) / 4 = "
              << static_cast<double>(10) / 4
              << "\n\n";

    //========================================================
    // Scientific Computing Note
    //========================================================

    /*
        Type conversions appear everywhere in scientific
        software.

        Examples include

        • detector efficiencies
        • event weights
        • histogram normalization
        • Monte Carlo simulations
        • probability calculations

        Modern C++ recommends using static_cast whenever an
        explicit conversion is required.
    */

    std::cout << "Program finished successfully.\n";

    return 0;
}