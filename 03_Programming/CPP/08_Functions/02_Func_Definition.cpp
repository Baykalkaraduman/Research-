#include <iostream>
#include <iomanip>      // Added
using namespace std;

//=====================================================
// Global Constants
//=====================================================

// A global constant can be accessed by every function.
// Since it is declared outside all functions,
// its lifetime is the entire program.

const double PI {3.14159265358979323846};

//=====================================================
// Function Prototypes (Added)
//=====================================================

// Prototypes tell the compiler that these functions
// exist somewhere later in the program.

double calc_area_circle(double radius);
double calc_volume_cylinder(double radius, double height);

void area_circle();
void volume_cylinder();

//=====================================================
// Function Definitions
//=====================================================

// Calculates the area of a circle.
//
// Formula:
// Area = PI * r²
//
// Parameter:
// radius -> radius of the circle
//
// Return:
// area of the circle

double calc_area_circle(double radius)
{
    return PI * radius * radius;
}

//-----------------------------------------------------

// Calculates cylinder volume.
//
// Formula:
//
// Volume = Base Area × Height
//
// Instead of rewriting the area formula,
// we simply reuse calc_area_circle().
//
// This demonstrates code reuse.

double calc_volume_cylinder(double radius,
                            double height)
{
    return calc_area_circle(radius) * height;
}

//=====================================================

// User interface function.
//
// Notice:
//
// This function DOES NOT calculate anything.
//
// It only
//
// 1. gets input
// 2. calls another function
// 3. prints the result
//
// Separating calculations from input/output
// is considered good software design.

void area_circle()
{
    double radius {};

    cout << "\nEnter the radius of the circle: ";
    cin >> radius;

    if(radius < 0)                       // Added
    {
        cout << "Radius cannot be negative.\n";
        return;
    }

    cout << fixed << setprecision(2);    // Added

    cout << "Area = "
         << calc_area_circle(radius)
         << endl;
}

//=====================================================

// Similar idea.
//
// This function only communicates with the user.
//
// The mathematical calculation is delegated
// to calc_volume_cylinder().

void volume_cylinder()
{
    double radius {};
    double height {};

    cout << "\nEnter cylinder radius: ";
    cin >> radius;

    cout << "Enter cylinder height: ";
    cin >> height;

    if(radius < 0 || height < 0)         // Added
    {
        cout << "Radius and height must be positive.\n";
        return;
    }

    cout << fixed << setprecision(2);

    cout << "Cylinder Volume = "
         << calc_volume_cylinder(radius,height)
         << endl;
}

//=====================================================
// main()
//=====================================================

int main()
{
    cout << "========== Function Example ==========\n";

    area_circle();

    cout << "\nCalling the same function again...\n";

    area_circle();

    volume_cylinder();

    //=================================================
    // Added Example
    //=================================================

    cout << "\n========== Direct Function Call ==========\n";

    double r {5};

    cout << "Area of radius "
         << r
         << " = "
         << calc_area_circle(r)
         << endl;

    cout << "\n========== Nested Function Calls ==========\n";

    cout << "Volume of cylinder (r=3, h=10) = "
         << calc_volume_cylinder(3,10)
         << endl;

    return 0;
}