//============================================================
// Topic      : Equality and Relational Operators
//
// Description:
// Demonstrates comparison operators in C++
//
// Covered Operators:
//
// ==
// !=
// <
// >
// <=
// >=
//
// Also demonstrates:
//
// • bool
// • boolalpha
// • implicit conversions
// • floating-point comparison
//
// Author : Emir Karaduman
//============================================================

#include <iostream>

int main()
{
    bool equal_result {};
    bool not_equal_result {};

    int num1 {};
    int num2 {};

    std::cout << std::boolalpha;

    //--------------------------------------------------------
    // Integer comparison
    //--------------------------------------------------------

    std::cout << "Enter two integers: ";
    std::cin >> num1 >> num2;

    equal_result = (num1 == num2);
    not_equal_result = (num1 != num2);

    std::cout << "\nEquality Comparison\n";
    std::cout << "-------------------\n";

    std::cout << num1 << " == "
              << num2
              << " -> "
              << equal_result
              << '\n';

    std::cout << num1 << " != "
              << num2
              << " -> "
              << not_equal_result
              << "\n\n";

    //--------------------------------------------------------
    // Character comparison
    //--------------------------------------------------------

    char char1 {};
    char char2 {};

    std::cout << "Enter two characters: ";
    std::cin >> char1 >> char2;

    std::cout << '\n';

    std::cout << char1
              << " == "
              << char2
              << " -> "
              << (char1 == char2)
              << '\n';

    std::cout << char1
              << " != "
              << char2
              << " -> "
              << (char1 != char2)
              << "\n\n";

    //--------------------------------------------------------
    // Floating-point comparison
    //--------------------------------------------------------

    std::cout << "Floating Point Examples\n";
    std::cout << "-----------------------\n";

    bool result {};

    result = (12.0 == 12);

    std::cout
        << "12.0 == 12 -> "
        << result
        << '\n';

    // Added
    result = (0.1 + 0.2 == 0.3);

    std::cout
        << "0.1 + 0.2 == 0.3 -> "
        << result
        << "   // Added\n";

    std::cout
        << "(Floating-point numbers should generally "
        << "NOT be compared using ==)\n\n";

    //--------------------------------------------------------
    // Relational Operators
    //--------------------------------------------------------

    std::cout << "Enter two more integers: ";
    std::cin >> num1 >> num2;

    std::cout << '\n';

    std::cout << num1 << " <  " << num2
              << " -> "
              << (num1 < num2)
              << '\n';

    std::cout << num1 << " >  " << num2
              << " -> "
              << (num1 > num2)
              << '\n';

    std::cout << num1 << " <= " << num2
              << " -> "
              << (num1 <= num2)
              << '\n';

    std::cout << num1 << " >= " << num2
              << " -> "
              << (num1 >= num2)
              << "\n\n";

    //--------------------------------------------------------
    // Practical Example
    //--------------------------------------------------------

    const int minimum_age {18};

    int age {};

    std::cout << "Enter your age: ";
    std::cin >> age;

    std::cout
        << "Age >= "
        << minimum_age
        << " -> "
        << (age >= minimum_age)
        << '\n';

    //--------------------------------------------------------
    // Scientific Computing Note
    //--------------------------------------------------------

    // Added
    std::cout
        << "\nNOTE:\n";
    std::cout
        << "In scientific programming, floating-point\n"
        << "numbers are usually compared using a\n"
        << "tolerance rather than ==.\n";

    return 0;
}