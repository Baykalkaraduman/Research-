/**
 * @file std_array_demo.cpp
 * @brief Demonstration of std::array and various STL algorithms.
 * 
 * This file illustrates how to use the C++11 std::array container, 
 * which is a safer, more feature-rich wrapper around standard C-style arrays.
 * It also demonstrates its seamless integration with standard algorithms
 * from <algorithm> and <numeric>.
 */

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>  // For mathematical algorithms like std::accumulate

/**
 * @brief Utility function to display the contents of a std::array.
 * 
 * @param arr A constant reference to a std::array of exactly 5 integers.
 * @note Unlike std::vector, the size of std::array is part of its type.
 * Therefore, this specific function will ONLY accept a std::array<int, 5>.
 */
void display(const std::array<int, 5> &arr) {
    std::cout << "[ ";
    // Range-based for loop for safe and clean iteration
    for (const auto &i: arr)
        std::cout << i << " ";
    std::cout <<  "]"<< std::endl;
}

/**
 * @brief Demonstrates initialization, assignment, size, and element access.
 */
void test1() {
    std::cout << "\nTest1 =========================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};     // Initialization (double {{ }} required in some older C++11 compilers)
    std::array<int, 5> arr2;                 // Uninitialized array
    
    display(arr1);
    display(arr2);          // Elements contain 'garbage' (uninitialized memory values)
        
    arr2  = {10,20,30,40,50}; // Assignment after declaration

    display(arr1);
    display(arr2);
    
    // .size() returns the number of elements (always 5 for this type)
    std::cout << "Size of arr1 is: " << arr1.size() << std::endl;       // 5 
    std::cout << "Size of arr2 is: " << arr2.size() << std::endl;       // 5
    
    // Element access
    arr1[0] = 1000;         // Direct access (No bounds checking)
    arr1.at(1) = 2000;      // Safe access (Performs bounds checking and throws out_of_range)
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front() << std::endl;        // First element: 10
    std::cout << "Back of arr2: " << arr2.back() << std::endl;          // Last element: 50
}
 
/**
 * @brief Demonstrates fill() and swap() member functions.
 */
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};     
    std::array<int, 5> arr2 {10,20,30,40,50};
    
    display(arr1);
    display(arr2);
    
    // .fill() assigns the given value to every element in the array
    arr1.fill(0);
    
    display(arr1);
    display(arr2);
    
    // .swap() exchanges the contents of two arrays of the exact same type and size
    arr1.swap(arr2);
    
    display(arr1);
    display(arr2);
}

/**
 * @brief Demonstrates accessing the underlying raw pointer.
 */
void test3() {
    std::cout << "\nTest3 =========================" << std::endl;

    std::array<int, 5> arr1 {1,2,3,4,5};     

    // .data() returns a raw pointer to the underlying memory array.
    // Useful for passing std::array data to legacy C APIs.
    int *ptr = arr1.data();
    std::cout << ptr << std::endl; // Prints the memory address
    
    *ptr = 10000; // Dereferencing and modifying the first element (arr1[0])
    
    display(arr1);
}

/**
 * @brief Demonstrates sorting using std::sort from <algorithm>.
 */
void test4() {
    std::cout << "\nTest4 =========================" << std::endl;

    std::array<int, 5> arr1 {2,1,4,5,3};     
    display(arr1);
    
    // std::sort requires random access iterators, which std::array provides
    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

/**
 * @brief Demonstrates finding the minimum and maximum elements.
 */
void test5() {
    std::cout << "\nTest5 =========================" << std::endl;

    std::array<int, 5> arr1 {2,1,4,5,3};     

    // std::min_element returns an iterator to the smallest element
    std::array<int,5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
    
    // Using 'auto' is cleaner for iterators
    auto max_num = std::max_element(arr1.begin(), arr1.end());
    
    // Dereference the iterators to get the actual values
    std::cout << "min: " << *min_num << " , max: " << *max_num << std::endl;
}

/**
 * @brief Demonstrates finding adjacent duplicates.
 */
void test6() {
    std::cout << "\nTest6 =========================" << std::endl;

    std::array<int, 5> arr1 {2,1,3,3,5};     

    // std::adjacent_find looks for two consecutive identical elements
    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    
    // Check if the iterator reached the end (meaning no match was found)
    if (adjacent != arr1.end()) 
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    else 
        std::cout << "No adjacent elements found" << std::endl;
}

/**
 * @brief Demonstrates calculating the sum of elements using std::accumulate.
 */
void test7() {
    std::cout << "\nTest7 =========================" << std::endl;

    // std::accumulate requires the <numeric> header
    std::array<int, 5> arr1 {1,2,3,4,5};     

    // 0 is the initial value for the sum.
    // The type of this initial value determines the type of the result (e.g., 0.0 for double).
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}

/**
 * @brief Demonstrates counting occurrences of a specific value.
 */
void test8() {
    std::cout << "\nTest8 =========================" << std::endl;
    std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};
    
    // std::count returns the number of times the target value (3) appears in the range
    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found 3 : " << count << " times" << std::endl;
}

/**
 * @brief Demonstrates counting elements based on a condition using std::count_if and a lambda.
 */
void test9() {
    std::cout << "\nTest9 =========================" << std::endl;
    std::array<int, 10> arr1 {1, 2, 3, 50, 60, 70, 80, 200, 300 ,400};
    
    // std::count_if uses a boolean predicate. 
    // Here we use a Lambda Expression: [](int x) { return x>10 && x<200; }
    // It returns true if the element is strictly between 10 and 200.
    int count = std::count_if(arr1.begin(), arr1.end(), 
                                            [](int x) { return x>10 && x<200; });
                                            
    std::cout << "Found  " << count << " matches" << std::endl; // Should be 4 (50, 60, 70, 80)
}

int main()  {    

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    
    return 0;
}