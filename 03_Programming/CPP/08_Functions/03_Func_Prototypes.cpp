#include <iostream>
using namespace std;

// FUNCTION PROTOTYPES (Forward Declarations)
// These tell the compiler: "These functions exist, here is their name, 
// return type, and parameters. Don't worry, the actual code is coming later."
// This allows us to place 'main()' at the top and organize function definitions below it.
void area_circle ();
void volume_cylinder (); 
double calc_area_circle(double radius);
double calc_volume_cylinder (double radius, double height); 

const double pi {3.14159}; 

int main () { 
    // Now 'main' is at the top, which makes the code much easier to read.
    area_circle(); 
    area_circle(); 
    volume_cylinder();

    return 0;
}

// FUNCTION DEFINITIONS
// The actual logic of the functions is placed down here. The order of these 
// definitions no longer matters because the prototypes already informed the compiler.
double calc_area_circle(double radius) { 
    return pi * radius * radius;
}

double calc_volume_cylinder (double radius, double height) {
    return calc_area_circle(radius) * height; 
}

void area_circle () { 
    double radius {};
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;
    cout << "The area of the circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

void volume_cylinder () { 
    double radius{};
    double height{};
    cout << "\nEnter the radius of the cylinder: ";
    cin >> radius;
    cout << "\nEnter the height of the cylinder: ";
    cin >> height;
    cout << "The volume of the cylinder with radius " << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height);
}