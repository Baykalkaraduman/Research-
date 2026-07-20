/***********************************************************************
 * PassingPointers.cpp
 *
 * Topic:
 *      Passing Pointers to Functions
 *
 * Concepts Covered
 * ------------------------------------------------------------
 * 1. Passing pointers to modify variables
 * 2. Passing addresses vs passing values
 * 3. Swapping variables using pointers
 * 4. Passing arrays to functions
 * 5. Passing vectors using pointers
 * 6. const pointer parameters
 * 7. nullptr safety
 * 8. Pointer parameter best practices
 *
 ***********************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//==============================================================
// Function Prototypes
//==============================================================

void print_title(const string& title);

void double_data(int *int_ptr);

void swap_values(int *a, int *b);

void display_vector(const vector<string> *const v);

void display_array(const int *array, int sentinel);

//==============================================================
// Helper Function
//==============================================================

void print_title(const string& title) {

    cout << "\n=====================================================\n";
    cout << title << endl;
    cout << "=====================================================\n";
}

//==============================================================
// Double Data
//==============================================================

void double_data(int *int_ptr) {

    if (int_ptr == nullptr) {
        cout << "nullptr received! Cannot modify data.\n";
        return;
    }

    *int_ptr *= 2;
}

//==============================================================
// Swap Two Variables
//==============================================================

void swap_values(int *a, int *b) {

    if (a == nullptr || b == nullptr) {
        cout << "Cannot swap nullptr values.\n";
        return;
    }

    int temp {*a};

    *a = *b;
    *b = temp;
}

//==============================================================
// Display Vector
//==============================================================

void display_vector(const vector<string> *const v) {

    if (v == nullptr) {
        cout << "Vector pointer is nullptr.\n";
        return;
    }

    cout << "Vector contains:\n";

    for (const auto &item : *v)
        cout << item << endl;
}

//==============================================================
// Display Array
//==============================================================

void display_array(const int *array, int sentinel) {

    if (array == nullptr) {
        cout << "Array pointer is nullptr.\n";
        return;
    }

    while (*array != sentinel) {

        cout << *array << " ";
        ++array;
    }

    cout << endl;
}

//==============================================================
// Main
//==============================================================

int main() {

    //==========================================================
    // Example 1
    // Passing Pointer to Modify Data
    //==========================================================

    print_title("Example 1 : Passing Pointer");

    int value {10};

    cout << "Original value : "
         << value << endl;

    cout << "Memory address : "
         << &value << endl;

    double_data(&value);

    cout << "After double_data(&value)\n";

    cout << "Value : "
         << value << endl;

    //----------------------------------------------------------

    int *value_ptr {&value};

    cout << "\nCalling function using pointer variable...\n";

    double_data(value_ptr);

    cout << "Value : "
         << value << endl;

    //==========================================================
    // Example 2
    // Swapping Variables
    //==========================================================

    print_title("Example 2 : Swapping Variables");

    int x {100};
    int y {200};

    cout << "Before swap\n";

    cout << "x = "
         << x << endl;

    cout << "y = "
         << y << endl;

    swap_values(&x, &y);

    cout << "\nAfter swap\n";

    cout << "x = "
         << x << endl;

    cout << "y = "
         << y << endl;

    //==========================================================
    // Example 3
    // Passing Vector
    //==========================================================

    print_title("Example 3 : Passing Vector");

    vector<string> experiments {

        "Tau Trigger",
        "Muon Detector",
        "Axion Search",
        "CMS Framework"

    };

    display_vector(&experiments);

    //==========================================================
    // Example 4
    // Passing Arrays
    //==========================================================

    print_title("Example 4 : Passing Array");

    int scores[] {

        100,
        98,
        95,
        90,
        88,
        85,
        -1

    };

    display_array(scores, -1);

    //==========================================================
    // Example 5
    // nullptr Safety
    //==========================================================

    print_title("Example 5 : nullptr Safety");

    int *null_pointer {nullptr};

    double_data(null_pointer);

    display_array(null_pointer, -1);

    //==========================================================
    // Example 6
    // Pointer Parameter Summary
    //==========================================================

    print_title("Example 6 : Summary");

    cout << "Passing pointers allows functions to modify\n";
    cout << "the original variables stored in memory.\n\n";

    cout << "Always validate pointers before dereferencing.\n";

    cout << "Use const whenever the function should not\n";
    cout << "modify the object being pointed to.\n";

    cout << "\nProgram Finished Successfully.\n";

    return 0;
}