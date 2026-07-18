#include <iostream>
using namespace std;

//=============================================
// Function Prototypes
//=============================================

unsigned long long factorial(unsigned long long n);
unsigned long long fibonacci(unsigned long long n);

//=============================================
// Recursive Factorial
//=============================================

unsigned long long factorial(unsigned long long n)
{
    // Base Case
    if (n == 0)
        return 1;

    // Recursive Case
    return n * factorial(n - 1);
}

//=============================================
// Recursive Fibonacci
//=============================================

unsigned long long fibonacci(unsigned long long n)
{
    // Base Cases

    if (n <= 1)
        return n;

    // Recursive Case

    return fibonacci(n - 1) + fibonacci(n - 2);
}

//=============================================
// Main
//=============================================

int main()
{
    cout << "========== FACTORIAL ==========\n\n";

    for (unsigned long long i {0}; i <= 10; ++i)
    {
        cout << i << "! = "
             << factorial(i)
             << endl;
    }

    cout << "\n========== FIBONACCI ==========\n\n";

    for (unsigned long long i {0}; i <= 15; ++i)
    {
        cout << "F(" << i << ") = "
             << fibonacci(i)
             << endl;
    }

    cout << "\n========== LARGE EXAMPLES ==========\n\n";

    cout << "20! = "
         << factorial(20)
         << endl;

    cout << "F(40) = "
         << fibonacci(40)
         << endl;

    return 0;
}