/**
 * @file sequence_containers_vector.cpp
 * @brief Comprehensive guide to std::vector and STL algorithms.
 * 
 * In computational science, std::vector is the default dynamic array. 
 * It guarantees contiguous memory layout, making it extremely cache-friendly 
 * for numerical iterations. Understanding capacity management (reserve vs size) 
 * is critical to preventing expensive memory reallocations in hot loops 
 * (like Monte Carlo simulations or DAQ event loops).
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Custom class to demonstrate vector storage of user-defined types.
 */
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) 
        : name{name}, age{age}  {}
        
    /**
     * @brief Overloaded less-than operator.
     * Required for std::sort or when inserting into ordered containers like std::set.
     */
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    
    /**
     * @brief Overloaded equality operator.
     * Required for algorithms like std::find, std::count, or std::remove.
     */
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

/**
 * @brief Stream insertion operator for printing Person objects.
 */
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name << ":" << p.age;
    return os;
}

/**
 * @brief Displays vector elements using std::for_each and a lambda.
 * 
 * @note std::for_each can often be parallelized (in C++17 and later) 
 * using execution policies (std::execution::par), making it highly 
 * efficient for large dataset processing.
 */
void display2(const std::vector<int> &vec) {
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(),
        [](int x) { std::cout << x << " ";});
    std::cout << "]" << std::endl;
}

/**
 * @brief Generic template function to display any vector.
 */
template <typename T>
void display(const std::vector<T> &vec) {
    std::cout << "[ ";
    for (const auto &elem: vec)
        std::cout << elem << " ";
    std::cout <<  "]"<< std::endl;
}

/**
 * @brief Demonstrates initialization and assignment.
 */
void test1() {
    std::cout << "\nTest1 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    vec = {2,4,5,6}; // Reassigns elements, updating size automatically
    display2(vec);
    
    // Fill constructor: creates a vector with 10 elements, all initialized to 100.
    // Useful for pre-allocating baseline arrays in data analysis.
    std::vector<int> vec1 (10, 100);    
    display(vec1);
}

/**
 * @brief Demonstrates dynamic sizing, capacity mechanics, and memory allocation.
 * 
 * @note capacity() is how much memory is allocated. size() is how much is actively used.
 * Reallocation (when size > capacity) is highly expensive.
 */
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec max size: " << vec.max_size() << std::endl; // Hardware/OS limits
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    
    // Adding an element forces a reallocation if size reaches capacity.
    // Usually, the STL doubles the capacity under the hood.
    vec.push_back(6);
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    
    // shrink_to_fit() frees unused memory (Capacity becomes equal to Size).
    vec.shrink_to_fit();    // C++11
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
    
    // reserve() pre-allocates memory. 
    // CRITICAL for physics simulations: If you know you will generate 100,000 particles, 
    // reserve(100000) first to completely avoid runtime reallocation overhead.
    vec.reserve(100);
    display(vec);
    std::cout << "\nvec size: " << vec.size() << std::endl;
    std::cout << "vec capacity: " << vec.capacity() << std::endl;
}

/**
 * @brief Direct vs Bounds-Checked element access.
 */
void test3() {
    std::cout << "\nTest3 =========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    vec[0] = 100;     // Fast, unchecked. Use in performance-critical loops.
    vec.at(1) = 200;  // Safe, checks bounds. Use when reading external input/files.
    
    display(vec);
}

/**
 * @brief Demonstrates Object insertion: push_back vs emplace_back.
 */
void test4() {
    std::cout << "\nTest4 =========================" << std::endl;
    std::vector<Person> stooges;
    
    Person p1 {"Larry", 18};
    display(stooges);
    
    // push_back copies or moves the existing object into the vector.
    stooges.push_back(p1);
    display(stooges);
    
    // Creates a temporary object, then moves it. Less efficient.
    stooges.push_back(Person{"Moe", 25});
    display(stooges);
    
    // emplace_back constructs the object IN PLACE directly in the vector's memory.
    // BEST PRACTICE: Use emplace_back for complex objects to avoid unnecessary copies.
    stooges.emplace_back("Curly", 30);      
    display(stooges);
}

/**
 * @brief Demonstrates front/back access and removing elements.
 */
