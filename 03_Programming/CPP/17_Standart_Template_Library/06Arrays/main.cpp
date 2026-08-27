/**
 * @file sequence_containers_array.cpp
 * @brief Demonstration of std::array and STL algorithms for Numerical Computing.
 * 
 * In computational science and physics simulations, std::array provides 
 * a zero-overhead, stack-allocated, cache-friendly alternative to C-style raw arrays.
 * It is ideal for fixed-size mathematical constructs (e.g., 3x3 rotation matrices, 
 * 4-momentum vectors) and interfaces seamlessly with the <algorithm> library.
 */

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>  // Essential for numerical operations like accumulate (integration)

/**
 * @brief Displays the contents of a 5-element integer array.
 * 
 * @param arr A constant reference to avoid copying. The size (5) is part of the type signature.
 * @note In scientific computing, range-based for loops ensure safe traversal of data points
 * without risking out-of-bounds memory access.
 */
void display(const std::array<int, 5> &arr) {
    std::cout << "[ ";
    for (const auto &i: arr)
        std::cout << i << " ";
    std::cout <<  "]"<< std::endl;
}

/**
 * @brief Demonstrates initialization, memory assignment, and safe access.
 */
void test1() {
    std::cout << "\nTest1 =========================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};     // Double {{ }} required in early C++11
    std::array<int, 5> arr2;                 // Uninitialized (contains memory garbage)
    
    display(arr1);
    display(arr2);          
        
    arr2  = {10,20,30,40,50}; // Block assignment

    display(arr1);
    display(arr2);
    
    std::cout << "Size of arr1 is: " << arr1.size() << std::endl;       // Returns constexpr 5 
    std::cout << "Size of arr2 is: " << arr2.size() << std::endl;       // Returns constexpr 5
    
    // Memory access methods:
    arr1[0] = 1000;         // Direct access: No bounds checking (Faster, use in hot loops)
    arr1.at(1) = 2000;      // Safe access: Bounds checked (Throws std::out_of_range, use for UI/I-O)
    display(arr1);

    std::cout << "Front of arr2: " << arr2.front() << std::endl;        // 10
    std::cout << "Back of arr2: " << arr2.back() << std::endl;          // 50
}
 
/**
 * @brief Demonstrates buffer resetting and swapping.
 * 
 * Useful in simulations (like Monte Carlo steps) where you need to clear 
 * state buffers or swap double-buffers efficiently.
 */
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    std::array<int, 5> arr1 {1,2,3,4,5};     
    std::array<int, 5> arr2 {10,20,30,40,50};
    
    display(arr1);
    display(arr2);
    
    arr1.fill(0); // Instantly resets all elements to 0 (e.g., clearing energy deposits)
    
    display(arr1);
    display(arr2);
    
    arr1.swap(arr2); // Swaps contents in linear time
    
    display(arr1);
    display(arr2);
}

/**
 * @brief Interfacing modern C++ std::array with legacy C-APIs.
 */
void test3() {
    std::cout << "\nTest3 =========================" << std::endl;

    std::array<int, 5> arr1 {1,2,3,4,5};     

    // .data() yields a raw pointer to the contiguous memory block.
    // Highly useful when passing data to legacy Fortran/C libraries like BLAS or LAPACK.
    int *ptr = arr1.data();
    std::cout << ptr << std::endl;
    *ptr = 10000; // Modifies the first element
    
    display(arr1);
}

/**
 * @brief Sorting elements in ascending order.
 */
void test4() {
    std::cout << "\nTest4 =========================" << std::endl;

    std::array<int, 5> arr1 {2,1,4,5,3};     
    display(arr1);
    
    // std::sort requires Random Access Iterators (which std::array provides natively)
    std::sort(arr1.begin(), arr1.end());
    display(arr1);
}

/**
 * @brief Finding extrema (minimum and maximum values).
 * 
 * Frequently used to find bounding boxes or peak energy values in a dataset.
 */
void test5() {
    std::cout << "\nTest5 =========================" << std::endl;

    std::array<int, 5> arr1 {2,1,4,5,3};     

    // min_element/max_element return iterators, so they must be dereferenced (*)
    std::array<int,5>::iterator min_num = std::min_element(arr1.begin(), arr1.end());
    auto max_num = std::max_element(arr1.begin(), arr1.end());
    
    std::cout << "min: " << *min_num << " , max: " << *max_num << std::endl;
}

/**
 * @brief Locating adjacent duplicates.
 * 
 * Can be used to find consecutive identical sensor readings or flat signal regions.
 */
void test6() {
    std::cout << "\nTest6 =========================" << std::endl;

    std::array<int, 5> arr1 {2,1,3,3,5};     

    auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
    if (adjacent != arr1.end()) 
        std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
    else 
        std::cout << "No adjacent elements found" << std::endl;
}

/**
 * @brief Demonstrates numerical integration/summation via std::accumulate.
 */
void test7() {
    std::cout << "\nTest7 =========================" << std::endl;

    // std::accumulate is heavily used to sum energy deposits or calculate total mass.
    std::array<int, 5> arr1 {1,2,3,4,5};     

    // The '0' indicates the starting sum and dictates the return type (e.g., 0.0 for double)
    int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
    std::cout << "Sum of the elements in arr1 is: " << sum << std::endl;
}

/**
 * @brief Counting exact occurrences of a discrete value.
 */
void test8() {
    std::cout << "\nTest8 =========================" << std::endl;
    std::array<int, 10> arr1 {1,2,3,1,2,3,3,3,3,3};
    
    // Scans the array and counts how many times '3' appears
    int count = std::count(arr1.begin(), arr1.end(), 3);
    std::cout << "Found 3 : " << count << " times" << std::endl;
}

/**
 * @brief Filtering/Counting data based on custom mathematical predicates.
 */
void test9() {
    std::cout << "\nTest9 =========================" << std::endl;
    std::array<int, 10> arr1 {1, 2, 3, 50, 60, 70, 80, 200, 300 ,400};
    
    // Lambda functions are perfect for defining physical cutoffs or energy thresholds.
    // Example: Counting hits with energy strictly between 10 MeV and 200 MeV.
    int count = std::count_if(arr1.begin(), arr1.end(), 
                                            [](int x) { return x>10 && x<200; });
                                            
    std::cout << "Found  " << count << " matches" << std::endl;
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
