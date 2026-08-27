/**
 * @file associative_containers_map.cpp
 * @brief Demonstration of std::map and nested associative containers.
 * 
 * In computational science and physics simulations, std::map is essential for 
 * Key-Value associations. Common use cases include storing configuration 
 * parameters (e.g., mapping a parameter name to its double value), building 
 * lookup tables for particle properties (e.g., "muon" -> 105.66 MeV), or 
 * grouping hierarchical data (like a detector ID mapping to a set of hit times).
 * 
 * Performance: Lookup, insertion, and deletion are O(log N) as it is 
 * implemented as a balanced binary search tree (Red-Black Tree).
 */

#include <iostream>
#include <map>
#include <set>

/**
 * @brief Overloaded display function specifically for a map containing a set.
 * 
 * @param m A constant reference to a map where keys are strings and values are sets of ints.
 * @note In experimental physics, this structure is heavily used. For instance, 
 * mapping a "Detector_Layer" (string) to a unique set of "Activated_Channels" (set<int>).
 */
void display(const std::map<std::string, std::set<int>> &m) {
    std::cout << "[ ";
    // Elements in a std::map are stored as std::pair<const Key, Value>
    for (const auto &elem: m) {
        std::cout << elem.first << ": [ " ;         // elem.first is the Key (std::string)
            // elem.second is the Value (std::set<int>), so we iterate through it
            for (const auto &set_elem : elem.second) 
                 std::cout << set_elem <<  " ";
            std::cout << "] " ;
    }
    std::cout << "]  " << std::endl;
}

/**
 * @brief Generic template function to display any basic map.
 * 
 * @tparam T1 The data type of the Keys.
 * @tparam T2 The data type of the Values.
 */
template <typename T1, typename T2>
void display(const std::map<T1, T2> &l) {
    std::cout << "[ ";
    for (const auto &elem: l) {
        // elem.first is the Key, elem.second is the Value
        std::cout << elem.first << ":" << elem.second << " ";
    }
    std::cout << "]  " << std::endl;
}

/**
 * @brief Demonstrates basic map operations: insertion, access, and searching.
 */
void test1() {
    std::cout << "\nTest1 =========================" << std::endl;
    
    // Initialization. Keys are automatically sorted in ascending order.
    std::map<std::string, int> m {
        {"Larry", 3},
        {"Moe", 1},
        {"Curly", 2}
    };
    display(m);      
    
    // Method 1 for insertion: using std::pair explicitly
    m.insert( std::pair<std::string, int>("Anna", 10));
    display(m);
    
    // Method 2 for insertion: using std::make_pair (cleaner)
    m.insert(std::make_pair("Joe", 5));
    display(m);
    
    // Method 3 for insertion/update: using the subscript operator[]
    // WARNING: If "Frank" does not exist, operator[] CREATES it with a default 
    // initialized value (0 for ints), and then assigns 18 to it. 
    m["Frank"] = 18;
    display(m);
    
    // Accessing and modifying an existing key's value
    m["Frank"] += 10;               
    display(m);
    
    // O(log N) deletion by key
    m.erase("Frank");
    display(m);
    
    // .count() returns 1 if the key exists, 0 otherwise (since keys are unique)
    std::cout << "Count for Joe: " << m.count("Joe") << std::endl;
    std::cout << "Count for Frank: " << m.count("Frank") << std::endl;
    
    // O(log N) search. DO NOT use std::find from <algorithm> with maps!
    auto it = m.find("Larry");
    if (it != m.end())
        // 'it' is an iterator pointing to a std::pair
        std::cout << "Found: " << it->first << " : " << it->second << std::endl;    
        
    // Deallocates all nodes in the Red-Black Tree
    m.clear();
    
    display(m);
}

/**
 * @brief Demonstrates nested associative containers (Map of Sets).
 */
void test2() {
    std::cout << "\nTest2 =========================" << std::endl;
    
    // A map where each student's name (Key) maps to a set of their unique grades (Value)
    std::map<std::string, std::set<int>> grades  {
        {"Larry", {100, 90} },
        {"Moe",  {94} },
        {"Curly", {80, 90, 100} }
    };
    
    display(grades);
    
    // Accessing Larry's set via operator[] and inserting a new unique value into it
    grades["Larry"].insert(95);                 
    
    display(grades);
    
    // Safely searching for "Moe" without risking the creation of a new entry
    // (which operator[] would do if "Moe" didn't exist).
    auto it = grades.find("Moe");
    if (it != grades.end())                         // found "Moe"
    {
            // it->second gives us a reference to the std::set<int> associated with "Moe"
            it->second.insert(1000);            
    }                                               
    display(grades);
}

int main() {
    test1();
    test2();
    return 0;
}
