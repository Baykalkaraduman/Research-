/**
 * @file unscoped_enumerations_demo.cpp
 * @brief Demonstration of Unscoped Enumerations (C-style enums) in C++.
 * 
 * In computational science and embedded engineering, enumerations are critical 
 * for defining Finite State Machines (FSMs), hardware register flags, and 
 * simulation phases. 
 * 
 * @warning Unscoped enums leak their enumerator names into the surrounding scope 
 * (causing namespace pollution) and implicitly convert to integers, which can 
 * lead to severe type-safety bugs. Modern C++ generally prefers 'enum class'.
 */

#include <iostream>
#include <vector>
#include <string>

// ========================================================================
// Test 1: Basic Enumerations and Scope Leakage
// ========================================================================

/**
 * @brief Simple unscoped enumeration for spatial directions.
 * 
 * Notice that 'North', 'South', etc., leak into the global scope.
 * If we uncomment the 'Street' enum below, the compiler will throw a redefinition 
 * error because 'North' is already defined in the same scope.
 */
enum Direction {North = 1, South = 10, East, West };
// enum Street {Main, North, Elm};   // ERROR: 'North' is already declared!

/**
 * @brief Converts a Direction enum to its string representation.
 * 
 * @note In logging and UI/UX for simulations, we constantly need to translate 
 * raw enum states back to human-readable strings.
 */
std::string direction_to_string(Direction direction) {
    std::string result;
    switch (direction) {
        case North:
            result = "North";
            break;
        case South:
            result = "South";
            break;
        case East:
            result = "East";
            break;
        case West:
            result = "West";
            break;
        default:
            result = "Unknown direction";
    }
    return result;
}

void test1() {
    std::cout << "\n--- Test1 --------------------------\n" << std::endl;

    Direction direction {North};
    std::cout << "\nDirection " << direction << std::endl; // Displays the underlying int (1)
    std::cout << direction_to_string(direction) << std::endl;
    
    direction = West;
    std::cout << "\nDirection " << direction << std::endl; // Displays the underlying int (12)
    std::cout << direction_to_string(direction) << std::endl;
    
    // direction = 5;  // Compiler Error: Cannot implicitly convert int to Direction.
    
    // EXTREME DANGER: C-style cast or static_cast allows you to force an integer 
    // into an enum, EVEN IF the integer does not map to a valid enumerator!
    // In physics simulations, this can lead to undefined behavior (e.g., trying 
    // to access a non-existent detector state).
    direction = Direction(100);
    std::cout << "\nDirection " << direction << std::endl;  // Displays 100! (Invalid state)
    std::cout << direction_to_string(direction) << std::endl; // Displays "Unknown direction"

    direction = static_cast<Direction>(100);
    std::cout << "\nDirection " << direction << std::endl;  // Displays 100!
    std::cout << direction_to_string(direction) << std::endl;
}

// ========================================================================
// Test 2: Overloading Operators and State Validation
// ========================================================================

enum Grocery_Item {Milk, Bread, Apple, Orange};

/**
 * @brief Stream insertion overload for Grocery_Item.
 * 
 * Allows direct printing of enum values using std::cout.
 */
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)
{
    switch (grocery_item) {
        case Milk:      os << "Milk";   break;
        case Bread:     os << "Bread";  break;
        case Apple:     os << "Apple";  break;
        case Orange:    os << "Orange"; break;
        default:        os << "Invalid item"; 
    }
    return os;
}

/**
 * @brief Validates if the underlying integer corresponds to a real enumerator.
 * 
 * @note This pattern is crucial when reading enum states from raw data streams 
 * (like binary files or network packets) where data corruption might occur.
 */
bool is_valid_grocery_item(Grocery_Item grocery_item)
{
    switch (grocery_item) {
        case Milk:  
        case Bread:
        case Apple:
        case Orange:
            return true;
        default:        
            return false; 
    }
}

/**
 * @brief Processes a list of items and categorizes them by validity.
 */
