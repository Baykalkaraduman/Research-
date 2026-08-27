/**
 * @file stl_and_lambdas_demo.cpp
 * @brief Integration of STL Algorithms and Lambda Expressions.
 * 
 * In computational science, combining STL algorithms with lambdas eliminates 
 * boilerplate loops and provides massive optimization opportunities (e.g., auto-vectorization).
 * 
 * - Non-modifying algorithms (for_each, all_of, is_permutation) are used for data inspection.
 * - Modifying algorithms (transform, remove_if, sort) are used for data mutation, 
 *   scaling, and filtering (like applying energy cuts or calibration shifts in simulations).
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // Required for std::iota

// ========================================================================
// Test 1: std::for_each (Non-modifying sequence operation)
// ========================================================================
/**
 * @brief Displays each element using std::for_each and a stateless lambda.
 */
void test1()
{
    std::cout << "\n---Test1 --------------------------" << std::endl;
    
    std::vector<int> nums {10,20,30,40,50};
    
    // std::for_each applies the lambda to every element in the range.
    std::for_each(nums.begin(), nums.end(), [] (int num) {
        std::cout << num << " ";
    });
}

// ========================================================================
// Test 2: std::is_permutation (Non-modifying sequence operation)
// ========================================================================
/**
 * @brief Tests whether two geometric shapes (Triangles) are equivalent.
 * 
 * In spatial physics or mesh generation, we often need to check if two elements 
 * (like mesh triangles or molecular bonds) consist of the same constituent points, 
 * regardless of the order they were stored in memory.
 */
void test2()
{
    std::cout << "\n\n---Test2 --------------------------" << std::endl;
    
    struct Point
    {
        int x;
        int y;
    };
    
    Point pt1{1,2};
    Point pt2{4,3};
    Point pt3{3,5};
    Point pt4{3,1};
    
    std::vector<Point> triangle1 {pt1,pt2,pt3};
    std::vector<Point> triangle2 {pt2,pt3,pt1}; // Same points, different order
    std::vector<Point> triangle3 {pt1,pt2,pt4}; // Different points
    
    // std::is_permutation checks if triangle2 contains the exact same elements as triangle1.
    // We provide a custom lambda predicate to define what "equality" means for a Point.
    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle2.begin(), [] (Point lhs, Point rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }))
        std::cout << "Triangle1 and Triangle2 are equivalent!" << std::endl;
    else
        std::cout << "Triangle1 and Triangle2 are not equivalent!" << std::endl;
        
    // Test whether triangle1 and triangle3 are equivalent
    if (std::is_permutation(triangle1.begin(), triangle1.end(), triangle3.begin(), [] (Point lhs, Point rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }))
        std::cout << "Triangle1 and Triangle3 are equivalent!" << std::endl;
    else
        std::cout << "Triangle1 and Triangle3 are not equivalent!" << std::endl;
}

// ========================================================================
// Test 3: std::transform (Modifying sequence operation)
// ========================================================================
/**
 * @brief Mutates a sequence in place by applying an operation.
 * 
 * Highly utilized in numerical arrays (e.g., scaling a vector of energy deposits).
 * Here, we use a stateful lambda capturing `bonus_points` by value.
 */
void test3()
{
    std::cout << "\n---Test3 --------------------------" << std::endl;
    
    std::vector<int> test_scores {93,88,75,68,65};
    int bonus_points {5};
    
    // std::transform reads from begin() to end(), applies the lambda, and overwrites begin().
    std::transform(test_scores.begin(), test_scores.end(), test_scores.begin(), [bonus_points] (int score) {
        return score += bonus_points;
    });
    
    // Display updated test_scores
    for (int score : test_scores)
        std::cout << score << " ";
}

// ========================================================================
// Test 4: Erase-Remove Idiom (Crucial C++ Design Pattern)
// ========================================================================
/**
 * @brief Demonstrates the Erase-Remove Idiom to filter out data.
 * 
 * std::remove_if DOES NOT actually erase elements from the vector or change its size.
 * It merely shifts the "kept" elements to the front and returns an iterator pointing 
 * to the new logical end of the data. 
 * To actually free the memory/shrink the container, we MUST wrap it in vector::erase().
 */
void test4()
{
    std::cout << "\n\n---Test4 --------------------------" << std::endl;
    
    std::vector<int> nums {1,2,3,4,5};
    
    // erase-remove idiom: Remove all even numbers.
    nums.erase(std::remove_if(nums.begin(), nums.end(), [] (int num) {
            return num % 2 == 0;
        }), 
        nums.end());
    
    // Displays updated nums: 1 3 5
    for (int num : nums)
        std::cout << num << " ";
}

// ========================================================================
// Helper Class for Test 5
// ========================================================================
class Person {
    friend std::ostream &operator<<(std::ostream &os, const Person &rhs);
private:
    std::string name;
    int age;
public:
    Person(std::string name, int age) : name{name}, age{age} {};
    Person(const Person &p): name{p.name}, age{p.age} { }
    ~Person() = default;
    
