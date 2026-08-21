/**
 * ============================================================================
 * FILE: miles_per_gallon_function_exception.cpp
 * DESCRIPTION: 
 * Demonstrates throwing exceptions from a function. 
 * This is a crucial architectural pattern: functions should be responsible for 
 * detecting errors and throwing exceptions, while the calling code (e.g., main) 
 * is responsible for catching and handling those errors. This decouples logic.
 * ============================================================================
 */

#include <iostream>

/**
 * ============================================================================
 * FUNCTION: calculate_mpg
 * Calculates miles per gallon. 
 * Notice that this function does NOT contain a try/catch block. It only detects 
 * the error and throws an exception, delegating the handling to the caller.
 * ============================================================================
 */
double calculate_mpg(int miles, int gallons) {
    // 1. ERROR DETECTION
    if (gallons == 0)
        // 2. THROWING: Aborts this function immediately. 
        // The C++ runtime will now look up the call stack for a catch block.
        throw 0; 
        
    // Normal execution path (only reached if no exception is thrown)
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
    // EXCEPTION HANDLING (The Caller's Responsibility)
    // =========================================================
    try {
        // The try block watches over the function call.
        // If calculate_mpg throws, execution halts here and jumps to the catch block.
        miles_per_gallon = calculate_mpg(miles, gallons);
        
        // This line is skipped if an exception is thrown inside calculate_mpg.
        std::cout << "Result: " << miles_per_gallon << std::endl;
    }
    catch (int &ex) {
        // 3. ERROR HANDLING
        // Catches the integer thrown by calculate_mpg.
        std::cerr << "Tried to divide by zero" << std::endl;
    }
    
    std::cout << "Bye" << std::endl;

    return 0;
}