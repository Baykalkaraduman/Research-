/**
 * @file function_objects_and_lambdas.cpp
 * @brief Introduction to Function Objects (Functors) and Lambda Expressions.
 * 
 * In computational science, we frequently need to apply specific operations to 
 * large datasets (e.g., scaling energy values, calculating squared deviations).
 * A "Functor" is a class or struct that overloads the function call operator `operator()`.
 * This allows an object to be called as if it were a function, with the massive 
 * advantage that it can maintain internal STATE (member variables).
 * 
 * Lambdas (introduced in C++11) are essentially a concise, inline way to create 
 * these function objects without manually writing the boilerplate class structure.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

/**
 * @brief A simple stateless Functor.
 * 
 * Overloads the () operator to square a given integer.
 * Commonly used in numerical analysis (e.g., calculating residuals in Least Squares).
 */
struct Square_Functor {
    void operator() (int x) {
            std::cout << x * x  << " ";
    }
};

/**
 * @brief A generic (templated) stateless Functor.
 * 
 * @tparam T The data type to be displayed.
 * Useful for dumping generic vector contents to standard output during debugging.
 */
template <typename T>
struct Displayer {
    void operator() (const T &data) {
        std::cout << data << " ";
    }
};

/**
 * @brief A STATEFUL Functor.
 * 
 * Unlike standard C-style function pointers, this Functor retains state (the 'num' variable).
 * In physics simulations, this is highly useful for applying a runtime-defined scaling 
 * factor (like a calibration constant or unit conversion multiplier) across millions of events.
 */
class Multiplier {
private:
    int num{}; // Internal state
public:
    // Constructor initializes the state
    Multiplier(int n) : num{n} {}
    
    // The overloaded call operator uses the internal state during execution
    int operator()(int n) const {
        return n * num;
    }
};

int main()
{
    // ========================================================================
    // Test 1: Direct instantiation and invocation of Functors
    // ========================================================================
    std::cout << "\nTest1 =================" << std::endl;
    Square_Functor square;
    square(4);      // Under the hood, this calls: square.operator()(4). Displays 16.
    
    Displayer<int> d1;
    Displayer<std::string> d2;
    d1(100);              // displays 100
    d2("Frank");          // displays Frank
    
    // ========================================================================
    // Test 2: Passing Functors to STL Algorithms
    // ========================================================================
    std::cout << "\nTest2 =================" << std::endl;
    std::vector<int> vec1 {1,2,3,4,5};
    std::vector<std::string> vec2 {"Larry", "Moe", "Curly"};
    
    // Passing a named functor object
    std::for_each(vec1.begin(), vec1.end(), square);                // 1 4 9 16 25
    std::cout << std::endl;
    
    // Passing an unnamed, temporary (anonymous) functor object: Displayer<int>()
    std::for_each(vec1.begin(), vec1.end(), Displayer<int>());      // 1 2 3 4 5
    std::cout << std::endl;
    
    std::for_each(vec1.begin(), vec1.end(), d1);                    // 1 2 3 4 5
    std::cout << std::endl;
    
    std::for_each(vec2.begin(), vec2.end(), Displayer<std::string>()); // Larry Moe Curly
    std::cout << std::endl;
    
    std::for_each(vec2.begin(), vec2.end(), d2);    // Larry Moe Curly
    std::cout << std::endl;
    
    // ========================================================================
    // Test 3: The modern approach -> Lambda Expressions
    // ========================================================================
    // A Lambda expression `[](int x) { ... }` tells the compiler to generate 
    // a Functor class behind the scenes automatically. It keeps the logic exactly 
    // where it is being used, vastly improving code readability.
    std::cout << "\nTest3 =================" << std::endl;
    
    // Inline lambda to square elements
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * x  << " "; });  // 1 4 9 16 25
    std::cout << std::endl;
    
    // Inline lambda to multiply by 10
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x * 10  << " "; }); // 10 20 30 40 50
    std::cout << std::endl;
    
    // Inline lambda to simply display
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x << " ";});    // 1 2 3 4 5
    std::cout << std::endl;
    
    // Inline lambda with a different type (std::string)
    std::for_each(vec2.begin(), vec2.end(), [](std::string  s) {std::cout << s  << " "; }); // Larry Moe Curly
    std::cout << std::endl;

    // ========================================================================
    // Test 4: Stateful operations using std::transform
    // ========================================================================
    std::cout << "\nTest4 =================" << std::endl;
    
    // Creating a stateful Functor with a multiplier of 100
    Multiplier mult(100);
    vec1 = {1,2,3,4};
    
    // std::transform modifies the vector in place.
    // It reads from vec1.begin(), applies 'mult', and writes back to vec1.begin().
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), mult);   
    std::for_each(vec1.begin(), vec1.end(),  d1);                           // 100 200 300 400
    std::cout << std::endl;

    vec1 = {1,2,3,4};
    
    // Doing the exact same transformation using a Lambda expression.
    // The lambda [](int x) { return x * 100;} acts just like the 'mult' functor.
    std::transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) { return x * 100;});
    std::for_each(vec1.begin(), vec1.end(), [](int x) {std::cout << x   << " "; });   // 100 200 300 400
  
    std::cout << std::endl;
    
    return 0;
}
