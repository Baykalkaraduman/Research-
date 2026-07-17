//============================================================
// Topic      : std::vector
//
// Description:
// This program introduces the std::vector container from the
// C++ Standard Template Library (STL).
//
// Topics covered:
//
// • Creating vectors
// • Initialization
// • Indexing
// • .at()
// • size()
// • push_back()
// • User input
//
// Author : Emir Karaduman
//============================================================

#include <iostream>
#include <vector>

int main()
{
    //========================================================
    // Introduction
    //========================================================

    /*
        std::vector is one of the most important containers
        in Modern C++.

        It behaves similarly to an array, but unlike arrays,
        its size can grow or shrink dynamically during runtime.

        Arrays:
            • Fixed size
            • Cannot grow
            • Managed manually

        Vectors:
            • Dynamic size
            • Automatically manages memory
            • Safer and easier to use

        ------------------------------------------------------

        Added:

        std::vector belongs to the Standard Template Library
        (STL), one of the most powerful components of C++.
        Almost every modern C++ project makes use of vectors.
    */

    //========================================================
    // Creating Vectors
    //========================================================

    /*
        General syntax:

            std::vector<data_type> vector_name;

        Examples:

            std::vector<int> numbers;
            std::vector<double> temperatures;
            std::vector<char> letters;
    */

    // Empty vector
    // std::vector<char> vowels;

    // Five characters initialized with '\0'
    // std::vector<char> vowels(5);

    // Initialized with values
    std::vector<char> vowels {'a', 'e', 'i', 'o', 'u'};

    std::cout << "========== Character Vector ==========\n\n";

    std::cout << "First vowel : " << vowels[0] << '\n';
    std::cout << "Last vowel  : " << vowels[4] << "\n\n";

    //========================================================
    // Integer Vectors
    //========================================================

    /*
        Different initialization methods.
    */

    // std::vector<int> test_scores(3);

    // std::vector<int> test_scores(3,100);

    std::vector<int> test_scores {100, 98, 92};

    std::cout << "========== Test Scores ==========\n\n";

    std::cout << "Using array syntax []\n\n";

    std::cout << test_scores[0] << '\n';
    std::cout << test_scores[1] << '\n';
    std::cout << test_scores[2] << "\n\n";

    //========================================================
    // Safe Element Access
    //========================================================

    /*
        Unlike operator[],

        .at()

        performs bounds checking.

        If the requested index is invalid,
        an exception is thrown instead of
        silently accessing invalid memory.

        ------------------------------------------------------

        Added:

        During software development,
        .at() is often preferred because
        programming mistakes become much
        easier to detect.
    */

    std::cout << "Using vector syntax (.at())\n\n";

    std::cout << test_scores.at(0) << '\n';
    std::cout << test_scores.at(1) << '\n';
    std::cout << test_scores.at(2) << "\n\n";

    //========================================================
    // Vector Size
    //========================================================

    /*
        size()

        Returns the number of elements
        currently stored inside the vector.

        ------------------------------------------------------

        Added:

        Do not confuse size() with capacity().

        size()
            -> Number of elements

        capacity()
            -> Allocated storage

        We will study capacity() later.
    */

    std::cout << "Current vector size : "
              << test_scores.size()
              << "\n\n";

    //========================================================
    // User Input
    //========================================================

    std::cout << "Enter three new test scores:\n";

    std::cin >> test_scores.at(0);
    std::cin >> test_scores.at(1);
    std::cin >> test_scores.at(2);

    std::cout << "\nUpdated Scores\n";
    std::cout << "--------------\n";

    std::cout << "Score 1 : "
              << test_scores.at(0) << '\n';

    std::cout << "Score 2 : "
              << test_scores.at(1) << '\n';

    std::cout << "Score 3 : "
              << test_scores.at(2) << "\n\n";

    //========================================================
    // push_back()
    //========================================================

    /*
        push_back()

        Adds a new element to the END
        of the vector.

        Example

            Before

            100
            98
            92

            push_back(75);

            After

            100
            98
            92
            75

        ------------------------------------------------------

        Added:

        If the vector runs out of storage,
        it automatically allocates a larger
        memory block, copies every element,
        destroys the old memory,
        and continues normally.

        This entire process is completely
        automatic and invisible to the user.
    */

    int score_to_add {};

    std::cout << "Enter a new score to append: ";
    std::cin >> score_to_add;

    test_scores.push_back(score_to_add);

    std::cout << "\nEnter one more score: ";
    std::cin >> score_to_add;

    test_scores.push_back(score_to_add);

    std::cout << "\nUpdated Vector\n";
    std::cout << "--------------\n";

    std::cout << "Score 1 : " << test_scores.at(0) << '\n';
    std::cout << "Score 2 : " << test_scores.at(1) << '\n';
    std::cout << "Score 3 : " << test_scores.at(2) << '\n';
    std::cout << "Score 4 : " << test_scores.at(3) << '\n';
    std::cout << "Score 5 : " << test_scores.at(4) << '\n';

    std::cout << "\nNew vector size : "
              << test_scores.size()
              << "\n\n";

    //========================================================
    // Added:
    // Difference between [] and .at()
    //========================================================

    /*
        operator[]

            ✔ Faster
            ✔ No bounds checking
            ✘ Undefined behavior for invalid indices

        .at()

            ✔ Safe
            ✔ Performs bounds checking
            ✔ Throws an exception if needed
            ✘ Slightly slower

        During debugging,
        .at() is often the preferred choice.
    */
    //========================================================
    // front() and back()
    //========================================================

    /*
        front()

            Returns a reference to the FIRST element
            stored in the vector.

        back()

            Returns a reference to the LAST element
            stored in the vector.

        These functions are often more readable than
        writing

            vector.at(0)

        or

            vector[vector.size()-1]

        ------------------------------------------------------

        Added:

        Both functions return references.

        This means they can also be used to modify
        the first or last element directly.
    */

    std::cout << "========== front() and back() ==========\n\n";

    std::cout << "First score : "
              << test_scores.front() << '\n';

    std::cout << "Last score  : "
              << test_scores.back() << "\n\n";
/*
    IMPORTANT

    Calling front() or back() on an EMPTY vector
    results in undefined behavior.

    Always ensure that the vector contains at least
    one element before using these functions.

    Example:

        if (!test_scores.empty())
        {
            std::cout << test_scores.front();
        }

    We will study empty() in a later chapter.
*/
    //========================================================
    // Nested Vectors (Two-Dimensional Vectors)
    //========================================================

    /*
        A vector can also store other vectors.

        This creates a dynamic two-dimensional
        data structure similar to a matrix.

        General syntax:

            std::vector<std::vector<int>> matrix;

        Unlike two-dimensional arrays,

        • the number of rows can grow,
        • each row can have a different length,
        • memory management is automatic.

        ------------------------------------------------------

        Added:

        Nested vectors are widely used in

            • Scientific Computing
            • Image Processing
            • Game Development
            • Graph Algorithms
            • High-Energy Physics

        because they provide much greater flexibility
        than fixed-size arrays.
    */

    std::vector<std::vector<int>> general_ratings
    {
        {1, 2, 3, 4},
        {2, 4, 1, 3},
        {2, 2, 7, 6}
    };

    std::cout << "========== Nested Vector ==========\n\n";

    //--------------------------------------------------------
    // Access using array syntax
    //--------------------------------------------------------

    std::cout << "Soldier #1 ratings using []\n\n";

    std::cout << general_ratings[0][0] << '\n';
    std::cout << general_ratings[0][1] << '\n';
    std::cout << general_ratings[0][2] << '\n';
    std::cout << general_ratings[0][3] << "\n\n";

    //--------------------------------------------------------
    // Access using .at()
    //--------------------------------------------------------

    std::cout << "Soldier #1 ratings using .at()\n\n";

    std::cout << general_ratings.at(0).at(0) << '\n';
    std::cout << general_ratings.at(0).at(1) << '\n';
    std::cout << general_ratings.at(0).at(2) << '\n';
    std::cout << general_ratings.at(0).at(3) << "\n\n";

    //========================================================
    // Added:
    // Memory Model
    //========================================================

    /*
        Although a nested vector looks like a matrix,

        it is NOT stored exactly like a 2D array.

        A two-dimensional array occupies one large
        contiguous block of memory.

        A nested vector stores

            vector
                ↓
            row 1
            row 2
            row 3

        where each row is itself an independent vector.

        Therefore,

        • rows may have different lengths,
        • rows may be resized independently,
        • inserting or removing rows is much easier.

        This flexibility comes with a very small
        performance cost compared to raw arrays.
    */

    //========================================================
    // Added:
    // Scientific Computing Note
    //========================================================

    /*
        Nested vectors are frequently used when
        handling matrix-like data whose size is
        unknown before runtime.

        Examples include

            • detector hit maps
            • event collections
            • particle trajectories
            • adjacency lists
            • simulation grids
    */

    //========================================================
    // Added:
    // Final Notes
    //========================================================

    /*
        std::vector is one of the most important
        containers in Modern C++.

        Many scientific libraries rely heavily on it.

            • ROOT
            • Geant4
            • Eigen
            • Boost
            • HepMC

        Becoming comfortable with vectors is one of
        the biggest milestones for a C++ programmer.
    */

    std::cout << "Program finished successfully.\n";

    return 0;
}