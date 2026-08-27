/**
 * @file stateful_lambdas_demo.cpp
 * @brief Demonstration of Stateful Lambda Expressions (Capture Lists).
 * 
 * In computational science, stateful lambdas are incredibly powerful for injecting 
 * dynamic parameters (like energy thresholds, calibration constants, or event counters)
 * directly into standard library algorithms (like std::copy_if or std::transform) 
 * without having to write full Functor classes.
 * 
 * The capture list `[...]` defines exactly what external variables the lambda 
 * takes with it. Under the hood, captured variables become member variables 
 * of the compiler-generated Functor class.
 */

#include <iostream>
#include <vector>
#include <algorithm>

// Global variables are implicitly accessible anywhere.
int global_x {1000};

/**
 * @brief Demonstrates capturing scope and global variable access.
 * 
 * The global variable `global_x` cannot be captured because it is not 
 * within the local reaching scope. However, it can still be accessed 
 * inside the lambda using normal C++ name lookup rules.
 */
void test1()
{
    std::cout << "\n---Test1 --------------------------" << std::endl;
    
    int local_x {100};
    
    // Capture 'local_x' by value.
    auto l = [local_x] () {
        std::cout << local_x << std::endl;
        std::cout << global_x << std::endl;
    };
    l();
}

/**
 * @brief Demonstrates capture by value and the 'mutable' keyword.
 * 
 * By default, the overloaded operator() generated for a lambda is `const`.
 * To modify a variable captured BY VALUE inside the lambda, we MUST use `mutable`.
 * @warning This only modifies the lambda's internal COPY of 'x', NOT the original 'x'.
 */
void test2()
{
    std::cout << "\n---Test2 --------------------------" << std::endl;
    
    int x {100};
    
    auto l = [x] () mutable {
        x += 100; // Modifies the internal copy
        std::cout << x << std::endl;
    };
    
    l(); // Internal x becomes 200
    std::cout << x << std::endl; // Original x remains 100
    
    l(); // Internal x becomes 300 (state is preserved across calls!)
    std::cout << x << std::endl; // Original x remains 100
}

/**
 * @brief Demonstrates capture by reference.
 * 
 * Any changes made to the captured reference variable within the lambda body
 * will permanently modify the actual external variable.
 * @note In physics loops, capturing counters or accumulators by reference is very common.
 */
void test3()
{
    std::cout << "\n---Test3 --------------------------" << std::endl;
    
    int x {100};
    
    // Capture 'x' by reference. 'mutable' is NOT needed to modify a referenced variable.
    auto l = [&x] () mutable {
        x += 100;
        std::cout << x << std::endl;
    };
    
    l(); // Outputs 200
    std::cout << x << std::endl; // Original x is now 200
}

/**
 * @brief Demonstrates default capture by value [=].
 * 
 * The compiler will automatically capture any external variables used inside 
 * the lambda body by value. Unused variables (like 'z') are ignored.
 */
void test4()
{
    std::cout << "\n---Test4 --------------------------" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};  // 'z' is not captured since it is not used in the body.
    
    auto l = [=] () mutable {
        x += 100;
        y += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    };
    l();
    
    std::cout << "\n";
    std::cout << x << std::endl; // Original x remains 100
    std::cout << y << std::endl; // Original y remains 200
}

/**
 * @brief Demonstrates default capture by reference [&].
 * 
 * Automatically captures all external variables used inside the body by reference.
 */
void test5()
{
    std::cout << "\n---Test5 --------------------------" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};
    
    auto l = [&] () {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();
    
    std::cout << "\n";
    std::cout << x << std::endl; // Original is now 200
    std::cout << y << std::endl; // Original is now 300
    std::cout << z << std::endl; // Original is now 400
}

/**
 * @brief Demonstrates mixed capture: Default by value, specific by reference.
 */
void test6()
{
    std::cout << "\n---Test6 --------------------------" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};
    
    // Capture everything by value, EXCEPT 'y' which is captured by reference.
    auto l = [=, &y] () mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();
    
    std::cout << "\n";
    std::cout << x << std::endl; // Unchanged
    std::cout << y << std::endl; // Changed to 300
    std::cout << z << std::endl; // Unchanged
}

/**
 * @brief Demonstrates mixed capture: Default by reference, specific by value.
 */
