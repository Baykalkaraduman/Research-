#include <iostream>
#include <iomanip>      // added
using namespace std;

//====================================================
// Function Prototypes
//====================================================
//
// A function prototype tells the compiler:
//
// • Function name
// • Return type
// • Parameter types
//
// but NOT the implementation.
//
// This allows us to define functions
// anywhere in the file.
//====================================================

//====================================================
// Why do we use prototypes?
//
// Without prototypes:
//
// main()
// {
//      area_circle();      // Compiler doesn't know it yet
// }
//
// void area_circle(){}
//
// -> Compiler Error
//
//----------------------------------------------------
//
// With prototypes:
//
// void area_circle();
//
// main()
// {
//      area_circle();
// }
//
// void area_circle(){}
//
// -> Works perfectly
//====================================================

//====================
// Function Prototypes
//====================

void area_circle();
void volume_cylinder();

double calc_area_circle(double radius);
double calc_volume_cylinder(double radius, double height);

void print_separator();                    // added
void display_menu();                       // added


//====================
// Global Constant
//====================

const double PI {3.14159265358979323846};


//====================================================
// Main
//====================================================

int main() {

    cout << fixed << setprecision(2);      // added

    display_menu();                        // added

    area_circle();

    print_separator();                     // added

    area_circle();

    print_separator();                     // added

    volume_cylinder();

    return 0;
}


//====================================================
// Function Definitions
//====================================================

double calc_area_circle(double radius) {

    return PI * radius * radius;
}


double calc_volume_cylinder(double radius,
                            double height) {

    return calc_area_circle(radius) * height;
}


void area_circle() {

    double radius {};

    cout << "\nEnter the radius of the circle: ";
    cin >> radius;

    cout << "Area = "
         << calc_area_circle(radius)
         << endl;
}


void volume_cylinder() {

    double radius {};
    double height {};

    cout << "\nEnter the cylinder radius: ";
    cin >> radius;

    cout << "Enter the cylinder height: ";
    cin >> height;

    cout << "Volume = "
         << calc_volume_cylinder(radius,height)
         << endl;
}


//====================================================
// Additional Functions
//====================================================

void print_separator() {               // added

    cout << "\n----------------------------------------\n";
}


void display_menu() {                  // added

    cout << "========================================\n";
    cout << "      FUNCTION PROTOTYPE EXAMPLE\n";
    cout << "========================================\n";
}

//====================================================
// Prototype Syntax
//
// return_type function_name(parameter_types);
//
// Examples:
//
// void print();
//
// int square(int);
//
// double average(double,double);
//
// bool is_even(int);
//
//====================================================