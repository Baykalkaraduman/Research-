#include <iostream>

int main()
{
    // --------------------------------------------------
    // Floating Point Data Types
    // --------------------------------------------------
    //
    // float        -> about 7 decimal digits
    // double       -> about 15 decimal digits
    // long double  -> highest precision
    //
    // Scientific computing usually relies on
    // double because it provides a good balance
    // between precision and memory usage.

    float gpa {3.11f};

    std::cout << "Current GPA : "
              << gpa
              << std::endl;

    std::cout << std::endl;

    double a {2.217812345};
    double b {5.5400010000};

    std::cout << "double × double = "
              << a * b
              << std::endl;

    float c {5.540001f};

    std::cout << "double × float = "
              << a * c
              << std::endl;

    std::cout << std::endl;

    long double x {2.21781234500000000001L};
    long double y {5.540001000000001258L};

    std::cout << "long double × long double = "
              << x * y
              << std::endl;

    std::cout << std::endl;

    // Scientific constants

    float simple_pi {3.14f};

    double pi {3.141592653589793};

    long double precise_pi
    {
        3.141592653589793238462643383279L
    };

    long double planck_constant
    {
        6.62607015e-34L
    };

    std::cout << "float        : "
              << simple_pi
              << std::endl;

    std::cout << "double       : "
              << pi
              << std::endl;

    std::cout << "long double  : "
              << precise_pi
              << std::endl;

    std::cout << "Planck Constant : "
              << planck_constant
              << std::endl;

    return 0;
}