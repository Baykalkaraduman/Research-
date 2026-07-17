#include <iostream>
#include <climits>      // Defines the minimum and maximum values
                        // for integer data types.

int main()
{
    // --------------------------------------------------
    // sizeof Operator
    // --------------------------------------------------
    //
    // The sizeof operator returns the number of bytes
    // occupied by a data type or a variable.
    //
    // Syntax:
    //
    // sizeof(type)
    // sizeof(variable)

    std::cout << "========== SIZE OF DATA TYPES ==========\n\n";

    std::cout << "char          : " << sizeof(char) << " bytes\n";
    std::cout << "short         : " << sizeof(short) << " bytes\n";
    std::cout << "int           : " << sizeof(int) << " bytes\n";
    std::cout << "unsigned int  : " << sizeof(unsigned int) << " bytes\n";
    std::cout << "long          : " << sizeof(long) << " bytes\n";
    std::cout << "long long     : " << sizeof(long long) << " bytes\n";

    std::cout << "\n";

    std::cout << "float         : " << sizeof(float) << " bytes\n";
    std::cout << "double        : " << sizeof(double) << " bytes\n";
    std::cout << "long double   : " << sizeof(long double) << " bytes\n";

    std::cout << "\n";

    // --------------------------------------------------
    // Integer Limits
    // --------------------------------------------------

    std::cout << "========== MINIMUM VALUES ==========\n\n";

    std::cout << "char       : " << CHAR_MIN << '\n';
    std::cout << "short      : " << SHRT_MIN << '\n';
    std::cout << "int        : " << INT_MIN << '\n';
    std::cout << "long       : " << LONG_MIN << '\n';
    std::cout << "long long  : " << LLONG_MIN << '\n';

    std::cout << "\n";

    std::cout << "========== MAXIMUM VALUES ==========\n\n";

    std::cout << "char       : " << CHAR_MAX << '\n';
    std::cout << "short      : " << SHRT_MAX << '\n';
    std::cout << "int        : " << INT_MAX << '\n';
    std::cout << "long       : " << LONG_MAX << '\n';
    std::cout << "long long  : " << LLONG_MAX << '\n';

    std::cout << "\n";

    // --------------------------------------------------
    // sizeof with Variables
    // --------------------------------------------------

    int age {23};
    double salary {52.39};

    std::cout << "Variable age occupies "
              << sizeof(age)
              << " bytes.\n";

    std::cout << "Variable salary occupies "
              << sizeof(salary)
              << " bytes.\n";

    return 0;
}