/**
 * ============================================================================
 * FILE: miles_per_gallon_exceptions.cpp
 * DESCRIPTION: 
 * Demonstrates basic Exception Handling in C++.
 * Exception handling cleanly separates the "Happy Path" (try block) from the 
 * "Error Handling Path" (catch block). If a critical error occurs, the program 
 * "throws" an exception, which instantly halts normal execution and jumps to 
 * the nearest matching "catch" block.
 * ============================================================================
 */

#include <iostream>

int main() {    
    int miles {};
    int gallons {};
    double miles_per_gallon {};
    
    std::cout << "Enter the miles driven: ";
    std::cin >> miles;
    std::cout << "Enter the gallons used: ";
    std::cin >> gallons;
    
    // =========================================================
    // EXCEPTION HANDLING (try - throw - catch)
    // =========================================================
    
    // 1. TRY BLOCK: This is the "Happy Path". 
    // We attempt to execute the logic assuming everything will go right.
    try {
        if (gallons == 0)
            // 2. THROW: If a fatal error condition is met, we abort the try block.
            // Throwing an integer (0) here. (Note: Throwing primitives is okay 
            // for learning, but standard objects are preferred in production).
            throw 0; 
            
        // If gallons == 0, the program NEVER reaches this line.
        // It immediately jumps to the catch block.
        miles_per_gallon = static_cast<double>(miles) / gallons;
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    // 3. CATCH BLOCK: The "Error Handler".
    // Catches the integer thrown above. Always catch by reference (&) to avoid copies!
    catch (int &ex) {
        std::cerr << "Sorry, you can't divide by zero" << std::endl;
    }
    
    std::cout << "Bye" << std::endl;
    return 0;
}