/**
 * ============================================================================
 * FILE: stream_field_manipulators.cpp
 * DESCRIPTION: 
 * Demonstrates stream manipulators for field width, justification, and fill characters.
 * Crucial concept: While justification (left/right) and setfill are STATEFUL 
 * (they stay active until changed), setw() is NON-STATEFUL. It only applies 
 * to the very next data item inserted into the stream.
 * ============================================================================
 */

#include <iostream>
#include <iomanip>  // CRITICAL: Required for setw() and setfill()

/**
 * ============================================================================
 * FUNCTION: ruler
 * A simple visual aid to help count character spaces in the console output.
 * ============================================================================
 */
void ruler() {
    std::cout << "\n12345678901234567890123456789012345678901234567890" << std::endl;
}

int main() {
    int num1 { 1234 };
    double num2 {1234.5678};
    std::string hello  {"Hello"};
    
    // =========================================================
    // 1. DEFAULTS (No formatting)
    // =========================================================
    std::cout << "\n--Defaults -------------------------------------------------------------------" << std::endl;
    ruler();
    // Everything is squished together.
    std::cout << num1 
              << num2 
              << hello 
              << std::endl;
    
    // Defaults - one per line
    std::cout << "\n--Defaults - one per line-----------------------------------------------------" << std::endl;
    ruler();
    std::cout << num1 <<std::endl;
    std::cout << num2 << std::endl;
    std::cout << hello << std::endl;
    
    // =========================================================
    // 2. FIELD WIDTH (setw) - Non-Stateful!
    // =========================================================
    // Set field width to 10. 
    // IMPORTANT: setw(10) ONLY applies to num1! 
    // num2 and hello revert to default width (0). Default justification is RIGHT.
    std::cout << "\n--width 10 for num1-----------------------------------------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10)  << num1 
              << num2           
              << hello 
              << std::endl;
    // Output: [      1234]1234.5678Hello
    
    // Set field width to 10 for the first 2 outputs.
    // We MUST call setw() again for num2.
    std::cout << "\n--width 10 for num1 and num2------------------------------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << num1 
              << std::setw(10) << num2  
              << hello 
              << std::endl;
    // Output: [      1234][ 1234.5678]Hello
                  
    // Set field width to 10 for all 3 outputs.
    // We must call setw(10) three separate times.
    std::cout << "\n--width 10 for num1 and num2 and hello--------------------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << num1 
              << std::setw(10) << num2  
              << std::setw(10) << hello 
              << std::endl;
    // Output: [      1234][ 1234.5678][     Hello]
                  
    // =========================================================
    // 3. JUSTIFICATION (std::left / std::right) - Stateful!
    // =========================================================
    // Set field width to 10 for all 3 outputs and justify all left.
    // Notice that std::left is stateful; once set, it applies to num2 and hello automatically.
    // However, the author explicitly wrote std::left multiple times here for clarity.
    std::cout << "\n--width 10 for num1 and num2 and hello left for all---------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << std::left << num1 
              << std::setw(10) << std::left << num2  
              << std::setw(10) << std::left << hello 
              << std::endl;
    // Output: [1234      ][1234.5678 ][Hello     ]
                  
    // =========================================================
    // 4. FILL CHARACTERS (std::setfill) - Stateful!
    // =========================================================
    // setfill changes the default blank space (' ') to a dash ('-').
    // This is PERSISTENT (Stateful) for all future setw() calls on this stream.
    std::cout << std::setfill('-');
    std::cout << "\n--width 10 for num1 and num2 and hello left for all setfill to dash------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << std::left << num1 
              << std::setw(10) << std::left << num2  
              << std::setw(10) << std::left << hello 
              << std::endl;
    // Output: [1234------][1234.5678-][Hello-----]
    
    // Set width to 10 for all, left justify all, and vary the setfill character.
    // Because setfill is stateful, changing it dynamically overrides the previous fill.
    std::cout << "\n--width 10 for num1 and num2 and hello - setfill varies------------------------" << std::endl;
    ruler(); 
    std::cout << std::setw(10) << std::left << std::setfill('*') << num1 
              << std::setw(10) << std::left << std::setfill('#') << num2  
              << std::setw(10) << std::left << std::setfill('-') << hello 
              << std::endl;
    // Output: [1234******][1234.5678#][Hello-----]
    
    std::cout << std::endl << std::endl;
    return 0;
}