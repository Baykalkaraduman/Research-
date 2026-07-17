//============================================================
// Topic      : Assignment Operators
//
// Description:
// Demonstrates variable initialization, assignment,
// chained assignment, and compound assignment operators.
//
// Topics Covered:
//
// • Initialization
// • Assignment
// • l-values and r-values
// • Chained assignment
// • Compound assignment operators
//
// Author : Emir Karaduman
//============================================================

#include <iostream>

int main()
{
    //--------------------------------------------------------
    // Variable Initialization
    //--------------------------------------------------------

    int num1 {10};
    int num2 {20};

    /*
        Variables are initialized when they are created.

        This is NOT assignment.

        Initialization happens only once,
        at the moment the variable is constructed.
    */

    std::cout << "Initial values\n";
    std::cout << "num1 = " << num1 << '\n';
    std::cout << "num2 = " << num2 << "\n\n";

    //--------------------------------------------------------
    // Assignment
    //--------------------------------------------------------

    /*
        Now we assign a NEW value.

        The variable already exists.
    */

    num1 = 100;

    std::cout << "After assignment\n";
    std::cout << "num1 = " << num1 << '\n';
    std::cout << "num2 = " << num2 << "\n\n";

    //--------------------------------------------------------
    // Assigning One Variable to Another
    //--------------------------------------------------------

    num1 = num2;

    std::cout << "After num1 = num2\n";
    std::cout << "num1 = " << num1 << '\n';
    std::cout << "num2 = " << num2 << "\n\n";

    //--------------------------------------------------------
    // Chained Assignment
    //--------------------------------------------------------

    /*
        Assignment is evaluated
        from RIGHT to LEFT.

        num2 becomes 1000

        then

        num1 becomes num2
    */

    num1 = num2 = 1000;

    std::cout << "After chained assignment\n";
    std::cout << "num1 = " << num1 << '\n';
    std::cout << "num2 = " << num2 << "\n\n";

    //--------------------------------------------------------
    // Compound Assignment Operators
    //--------------------------------------------------------
    // Added
    int value {50};

    std::cout << "Compound Assignment Operators\n\n";

    std::cout << "Initial value = " << value << '\n';

    value += 10;
    std::cout << "After value += 10 : " << value << '\n';

    value -= 20;
    std::cout << "After value -= 20 : " << value << '\n';

    value *= 3;
    std::cout << "After value *= 3  : " << value << '\n';

    value /= 4;
    std::cout << "After value /= 4  : " << value << '\n';

    value %= 5;
    std::cout << "After value %= 5  : " << value << "\n\n";

    //--------------------------------------------------------
    // Scientific Computing Note
    //--------------------------------------------------------

    /*
        Compound assignment operators are extremely common in
        scientific software.

        Example:

            total_energy += event_energy;

            detector_hits++;

            sum += measurement;

        They make the code shorter and easier to read.
    */

    return 0;
}