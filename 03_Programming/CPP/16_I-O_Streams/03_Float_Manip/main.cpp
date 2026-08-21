/**
 * ============================================================================
 * FILE: floating_point_manipulators.cpp
 * DESCRIPTION: 
 * Demonstrates stream manipulators for floating-point formatting in C++.
 * Covers precision setting, fixed vs. scientific notation, forcing decimal 
 * points (showpoint), and forcing positive signs (showpos).
 * ============================================================================
 */

#include <iostream>
#include <iomanip>  // CRITICAL: Required for std::setprecision

int main() {
    // Note: A standard 'double' can hold roughly 15-17 decimal digits of precision.
    double num1 {123456789.987654321};
    double num2 {1234.5678};                     
    double num3 {1234.0};                          
 
    // =========================================================
    // 1. DEFAULT SETTINGS
    // =========================================================
    // Default precision is 6 SIGNIFICANT digits (total digits, not just after decimal).
    // Trailing zeros are removed by default.
    std::cout << "--Defaults ----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: 1.23457e+08 (Forces scientific to fit in 6 digits)
    std::cout << num2 << std::endl;    // Outputs: 1234.57 (Rounded to 6 significant digits)
    std::cout << num3 << std::endl;    // Outputs: 1234 (Trailing .0 is dropped)
    
    // =========================================================
    // 2. CHANGING PRECISION (Default Mode = Significant Digits)
    // =========================================================
    std::cout << std::setprecision(2);
    std::cout << "--Precision 2----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: 1.2e+08
    std::cout << num2 << std::endl;    // Outputs: 1.2e+03
    std::cout << num3 << std::endl;    // Outputs: 1.2e+03
    
    std::cout << std::setprecision(5);
    std::cout << "--Precision 5----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: 1.2346e+08
    std::cout << num2 << std::endl;    // Outputs: 1234.6
    std::cout << num3 << std::endl;    // Outputs: 1234

    std::cout << std::setprecision(9);
    std::cout << "--Precision 9----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: 123456790 (Rounded to 9 digits)
    std::cout << num2 << std::endl;    // Outputs: 1234.5678
    std::cout << num3 << std::endl;    // Outputs: 1234

    // =========================================================
    // 3. FIXED NOTATION
    // =========================================================
    // CRITICAL DIFFERENCE: Once 'fixed' or 'scientific' is set, setprecision() 
    // now dictates the number of digits AFTER the decimal point, NOT total digits!
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << "--Precision 3 - fixed ----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: 123456789.988
    std::cout << num2 << std::endl;    // Outputs: 1234.568
    std::cout << num3 << std::endl;    // Outputs: 1234.000 (Forces trailing zeros!)
    
    // =========================================================
    // 4. SCIENTIFIC NOTATION
    // =========================================================
    std::cout << std::setprecision(3) << std::scientific;
    std::cout << "--Precision 3 - scientific  ----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: 1.235e+08
    std::cout << num2 << std::endl;    // Outputs: 1.235e+03
    std::cout << num3 << std::endl;    // Outputs: 1.234e+03
    
    // Uppercase changes 'e' to 'E' in scientific notation
    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << "--Precision 3 - scientific - uppercase  ----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: 1.235E+08
    std::cout << num2 << std::endl;    // Outputs: 1.235E+03
    std::cout << num3 << std::endl;    // Outputs: 1.234E+03
    
    // =========================================================
    // 5. SHOW POSITIVE SIGN
    // =========================================================
    std::cout << std::setprecision(3) << std::fixed << std::showpos;
    std::cout << "--Precision 3 - fixed - showpos ----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: +123456789.988
    std::cout << num2 << std::endl;    // Outputs: +1234.568
    std::cout << num3 << std::endl;    // Outputs: +1234.000
    
    // =========================================================
    // 6. CLEARING FLAGS AND SHOWPOINT
    // =========================================================
    // Removing fixed and scientific formatting simultaneously
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::resetiosflags(std::ios::showpos);
    
    // std::showpoint forces the decimal point to print, even if the fractional part is zero.
    // Reverted to default mode, so precision 10 means 10 TOTAL significant digits.
    std::cout << std::setprecision(10) << std::showpoint;
    std::cout << "-- precision 10 - showpoint ----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: 123456790.0
    std::cout << num2 << std::endl;    // Outputs: 1234.567800
    std::cout << num3 << std::endl;    // Outputs: 1234.000000

    // =========================================================
    // 7. COMPLETE RESET TO DEFAULTS
    // =========================================================
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::setprecision(6);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::showpoint);

    std::cout << "--Back to defaults----------------------------" << std::endl;
    std::cout << num1 << std::endl;    // Outputs: 1.23457e+08
    std::cout << num2 << std::endl;    // Outputs: 1234.57
    std::cout << num3 << std::endl;    // Outputs: 1234
    
    return 0;
}