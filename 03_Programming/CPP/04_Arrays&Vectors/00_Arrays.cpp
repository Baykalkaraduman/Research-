//============================================================
// Topic      : Arrays in C++
//
// Description:
// This program demonstrates how fixed-size arrays work in C++.
// It covers:
//
//  • Array declaration
//  • Initialization
//  • Indexing
//  • Modifying elements
//  • Default initialization
//  • Garbage values
//  • User input
//
// Author : Emir Karaduman
//============================================================

#include <iostream>

int main()
{
    //========================================================
    // Character Arrays
    //========================================================

    /*
        Arrays store elements of the SAME data type
        in contiguous memory locations.

        General syntax:

            data_type array_name[size];

        or

            data_type array_name[] {values};

        Properties:

        • Indexing starts at 0.
        • Array size is fixed.
        • Elements are stored sequentially in memory.
    */

    char vowels[] {'a', 'e', 'i', 'o', 'u'};

    std::cout << "========== Character Array ==========\n\n";

    std::cout << "First vowel : " << vowels[0] << '\n';
    std::cout << "Last vowel  : " << vowels[4] << "\n\n";

    // Accessing vowels[5] would be undefined behavior.
    // Arrays do NOT perform bounds checking.

    //========================================================
    // Double Arrays
    //========================================================

    double highest_temperatures[]
    {
        31.4,
        31.8,
        32.0,
        33.1,
        33.62,
        34.2,
        34.8
    };

    std::cout << "========== Double Array ==========\n\n";

    std::cout << "Lowest recorded maximum temperature: "
              << highest_temperatures[0]
              << " °C\n";

    highest_temperatures[0] = 31.6;

    std::cout << "Updated value: "
              << highest_temperatures[0]
              << " °C\n\n";

    //========================================================
    // Uninitialized Arrays
    //========================================================

    /*
        Local arrays are NOT automatically initialized.

        Their elements contain whatever happened
        to exist in memory.

        These values are called garbage values.
    */

    int test_scores[5];

    std::cout << "========== Garbage Values ==========\n\n";

    std::cout << test_scores[0] << '\n';
    std::cout << test_scores[1] << '\n';
    std::cout << test_scores[2] << '\n';
    std::cout << test_scores[3] << '\n';
    std::cout << test_scores[4] << "\n\n";

    //========================================================
    // Zero Initialization
    //========================================================

    /*
        Brace initialization initializes every element
        to zero.
    */

    int initialized_scores[5] {};

    std::cout << "========== Zero Initialized ==========\n\n";

    std::cout << initialized_scores[0] << '\n';
    std::cout << initialized_scores[1] << '\n';
    std::cout << initialized_scores[2] << '\n';
    std::cout << initialized_scores[3] << '\n';
    std::cout << initialized_scores[4] << "\n\n";

    //========================================================
    // Partial Initialization
    //========================================================

    /*
        Only the first element is initialized.

        Remaining elements become zero.

        {100}

        ↓

        [100][0][0][0][0]
    */

    int partial_scores[5] {100};

    std::cout << "========== Partial Initialization ==========\n\n";

    std::cout << partial_scores[0] << '\n';
    std::cout << partial_scores[1] << '\n';
    std::cout << partial_scores[2] << '\n';
    std::cout << partial_scores[3] << '\n';
    std::cout << partial_scores[4] << "\n\n";

    //========================================================
    // User Input
    //========================================================

    std::cout << "Enter five test scores:\n";

    std::cin >> test_scores[0];
    std::cin >> test_scores[1];
    std::cin >> test_scores[2];
    std::cin >> test_scores[3];
    std::cin >> test_scores[4];

    std::cout << "\nUpdated scores:\n\n";

    std::cout << test_scores[0] << '\n';
    std::cout << test_scores[1] << '\n';
    std::cout << test_scores[2] << '\n';
    std::cout << test_scores[3] << '\n';
    std::cout << test_scores[4] << '\n';

    return 0;
}