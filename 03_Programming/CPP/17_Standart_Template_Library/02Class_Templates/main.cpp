/**
 * @file class_templates_demo.cpp
 * @brief Demonstration of C++ Class Templates.
 * 
 * This file illustrates how to define and instantiate template classes and structs.
 * Class templates allow a class to operate with generic data types.
 * 
 * @note Template classes are typically completely contained in header files (.h or .hpp).
 * Because the compiler needs to see the full template definition to generate 
 * the specific type instantiations, we usually do not separate them into .cpp files.
 */

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief A generic Item class that can hold a value of any type.
 * 
 * @tparam T The data type of the 'value' member variable.
 */
template <typename T>
class Item {
private:
    std::string name;
    T value; // The type of this variable is determined at instantiation.

public:
    /**
     * @brief Constructor to initialize the Item.
     * 
     * @param name The name of the item.
     * @param value The value of the item, of generic type T.
     */
    Item(std::string name, T value) : name{name}, value{value} 
    {}

    /**
     * @brief Getter for the item's name.
     * @return std::string The name of the item.
     */
    std::string get_name() const { return name; }

    /**
     * @brief Getter for the item's value.
     * @return T The value of the item.
     */
    T get_value() const { return value; }
};

/**
 * @brief A generic struct to hold a pair of heterogeneous values.
 * 
 * @tparam T1 The data type of the first element.
 * @tparam T2 The data type of the second element.
 */
template <typename T1, typename T2>
struct My_Pair {
    T1 first;
    T2 second;
};

int main() {
    
    // ========================================================================
    // 1. Instantiating Class Templates with Primitive Types
    // ========================================================================
    // Here, we explicitly specify that T is 'int'.
    Item<int> item1 {"Emir", 100};
    std::cout << item1.get_name() << " " << item1.get_value() << std::endl;
    
    // ========================================================================
    // 2. Instantiating Class Templates with Standard Library Types
    // ========================================================================
    // Here, we explicitly specify that T is 'std::string'.
    Item<std::string> item2 {"Emir", "Professor"};
    std::cout << item2.get_name() << " " << item2.get_value() << std::endl;
    
    // ========================================================================
    // 3. Nested Template Instantiation
    // ========================================================================
    // We can use a template class as the type parameter for another template class.
    // T is explicitly specified as 'Item<std::string>'.
    Item<Item<std::string>> item3 {"Emir", {"C++", "Professor"}};
    
    std::cout << item3.get_name() << " " 
              << item3.get_value().get_name() << " "    // Accessing the inner Item's name
              << item3.get_value().get_value() << std::endl; // Accessing the inner Item's value
    
    std::cout << "\n================================" << std::endl;
    
    // ========================================================================
    // 4. Using Template Classes with STL Containers
    // ========================================================================
    // A vector that stores Item objects, where each Item's T is 'double'.
    std::vector<Item<double>> vec {};
    
    vec.push_back(Item<double>("Larry", 100.0));
    vec.push_back(Item<double>("Moe", 200.0));
    vec.push_back(Item<double>("Curly", 300.0));
    
    // Iterating through the vector using a range-based for loop.
    // 'const auto &' is used for read-only access without copying the objects.
    for (const auto &item : vec) {
        std::cout << item.get_name() << " " << item.get_value() << std::endl;
    }
   
    std::cout << "\n================================" << std::endl;
    
    // ========================================================================
    // 5. Instantiating Structs with Multiple Template Parameters
    // ========================================================================
    // T1 is 'std::string', T2 is 'int'.
    My_Pair<std::string, int> p1 {"Emir", 100};
    
    // T1 is 'int', T2 is 'double'.
    My_Pair<int, double> p2 {124, 13.6};

    std::cout << p1.first << ", " << p1.second << std::endl;
    std::cout << p2.first << ", " << p2.second << std::endl;
    
    return 0;
}