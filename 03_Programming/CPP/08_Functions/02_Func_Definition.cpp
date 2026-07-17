#include <iostream>
using namespace std;

// GLOBAL CONSTANT
// Defined outside of any function. It has "global scope," meaning any function 
// in this file can access and use it. 'const' prevents it from being changed.
const double pi {3.14159}; 

// FUNCTION DEFINITION BEFORE MAIN
// Because there are no prototypes, we MUST define the function before it is called.
// The compiler reads top-to-bottom.
double calc_area_circle(double radius) { 
    return pi * radius * radius;
}

double calc_volume_cylinder (double radius, double height) {
    // Functions can call other functions! Here we reuse the area logic.
    return calc_area_circle(radius) * height; 
}

// VOID FUNCTION
// 'void' means this function does not return a value to the caller.
// It simply executes a block of code (like printing to the console).
void area_circle () { 
    double radius {}; // Local variable, only exists inside this function
    cout << "\nEnter the radius of the circle: ";
    cin >> radius;
    // Calling the calculation function and immediately printing its returned value
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

int main () { 
    // The program execution ALWAYS starts here, regardless of where 'main' is placed.
    area_circle(); 
    area_circle(); // Functions can be called multiple times, enabling code reuse.
    volume_cylinder();

    return 0;
}