void test5() {
    std::cout << "\nTest5 =========================" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 30}
    };
    
    display(stooges);
    std::cout << "\nFront: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;
    
    // pop_back removes the last element (O(1) operation).
    stooges.pop_back();
    display(stooges);
}

/**
 * @brief Demonstrates clearing and erasing elements, handling iterator invalidation.
 */
void test6() {
    std::cout << "\nTest6 =========================" << std::endl;
    std::vector<int> vec {1,2,3,4,5};
    display(vec);
    
    // clear() sets size to 0 but DOES NOT free the allocated capacity!
    vec.clear();    
    display(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    display(vec);
    // Erase a specific range: [begin, begin+2) -> Erases first two elements.
    // Erasing from the front/middle of a vector is slow O(n) due to memory shifting.
    vec.erase(vec.begin(), vec.begin() + 2);
    display(vec);
    
    vec = {1,2,3,4,5,6,7,8,9,10};
    
    // Standard idiom for conditionally erasing elements while iterating.
    // Notice how 'it' is updated by vec.erase() because erasing invalidates the current iterator.
    auto it = vec.begin();
    while (it != vec.end()) {
        if (*it %2 == 0)
            it = vec.erase(it);  // erase() returns the iterator to the next valid element
        else
            it++;   // only increment if not erased!
    }
    display(vec);
}

/**
 * @brief Demonstrates swapping two vectors.
 */
void test7() {
    std::cout << "\nTest7 =========================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<int> vec2 {10,20,30,40,50};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    // Swapping vectors is O(1) because it only swaps internal pointers, not the actual data.
    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

/**
 * @brief Demonstrates sorting a vector.
 */
void test8() {
    std::cout << "\nTest8  =========================" << std::endl;

    std::vector<int> vec1 {1,21,3,40,12};    
    
    display(vec1);
    // Uses O(N log N) IntroSort algorithm (QuickSort + HeapSort)
    std::sort(vec1.begin(), vec1.end());
    display(vec1);
}

/**
 * @brief Demonstrates copying data safely using std::back_inserter.
 * 
 * @note Extremely important for filtering datasets. std::back_inserter dynamically 
 * pushes elements to the target vector, preventing Segmentation Faults that occur 
 * if you try to copy into a vector that hasn't been allocated enough space.
 */
void test9() {
    std::cout << "\nTest9  =========================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};   
    std::vector<int> vec2 {10,20};
    
    display(vec1); 
    display(vec2);
    std::cout << std::endl;

    // Appends vec1 elements to the end of vec2 safely.
    std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    vec1 = {1,2,3,4,5,6,7,8,9,10};
    vec2 = {10,20};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    // Copy only elements that pass the predicate (Even numbers)
    std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
            [](int x) { return x%2 == 0; });
    display(vec1);
    display(vec2);
}

/**
 * @brief Demonstrates vector math operations using std::transform.
 * 
 * @note This is the C++ equivalent of NumPy array operations (e.g., element-wise multiplication).
 * Very common in physics when multiplying two data vectors.
 */
void test10() {
    std::cout << "\nTest10  =========================" << std::endl;
    
    std::vector<int> vec1 {1,2,3,4,5};   
    std::vector<int> vec2 {10,20,30,40,50};
    std::vector<int> vec3; // Empty vector
    
    // Takes elements from vec1 and vec2, multiplies them, and appends to vec3.
    // 1*10, 2*20, 3*30, 4*40, 5*50
    std::transform(vec1.begin(), vec1.end(), vec2.begin(),
        std::back_inserter(vec3),
        [](int x, int y) { return x * y;});
        
    display(vec3);
}

/**
 * @brief Demonstrates inserting elements from one vector into the middle of another.
 */
void test11() {
    std::cout << "\nTest11  =========================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 {100,200,300,400};
    
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    // Find the position of '5'
    auto it = std::find(vec1.begin(), vec1.end(), 5);
    if (it != vec1.end()) {
        std::cout << "inserting..." << std::endl;
        // Inserts the entire vec2 right before the '5' in vec1.
        // Warning: This shifts all subsequent elements, which can be slow for massive vectors.
        vec1.insert(it, vec2.begin(), vec2.end());
    } else {
        std::cout << "Sorry, 5 not found" << std::endl;
    }
    display(vec1);
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
    test10();
    test11();
    
    return 0;
}
