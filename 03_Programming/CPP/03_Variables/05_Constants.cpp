#include <iostream>

int main()
{
    // --------------------------------------------------
    // Constants
    // --------------------------------------------------
    //
    // Constants are variables whose values
    // cannot be modified after initialization.
    //
    // They make programs safer and easier
    // to understand.

    const double kahramanmaras_price {1.50};
    const double roman_price {1.25};

    const double tax_rate {0.06};

    int kahramanmaras_balls {0};
    int roman_balls {0};
    int service_days {1};

    std::cout << "=========================================\n";
    std::cout << " Welcome to Emir's Ice Cream Shop\n";
    std::cout << "=========================================\n\n";

    std::cout << "How many Kahramanmaras ice cream scoops would you like? ";
    std::cin >> kahramanmaras_balls;

    std::cout << "How many Roman ice cream scoops would you like? ";
    std::cin >> roman_balls;

    std::cout << "For how many days would you like this service? ";
    std::cin >> service_days;

    const double subtotal =
        (kahramanmaras_balls * kahramanmaras_price) +
        (roman_balls * roman_price);

    const double tax = subtotal * tax_rate;

    const double daily_total = subtotal + tax;

    const double final_total = daily_total * service_days;

    std::cout << "\n=========================================\n";
    std::cout << "              ORDER SUMMARY\n";
    std::cout << "=========================================\n";

    std::cout << "Kahramanmaras scoops : "
              << kahramanmaras_balls << '\n';

    std::cout << "Roman scoops         : "
              << roman_balls << '\n';

    std::cout << "Days                 : "
              << service_days << '\n';

    std::cout << "\nSubtotal : $"
              << subtotal << '\n';

    std::cout << "Tax (6%) : $"
              << tax << '\n';

    std::cout << "Daily Total : $"
              << daily_total << '\n';

    std::cout << "\nFinal Total : $"
              << final_total << '\n';

    return 0;
}