     std::string get_name() const { return name; }
    void set_name(std::string name) {this->name = name; };
    int get_age() const {return age; }
    void set_age(int age) {this->age = age; }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs) {
    os << "[Person: " <<rhs.name << " : " <<rhs.age << "]";
    return os;
}

// ========================================================================
// Test 5: std::sort with Custom Lambda Predicates
// ========================================================================
/**
 * @brief Sorts elements dynamically using lambda comparison rules.
 */
void test5()
{
    std::cout << "\n\n---Test5 --------------------------" << std::endl;
    
    Person person1("Larry", 18);
    Person person2("Moe", 30);
    Person person3("Curly", 25);
    
    std::vector<Person> people {person1,person2,person3};
    
    // Sort people by name in ascending order
    // Note: Passing Person by value here triggers copy constructors. 
    // In high-performance code, use: [](const Person &lhs, const Person &rhs)
    std::sort(people.begin(), people.end(), [] (Person lhs, Person rhs) {
        return lhs.get_name() < rhs.get_name();
    });
    
    // Displays people sorted by name in ascending order
    for (Person person : people)
        std::cout << person << std::endl;
        
    std::cout << "\n";
        
    // Sort people by age in descending order (using > instead of <)
    std::sort(people.begin(), people.end(), [] (Person lhs, Person rhs) {
        return lhs.get_age() > rhs.get_age();
    });
    
    // Displays people sorted by age in descending order
    for (Person person : people)
        std::cout << person << std::endl;
}

// ========================================================================
// Test 6: std::all_of and std::iota
// ========================================================================
/**
 * @brief Tests if a specific condition holds true for ALL elements.
 * 
 * @param nums Vector of integers to test.
 * @param start_value Lower bound of the acceptable range.
 * @param end_value Upper bound of the acceptable range.
 * @return true if ALL elements are within [start_value, end_value].
 */
bool in_between(const std::vector<int> &nums, int start_value, int end_value) {
    bool result {false};
    // The lambda captures the bounding thresholds by value
    result = std::all_of(nums.begin(), nums.end(), [start_value, end_value](int value) {
        return value >= start_value && value <= end_value;
    });
    return result;
}

void test6() {
        std::cout << "\n---Test6 --------------------------" << std::endl;
        std::cout << std::boolalpha;

        std::vector<int> nums(10);
        // std::iota fills the range with sequentially increasing values starting from 1
        // (1, 2, 3, 4, 5, 6, 7, 8, 9, 10). Very useful for generating test data.
        std::iota(nums.begin(), nums.end(), 1);  
        
        for (int num : nums)
            std::cout << num << " ";
            
        std::cout << std::endl;
        
        std::cout << in_between(nums, 50, 60) << std::endl; // false
        std::cout << in_between(nums, 1, 10) << std::endl;  // true
        std::cout << in_between(nums, 5, 7) << std::endl;   // false
}

// ========================================================================
// Test 7: Nested Lambdas with std::all_of and std::none_of
// ========================================================================
/**
 * @brief Validator checking against a single restricted symbol.
 */
class Password_Validator1 {
private:
    char restricted_symbol {'$'};
public:
    bool is_valid(std::string password) {
        // [this] is captured so the lambda can access the member variable 'restricted_symbol'
        return std::all_of(password.begin(), password.end(), [this] (char character) {
            return character != restricted_symbol;
        });
    }
};

/**
 * @brief Validator checking against a dynamic vector of restricted symbols.
 * 
 * Demonstrates a powerful nested algorithm structure:
 * "For ALL characters in the password, verify that NONE OF them match any symbol in the restricted list."
 */
class Password_Validator2 {
private:
    std::vector<char> restricted_symbols {'!','$','+'};
public:
    bool is_valid(std::string password) {
        return std::all_of(password.begin(), password.end(), [this] (char character) {
            // Nested lambda!
            return std::none_of(restricted_symbols.begin(), restricted_symbols.end(), [character] (char symbol) {
                return character == symbol;
            });
        });
    }
};

void test7()
{
    std::cout << "\n---Test7 --------------------------" << std::endl;
    
    // Password_Validator1 --------------------------------------------------
    std::string password {"holywood1$"};
    Password_Validator1 pv1;
    
    // Test whether password is valid
    if (pv1.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;
        
    // Test whether new password is valid
    password = "hollywood1";
    if (pv1.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;
        
    std::cout << "\n";

    // Password_Validator2 --------------------------------------------------
    password = "C++Rocks!";
    Password_Validator2 pv2;
    
    // Test whether password is valid
    if (pv2.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;
        
    // Test whether new password is valid
    password = "CPlusPlusRocks!";
    if (pv2.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;
        
    // Test whether new password is valid
    password = "CPlusPlusRocks";
    if (pv2.is_valid(password))
        std::cout << "The password " << password << " is valid!" << std::endl;
    else
        std::cout << "The password " << password << " is not valid!" << std::endl;
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
    
    std::cout << "\n";
    return 0;
}
