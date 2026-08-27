/**
 * @file algorithms_demo.cpp
 * @brief Demonstration of C++ STL Algorithms.
 * 
 * This file explores standard algorithms provided by the <algorithm> library.
 * STL algorithms operate on containers via iterators, meaning the same algorithm 
 * (like std::find or std::count) can be used seamlessly across different 
 * data structures (vectors, lists, etc.).
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype> 

/**
 * @brief A custom user-defined type representing a Person.
 */
class Person {
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) 
        : name{name}, age{age}  {}
        
    /**
     * @brief Overloads the '<' operator.
     * Useful if we ever want to use algorithms like std::sort on Person objects.
     */
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    
    /**
     * @brief Overloads the '==' operator.
     * REQUIRED for equality-based algorithms like std::find or std::count to work.
     * Without this, the compiler wouldn't know how to check if two Persons are the same.
     */
    bool operator==(const Person &rhs) const {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

/**
 * @brief Demonstrates std::find to locate a specific element in a container.
 */
void find_test() {
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};
    
    // std::find returns an iterator pointing to the first element that matches '1'.
    // std::begin(vec) and std::end(vec) are non-member equivalents to vec.begin() and vec.end().
    auto loc = std::find(std::begin(vec), std::end(vec), 1);
    
    // We MUST check if the iterator reached the end() sentinel. 
    // Reaching end() means the element was not found.
    if (loc != std::end(vec))
        std::cout << "Found the number: " << *loc <<  std::endl;
    else 
        std::cout << "Couldn't find the number" << std::endl;
        
    std::list<Person> players {
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21}
    };
    
    // std::find with a custom object. 
    // It will use the overloaded operator== in the Person class to compare elements.
    auto loc1 = std::find(players.begin(), players.end(), Person{"Moe", 20});
    if (loc1 != players.end())
        std::cout << "Found  Moe" << std::endl;
    else
        std::cout << "Moe not found" << std::endl;
}

/**
 * @brief Demonstrates std::count to find the total occurrences of an exact value.
 */
void count_test() {
    std::cout << "\n========================" << std::endl;

     std::vector<int> vec {1,2,3,4,5,1,2,1};
     
     // std::count checks for exact equality (returns the number of '1's).
     int num = std::count(vec.begin(), vec.end(), 1);
     std::cout << num << " occurrences found" << std::endl;
}

/**
 * @brief Demonstrates std::count_if using Lambda Expressions as predicates.
 * 
 * A predicate is a function (or lambda) that returns a boolean (true/false).
 */
void count_if_test() {
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5,1,2,1,100};
    
    // std::count_if executes the lambda for each element. 
    // [](int x) { return x % 2 == 0; } returns true if 'x' is even.
    int num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << num << " even numbers found" << std::endl;
    
    // Count odd numbers
    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; });
    std::cout << num << " odd numbers found" << std::endl;
    
    // Determine how many elements in vec are >= 5
    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x >= 5; });
    std::cout << num << "  numbers are >= 5" << std::endl;
}

/**
 * @brief Demonstrates std::replace to swap specific values in-place.
 */
void replace_test() {
    std::cout << "\n========================" << std::endl;

     std::vector<int> vec {1,2,3,4,5,1,2,1};
     for (auto i: vec) {
         std::cout << i << " ";
     }
     std::cout << std::endl;
     
    // std::replace scans the range and replaces every occurrence of '1' with '100' directly in the vector.
    std::replace(vec.begin(), vec.end(), 1, 100);
    
    for (auto i: vec) {
         std::cout << i << " ";
     }
    std::cout << std::endl;
}

/**
 * @brief Demonstrates std::all_of to check if EVERY element satisfies a condition.
 */
void all_of_test() {
    std::vector<int> vec1 {1,3,5,7,9,1,3,13,19,5};
    
    // std::all_of returns true ONLY if the lambda returns true for ALL elements in the range.
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) { return x > 10; }))
        std::cout << "All the elements are > 10" << std::endl;
    else    
        std::cout << "Not all the elements are > 10" << std::endl;
    
    if (std::all_of(vec1.begin(), vec1.end(), [](int x) { return x < 20; }))
        std::cout << "All the elements are < 20" << std::endl;
    else    
        std::cout << "Not all the elements are < 20" << std::endl;        
}

/**
 * @brief Demonstrates std::transform to mutate elements using a function.
 */
void string_transform_test() {
    std::cout << "\n========================" << std::endl;

    std::string str1 {"This is a test"};
    std::cout << "Before transform: " << str1 << std::endl;
    
    // std::transform takes an input range (begin to end), 
    // an output destination (in this case, overwriting from the beginning),
    // and a function/operation to apply to each element (::toupper to uppercase chars).
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    
    std::cout << "After transform: " << str1 << std::endl;
}

int main() {
    // Uncomment the functions you wish to test
    find_test();
//  count_test();
//  count_if_test();
//  replace_test();
//  all_of_test();
//  string_transform_test();

    return 0;
}
