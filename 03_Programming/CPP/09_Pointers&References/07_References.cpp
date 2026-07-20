/***********************************************************************
 * Reference.cpp
 *
 * Topic:
 *      References in C++
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. What is a reference?
 * 2. Reference vs Pointer
 * 3. Reference aliasing
 * 4. Modifying original variables
 * 5. Range-based for loops
 * 6. References with vectors
 * 7. const references
 * 8. Best practices
 *
 ***********************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//==============================================================
// Helper Function
//==============================================================

void print_title(const string &title)
{
    cout << "\n=====================================================\n";
    cout << title << endl;
    cout << "=====================================================\n";
}

//==============================================================
// Main
//==============================================================

int main()
{
    //----------------------------------------------------------
    // Example 1
    //----------------------------------------------------------

    print_title("Example 1 : Creating References");

    int num {100};

    int &ref {num};

    cout << "Value of num : "
         << num << endl;

    cout << "Value of ref : "
         << ref << endl;

    cout << "\nMemory addresses\n";

    cout << "&num : "
         << &num << endl;

    cout << "&ref : "
         << &ref << endl;

    cout << "\nNotice that both addresses are identical.\n";

    //----------------------------------------------------------
    // Example 2
    //----------------------------------------------------------

    print_title("Example 2 : Changing Original Variable");

    num = 200;

    cout << "num : "
         << num << endl;

    cout << "ref : "
         << ref << endl;

    //----------------------------------------------------------
    // Example 3
    //----------------------------------------------------------

    print_title("Example 3 : Changing Through Reference");

    ref = 300;

    cout << "num : "
         << num << endl;

    cout << "ref : "
         << ref << endl;

    //----------------------------------------------------------
    // Example 4
    //----------------------------------------------------------

    print_title("Example 4 : Range-Based For Loop (Copy)");

    vector<string> stooges {

        "Larry",
        "Moe",
        "Curly"

    };

    cout << "Original vector\n";

    for (const auto &name : stooges)
        cout << name << endl;

    cout << "\nTrying to modify using COPY...\n";

    for (auto name : stooges)
        name = "Funny";

    cout << "\nVector after copy loop\n";

    for (const auto &name : stooges)
        cout << name << endl;

    //----------------------------------------------------------
    // Example 5
    //----------------------------------------------------------

    print_title("Example 5 : Range-Based For Loop (Reference)");

    for (auto &name : stooges)
        name = "Funny";

    cout << "Vector after reference loop\n";

    for (const auto &name : stooges)
        cout << name << endl;

    //----------------------------------------------------------
    // Example 6
    //----------------------------------------------------------

    print_title("Example 6 : const References");

    cout << "Reading vector efficiently using const references\n\n";

    for (const auto &name : stooges)
        cout << name << endl;

    //----------------------------------------------------------
    // Summary
    //----------------------------------------------------------

    print_title("Summary");

    cout << "References are aliases.\n";

    cout << "They do not create copies.\n";

    cout << "They refer directly to existing objects.\n";

    cout << "\nModern C++ prefers references over raw pointers\n";
    cout << "whenever null values are unnecessary.\n";

    return 0;
}