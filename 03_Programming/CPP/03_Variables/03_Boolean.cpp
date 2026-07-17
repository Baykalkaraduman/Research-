#include <iostream>     // Provides standard input and output functionality.

int main()
{
    // --------------------------------------------------
    // Boolean Data Type
    // --------------------------------------------------
    //
    // A boolean variable can store only two values:
    //
    // true
    // false
    //
    // Internally, C++ usually stores
    // false as 0
    // true  as 1
    //
    // Booleans are heavily used in
    // conditions, loops and decision making.

    bool learning_stopped {false};

    std::cout << "Did the learning stop?" << std::endl;

    // Printing a bool without std::boolalpha
    // displays 0 for false and 1 for true.
    std::cout << learning_stopped << std::endl;

    std::cout << std::endl;

    learning_stopped = true;

    std::cout << "After changing the value:" << std::endl;
    std::cout << learning_stopped << std::endl;

    return 0;
}