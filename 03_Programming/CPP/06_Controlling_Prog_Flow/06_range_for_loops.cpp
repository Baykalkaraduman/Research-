#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

/*
====================================================
Range-Based For Loops (C++11)
====================================================

General Syntax

for (type variable : collection)
{
    statements;
}

or

for (auto variable : collection)
{
    statements;
}

A range-based for loop automatically visits every
element inside a collection.

The compiler internally creates the iteration,
so we no longer need an index variable.

Supported collections include:

- Arrays
- std::vector
- std::string
- initializer lists
- many STL containers

Modern C++ code heavily prefers range-based loops
whenever the index itself is not needed.
*/

int main() {

    cout << "========== Example 1 : Array ==========\n";

    int scores[]{10,20,30};

    for (int score : scores)
        cout << score << endl;



    cout << "\n========== Example 2 : Vector ==========\n";

    vector<double> temperatures
    {
        17.17,
        18.90,
        16.20,
        19.50,
        22.22,
        17.22,
        22.17
    };

    double sum{0.0};

    for (auto temp : temperatures)
        sum += temp;

    double average{0.0};

    if (!temperatures.empty())
        average = sum / temperatures.size();

    cout << fixed << setprecision(2);

    cout << "Average temperature = "
         << average
         << " Celsius"
         << endl;



    cout << "\n========== Example 3 : Initializer List ==========\n";

    for (auto value : {1,2,3,4,5})
        cout << value << " ";

    cout << endl;



    cout << "\n========== Example 4 : Character Array ==========\n";

    for (auto c : "This is a test")
        cout << c;

    cout << endl;



    cout << "\n========== Example 5 : Ignore Spaces ==========\n";

    for (auto c : "This is a test")
        if (c != ' ')
            cout << c;

    cout << endl;



    cout << "\n========== Example 6 : Replace Spaces ==========\n";

    for (auto c : "This is a test")
    {
        if (c == ' ')
            cout << '\t';
        else
            cout << c;
    }

    cout << endl;



    cout << "\n========== Example 7 : Modify Elements ==========\n";      // Added

    vector<int> values{1,2,3,4,5};

    cout << "Original vector: ";

    for (auto value : values)
        cout << value << " ";

    cout << endl;

    // Using a reference modifies the original vector.
    for (auto &value : values)        // Added
        value *= 10;

    cout << "Modified vector: ";

    for (auto value : values)
        cout << value << " ";

    cout << endl;



    cout << "\n========== Example 8 : const auto& ==========\n";    // Added

    /*
    const auto&
    avoids copying each element and also prevents
    accidental modification.

    This is the preferred style when reading
    complex STL objects.
    */

    vector<string> particles
    {
        "Electron",
        "Muon",
        "Tau",
        "Photon"
    };

    for (const auto &particle : particles)      // Added
        cout << particle << endl;



    cout << "\n========== Example 9 : Strings ==========\n";    // Added

    string detector{"CMS"};

    for (char letter : detector)
        cout << letter << " ";

    cout << endl;



    cout << "\n========== Example 10 : Scientific Computing ==========\n";   // Added

    vector<double> energies
    {
        12.4,
        18.7,
        25.3,
        31.6,
        27.9
    };

    cout << "Accepted energies (>20 GeV):" << endl;

    for (const auto &energy : energies)
    {
        if (energy > 20.0)
            cout << energy << " GeV" << endl;
    }

    return 0;
}