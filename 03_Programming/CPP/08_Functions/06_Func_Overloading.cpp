#include <iostream>
#include <string>
#include <vector>

using namespace std;

// =====================================================
// Function Overloading
// -----------------------------------------------------
// Multiple functions may share the same name,
// provided that their parameter lists are different.
//
// The compiler decides which function to call
// based on the number and types of the arguments.
// =====================================================

// Different overloads of print()

void print(int num);
void print(double num);
void print(const string &text);
void print(const string &first, const string &second);
void print(const vector<string> &vec);

int main() {

    cout << "========== Example 1 : Integer ==========\n";
    print(100);

    cout << "\n========== Example 2 : Character ==========\n";
    // char is automatically promoted to int
    print('A');

    cout << "\n========== Example 3 : Double ==========\n";
    print(12.5);

    cout << "\n========== Example 4 : Float ==========\n";
    // float is promoted to double
    print(12.5F);

    cout << "\n========== Example 5 : C-Style String ==========\n";

    // Implicit conversion
    print("C-style string");

    cout << "\n========== Example 6 : std::string ==========\n";

    string cpp_string {"Modern C++ String"};
    print(cpp_string);

    cout << "\n========== Example 7 : Two Strings ==========\n";

    print("Hello", cpp_string);

    cout << "\n========== Example 8 : Vector ==========\n";

    vector<string> physicists
    {
        "Einstein",
        "Bohr",
        "Feynman"
    };

    print(physicists);

    return 0;
}

//=====================================================

void print(int num)
{
    cout << "Printing integer : "
         << num << endl;
}

//=====================================================

void print(double num)
{
    cout << "Printing double : "
         << num << endl;
}

//=====================================================

void print(const string &text)
{
    cout << "Printing string : "
         << text << endl;
}

//=====================================================

void print(const string &first,
           const string &second)
{
    cout << "Printing two strings : "
         << first
         << " | "
         << second
         << endl;
}

//=====================================================

void print(const vector<string> &vec)
{
    cout << "Printing vector contents:\n";

    for(const auto &item : vec)
        cout << " - " << item << endl;
}