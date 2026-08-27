/**
 * @file associative_containers_set.cpp
 * @brief Demonstration of std::set and strict weak ordering concepts.
 * 
 * In computational science, std::set (typically implemented as a Red-Black Tree)
 * is used when we need to maintain a dynamically sorted collection of UNIQUE elements.
 * Common use cases: tracking unique particle IDs, filtering out duplicate sensor 
 * hits, or maintaining an ordered list of simulation events.
 * 
 * Performance: Insertion, deletion, and search are O(log N).
 */

#include <iostream>
#include <set>

/**
 * @brief Custom class to demonstrate how std::set handles user-defined types.
 */
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) 
        : name{name}, age{age}  {}
        
    /**
     * @brief Overloaded less-than operator (CRITICAL FOR std::set).
     * 
     * @warning std::set uses ONLY operator< to determine BOTH ordering and EQUIVALENCE.
     * If !(a < b) && !(b < a) is true, std::set considers 'a' and 'b' to be EQUIVALENT 
     * (meaning they are the same item). 
     * In this specific implementation, two Persons are considered identical if they 
     * have the SAME AGE, completely ignoring their names!
     */
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    
    /**
     * @brief Overloaded equality operator.
     * @note Interestingly, std::set DOES NOT use operator== to check for duplicates.
     * It relies entirely on the equivalence logic derived from operator<.
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
 * @brief Generic template function to display any set.
 * 
 * Iterating through a std::set naturally retrieves elements in sorted order.
 */
template <typename T>
void display(const std::set<T> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Demonstrates basic set operations: insertion, sorting, and uniqueness.
 */
void test1() {
    std::cout << "\nTest1 =========================" << std::endl;
    // Elements are automatically sorted and duplicates are ignored upon initialization
    std::set<int> s1 {1, 4, 3, 5, 2};
    display(s1); // Output: 1 2 3 4 5
    
    // Attempting to assign duplicates; they will be silently discarded
    s1 = {1,2,3,1,1,2,2,3,3,4,5};
    display(s1); // Output: 1 2 3 4 5
    
    s1.insert(0);  // O(log N) insertion
    s1.insert(10); // O(log N) insertion
    
    display(s1);
    
    // .count() returns 1 if found, 0 if not (since sets cannot have duplicates)
    if (s1.count(10)) 
        std::cout << "10 is in the set" << std::endl;
    else
        std::cout << "10 is NOT in the set" << std::endl;

    // .find() is O(log N). DO NOT use std::find() from <algorithm> here, 
    // because std::find is O(N) linear search. Always use the member function!
    auto it = s1.find(5);
    if (it != s1.end())
        std::cout << "Found: " << *it << std::endl;    
        
    s1.clear();
    
    display(s1);
}

/**
 * @brief Demonstrates the equivalence trap caused by strict weak ordering.
 */
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    std::set<Person> stooges {
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges);           // Sorted by age due to operator<

    stooges.emplace("James", 50);   
    display(stooges);

    // This will NOT be inserted!
    // Why? Because operator< only compares age. 
    // Since 50 is not < 50, the set thinks "Frank" is a duplicate of "James".
    stooges.emplace("Frank", 50); 
    display(stooges);
    
    // Standard erasure using find
    auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end())
        stooges.erase(it);
    
    display(stooges);
    
    // DANGER: We are searching for "XXXX" with age 50.
    // Because operator< only checks age, find() will locate "James, 50" 
    // and erase him, thinking "XXXX" and "James" are the same object!
    it = stooges.find(Person("XXXX", 50));                                                                           
    if (it != stooges.end())
        stooges.erase(it);
    display(stooges); 
}

/**
 * @brief Demonstrates std::set::insert return types and logic flow.
 */
void test3() {
    std::cout << "\nTest3 =========================" << std::endl;
    
    std::set<std::string> s {"A", "B", "C"};
    display(s);
    
    // insert() returns a std::pair<iterator, bool>.
    // result.first = an iterator pointing to the inserted (or existing) element.
    // result.second = true if insertion was successful, false if it was a duplicate.
    auto result = s.insert("D");
    display(s);
    
    std::cout << std::boolalpha;
    std::cout << "first: " <<  *(result.first)<< std::endl; // Output: D
    std::cout  << "second: " << result.second << std::endl; // Output: true
    
    std::cout << std::endl;

    // Attempting to insert a duplicate
    result = s.insert("A");
    display(s);
    
    std::cout << std::boolalpha;
    std::cout << "first: " <<  *(result.first)<< std::endl; // Output: A
    std::cout  << "second: " << result.second << std::endl; // Output: false
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
