/**
 * ============================================================================
 * FILE: miles_per_gallon_no_exceptions.cpp
 * DESCRIPTION: 
 * Demonstrates traditional error handling using standard control flow (if-else).
 * While this works for simple scripts, in large applications, mixing error 
 * checking logic with the main business logic makes the code hard to read 
 * and maintain.
 * ============================================================================
 */

#include <iostream>

int main() {    
    int miles {};
    int gallons {};
    double miles_per_gallon {};   
 
    std::cout << "Enter the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    
    // =========================================================
    // TRADITIONAL ERROR CHECKING
    // =========================================================
    // The "happy path" (successful execution) and the error handling 
    // are tangled together in the same control structure.
    if (gallons != 0) {
        // Safe to divide
        miles_per_gallon = static_cast<double>(miles) / gallons;
        std::cout << "Result: " << miles_per_gallon << std::endl;
    } else {
        // Error state: Manual check triggered
        std::cerr << "Sorry, can't divide by zero" << std::endl;
    }

    std::cout << "Bye" << std::endl;
    return 0;
}