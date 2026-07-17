#include <iostream>     // Standard Input / Output library.
                        // It provides objects such as std::cin,
                        // std::cout and std::endl.

int main() {

    // Declare an integer variable.
    // At this point the variable exists in memory,
    // but it does not yet contain a meaningful value.
    int favourite_number;

    // Ask the user for input.
    std::cout << "Enter your favourite number between 1 and 100: ";

    // Read an integer from the keyboard and store it
    // inside the variable favourite_number.
    std::cin >> favourite_number;

    // Print a message to the console.
    std::cout << "Amazing! That's my favorite number as well."
              << std::endl;

    // Display the value entered by the user.
    std::cout << "No Really! "
              << favourite_number
              << " is my favourite number as well."
              << std::endl;

    // Return 0 indicates successful execution.
    return 0;
}