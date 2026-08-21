/**
 * ============================================================================
 * FILE: integer_manipulators.cpp
 * DESCRIPTION: 
 * Demonstrates stream manipulators for integer formatting in C++.
 * Covers changing number bases (decimal, hexadecimal, octal), displaying 
 * base prefixes (0x, 0), uppercasing hex characters, and forcing positive signs.
 * ============================================================================
 */

#include <iostream>
#include <iomanip>  // Required for parameterized manipulators like resetiosflags

int main() {
    int num {255};
 
    // =========================================================
    // 1. CHANGING BASES (Stateful Manipulators)
    // =========================================================
    std::cout << "\n--- Base Formats -------------------------------------------" << std::endl;
    // std::dec is the default. Outputs base 10.
    std::cout << std::dec << num << std::endl; // Output: 255
    
    // std::hex changes the stream to base 16. Characters a-f are lowercase by default.
    std::cout << std::hex << num << std::endl; // Output: ff
    
    // std::oct changes the stream to base 8.
    std::cout << std::oct << num << std::endl; // Output: 377
    
    // =========================================================
    // 2. SHOWING BASE PREFIXES
    // =========================================================
    std::cout << "\n--- Showbase -----------------------------------------------" << std::endl;
    // std::showbase adds the appropriate mathematical prefix to the output.
    std::cout << std::showbase; 
    
    std::cout << std::dec << num << std::endl; // Output: 255  (No prefix for decimal)
    std::cout << std::hex << num << std::endl; // Output: 0xff (0x prefix for hex)
    std::cout << std::oct << num << std::endl; // Output: 0377 (0 prefix for octal)
    
    // =========================================================
    // 3. UPPERCASE FORMATTING
    // =========================================================
    std::cout << "\n--- Uppercase Hex ------------------------------------------" << std::endl;
    // std::uppercase converts hex characters (a-f) and the 'x' prefix to uppercase.
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl; // Output: 0XFF

    // =========================================================
    // 4. FORCING THE POSITIVE SIGN
    // =========================================================
    std::cout << "\n--- Showpos ------------------------------------------------" << std::endl;
    // std::showpos forces a '+' sign in front of positive numbers.
    // NOTE: This ONLY applies to base 10 (decimal) formatting!
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl; // Output: +255
    std::cout << std::hex << num << std::endl; // Output: 0XFF (No sign for hex)
    std::cout << std::oct << num << std::endl; // Output: 0377 (No sign for octal)
    
    // =========================================================
    // 5. USING STREAM METHODS (Alternative Syntax)
    // =========================================================
    // Setting flags directly on the cout object using bitmasks
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);

    // =========================================================
    // 6. RESETTING TO DEFAULTS
    // =========================================================
    // CRITICAL: To reset the base (dec/hex/oct), you must clear the 'basefield'.
    std::cout << std::resetiosflags(std::ios::basefield); 
    
    // Resetting standalone toggle flags
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);

    // =========================================================
    // 7. INTERACTIVE TESTING
    // =========================================================
    std::cout << "\n--- Interactive --------------------------------------------" << std::endl;
    std::cout << "Enter an integer : ";
    std::cin >> num; // Example input: 255
    
    std::cout << "Decimal default  : " << num << std::endl; // 255
    
    std::cout << "Hexadecimal      : " << std::hex << num << std::endl; // ff
    std::cout << "Hexadecimal      : " << std::hex << std::uppercase << num << std::endl; // FF (No base)
    
    // Note: Once uppercase is set, it stays set for future hex outputs.
    std::cout << "Hexadecimal      : " << std::hex  << num << std::endl; // FF
    
    std::cout << "Hexadecimal      : " << std::hex << std::nouppercase << num << std::endl; // ff

    std::cout << "Octal            : " << std::oct << num << std::endl; // 377
    
    std::cout << "Hexadecimal      : " << std::hex << std::showbase << num << std::endl; // 0xff
    std::cout << "Octal            : " << std::oct << num << std::endl; // 0377
    
    std::cout << std::endl << std::endl;
    return 0;
}