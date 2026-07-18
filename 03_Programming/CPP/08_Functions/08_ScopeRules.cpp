#include <iostream>
using namespace std;

//==================================================
// Function Prototypes
//==================================================

void local_example(int x);
void global_example();
void static_local_example();
void shadowing_example();
void scope_resolution_example();

//==================================================
// Global Variables
//==================================================

int num {300};          // Global variable
const double PI {3.14159};

//==================================================
// Local Scope Example
//==================================================

void local_example(int x) {

    int num {1000};     // Local variable

    cout << "\n===== Local Scope =====\n";

    cout << "Initial local num : "
         << num << endl;

    num = x;

    cout << "Modified local num: "
         << num << endl;

    cout << "Parameter x        : "
         << x << endl;
}

//==================================================
// Global Scope Example
//==================================================

void global_example() {

    cout << "\n===== Global Scope =====\n";

    cout << "Global num before : "
         << num << endl;

    num *= 2;

    cout << "Global num after  : "
         << num << endl;
}

//==================================================
// Static Local Example
//==================================================

void static_local_example() {

    static int counter {0};

    cout << "\n===== Static Local Variable =====\n";

    ++counter;

    cout << "Function called "
         << counter
         << " time(s)"
         << endl;
}

//==================================================
// Variable Shadowing Example
//==================================================

void shadowing_example() {

    int num {50};

    cout << "\n===== Variable Shadowing =====\n";

    cout << "Local num : "
         << num
         << endl;

    cout << "Global num: "
         << ::num
         << endl;
}

//==================================================
// Scope Resolution Operator
//==================================================

void scope_resolution_example() {

    int num {999};

    cout << "\n===== Scope Resolution Operator =====\n";

    cout << "Local num  : "
         << num
         << endl;

    cout << "Global num : "
         << ::num
         << endl;
}

//==================================================
// Main
//==================================================

int main() {

    cout << "========== MAIN ==========\n";

    int num {100};
    int value {500};

    cout << "Main local num : "
         << num
         << endl;

    //------------------------------------------------

    {

        cout << "\nEntering inner block...\n";

        int num {200};

        cout << "Inner block num : "
             << num
             << endl;

        cout << "Outer value      : "
             << value
             << endl;

    }

    cout << "\nBack in main...\n";

    cout << "Main local num : "
         << num
         << endl;

    //------------------------------------------------

    local_example(10);
    local_example(20);

    //------------------------------------------------

    global_example();
    global_example();

    //------------------------------------------------

    static_local_example();
    static_local_example();
    static_local_example();

    //------------------------------------------------

    shadowing_example();

    //------------------------------------------------

    scope_resolution_example();

    //------------------------------------------------

    cout << "\n========== END ==========\n";

    return 0;
}