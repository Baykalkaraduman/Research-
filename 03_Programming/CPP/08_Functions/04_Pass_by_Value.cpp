#include <iostream>
#include <string>
#include <vector>

using namespace std;

// FUNCTION PROTOTYPES
void pass_by_value1 (int num); 
void pass_by_value2 (string s); 
void pass_by_value3 (vector<string> v); 
void print_vector (vector<string> v);

// DEFINITIONS: PASS-BY-VALUE
// "Pass-by-value" means the function receives a COPY of the data, not the original.
// Any changes made to 'num', 's', or 'v' inside these functions will ONLY affect 
// the local copy, leaving the original variable in main() completely untouched.

void pass_by_value1(int num) {
    num = 1000; // Changes the local copy, not the original variable.
}

void pass_by_value2 (string s) {
    s = "Changed"; // Changes the local string copy.
}

void pass_by_value3 (vector<string> v) {
    v.clear(); // Empties the local vector copy. The original vector remains intact.
}

void print_vector (vector<string> v) {
    // A range-based for loop to iterate through the vector
    for (auto s: v)
        cout << s << " ";
    cout << endl;
}

int main () {
    int num {10};
    int another_num {20};

    // Demonstrating Pass-by-Value with Integers
    cout << "num before calling pass_by_value1: " << num << endl; // Prints 10
    pass_by_value1(num); // Passes a COPY of 'num' (value 10)
    cout << "num after calling pass_by_value1: " << num << endl; // Still prints 10!

    cout << "another_num before calling pass_by_value1: " << another_num << endl; // Prints 20
    pass_by_value1(another_num);
    cout << "another_num after calling pass_by_value1: " << another_num << endl; // Still prints 20!

    // Demonstrating Pass-by-Value with Strings
    string name {"Emir"};
    cout << "\nname before calling pass_by_value2: " << name << endl; // Prints Emir
    pass_by_value2(name);
    cout << "\nname after calling pass_by_value2: " << name << endl; // Still prints Emir!

    // Demonstrating Pass-by-Value with Vectors
    // Note: Passing large vectors by value creates a full copy in memory, which is inefficient.
    // In advanced C++ (and physics frameworks), pass-by-reference is used for large objects.
    vector<string> stooges {"Larry", "Moe", "Curly"};
    cout << "\nstooges before calling pass_by_value3: ";
    print_vector(stooges); 
    
    pass_by_value3(stooges); // Function clears its own copy, not 'stooges'
    
    cout << "stooges after calling the pass_by_value3: ";
    print_vector(stooges); // Elements are still there!

    return 0;
}