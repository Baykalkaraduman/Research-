//============================================================
// Topic      : Arithmetic Operators
//
// Description:
// This program demonstrates the basic arithmetic operators
// available in C++.
//
// Topics covered:
//
// • Addition (+)
// • Subtraction (-)
// • Multiplication (*)
// • Division (/)
// • Modulus (%)
// • Integer Division
// • Floating-Point Division
//
// Author : Emir Karaduman
//============================================================

#include <iostream>

int main()
{
    //========================================================
    // Variable Declaration
    //========================================================

    /*
        We define two integer variables that will be used
        throughout this program.

        Integer variables store whole numbers only.
    */

    int num1 {200};
    int num2 {100};

    int result {};

    //========================================================
    // Addition Operator (+)
    //========================================================

    /*
        The addition operator calculates the sum of two values.

        Syntax:

            value1 + value2
    */

    std::cout << "========== Addition ==========\n\n";

    std::cout << num1
              << " + "
              << num2
              << " = "
              << num1 + num2
              << '\n';

    result = num1 + num2;

    std::cout << "Stored Result : "
              << result
              << "\n\n";

    //========================================================
    // Subtraction Operator (-)
    //========================================================

    /*
        The subtraction operator subtracts the second value
        from the first.

        Syntax

            value1 - value2
    */

    result = num1 - num2;

    std::cout << "========== Subtraction ==========\n\n";

    std::cout << num1
              << " - "
              << num2
              << " = "
              << result
              << "\n\n";

    //========================================================
    // Multiplication Operator (*)
    //========================================================

    /*
        Multiplies two values together.

        Syntax

            value1 * value2
    */

    result = num1 * num2;

    std::cout << "========== Multiplication ==========\n\n";

    std::cout << num1
              << " * "
              << num2
              << " = "
              << result
              << "\n\n";

    //========================================================
    // Division Operator (/)
    //========================================================

    /*
        Divides one value by another.

        IMPORTANT

        The result depends on the data types.

        int / int

            gives an integer result

        double / double

            gives a floating-point result
    */

    result = num1 / num2;

    std::cout << "========== Division ==========\n\n";

    std::cout << num1
              << " / "
              << num2
              << " = "
              << result
              << "\n\n";

    //========================================================
    // Modulus Operator (%)
    //========================================================

    /*
        The modulus operator returns the remainder
        after integer division.

        Example

            13 % 5

        gives

            3

        because

            13 = 5 × 2 + 3

        ------------------------------------------------------

        Added:

        The modulus operator only works with
        integer types.

        It cannot be used directly with
        floating-point numbers.
    */

    result = num1 % num2;

    std::cout << "========== Modulus ==========\n\n";

    std::cout << num1
              << " % "
              << num2
              << " = "
              << result
              << "\n\n";

    //========================================================
    // Integer Division
    //========================================================

    /*
        Integer division is one of the most common
        sources of confusion for beginners.

        Since both operands are integers,

            int / int

        always produces an integer.

        The fractional part is discarded.
    */

    std::cout << "========== Integer Division ==========\n\n";

    result = num2 / num1;

    std::cout << num2
              << " / "
              << num1
              << " = "
              << result
              << '\n';

    /*
        Mathematical result

            100 / 200 = 0.5

        C++ result

            0

        because the decimal part is removed.
    */

    result = num2 % num1;

    std::cout << num2
              << " % "
              << num1
              << " = "
              << result
              << "\n\n";

    //========================================================
    // Another Modulus Example
    //========================================================

    num2 = 3;

    result = num1 % num2;

    std::cout << num1
              << " % "
              << num2
              << " = "
              << result
              << "\n\n";

    /*
        200 / 3

            quotient  = 66
            remainder = 2

        Therefore

            200 % 3 = 2
    */

    //========================================================
    // Floating-Point Division
    //========================================================

    /*
        Added:

        If at least ONE operand is floating-point,

        the division is performed using floating-point
        arithmetic.

        This preserves the decimal places.
    */

    std::cout << "========== Floating Point Division ==========\n\n";

    std::cout << "5 / 10      = "
              << 5 / 10
              << '\n';

    std::cout << "5.0 / 10.0  = "
              << 5.0 / 10.0
              << '\n';

    std::cout << "5.0 / 10    = "
              << 5.0 / 10
              << '\n';

    std::cout << "5 / 10.0    = "
              << 5 / 10.0
              << "\n\n";

    //========================================================
    // Currency Converter Example
    //========================================================

    /*
        This example combines several concepts that we have
        learned so far.

        • Variables
        • Constants
        • User Input
        • Arithmetic Operators
        • Assignment Operator

        The user enters an amount in Euros and the program
        converts it to U.S. Dollars.
    */

    std::cout << "\n========================================\n";
    std::cout << "        Currency Converter";
    std::cout << "\n========================================\n\n";

    //========================================================
    // Constant Variables
    //========================================================

    /*
        The keyword 'const' creates a constant variable.

        A constant variable cannot be modified after it has
        been initialized.

        This prevents accidental changes and makes programs
        easier to understand.

        Added:

        Constants are heavily used in scientific software.

        Examples:

            Speed of light
            Pi
            Electron mass
            Detector dimensions
            Calibration constants

        Using const helps prevent bugs.
    */

    const double USD_PER_EUR {1.19};

    /*
        Variable names should clearly describe
        what they represent.

        GOOD

            USD_PER_EUR

        BAD

            x
            value
            temp
    */

    double euros {};
    double dollars {};

    std::cout << "Enter an amount in Euros: ";
    std::cin >> euros;

    dollars = euros * USD_PER_EUR;

    std::cout << '\n';

    std::cout << euros
              << " EUR = "
              << dollars
              << " USD\n";

    //========================================================
    // Added: Precision Example
    //========================================================

    /*
        Because we use 'double',

        decimal values are preserved.

        Example

            10.5 EUR

        can be converted correctly.

        If we used integers instead,

        all decimal information would be lost.
    */

    //========================================================
    // Scientific Computing Note (Added)
    //========================================================

    /*
        In particle physics and scientific computing,
        constants should NEVER be "hard-coded"
        throughout a program.

        Instead of writing

            energy = energy * 1.602e-19;

        define

            const double ELECTRON_CHARGE {1.602176634e-19};

        and reuse it everywhere.

        Advantages

        • easier maintenance

        • fewer typing mistakes

        • improved readability

        • safer code
    */

    //========================================================
    // End of Program
    //========================================================

    std::cout << "\nProgram finished successfully.\n";

    return 0;
}