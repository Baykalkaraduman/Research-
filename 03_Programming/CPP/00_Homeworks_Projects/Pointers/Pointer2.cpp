#include <iostream>

using namespace std;

// =================================================
// Function Prototypes
// =================================================

int *create_array (size_t &size);

// Size is defined and initialized but it gets its value from the user inside the function
// Since we are giving a new value to the size inside the function in order to transfer its new value
// It can be also used for returning more than one value (Not this case)

void print_array(const int *const arr, size_t size);

// As mentioned earlier arrays acts similar to pointers
// Pointers just shows a location on the memory 
// Moving from this *(pointer + int) allows you to move in the memory and pointing different values
// *(pointer + int) = pointer_storage + int*byte(it is how memory is designed so we can sum them up)
// Because arrays stores data like:

// xf1000 -> id 0
// xf1004 -> id 1
// xf1006 -> id 2

// So it basically stores the next element in the next location at the memory 

// If you are going to return multiple elements you better use pointers

int find_max(const int *const arr, size_t size);

// We just want to find the max value and print it so we must be careful not to change the values 
// That's why we use "const" before the variable type.
// Even if you want to change the pointer oftentimes generating another pointer that points heap for a short time is more efficient and better solution.
// We also don't want to change where pointer points, because it will cause a crash and might cause a memory leak
// That's why you should use "const" before the pointer as well (Unless you want to change where pointer points)

int find_min(const int *const arr, size_t size);

double find_mean(const int *const arr, size_t size);

int* reverse_array(int *const arr, size_t size);

int* merge_array(const int *const arr1, size_t size1, const int *const arr2, size_t size2);

int* remove_array(const int *const arr, size_t size);

int print_array_updated(const int *const arr, size_t size);

// =================================================
// Function Definitons
// =================================================

int *create_array (size_t &size) {      
    cout << "\nEnter the number of elements for the new array: ";
    cin >> size;

    int *new_arr = new int[size];
    for(size_t i{0}; i < size; ++i) {
        cout << "\nEnter element #" << i+1 << ": ";
        cin >> *(new_arr + i);
    }
    return new_arr;

}

//-----------------------------------------------------------------

