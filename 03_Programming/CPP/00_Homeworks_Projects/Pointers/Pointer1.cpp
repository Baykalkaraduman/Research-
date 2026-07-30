#include <iostream>
#include <string>

using namespace std;

// ===================================================
// Function Prototypes
// ===================================================
// We are using & in order to move the size to main function
int* array_generator(size_t &size); 

void display_array(const int *const array, size_t size);

int* array_multiplier(const int *const arr1, size_t size1, const int *const arr2, size_t size2, size_t &new_size);

// ===================================================
// Function Definitions
// ===================================================
int* array_generator(size_t &size) {
    cout << "\nEnter how much storage you need for the new array: ";
    cin >> size;
    
    int* new_array {new int[size]};

    cout << "Enter the elements of the array: " << endl;
    for(size_t i{0}; i < size; ++i) {
        cout << "Element #" << i+1 << ": ";
        cin >> new_array[i];
    }    
    return new_array;
}

void display_array(const int *const array, size_t size) {
    cout << "Displaying the array: ";
    for(size_t i{0}; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int* array_multiplier(const int *const arr1, size_t size1, const int *const arr2, size_t size2, size_t &new_size) {
    new_size = size1 * size2; 
    int *arr = new int[new_size];

    size_t index = 0;

    for(size_t i{0}; i < size1; ++i) {
        for(size_t j{0}; j < size2; ++j) {
            arr[index] = arr1[i] * arr2[j];
            index++;
        }
    }
    return arr;
}

// ===================================================
// Main Function
// ===================================================

int main() {
    size_t size1{0};
    int *first_array = array_generator(size1);
    display_array(first_array, size1);
    
    size_t size2{0};
    int *second_array = array_generator(size2);
    display_array(second_array, size2);

    size_t new_size{0};
    int *arr = array_multiplier(first_array, size1, second_array, size2, new_size);
    
    cout << "\n--- Result of Multiplication ---" << endl;
    display_array(arr, new_size); 

    // Releasing the memory preventing memory leak
    delete [] first_array;
    delete [] second_array;
    delete [] arr;

    first_array = nullptr;
    second_array = nullptr;
    arr = nullptr;

    return 0;
}