void display_grocery_list(const std::vector<Grocery_Item> &grocery_list)
{
    std::cout << "Grocery List" << "\n==============================" << std::endl;
    int invalid_item_count{0};
    int valid_item_count {0};
    
    for (Grocery_Item grocery_item : grocery_list)
    {
        std::cout << grocery_item << std::endl;  // Uses the overloaded operator<<
        
        // Filter logical errors
        if (is_valid_grocery_item(grocery_item))
            valid_item_count++;
        else
            invalid_item_count++;
    }
    
    std::cout << "==============================" << std::endl;
    std::cout << "Valid items: " <<  valid_item_count << std::endl;
    std::cout << "Invalid items: " <<  invalid_item_count << std::endl;
    std::cout << "Total items: " <<  valid_item_count + invalid_item_count << std::endl;
}

void test2() {
    std::cout << "\n--- Test2 --------------------------\n" << std::endl;
    
    std::vector<Grocery_Item> shopping_list;
    
    shopping_list.push_back(Apple);
    shopping_list.push_back(Apple);
    shopping_list.push_back(Milk);
    shopping_list.push_back(Orange);
    
    // Grocery_Item item = 100; // Compiler error
    
    int Helicopter {1000};
    
    // Bypassing type safety! 
    shopping_list.push_back(Grocery_Item(Helicopter));  // Pushes 1000 (Invalid)
    shopping_list.push_back(Grocery_Item(0));           // Pushes 0, which maps to Milk!
    
    display_grocery_list(shopping_list);
}

// ========================================================================
// Test 3: Finite State Machines (Rocket Launch Simulation)
// ========================================================================

/**
 * @brief FSM States for a rocket launch system.
 */
enum State {Engine_Failure, Inclement_Weather, Nominal, Unknown};

/**
 * @brief FSM Commands/Sequences to execute.
 */
enum Sequence{Abort, Hold, Launch};

/**
 * @brief Stream extraction overload to read raw user/sensor input into a State.
 * 
 * @note std::underlying_type_t<State> dynamically deduces the integer type 
 * used by the enum (usually 'int'). This is excellent for cross-platform 
 * compatibility when interfacing with hardware.
 */
std::istream &operator>>(std::istream &is, State &state) 
{
    std::underlying_type_t<State> user_input;
    is >> user_input;
    
    switch (user_input) {
        case Engine_Failure:       
        case Inclement_Weather:
        case Nominal:
        case Unknown:
            state = State(user_input);
            break;
        default:                   
            std::cout << "User input is not a valid launch state." << std::endl;
            state = Unknown; // Fail-safe default
    }
    
    return is;
}

/**
 * @brief Stream insertion overload for Sequence.
 */
std::ostream &operator<<(std::ostream &os, const Sequence &sequence)
{
    switch (sequence) {
        case Abort:     os << "Abort";  break;
        case Hold:      os << "Hold";   break;
        case Launch:    os << "Launch"; break;
    }
    return os;
}

/**
 * @brief Triggers the hardware/system sequence based on the FSM evaluation.
 */
void initiate(Sequence sequence)
{
    std::cout << "Initiate " << sequence << " sequence!" << std::endl; 
}

/**
 * @brief Master control function for the Rocket FSM.
 */
void test3() {
    std::cout << "\n--- Test3 --------------------------\n" << std::endl;
    
    State state;
    std::cout << "Launch state: ";
    // Expected inputs: 0 (Failure), 1 (Weather), 2 (Nominal), 3 (Unknown)
    std::cin >> state;               
    
    // Evaluate current state and transition to a sequence command
    switch (state) {
        case Engine_Failure:        // Fallthrough logic
        case Unknown:               
            initiate(Abort); 
            break;
        case Inclement_Weather:  
            initiate(Hold); 
            break;
        case Nominal:              
            initiate(Launch); 
            break;
    }    
}

int main()
{
//  test1();
//  test2();
    test3();
    
    std::cout << "\n";
    return 0;
}
