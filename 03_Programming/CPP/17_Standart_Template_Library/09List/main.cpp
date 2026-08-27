/**
 * @file sequence_containers_list.cpp
 * @brief Demonstration of std::list (Doubly Linked List) and its iterators.
 * 
 * In computational science, std::list is utilized when the simulation requires 
 * frequent O(1) insertions and deletions in the middle of a dataset 
 * (e.g., dynamically generating or destroying particles in a Monte Carlo simulation).
 * 
 * @warning Because its nodes are scattered in heap memory, std::list suffers from 
 * high cache-miss rates. It lacks random access (no operator[]). For pure sequential 
 * number crunching, std::vector is almost always preferred.
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator> // Required for std::advance (navigating non-random-access iterators)

/**
 * @brief Custom class representing an entity (e.g., a simulation node).
 */
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;
public:
    // A Default Constructor is STRICTLY REQUIRED when using methods like std::list::resize()
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) 
        : name{name}, age{age}  {}
        
    /**
     * @brief Overloaded less-than operator.
     * Crucial for the internal std::list::sort() method to work.
     */
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
    
    /**
     * @brief Overloaded equality operator.
     * Required for std::find to locate a specific Person inside the linked list.
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
 * @brief Generic template function to display any list.
 * 
 * @note We MUST use a range-based for loop or iterators. 
 * We CANNOT use a standard for-loop with index (i) because std::list 
 * does not support random access (l[i] is invalid).
 */
template <typename T>
void display(const std::list<T> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) {
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Demonstrates initialization and O(1) front/back insertions.
 */
void test1() {
    std::cout << "\nTest1 =========================" << std::endl;

    std::list<int> l1 {1,2,3,4,5};
    display(l1);
    
    std::list<std::string> l2;
    l2.push_back("Back");   // O(1) operation
    l2.push_front("Front"); // O(1) operation
    display(l2);
    
    std::list<int> l3;
    l3 = {1,2,3,4,5,6,7,8,9,10};
    display(l3);
    
    // Fill constructor: Allocates 10 separate nodes in memory, each holding '100'.
    std::list<int> l4 (10, 100);
    display(l4);
}

/**
 * @brief Demonstrates basic properties and memory clearing.
 */
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;

    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    std::cout << "Size: " << l.size() << std::endl; // O(1) in C++11 and later
    
    std::cout << "Front : " << l.front() << std::endl;
    std::cout << "Back  : " << l.back() << std::endl;
    
    // Deallocates every single node in the heap memory
    l.clear();
    display(l);
    std::cout << "Size: " << l.size() << std::endl;
}

/**
 * @brief Demonstrates dynamic resizing of the linked list.
 */
void test3() {
    std::cout << "\nTest3 =========================" << std::endl;

    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    
    // Shrinks the list. The last 5 nodes are destroyed and memory is freed.
    l.resize(5);
    display(l);
    
    // Expands the list. 5 new nodes are created with the default value (0 for int).
    l.resize(10);
    display(l);
    
    std::list<Person> persons;
    // Creates 5 new Person nodes. This is why Person() default constructor is mandatory!
    persons.resize(5);             
    display(persons);
}

/**
 * @brief Demonstrates navigating and modifying the list using iterators.
 * 
 * @note This is the most important concept in std::list. Finding the element is O(N), 
 * but once the iterator is there, inserting/erasing is O(1) because it only involves 
 * repointing the "next" and "prev" node pointers.
 */
void test4() {
    std::cout << "\nTest4 =========================" << std::endl;

    std::list<int> l {1,2,3,4,5,6,7,8,9,10};
    display(l);
    
    // O(N) search to find '5'
    auto it = std::find(l.begin(), l.end(), 5);
    if (it != l.end()) {
        l.insert(it, 100); // O(1) insertion right before '5'
    }
    display(l);
    
    std::list<int> l2 {1000,2000,3000};
    // Splicing/Inserting another list at the iterator's position
    l.insert(it, l2.begin(), l2.end());
    display(l);
    
    // IMPORTANT: Because std::list iterators are NOT random-access, we CANNOT do (it - 4).
    // std::advance loops under the hood to move the iterator safely.
    std::advance(it, -4);       // point to the 100
    std::cout << *it << std::endl;
    
    // O(1) removal. The iterator 'it' becomes invalid after this operation.
    l.erase(it);                    
    display(l);
}

/**
 * @brief Demonstrates in-place object construction within the list.
 */
void test5() {
    std::cout << "\nTest5 =========================" << std::endl;

    std::list<Person>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    
    display(stooges);
    std::string name;
    int age{};
    std::cout << "\nEnter the name of the next stooge: ";
    getline(std::cin, name);
    std::cout << "Enter their age: ";
    std::cin >> age;
    
    // Constructs the Person directly at the back node (no temporary copies).
    stooges.emplace_back(name, age);
    display(stooges);
    
    // Insert Frank before Moe
    auto it = std::find(stooges.begin(), stooges.end(), Person{"Moe", 25});
    if (it != stooges.end())
        // emplace constructs the object directly at the iterator's position
        stooges.emplace(it, "Frank", 18);
        
    display(stooges);    
}

/**
 * @brief Demonstrates the internal sort method of std::list.
 * 
 * @warning You CANNOT use std::sort(l.begin(), l.end()) because std::sort 
 * requires Random Access Iterators. Instead, std::list provides its own 
 * optimized member function sort() which manipulates the node pointers directly.
 */
void test6() {
    std::cout << "\nTest6 =========================" << std::endl;
    
    std::list<Person>  stooges {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    
    display(stooges);
    
    // Uses Person::operator< to sort the nodes by age. 
    stooges.sort();
    
    display(stooges);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    std::cout << std::endl;
    return 0;
}