void test7()
{
    std::cout << "\n---Test7 --------------------------" << std::endl;
    
    int x {100};
    int y {200};
    int z {300};
    
    // Capture everything by reference, EXCEPT 'x' and 'z' which are by value.
    auto l = [&, x, z] () mutable {
        x += 100;
        y += 100;
        z += 100;
        std::cout << x << std::endl;
        std::cout << y << std::endl;
        std::cout << z << std::endl;
    };
    l();
    
    std::cout << "\n";
    std::cout << x << std::endl; // Unchanged
    std::cout << y << std::endl; // Changed to 300
    std::cout << z << std::endl; // Unchanged
}

/**
 * @brief Custom class to demonstrate capturing 'this' in member functions.
 */
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person() = default;
    Person(std::string name, int age) : name{name}, age{age} {}
    Person(const Person &p) = default;
    ~Person() = default;
    
    std::string get_name() const { return name; }
    void set_name(std::string name) {this->name = name; };
    int get_age() const {return age; }
    void set_age(int age) {this->age = age; }
    
    // Returning lambdas that capture the current object instance ('this').
    // These allow the lambda to modify member variables (name, age).
    auto change_person1() {return [this] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
    auto change_person2() {return [=] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
    auto change_person3() {return [&] (std::string new_name, int new_age) {name = new_name; age = new_age;};}
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
    return os;
}

/**
 * @brief Demonstrates object member captures ([this], [=], [&]).
 */
void test8()
{
    std::cout << "\n---Test8 --------------------------" << std::endl;

    Person person("Larry", 18);
    std::cout << person << std::endl;
    
    // Explicit capture of 'this' (Preferred modern C++ approach)
    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    std::cout << person << std::endl;
    
    // Default capture [=] captures 'this' by reference. 
    // @warning Implicitly capturing 'this' via [=] is DEPRECATED in C++20.
    auto change_person2 = person.change_person2();
    change_person2("Curly", 25);
    std::cout << person << std::endl;
    
    // Default capture [&] also captures 'this' by reference.
    auto change_person3 = person.change_person3();
    change_person3("Frank", 34);
    std::cout << person << std::endl;
}

/**
 * @brief A manual Functor class equivalent to a lambda capturing 'y' by value.
 */
class Lambda {
private:
    int y; // The captured state
public:
    Lambda(int y) : y{y} {};
    
    // The overloaded call operator
    void operator() (int x) const {
        std::cout << x + y << std::endl;
    };
};

/**
 * @brief Proves that Lambdas are just compiler-generated Functor classes.
 */
void test9()
{
    std::cout << "\n---Test9 --------------------------" << std::endl;
    
    int y {100};
    
    Lambda lambda1(y); // Manual Functor instantiation
    
    // Compiler generates a closure class identical to 'Lambda' behind the scenes.
    auto lambda2 = [y] (int x) {std::cout << x + y << std::endl;};
    
    lambda1(200); // Outputs 300
    lambda2(200); // Outputs 300
}

/**
 * @brief A container class representing a group of people.
 */
class People {
    std::vector<Person> people;
    int max_people;
public:
    People(int max=10) : max_people(max) { }
    People(const People &p) = default;
    
    void add(std::string name, int age) {
        people.emplace_back(name, age);
    }
    void set_max_people(int max) {
        max_people = max;
    }
    int get_max_people() const {
        return max_people;
    }
    
    /**
     * @brief A highly practical example of mixed captures in algorithms.
     * 
     * @note This mimics how we filter Data Acquisition (DAQ) events. 
     * E.g., we want to collect hits (people) that pass an energy threshold (max_age)
     * but we stop collecting once we hit a buffer limit (max_people).
     */
    std::vector<Person> get_people(int max_age) {
        std::vector<Person> result;
        int count{0}; // Track how many items we successfully added
        
        // [this] captures member variables like max_people
        // [&count] captures the local tracking variable by reference so we can modify it
        // [max_age] captures the function parameter by value
        std::copy_if(people.begin(), 
                           people.end(), 
                           std::back_inserter(result),
                           [this, &count, max_age](const Person &p){ 
                               return p.get_age() > max_age &&  ++count<=max_people;
                           });
        return result;
    }
};

/**
 * @brief Demonstrates advanced lambda predicates in real-world data filtering.
 */
void test10() {
    std::cout << "\n---Test10 --------------------------" << std::endl;

    People friends;
    friends.add("Larry", 18);
    friends.add("Curly", 25);
    friends.add("Moe", 35);
    friends.add("Frank", 28);
    friends.add("James", 65);
    
    auto result = friends.get_people(17);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;
        
    friends.set_max_people(3);
    
    result = friends.get_people(17);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;
        
    result = friends.get_people(50);
    
    std::cout << std::endl;
    for (const auto &p: result)
        std::cout << p << std::endl;
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
    test8();
    test9();
    test10();
    
    std::cout << "\n";
    return 0;
}
