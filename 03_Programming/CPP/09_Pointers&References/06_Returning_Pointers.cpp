/**********************************************************************
 * ReturningPointers.cpp
 *
 * Topic:
 *      Returning Pointers from Functions
 *
 * Concepts Covered
 * ----------------------------------------------------------
 * 1. Returning dynamically allocated memory
 * 2. Heap allocation
 * 3. Returning pointer values
 * 4. Default arguments
 * 5. Pointer arithmetic
 * 6. Dynamic arrays
 * 7. Memory ownership
 * 8. Preventing memory leaks
 *********************************************************************/

#include <iostream>

using namespace std;

//===============================================================
// Function Prototypes
//===============================================================

int* create_array(size_t size, int init_value = 0);

void display(const int *const array, size_t size);

//===============================================================
// Create Dynamic Array
//===============================================================

int* create_array(size_t size, int init_value) {

    // Allocate memory on the heap

    int *new_storage {new int[size]};

    // Initialize every element

    for (size_t i {0}; i < size; ++i)
        *(new_storage + i) = init_value;

    return new_storage;
}

//===============================================================
// Display Array
//===============================================================

void display(const int *const array, size_t size) {

    cout << "\nArray contents\n";
    cout << "-----------------------------\n";

    for (size_t i {0}; i < size; ++i)
        cout << array[i] << " ";

    cout << endl;
}

//===============================================================
// Main
//===============================================================

int main() {

    cout << "========== Returning Pointers ==========\n";

    size_t size {};
    int init_value {};

    cout << "\nHow many integers would you like to allocate? ";
    cin >> size;

    cout << "Initial value: ";
    cin >> init_value;

    //----------------------------------------------------------

    int *my_array {nullptr};

    my_array = create_array(size, init_value);

    //----------------------------------------------------------

    display(my_array, size);

    //----------------------------------------------------------
    // Pointer Arithmetic Example
    //----------------------------------------------------------

    cout << "\nPointer Arithmetic Example\n";
    cout << "-----------------------------\n";

    for (size_t i {0}; i < size; ++i)
        cout << *(my_array + i) << " ";

    cout << endl;

    //----------------------------------------------------------
    // Memory Information
    //----------------------------------------------------------

    cout << "\nMemory Information\n";
    cout << "-----------------------------\n";

    cout << "Address of first element : "
         << my_array << endl;

    cout << "Address of second element: "
         << my_array + 1 << endl;

    cout << "Address of third element : "
         << my_array + 2 << endl;

    //----------------------------------------------------------
    // Free Heap Memory
    //----------------------------------------------------------

    delete[] my_array;

    my_array = nullptr;

    cout << "\nDynamic memory released successfully.\n";

    return 0;
}