#include <iostream>
#include <iomanip>      // added
#include <cmath>

using namespace std;

int main() {

    cout << fixed << setprecision(4);          // added

    const double PI {3.14159265358979323846};  // added

    double num {};

    cout << "Enter a number: ";
    cin >> num;

    cout << "\n========== Basic Functions ==========\n";

    cout << "Square root        : " << sqrt(num) << endl;
    cout << "Cube root          : " << cbrt(num) << endl;
    cout << "Absolute value     : " << abs(num) << endl;          // added
    cout << "Floating abs       : " << fabs(num) << endl;         // added

    cout << "\n========== Trigonometric Functions ==========\n";

    cout << "sin(x)             : " << sin(num) << endl;
    cout << "cos(x)             : " << cos(num) << endl;
    cout << "tan(x)             : " << tan(num) << endl;          // added

    cout << "\n========== Rounding Functions ==========\n";

    cout << "ceil()             : " << ceil(num) << endl;
    cout << "floor()            : " << floor(num) << endl;
    cout << "round()            : " << round(num) << endl;
    cout << "trunc()            : " << trunc(num) << endl;        // added

    cout << "\n========== Exponential Functions ==========\n";

    cout << "exp(x)             : " << exp(num) << endl;          // added

    if (num > 0) {
        cout << "ln(x)              : " << log(num) << endl;        // added
        cout << "log10(x)           : " << log10(num) << endl;      // added
    }
    else {
        cout << "Natural logarithm is undefined for x <= 0" << endl;
        cout << "Base-10 logarithm is undefined for x <= 0" << endl;
    }

    cout << "\n========== Powers ==========\n";

    double exponent {};

    cout << "Enter the exponent: ";
    cin >> exponent;

    cout << num << "^" << exponent
         << " = "
         << pow(num, exponent)
         << endl;

    cout << "\n========== Degree / Radian Conversion ==========\n";

    double degrees {};

    cout << "Enter an angle in degrees: ";
    cin >> degrees;

    double radians = degrees * PI / 180.0;         // added

    cout << degrees << " degrees = "
         << radians
         << " radians"
         << endl;

    cout << "sin(" << degrees << "°) = "
         << sin(radians)
         << endl;

    cout << "\n========== Distance Formula ==========\n";      // added

    double x {}, y {};

    cout << "Enter x and y coordinates: ";
    cin >> x >> y;

    cout << "Distance from origin = "
         << hypot(x, y)
         << endl;

    cout << "\n========== Floating Modulus ==========\n";      // added

    double a {}, b {};

    cout << "Enter two floating-point numbers: ";
    cin >> a >> b;

    if (b != 0)
        cout << "fmod(" << a << ", "
             << b
             << ") = "
             << fmod(a, b)
             << endl;
    else
        cout << "Division by zero is not allowed."
             << endl;

    return 0;
}