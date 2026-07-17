#include <iostream>
#include <iomanip> // Included for stream manipulators like setprecision()
#include <string>

using namespace std;

// FUNCTION PROTOTYPES WITH DEFAULT ARGUMENTS
// We declare the default arguments here in the prototype. If the caller does not 
// provide a value for these parameters, the compiler automatically uses these defaults.
// RULE: Once a default argument is provided, all subsequent parameters in the list 
// must also have default arguments.
double calc_cost(double base_cost = 110, double tax_rate = 0.06, double shipping = 3.50); 
void greeting(string name, string prefix = "Mr.", string suffix = "");

// FUNCTION DEFINITIONS
// Notice that we DO NOT repeat the default values in the definition.
double calc_cost (double base_cost, double tax_rate, double shipping) {
    // Calculates total cost. 'base_cost += ...' updates base_cost and returns it.
    return base_cost += (base_cost * tax_rate) + shipping;
}

void greeting(string name, string prefix, string suffix) {
    // Concatenates the strings and prints them.
    cout << "Hello " << prefix + " " << name + " " << suffix << endl; 
}

int main() {
    double cost {0}; // Best practice: initialize variables at declaration

    // 1. Passing all arguments: No default arguments are used.
    cost = calc_cost(120.0, 0.08, 4.25); 

    // Formatting the output to always show 2 decimal places (e.g., 120.00)
    cout << fixed << setprecision(2);
    cout << "Cost is " << cost << endl;

    // 2. Missing one argument: 'shipping' uses the default value (3.50).
    cost = calc_cost(100.0, 0.08); 
    cout << "Cost is " << cost << endl;

    // 3. Missing two arguments: 'tax_rate' (0.06) and 'shipping' (3.50) use defaults.
    cost = calc_cost(200.0); 
    cout << "Cost is " << cost << endl;

    // 4. Missing all arguments: Uses all defaults (110, 0.06, 3.50).
    cost = calc_cost(); 
    cout << "Cost is " << cost << endl;

    // Testing the greeting function with various combinations of default arguments
    greeting("Emir Karaduman", "Professor", "Ph.D"); // No defaults used
    greeting("Ilayda Karaduman", "Doctor");          // 'suffix' uses default ("")
    greeting("Yalcin Karaduman");                    // 'prefix' ("Mr.") and 'suffix' ("") use defaults
    greeting("Esra Karaduman", "Mrs.");              // 'prefix' is overwritten, 'suffix' uses default

    return 0;
}