/*
============================================================
Topic      : Dereference Operator (*)
Author     : Emir Karaduman

Description:
    Learning how to access and modify data through pointers.

Concepts covered:
    - Dereference operator (*)
    - Reading values through pointers
    - Modifying values through pointers
    - Reassigning pointers
    - Pointers with strings
    - Pointers with vectors
    - Object access through pointers
============================================================
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    cout << "================ Example 1 : Basic Dereferencing ================\n\n";

    string greeting {"Hello"};
    string* greeting_ptr {&greeting};

    cout << "Variable value          : " << greeting << endl;
    cout << "Pointer stores address  : " << greeting_ptr << endl;
    cout << "Dereferenced pointer    : " << *greeting_ptr << endl;

    cout << "\nChanging where the pointer points...\n";

    string farewell {"Goodbye"};

    greeting_ptr = &farewell;

    cout << "Pointer now points to   : " << *greeting_ptr << endl;
    cout << "Original variable still : " << greeting << endl;

    // ------------------------------------------------------------

    cout << "\n================ Example 2 : Modifying Through a Pointer ================\n\n";

    int score {100};
    int* score_ptr {&score};

    cout << "Original score          : " << score << endl;
    cout << "Pointer reads           : " << *score_ptr << endl;

    *score_ptr = 250; // Basicly assigning the new value at a spesific location, overriding.

    cout << "\nAfter modification through pointer\n";

    cout << "Pointer reads           : " << *score_ptr << endl;
    cout << "Variable value          : " << score << endl;

    /*
        score:

        +-----------+
        |   250     |
        +-----------+
             ▲
             │
        score_ptr
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 3 : Pointer Reassignment ================\n\n";

    double high_temp {100.7};
    double low_temp {37.4};

    double* temp_ptr {&high_temp};

    cout << "Current temperature : " << *temp_ptr << endl;

    temp_ptr = &low_temp;   // Assigning a new location to the pointer. Doesn't change the original variable just changes where the pointer points.

    cout << "Pointer redirected to low_temp\n";

    cout << "Current temperature : " << *temp_ptr << endl;

    cout << "\nNotice:\n";
    cout << "high_temp is still : " << high_temp << endl;
    cout << "Only the pointer changed.\n";

    // ------------------------------------------------------------

    cout << "\n================ Example 4 : Strings ================\n\n";

    string scientist {"Richard Feynman"};

    string* scientist_ptr {&scientist};

    cout << "Original name : " << *scientist_ptr << endl;

    scientist = "Paul Diraac";

    cout << "After modifying the string\n";

    cout << "Pointer now reads : " << *scientist_ptr << endl;

    /*
        The pointer did not change.

        The object itself changed.

        Therefore the pointer automatically "sees"
        the new value.
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 5 : Vectors ================\n\n";

    vector<string> experiments
    {
        "Tau Trigger",
        "Axion Detector",
        "Muon Chamber",
        "Dark Matter Search"
    };

    vector<string>* experiment_ptr {&experiments};

    cout << "First experiment : "
         << (*experiment_ptr).at(0)
         << endl;

    cout << "\nComplete experiment list\n\n";

    for (const auto& experiment : *experiment_ptr)
        cout << experiment << endl;

    // ------------------------------------------------------------

    cout << "\n================ Example 6 : Modifying a Vector Through a Pointer ================\n\n";

    (*experiment_ptr).push_back("Quantum Computing");

    cout << "After push_back()\n\n";

    for (const auto& experiment : experiments)
        cout << experiment << endl;

    // ------------------------------------------------------------

    cout << "\n================ Example 7 : Dot Operator vs Arrow Operator ================\n\n";

    cout << "Current vector size : "
         << (*experiment_ptr).size()
         << endl;

    /*
        We currently use

            (*pointer).member

        Later we will learn the cleaner syntax

            pointer->member

        which is completely equivalent.
    */

    cout << "\n================ Program Finished ================\n";

    return 0;
}