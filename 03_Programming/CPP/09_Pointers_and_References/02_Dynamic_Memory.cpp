/*
============================================================
Topic      : Dynamic Memory Allocation
Author     : Emir Karaduman

Description:
    Learning how memory is allocated dynamically from the heap
    using new and delete operators.

Concepts covered:
    - Stack vs Heap
    - new
    - delete
    - Dynamic variables
    - Dynamic arrays
    - Memory leaks
    - nullptr
============================================================
*/

#include <iostream>

using namespace std;

int main() {

    cout << "================ Example 1 : Dynamic Integer =================\n\n";

    /*
        Local variables are normally stored on the Stack.

        Sometimes we don't know how much memory we need
        while writing the program.

        In such cases we allocate memory from the Heap.
    */

    int* int_ptr {nullptr};

    cout << "Pointer before allocation : " << int_ptr << endl;

    int_ptr = new int;

    cout << "Pointer after allocation  : " << int_ptr << endl;

    *int_ptr = 150;

    cout << "Stored value              : " << *int_ptr << endl;

    /*
        Memory

        Stack                    Heap

        int_ptr  ----------->     150
    */

    delete int_ptr;     // We must give back the storage we took from the heap otherwise it will cause a memory leak.
    int_ptr = nullptr;

    cout << "\nMemory released successfully.\n";

    // ------------------------------------------------------------

    cout << "\n================ Example 2 : Dynamic Double =================\n\n";

    double* temperature_ptr {new double};       // Right now it is just an adress on the heap.

    *temperature_ptr = 36.8;                    // Adress on the heap now holds this value.

    cout << "Temperature : " << *temperature_ptr << endl;

    delete temperature_ptr;
    temperature_ptr = nullptr;

    // ------------------------------------------------------------

    cout << "\n================ Example 3 : Dynamic Array =================\n\n";

    size_t size {};

    cout << "How many temperatures do you want to store? ";
    cin >> size;

    double* temperatures {new double[size]};        // Allocating memory on the heap with given size. 

    cout << "\nEnter " << size << " temperatures\n\n";

    for (size_t i {0}; i < size; ++i) {
        cout << "Temperature #" << i + 1 << ": ";
        cin >> temperatures[i];
    }

    cout << "\nStored temperatures\n\n";

    for (size_t i {0}; i < size; ++i)
        cout << temperatures[i] << " ";

    cout << endl;

    delete[] temperatures;
    temperatures = nullptr;

    // ------------------------------------------------------------

    cout << "\n================ Example 4 : Memory Leak Demonstration =================\n\n";

    /*
        Wrong:

        int* leak = new int;

        leak = nullptr;

        The allocated memory still exists,
        but there is no pointer pointing to it.

        This is called a MEMORY LEAK.

        Since we lost the address,
        delete can no longer free it.

        Always delete allocated memory before
        losing the pointer.
    */

    cout << "Example explained in comments.\n";

    // ------------------------------------------------------------

    cout << "\n================ Example 5 : new with Initialization =================\n\n";

    int* age {new int {22}};

    cout << "Age : " << *age << endl;

    delete age;
    age = nullptr;

    // ------------------------------------------------------------

    cout << "\n================ Example 6 : nullptr After delete =================\n\n";

    int* number {new int {500}};

    cout << "Before delete : " << number << endl;

    delete number;

    number = nullptr;

    cout << "After delete  : " << number << endl;

    /*
        Good practice:

        delete ptr;
        ptr = nullptr;

        Prevents dangling pointers.
    */

    cout << "\n================ Program Finished ================\n";

    return 0;
}