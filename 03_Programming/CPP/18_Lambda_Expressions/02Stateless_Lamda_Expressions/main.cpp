/**
 * @file stateless_lambdas_demo.cpp
 * @brief Demonstration of Stateless Lambda Expressions in C++.
 * 
 * In computational science, stateless lambdas (lambdas with an empty capture list [])
 * are frequently used as "predicates" (condition checkers) or custom sorting rules.
 * Because they do not capture external variables, the compiler can optimize them 
 * directly into raw function pointers, meaning they carry ZERO performance overhead 
 * inside heavy numerical loops (like Geant4 stepping actions or ROOT TTree analyses).
 */

#include <iostream>
#include <string>
#include <vector>
#include <functional>   // Required for std::function wrappers
#include <algorithm>

/**
 * @brief Custom class representing an entity (e.g., a simulation node or particle).
 */
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name{name}, age{age} {};
    // Copy constructor
    Person(const Person &p): name{p.name}, age{p.age} { }
    ~Person() = default;
    
    std::string get_name() const { return name; }
    void set_name(std::string name) {this->name = name; };
    int get_age() const {return age; }
    void set_age(int age) {this->age = age; }
};

/**
 * @brief Stream insertion operator for Person.
 */
std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
    return os;
}

/**
 * @brief Demonstrates Immediately Invoked Function Expressions (IIFE).
 */
void test1() {
    std::cout << "\n---Test1 --------------------------" << std::endl;

    // Defines a lambda and immediately calls it using () at the end.
    [] () {std::cout << "Hi" << std::endl; }();
    
    // Defines a lambda that takes an integer, and immediately passes 100 to it.
    [] (int x) { std::cout << x << std::endl;}(100);
    
    // Defines a lambda taking two integers, and immediately evaluates it.
    [](int x, int y) { std::cout << x+y << std::endl; }(100,200);
}

/**
 * @brief Demonstrates passing parameters by value vs. reference to lambdas.
 */
void test2() {
    std::cout << "\n---Test2 --------------------------" << std::endl;
    
    // Assigning a lambda to a variable using 'auto'. 
    // The actual type is a unique, compiler-generated closure class.
    auto l1 =   [] () {std::cout << "Hi" << std::endl;};
    l1();
    
    int num1 {100};
    int num2 {100};

    // Passed by value (copies are made).
    auto l2 = [](int x, int y) { std::cout << x+y << std::endl; };
    l2(10,20);
    l2(num1, num2);
    
    // Passed by reference (x) and by value (y).
    // In physics loops, passing heavy objects by reference avoids expensive copies.
    auto l3 = [](int &x, int y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
        x = 1000; // This modifies the actual 'num1' in the caller scope!
        y = 2000; // This only modifies the local copy.
    };
    
    l3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl; // num1 is now 1000
}

/**
 * @brief Demonstrates passing user-defined objects to lambdas.
 */
void test3() {
    std::cout << "\n---Test3 --------------------------" << std::endl;
    Person stooge {"Larry", 18};
    std::cout << stooge << std::endl;
    
    // Pass by Value: Triggers the copy constructor. (Slow for large objects)
    auto l4 = [] (Person p) {
        std::cout << p << std::endl; 
    };
    l4(stooge);
    
    // Pass by Const Reference: No copy, read-only. (BEST PRACTICE for analysis)
    auto l5 = [] (const Person &p) {
        std::cout << p << std::endl; 
    };
    l5(stooge);
    
    // Pass by Reference: No copy, modifiable. (Use when mutating data)
    auto l6 = [] (Person &p) {
        p.set_name("Frank");
        p.set_age(25);
        std::cout << p << std::endl; 
    };
    l6(stooge);
    
    // Original object was modified by l6.
    std::cout << stooge << std::endl;
}

/**
 * @brief Applies a functional filter (predicate) over a vector.
 * 
 * @param vec The data vector to process.
 * @param func A std::function wrapper that takes an int and returns a bool.
 * 
 * @note In Data Acquisition (DAQ) systems, this pattern is heavily used to 
 * define dynamic "cuts" (e.g., filtering out particles with energy < 50 MeV)
 * without rewriting the core loop logic.
 */
void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func)   {
// void filter_vector (const std::vector<int>  &vec, auto func) { // C++20 alternative
    std::cout <<"[ ";
    for (int i: vec) {
        if (func(i)) // If the lambda evaluates to true
            std::cout << i  << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Demonstrates passing lambdas as std::function arguments.
 */
void test4() {
    std::cout << "\n---Test4 --------------------------" << std::endl;
    std::vector<int> nums {10,20,30,40,50,60,70,80,90,100};
    
    // Filter elements strictly greater than 50
    filter_vector(nums, [](int x) {return x>50;});
    
    // Filter elements less than or equal to 30
    filter_vector(nums, [](int x) {return x<=30;});
    
    // Filter elements within a specific range [30, 60]
    filter_vector(nums, [](int x) {return x>= 30 && x <=60;});
}

/**
 * @brief A factory function that generates and returns a lambda.
 * 
 * @return An anonymous closure (lambda) object.
 */
auto make_lambda() {
    return [] () {std::cout << "This lambda was made using the make_lambda function!" << std::endl;};
}

/**
 * @brief Demonstrates returning a lambda from a function.
 */
void test5() {
    std::cout << "\n---Test5 --------------------------" << std::endl;
    
    auto l5 = make_lambda();
    l5();
}

/**
 * @brief Demonstrates Generic Lambdas (Introduced in C++14).
 * 
 * Using 'auto' in the parameter list makes the lambda act like a template.
 * This is incredibly powerful for mathematical functions that might take 
 * ints, floats, or doubles depending on the precision needed.
 */
void test6() {
    std::cout << "\n---Test6 --------------------------" << std::endl;
    auto l6 = [](auto x, auto y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
    };
    
    l6(10,20);                 // Deduced as (int, int)
    l6(100.3, 200);            // Deduced as (double, int)
    l6(12.5, 15.54);           // Deduced as (double, double)
    
    // Deduced as (Person, Person) - requires overloaded operator<<
    l6 (Person("Larry", 18), Person("Curly", 22));
}

/**
 * @brief Demonstrates using lambdas directly inside STL algorithms.
 */
void test7() {
      std::cout << "\n---Test7 --------------------------" << std::endl;

    std::vector<Person> stooges {
        {"Larry", 18},
        {"Moe", 30},
        {"Curly", 25}
    };
    
    // Sorting by name. The lambda overrides the default Person::operator<
    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_name() < p2.get_name();
    });
    
    std::for_each(begin(stooges), end(stooges), [](const Person &p) {
        std::cout << p << std::endl;
    });
    
    std::cout << std::endl;
    
     // Sorting by age dynamically using another lambda
     std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.get_age()< p2.get_age();
    });
    
    std::for_each(begin(stooges), end(stooges), [](const Person &p) {
        std::cout << p << std::endl;
    });
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    
    std::cout << std::endl;
    return 0;
}
