/**
 * @file scoped_enumerations_demo.cpp
 * @brief Demonstration of Scoped Enumerations (enum class) in modern C++.
 * 
 * In robust computational science and software engineering, 'enum class' is 
 * strictly preferred over traditional C-style enums. 
 * 
 * Key Advantages:
 * 1. Type Safety: They do NOT implicitly convert to integers.
 * 2. Scope Containment: Enumerators are kept strictly inside the enum's scope, 
 *    preventing global namespace pollution (e.g., you must use Grocery_Item::Milk 
 *    instead of just Milk).
 */

#include <iostream>
#include <vector>

// ========================================================================
// Test 1: Basic Scoped Enumerations and Type Safety
// ========================================================================

/**
 * @brief Scoped enumeration holding the items for a grocery list.
 * 
 * The values of the enumerators could represent item codes in a database.
 * Because it's an 'enum class', these names (Milk, Bread) will not clash 
 * with other variables named Milk or Bread in the global scope.
 */
enum class Grocery_Item {Milk=350, Bread=250, Apple=132, Orange=100};

/**
 * @brief Overloaded stream insertion operator for Grocery_Item.
 * 
 * Inserts the string representation and the underlying integer value 
 * to the output stream.
 */
std::ostream &operator<<(std::ostream &os, Grocery_Item grocery_item)
{
    // std::underlying_type_t dynamically deduces the integer type used by the enum class 
    // (default is int). Because scoped enums don't implicitly convert to ints, 
    // we MUST explicitly cast it using this deduced type to print the numeric code.
    std::underlying_type_t<Grocery_Item> value = std::underlying_type_t<Grocery_Item>(grocery_item);
    
    switch (grocery_item) {
        case Grocery_Item::Milk:      
            os << "Milk";
            break;
        case Grocery_Item::Bread:
            os << "Bread";
            break;
        case Grocery_Item::Apple:     
            os << "Apple";
            break;
        case Grocery_Item::Orange:    
            os << "Orange";
            break;
        default:        
            os << "Invalid item";
    }
    os << " : " << value;
    return os;
}

/**
 * @brief Validates whether a provided Grocery_Item corresponds to a valid enumerator.
 * 
 * @note This acts as a safeguard against bad explicit casts (e.g., casting 
 * an arbitrary integer into a Grocery_Item).
 */
bool is_valid_grocery_item(Grocery_Item grocery_item)
{
    switch (grocery_item) {
        case Grocery_Item::Milk:  
        case Grocery_Item::Bread:
        case Grocery_Item::Apple:
        case Grocery_Item::Orange:
            return true;
        default:        
            return false; 
    }
}

/**
 * @brief Iterates through a vector of items, validates them, and displays results.
 */
void display_grocery_list(const std::vector<Grocery_Item> &grocery_list)
{
    std::cout << "Grocery List" << "\n==============================" << std::endl;
    int invalid_item_count{0};
    int valid_item_count {0};
    
    for (Grocery_Item grocery_item : grocery_list)
    {
        std::cout << grocery_item << std::endl;  // Uses the overloaded operator<<
        
        // Check if the memory actually holds a valid item code
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

/**
 * @brief Tests type safety and scoping of enum class.
 */
void test1() {
    std::cout << "\n--- Test1 --------------------------\n" << std::endl;
    
    std::vector<Grocery_Item> shopping_list;
    
    // Notice the scope resolution operator (::). 
    // We can no longer just say 'Apple'.
    shopping_list.push_back(Grocery_Item::Apple);
    shopping_list.push_back(Grocery_Item::Milk);
    shopping_list.push_back(Grocery_Item::Orange);
    
    int Helicopter {1000};
    // shopping_list.push_back(Helicopter); // COMPILER ERROR: Type Safety in action!
    
    // Explicit casting is still possible, but dangerous. The compiler trusts you.
    shopping_list.push_back(Grocery_Item(Helicopter));  // Invalid item (1000)
    shopping_list.push_back(Grocery_Item(350));         // Will add Milk again!
    
    display_grocery_list(shopping_list);
}

// ========================================================================
// Test 2: Enums Embedded Inside Classes
// ========================================================================

/**
 * @brief A class modeling an entity (e.g., a simulation object or game player).
 * 
 * Embedding 'enum class' inside a standard class provides incredible encapsulation.
 * It strictly binds the state options to the object they belong to.
 */
class Player {
    friend std::ostream &operator<<(std::ostream &os, const Player &p);
public:
    // These states belong STRICTLY to the Player class.
    enum class Mode {Attack, Defense, Idle};
    enum class Direction {North, South, East, West};
    
    // Constructor with default arguments
    Player(std::string name, Mode mode = Mode::Idle, Direction direction = Direction::North):
        name{name}, mode{mode}, direction{direction} {}

    // Getters and Setters
    std::string get_name() const {
        return name;
    }
    void set_name(std::string name) {
        this->name = name;
    }
    
    Mode get_mode() const {return mode; }
    void set_mode(Mode mode) {
        this->mode = mode;
    }

    Direction get_direction() const {return direction; }
    void set_direction(Direction direction) {
        this->direction = direction;
    }
private:
    std::string name;
    Mode mode;
    Direction direction;
};

/**
 * @brief Converts the Player::Mode enum to a string.
 */
std::string get_player_mode(Player::Mode mode) {
    std::string result;
    // Notice the double scoping: ClassScope::EnumScope::Enumerator
    switch (mode) {
        case Player::Mode::Attack:
            result = "Attack"; 
            break;
        case Player::Mode::Defense:
            result = "Defense";
            break;
        case Player::Mode::Idle:
            result = "Idle";
            break;
    };
    return result;
}

/**
 * @brief Converts the Player::Direction enum to a string.
 */
std::string get_player_direction(Player::Direction direction) {
    std::string result;
     switch (direction) {
        case Player::Direction::North:
            result = "North"; 
            break;
        case Player::Direction::South:
            result = "South"; 
            break;
        case Player::Direction::East:
            result = "East"; 
            break;
        case Player::Direction::West:
            result = "West"; 
            break;
    };
    return result;
}

/**
 * @brief Overloads the output stream insertion operator for the Player class.
 */
std::ostream &operator<<(std::ostream &os, const Player &p) {
    os << "Player name:      " << p.get_name() << "\n"
       << "Player mode:      " << get_player_mode(p.mode) << "\n"
       << "Player direction: " << get_player_direction(p.direction) 
       << std::endl;
    return os;
}

/**
 * @brief Demonstrates object creation with heavily scoped enums.
 */
void test2() {
       std::cout << "\n--- Test2 --------------------------\n" << std::endl;

    // The explicit syntax (Player::Mode::Attack) guarantees there is absolutely 
    // zero ambiguity about what this state represents.
    Player p1{"Cloud Strife", Player::Mode::Attack, Player::Direction::North};
    Player p2{"Tifa Lockhart", Player::Mode::Defense, Player::Direction::West};
    Player p3{"Sephiroth", Player::Mode::Idle, Player::Direction::South};

    std::cout << p1 << std::endl; 
    std::cout << p2 << std::endl; 
    std::cout << p3 << std::endl;
}

int main()
{
    test1();
    test2();
    std::cout << "\n";
    return 0;
}
