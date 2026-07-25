//============================================================
// Topic      : Multi-Dimensional Arrays
//
// Description:
// This program introduces two-dimensional arrays in C++.
// A two-dimensional array can be visualized as a table
// consisting of rows and columns.
//
// Concepts covered:
//
// • Declaration
// • Initialization
// • Accessing elements
// • Modifying elements
// • Row and column indexing
//
// Author : Emir Karaduman
//============================================================

#include <iostream>

int main()
{
    //========================================================
    // Two-Dimensional Arrays
    //========================================================

    /*
        A two-dimensional array is simply an array
        whose elements are themselves arrays.

        General syntax:

            data_type array_name[rows][columns];

        Example:

            int matrix[3][4];

        This creates a matrix containing

            3 rows
            4 columns

        Total elements:

            3 × 4 = 12
    */

    int numbers[3][4]
    {
        {1,  2,  3,  4},
        {2,  4,  1,  3},
        {12,17,22,40}
    };

    std::cout << "========== Matrix ==========\n\n";

    /*
            Columns

             0   1   2   3
          +-----------------+
    Row 0 |  1   2   3   4  |
    Row 1 |  2   4   1   3  |
    Row 2 | 12  17  22  40  |
          +-----------------+

        numbers[row][column]
    */

    std::cout << "numbers[1][0] = "
              << numbers[1][0]
              << '\n';

    std::cout << "numbers[2][3] = "
              << numbers[2][3]
              << "\n\n";

    //========================================================
    // Modifying Elements
    //========================================================

    /*
        Individual elements can be modified
        using their row and column indices.
    */

    numbers[2][3] = 12;
    numbers[2][0] = 40;

    std::cout << "========== Updated Matrix ==========\n\n";

    std::cout << "numbers[2][0] = "
              << numbers[2][0]
              << '\n';

    std::cout << "numbers[2][3] = "
              << numbers[2][3]
              << '\n';

    return 0;
}