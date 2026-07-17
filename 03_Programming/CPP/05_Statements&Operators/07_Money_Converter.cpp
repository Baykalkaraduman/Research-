#include <iostream>

using namespace std;

int main()
{
    cout << "========== Money Converter ==========\n\n";

    unsigned int cents {0};

    cout << "Enter the total amount of cents: ";
    cin >> cents;

    // Coin values (in cents)
    const int DOLLAR  {100};
    const int QUARTER {25};
    const int DIME    {10};
    const int NICKEL  {5};
    const int PENNY   {1};

    // Store the original value for later display      // Added
    unsigned int original_amount {cents};              // Added

    // Variables that will store the result
    int dollars  {0};
    int quarters {0};
    int dimes    {0};
    int nickels  {0};
    int pennies  {0};

    //--------------------------------------------------
    // Greedy algorithm
    //--------------------------------------------------

    dollars = cents / DOLLAR;
    cents %= DOLLAR;                     // Added (Cleaner than subtraction)

    quarters = cents / QUARTER;
    cents %= QUARTER;                    // Added

    dimes = cents / DIME;
    cents %= DIME;                       // Added

    nickels = cents / NICKEL;
    cents %= NICKEL;                     // Added

    pennies = cents;

    //--------------------------------------------------
    // Output
    //--------------------------------------------------

    cout << "\nBreakdown of " << original_amount << " cents\n";
    cout << "-------------------------------------\n";

    cout << "Dollars : " << dollars << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes   : " << dimes << endl;
    cout << "Nickels : " << nickels << endl;
    cout << "Pennies : " << pennies << endl;

    return 0;
}