void print_array(const int *const arr, size_t size) {
    cout << "\nPrinting array \n" << arr << ": " << endl;
    cout << "========================" << endl;
    for(size_t i{0}; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << "\n========================" << endl;
}

//-----------------------------------------------------------------

int find_max(const int *const arr, size_t size) {
    int max_element {*arr};

    for(size_t i{1}; i < size; ++i) {
        if( max_element < *(arr + i))
            max_element = *(arr + i);
    }
    return max_element;
}

//-----------------------------------------------------------------

int find_min(const int *const arr, size_t size) {
    int min_element {*arr};

    for(size_t i{1}; i < size; ++i) {
        if(min_element > *(arr + i))
            min_element = *(arr + i);
    }
    return min_element;
}

//-----------------------------------------------------------------

double find_mean(const int *const arr, size_t size) {
    double elements_sum {0};
    for(size_t i{0}; i < size; ++i)
        elements_sum += *(arr + i);
    return elements_sum/size;
}

//-----------------------------------------------------------------

int* reverse_array(int *const arr, size_t size) {
    int* rra = new int[size];
    size_t i {0};
    while (i < size) {
        *(rra + i) = *(arr + size -i-1);
        ++i;
    }
    return rra;
}

//-----------------------------------------------------------------

int *merge_array(const int *const arr1, size_t size1, const int *const arr2, size_t size2) {
    int *merged_array {new int[size1 + size2]};
    size_t i {0};
    while (i < size1) {
        *(merged_array + i) = *(arr1 + i);
        ++i;
    }
    size_t j {0};
    while (j < size2) {
        *(merged_array + size1 + j) = *(arr2 + j);
        ++j;
    }
    return merged_array;
}

//-----------------------------------------------------------------

int print_array_updated(const int *const arr, size_t size) {

    int del_id {};

    cout << "\nPrinting array. Choose the id of the element you want to delete:\n";
    cout << "========================" << endl;

    for(size_t i{0}; i < size; ++i)
        cout << *(arr + i) << " -> #" << i << endl;
    cout << "========================" << endl;

    do {
        cout << "\nEnter id: ";
        cin >> del_id;

        if(del_id < 0 || del_id >= static_cast<int>(size))
            cout << "Invalid id. Try again.\n";

    } while(del_id < 0 || del_id >= static_cast<int>(size));

    cout << "\nElement #" << del_id << " removed.\n";

    return del_id;
}

//-----------------------------------------------------------------

int *remove_array(const int *const arr, size_t size) {

    int delete_index = print_array_updated(arr, size);

    int *rarr = new int[size - 1];

    size_t j {0};

    for (size_t i {0}; i < size; ++i) {

        if (i != delete_index) {
            *(rarr + j) = *(arr + i);
            ++j;
        }
    }

    return rarr;
}

// =================================================
// Main Function
// =================================================

int main () {

    cout << "\n============== Creating the first array ==============\n";
    size_t size1 {0};
    int *arr1 = create_array(size1);

    cout << "\n============== Creating the second array ==============\n";
    size_t size2 {0};
    int *arr2 = create_array(size2);

    cout << "\n\n============== Printing the first array ==============\n";
    print_array(arr1, size1);

    cout << "\n\n============== Printing the second array ==============\n";
    print_array(arr2, size2);

    cout << "\n\n============== Finding the biggest element ==============\n";
    cout << "\nBiggest element in the arr1 is: \n" << endl;
    cout << find_max(arr1, size1) << endl;
    cout << "\nBiggest element in the arr2 is: \n" << endl;
    cout << find_max(arr2, size2) << endl;

    cout << "\n\n============== Finding the smallest element ==============\n";
    cout << "\nSmallest element in the arr1 is: \n" << endl;
    cout << find_min(arr1, size1) << endl;
    cout << "\nSmallest element in the arr2 is: \n" << endl;
    cout << find_min(arr2, size2) << endl;

    cout << "\n\n============== Finding the mean value of the element ==============\n";
    cout << "\nMean value of the arr1 is: \n" << endl;
    cout << find_mean(arr1, size1) << endl;
    cout << "\nMean value of the arr2 is: \n" << endl;
    cout << find_mean(arr2, size2) << endl;

    cout << "\n\n============== Reversing the order of the elements in the array ==============\n";

    cout << "\nReversed arr1 looks like: \n" << endl;
    int* reversed1 = reverse_array(arr1, size1);
    print_array(reversed1, size1); 
    cout << "\nReversed arr2 looks like: \n" << endl;
    int* reversed2 = reverse_array(arr2, size2);
    print_array(reversed2, size2);

    cout << "\n\n============== Merging the arrays ==============\n";
    cout << "\nArrays have been merged, here is the new array: \n" << endl;
    int* merged = merge_array(arr1, size1, arr2, size2);
    print_array(merged, size1+size2);

    cout << "\n\n============== Deleting element(s) from the array ==============\n";

    cout << "\nWhich array you want to delete an element from: \n" << endl;
    char selection {};
    do {
        cout << "\n====== Array Table ======\n" << endl;
        cout << "(1) arr1 " << endl;
        cout << "(2) arr2 " << endl;
        cout << "(3) merged " << endl;
        cout << "(q) Quit" << endl;
        cout << "\n=========================\n" << endl;
        cin >> selection; 

        if(selection == '1') {
            cout << "arr1 is choosen";
            int* new_rarr = remove_array(arr1, size1);
            cout << "New " << arr1 << ": " << endl;
            print_array(new_rarr, size1-1);
            delete [] new_rarr;
        } else if(selection == '2') {
            cout << "arr2 is choosen";
            int* new_rarr = remove_array(arr2, size2);
            cout << "New " << arr2 << ": " << endl;
            print_array(new_rarr, size2-1);
            delete [] new_rarr;
        } else if(selection == '3') {
            cout << "merged is choosen";
            int* new_rarr = remove_array(merged, size1+size2);
            cout << "New " << merged << ": " << endl;
            print_array(new_rarr, size1+size2-1);
            delete [] new_rarr;
        } else if (selection == 'q' || selection == 'Q') {
            cout << "Goodbye..." << endl;
        } else {
            cout << "Unvalid choice. Please choose again..." << endl;
        }
    } while (selection == 'q' && selection == 'Q');



    delete [] arr1;
    delete [] arr2;
    delete [] reversed1;
    delete [] reversed2;
    delete [] merged;

    return 0;
}