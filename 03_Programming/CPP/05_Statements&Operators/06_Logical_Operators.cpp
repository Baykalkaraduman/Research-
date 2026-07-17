//============================================================
// Topic      : Logical Operators
//
// Description:
// Demonstrates logical operators in C++
//
// Topics Covered:
//
// • Logical AND (&&)
// • Logical OR (||)
// • Logical NOT (!)
// • Combining relational expressions
// • Short-circuit evaluation
//
// Author : Emir Karaduman
//============================================================

#include <iostream>

int main()
{
    std::cout << std::boolalpha;

    //--------------------------------------------------------
    // Example 1 : Number inside a range
    //--------------------------------------------------------

    const int LOWER {10};
    const int UPPER {20};

    int number {};

    std::cout << "Enter an integer between "
              << LOWER
              << " and "
              << UPPER
              << ": ";

    std::cin >> number;

    bool within_bounds {};
    bool outside_bounds {};
    bool on_the_bounds {};

    within_bounds =
        (number > LOWER) &&
        (number < UPPER);

    outside_bounds =
        (number < LOWER) ||
        (number > UPPER);

    on_the_bounds =
        (number == LOWER) ||
        (number == UPPER);

    std::cout << "\nResults\n";
    std::cout << "-------\n";

    std::cout << "Within bounds : "
              << within_bounds
              << '\n';

    std::cout << "Outside bounds : "
              << outside_bounds
              << '\n';

    std::cout << "On the boundary : "
              << on_the_bounds
              << "\n\n";

    //--------------------------------------------------------
    // Example 2 : Jacket recommendation
    //--------------------------------------------------------

    double temperature {};
    double wind_speed {};

    std::cout << "Temperature (°C): ";
    std::cin >> temperature;

    std::cout << "Wind speed (km/h): ";
    std::cin >> wind_speed;

    bool wear_jacket =
        (temperature <= 4 && wind_speed >= 20);

    std::cout
        << "Should you wear a jacket? "
        << wear_jacket
        << "\n\n";

    //--------------------------------------------------------
    // Logical NOT
    //--------------------------------------------------------

    bool passed_exam {true};

    std::cout
        << "Passed exam      : "
        << passed_exam
        << '\n';

    std::cout
        << "Did NOT pass     : "
        << !passed_exam
        << "\n\n";

    //--------------------------------------------------------
    // Added : Short-Circuit Evaluation
    //--------------------------------------------------------

    bool first {false};
    bool second {true};

    std::cout << "Short-Circuit Examples\n";
    std::cout << "----------------------\n";

    std::cout
        << "(false && true) = "
        << (first && second)
        << '\n';

    std::cout
        << "(false || true) = "
        << (first || second)
        << "\n\n";

    /*
        In

            false && something

        C++ already knows the answer is false.

        The second expression is NOT evaluated.

        This is called Short-Circuit Evaluation.
    */

    //--------------------------------------------------------
    // Scientific Computing Note
    //--------------------------------------------------------

    /*
        Logical operators are heavily used in

        • Event selection
        • Trigger requirements
        • Detector quality cuts
        • Data filtering
        • Physics analysis
    */

    return 0;
}