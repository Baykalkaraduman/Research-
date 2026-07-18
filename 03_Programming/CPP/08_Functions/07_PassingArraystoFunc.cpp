#include <iostream>

using namespace std;

//==========================================================
// Passing Arrays to Functions
//
// Arrays are automatically passed by address.
//
// This means that functions work directly on the original
// array unless the parameter is declared as const.
//==========================================================

// Function prototypes

void print_array(const int arr[], size_t size);
void set_array(int arr[], size_t size, int value);
double average_array(const int arr[], size_t size);
int find_max(const int arr[], size_t size);

//==========================================================

int main() {

    cout << "========== Example 1 : Original Array ==========\n";

    int scores[] {100, 98, 85, 92, 100};

    print_array(scores, 5);

    cout << "\n========== Example 2 : Modifying the Array ==========\n";

    set_array(scores, 5, 100);

    print_array(scores, 5);

    cout << "\n========== Example 3 : Average ==========\n";

    cout << "Average = "
         << average_array(scores,5)
         << endl;

    cout << "\n========== Example 4 : Maximum ==========\n";

    cout << "Largest element = "
         << find_max(scores,5)
         << endl;

    return 0;
}

//==========================================================
// Print Array
//
// const means this function promises not to modify
// the contents of the array.
//==========================================================

void print_array(const int arr[], size_t size)
{
    cout << "Array contents: ";

    for(size_t i {0}; i < size; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

//==========================================================
// Modify Every Element
//
// Since the array is NOT const,
// this function changes the original array.
//==========================================================

void set_array(int arr[],
               size_t size,
               int value)
{
    for(size_t i {0}; i < size; ++i)
        arr[i] = value;
}

//==========================================================
// Calculate Average
//
// Read-only function
//==========================================================

double average_array(const int arr[],
                     size_t size)
{
    if(size == 0)
        return 0.0;

    int total {};

    for(size_t i {0}; i < size; ++i)
        total += arr[i];

    return static_cast<double>(total) / size;
}

//==========================================================
// Find Maximum
//
// Read-only function
//==========================================================

int find_max(const int arr[],
             size_t size)
{
    if(size == 0)
        return 0;

    int largest {arr[0]};

    for(size_t i {1}; i < size; ++i)
    {
        if(arr[i] > largest)
            largest = arr[i];
    }

    return largest;
}