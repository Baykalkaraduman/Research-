/**
 * ============================================================================
 * FILE: user_defined_exceptions.cpp
 * DESCRIPTION: 
 * Demonstrates the use of User-Defined Exception Classes.
 * Instead of throwing primitive types like int or std::string, we define custom 
 * classes. Even if these classes are completely empty, their unique TYPE identity 
 * allows the compiler to route the error to the correct, highly specific catch block.
 * ============================================================================
 */

#include <iostream>

/**
 * ============================================================================
 * EXCEPTION CLASSES
 * These are simple, empty classes. Their sole purpose in this basic example 
 * is to provide a unique type for the catch blocks to identify.
 * Note: In production code, these would typically inherit from std::exception.
 * ============================================================================
 */
class DivideByZeroException {
    // Empty class - used purely for its type name
};

class NegativeValueException {
    // Empty class - used purely for its type name
};

/**
 * ============================================================================
 * FUNCTION: calculate_mpg
 * Evaluates conditions and throws instances of our custom exception classes.
 * ============================================================================
 */
double calculate_mpg(int miles, int gallons) {
    if (gallons == 0)
        // Throwing an anonymous object of type DivideByZeroException by value.
        throw DivideByZeroException();
        
    if (miles < 0 || gallons < 0) 
        // Throwing an anonymous object of type NegativeValueException by value.
        throw NegativeValueException();
            
    // Normal execution path
    return static_cast<double>(miles) / gallons;
}

int main() {    
    int miles {};
    int gallons {};
    double miles_per_gallon {};
    
    std::cout << "Enter the miles driven: ";
    std::cin >> miles;
    std::cout << "Enter the gallons used: ";
    std::cin >> gallons;
    
    // =========================================================
    // EXCEPTION HANDLING WITH CUSTOM CLASSES
    // =========================================================
    try {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    // Catching the custom exception by CONST REFERENCE.
    // This is the absolute best practice to avoid object slicing and unnecessary copies.
    catch (const DivideByZeroException &ex) {
        std::cerr << "Sorry, you can't divide by zero" << std::endl;
    }
    // Catching the second custom exception by CONST REFERENCE.
    catch (const NegativeValueException &ex) {    
        std::cerr << "Sorry, one of your parameters is negative" << std::endl;
    }
    
    std::cout << "Bye" << std::endl;
    return 0;
}