/**
 * ============================================================================
 * FILE: miles_per_gallon_multiple_exceptions.cpp
 * DESCRIPTION: 
 * Demonstrates how to throw and catch multiple types of exceptions.
 * A single function can have multiple failure states. By throwing different 
 * data types (e.g., int, std::string, or custom classes), the caller can 
 * implement specific catch blocks to handle each unique failure appropriately.
 * ============================================================================
 */

#include <iostream>
#include <string>

/**
 * ============================================================================
 * FUNCTION: calculate_mpg
 * Contains multiple error conditions. It throws different types based on 
 * the specific error encountered.
 * ============================================================================
 */
double calculate_mpg(int miles, int gallons) {
    // 1. Error Condition: Division by zero
    // Throws an integer type.
    if (gallons == 0)
        throw 0; 
        
    // 2. Error Condition: Negative inputs (physically impossible for this context)
    // Throws a std::string type. 
    // (Note: In production code, using standard exception classes is preferred).
    if (miles < 0 || gallons < 0)
        throw std::string{"Negative value error"};
        
    // Normal execution path
    return static_cast<double>(miles) / gallons;
}

int main() {    
    int miles {};
    int gallons {};
    double miles_per_gallon {};   
    
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    // =========================================================
    // MULTIPLE EXCEPTION HANDLING
    // =========================================================
    try {
        // The try block executes. If any throw occurs inside calculate_mpg,
        // it instantly halts and jumps to the matching catch block below.
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    // CATCH BLOCK 1: Handles integer exceptions
    catch (int &ex) {
        std::cerr << "Tried to divide by zero" << std::endl;
    }
    // CATCH BLOCK 2: Handles std::string exceptions
    catch (std::string &ex) {
        std::cerr << ex << std::endl;
    }
    // NOTE: C++ evaluates catch blocks sequentially from top to bottom.
    // It executes the FIRST block that matches the thrown type.
    
    std::cout << "Bye" << std::endl;

    return 0;
}