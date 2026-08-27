/**
 * @file function_templates_demo.cpp
 * @brief Demonstration of C++ Function Templates.
 * 
 * This file illustrates how to create generic functions using templates.
 * Function templates allow us to write a single function definition that 
 * works with different data types, forming the backbone of generic programming
 * and the C++ Standard Template Library (STL).
 */

#include <iostream>
#include <string>

/**
 * @brief Template function to find the minimum of two values.
 * 
 * @tparam T The type of the arguments. Both arguments must be of the same type.
 * @param a First value.
 * @param b Second value.
 * @return T The smaller of the two values.
 * 
 * @note The type T MUST support the '<' operator for this function to compile.
 */
template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

/**
 * @brief Template function with multiple template parameters.
 * 
 * @tparam T1 The type of the first argument.
 * @tparam T2 The type of the second argument.
 * @param a First value to print.
 * @param b Second value to print.
 * 
 * @note Both T1 and T2 MUST support the '<<' operator with std::ostream.
 */
template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << " " << b << std::endl;
}

/**
 * @brief A custom user-defined type representing a Person.
 */
struct Person {
    std::string name;
    int age;
    
    /**
     * @brief Overloads the '<' operator to compare Person objects by age.
     * 
     * This is strictly required so that our template function `min` 
     * can evaluate `a < b` when passing Person objects. Without this, 
     * the compiler wouldn't know how to compare two 'Person' structs.
     */
    bool operator<(const Person &rhs) const {
        return this->age < rhs.age;
    }
};

/**
 * @brief Overloads the stream insertion operator '<<' for the Person struct.
 * 
 * This is required so that `std::cout` (and our `func` template) 
 * knows how to print a Person object.
 */
std::ostream &operator<<(std::ostream &os, const Person &p) {
    os << p.name;
    return os;
}

/**
 * @brief Template function to swap two values.
 * 
 * @tparam T The type of the variables to swap.
 * @param a Reference to the first variable.
 * @param b Reference to the second variable.
 * 
 * @note Arguments must be passed by reference (&) to modify the actual variables.
 */
template <typename T>
void my_swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // ========================================================================
    // 1. Swapping integers using template by reference
    // ========================================================================
    int x{100};
    int y{200};
    std::cout << x << ", " << y << std::endl;
    my_swap(x, y); // The compiler automatically deduces T as 'int'.
    std::cout << x << ", " << y << std::endl;
    
    // ========================================================================
    // 2. Using templates with custom user-defined types (Structs/Classes)
    // ========================================================================
    Person p1 {"Curly", 15};
    Person p2 {"Moe", 30};
    
    // The compiler deduces T as 'Person'. 
    // Inside min(), it uses the overloaded '<' operator in the Person struct.
    Person p3 = min(p1, p2);
    std::cout << p3.name << " is younger" << std::endl;
      
    // The compiler deduces T1 as 'Person' and T2 as 'Person'.
    // Inside func(), it uses the overloaded '<<' operator to print them.
    func(p1, p2);
    
    // ========================================================================
    // 3. Using the single-parameter template (min) with primitive types
    // ========================================================================
    // We can explicitly specify the type <int>, but it is usually optional 
    // if the compiler can deduce it directly from the arguments.
    std::cout << min<int>(2, 3) << std::endl;        // Explicitly int -> 2
    std::cout << min(2, 3) << std::endl;             // Implicitly deduced as int -> 2
    std::cout << min('A', 'B') << std::endl;         // Deduced as char -> 'A'
    std::cout << min(12.5, 9.2) << std::endl;        // Deduced as double -> 9.2
    
    // Expressions are evaluated first, then passed to the template.
    std::cout << min(5 + 2 * 2, 7 + 40) << std::endl; // min(9, 47) -> 9
    
    // ========================================================================
    // 4. Using the multiple-parameter template (func) with mixed types
    // ========================================================================
    func<int, int>(10, 20);            // Explicit typing
    func(10, 20);                      // Deduced as <int, int>
    
    func<char, double>('A', 12.4);     // Explicit typing
    func('A', 12.4);                   // Deduced as <char, double>
    
    // Mixed primitive and C-style string literal (const char*)
    func(1000, "Testing");             // Deduced as <int, const char*>
    
    // Mixed primitive and C++ std::string object
    func(2000, std::string{"Emir"});   // Deduced as <int, std::string>
    
    return 0;
}
