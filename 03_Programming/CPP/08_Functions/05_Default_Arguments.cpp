#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//======================================================
//              Function Prototypes
//======================================================

// Default arguments are specified only ONCE,
// usually in the function prototype.

double calculate_cost(double base_cost = 110.0,
                      double tax_rate = 0.06,
                      double shipping_cost = 3.50);

void greet(string name,
           string prefix = "Mr.",
           string suffix = "");

//======================================================
//              Function Definitions
//======================================================

double calculate_cost(double base_cost,
                      double tax_rate,
                      double shipping_cost)
{
    return base_cost + (base_cost * tax_rate) + shipping_cost;
}

void greet(string name,
           string prefix,
           string suffix)
{
    cout << "Hello "
         << prefix << " "
         << name;

    if (!suffix.empty())
        cout << ", " << suffix;

    cout << "!" << endl;
}

//======================================================
//                      Main
//======================================================

int main()
{
    cout << fixed << setprecision(2);

    cout << "================ Example 1 ================" << endl;

    double cost {};

    cost = calculate_cost(120.0, 0.08, 4.25);
    cout << "Cost = $" << cost << endl;

    //--------------------------------------------------

    cout << "\n================ Example 2 ================" << endl;

    cost = calculate_cost(100.0, 0.08);

    cout << "Shipping uses the default value." << endl;
    cout << "Cost = $" << cost << endl;

    //--------------------------------------------------

    cout << "\n================ Example 3 ================" << endl;

    cost = calculate_cost(200.0);

    cout << "Tax rate and shipping use default values." << endl;
    cout << "Cost = $" << cost << endl;

    //--------------------------------------------------

    cout << "\n================ Example 4 ================" << endl;

    cost = calculate_cost();

    cout << "All parameters use default values." << endl;
    cout << "Cost = $" << cost << endl;

    //--------------------------------------------------

    cout << "\n================ Example 5 ================" << endl;

    greet("Emir Karaduman",
          "Professor",
          "Ph.D");

    greet("Ilayda Karaduman",
          "Doctor");

    greet("Yalcin Karaduman");

    greet("Esra Karaduman",
          "Mrs.");

    //--------------------------------------------------

    cout << "\n================ Example 6 ================" << endl;

    cout << "Default arguments are filled from RIGHT to LEFT."
         << endl;

    cout << "Valid calls:" << endl;

    calculate_cost();
    calculate_cost(150);
    calculate_cost(150, 0.08);
    calculate_cost(150, 0.08, 5);

    //--------------------------------------------------

    cout << "\n================ Example 7 ================" << endl;

    cout << "Invalid declaration example:" << endl;

    /*
        INVALID

        void example(int a = 5,
                     int b,
                     int c = 10);

        Once a parameter has a default value,
        every parameter to its RIGHT must also
        have a default value.
    */

    //--------------------------------------------------

    cout << "\n================ Example 8 ================" << endl;

    cout << "Default arguments are substituted by the compiler."
         << endl;

    cout << "Calling\n\n";

    cout << "    calculate_cost(200);\n\n";

    cout << "is treated approximately as\n\n";

    cout << "    calculate_cost(200, 0.06, 3.50);\n";

    //--------------------------------------------------

    cout << "\n================ Example 9 ================" << endl;

    cout << "Default arguments should be declared only once,"
         << endl;

    cout << "normally in the function prototype."
         << endl;

    /*
        Correct

        double calculate_cost(double base = 110,
                              double tax = 0.06,
                              double shipping = 3.5);

        double calculate_cost(double base,
                              double tax,
                              double shipping)
        {
            ...
        }
    */

    //--------------------------------------------------

    cout << "\nProgram Finished!" << endl;

    return 0;
}