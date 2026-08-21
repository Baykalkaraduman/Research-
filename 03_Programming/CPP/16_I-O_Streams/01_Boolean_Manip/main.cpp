/**
 * ============================================================================
 * FILE: boolean_manipulators.cpp
 * DESCRIPTION: 
 * Demonstrates the use of I/O stream manipulators for boolean values.
 * By default, C++ outputs booleans as integers (1 for true, 0 for false). 
 * Stream manipulators allow us to change this formatting state for streams 
 * like std::cout or std::ofstream (for file I/O).
 * ============================================================================
 */

#include <iostream>
#include <iomanip>  // CRITICAL: Must include for parameterized manipulators like resetiosflags

int main() {
    
    // =========================================================
    // 1. DEFAULT BOOLEAN OUTPUT (0 / 1)
    // =========================================================
    // By default, C++ streams output boolean expressions as integers.
    std::cout << "noboolalpha - default  (10 == 10) : " << (10 == 10)  << std::endl; // Outputs 1
    std::cout << "noboolalpha - default  (10 == 20) : " << (10 == 20)  << std::endl; // Outputs 0
    
    // =========================================================
    // 2. USING INLINE MANIPULATORS (Stateful change)
    // =========================================================
    // Set to true/false text formatting using std::boolalpha
    std::cout << std::boolalpha;    
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl; // Outputs true
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl; // Outputs false
    
    // IMPORTANT: Manipulators are STATEFUL. 
    // The setting persists for all future boolean insertions on this specific stream
    // until it is explicitly changed back.
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;
    
    // Toggle back to 0/1 integer formatting using std::noboolalpha
    std::cout << std::noboolalpha;
    std::cout << "noboolalpha  (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "noboolalpha  (10 == 20) : " << (10 == 20)  << std::endl;
    
    // =========================================================
    // 3. USING STREAM METHODS (Alternative syntax)
    // =========================================================
    // We can also set formatting flags using the stream's .setf() method
    std::cout.setf(std::ios::boolalpha); // It might seen weird but it is libary::class::flag
    std::cout << "boolalpha   (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "boolalpha   (10 == 20) : " << (10 == 20)  << std::endl;
    
    // =========================================================
    // 4. RESETTING FLAGS VIA IOMANIP
    // =========================================================
    // resetiosflags removes specific flags. Removing boolalpha reverts 
    // the stream back to its default (0 / 1) state.
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "Default  (10 == 10) : " << (10 == 10)  << std::endl;
    std::cout << "Default  (10 == 20) : " << (10 == 20)  << std::endl;
    
    return 0;
}