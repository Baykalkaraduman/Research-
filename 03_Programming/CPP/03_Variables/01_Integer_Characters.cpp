#include <iostream>

int main()
{
    // --------------------------------------------------
    // Character Data Type
    // --------------------------------------------------
    //
    // char stores a single character.
    //
    // Characters are written using
    // single quotation marks.
    //
    // Example:
    //
    // 'A'
    //
    // Internally every character is stored
    // as an integer according to the ASCII table.

    char character {'A'};

    std::cout << "ASCII character : "
              << character
              << std::endl;

    character++;

    std::cout << "Next character : "
              << character
              << std::endl;

    std::cout << std::endl;

    // --------------------------------------------------
    // Integer Data Types
    // --------------------------------------------------

    int integer {-5};

    unsigned int speed_of_light
    {
        300'000'000
    };

    std::cout << "Integer : "
              << integer
              << std::endl;

    std::cout << "Speed of light : "
              << speed_of_light
              << " m/s"
              << std::endl;

    std::cout << std::endl;

    unsigned short minutes_per_day {1440};

    std::cout << "Minutes per day : "
              << minutes_per_day
              << std::endl;

    long seconds_per_day {86400};

    std::cout << "Seconds per day : "
              << seconds_per_day
              << std::endl;

    std::cout << std::endl;

    long long fictional_planet_age
    {
        4'543'000'000
    };

    std::cout << fictional_planet_age
              << std::endl;

    std::cout << std::endl;

    // --------------------------------------------------
    // Overflow Example
    // --------------------------------------------------
    //
    // The result of multiplication may exceed
    // the storage capacity of short.
    //
    // This phenomenon is called overflow.

    short value1 {30000};
    short value2 {1000};

    short overflow_result
    {
        static_cast<short>(value1 * value2)
    };

    long correct_result
    {
        static_cast<long>(value1) * value2
    };

    std::cout << "Overflow result : "
              << overflow_result
              << std::endl;

    std::cout << "Correct result  : "
              << correct_result
              << std::endl;

    return 0;
}