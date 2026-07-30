/*
============================================================
Topic      : Simple Pointers
Author     : Emir Karaduman
Description:
    Introduction to pointers in Modern C++.

    Concepts covered:
    - Memory addresses
    - Address-of operator (&)
    - Pointer declaration
    - nullptr
    - Pointer sizes
    - Storing addresses
    - Type safety
============================================================
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    cout << "================ Example 1 : Variables =================\n\n";

    int num {10};

    cout << "Value of num        : " << num << endl;
    cout << "Address of num      : " << &num << endl; // & operator shows the location of the variable
    cout << "Size of num         : " << sizeof(num) << " bytes\n";

    // ---------------------------------------------------------

    cout << "\n================ Example 2 : Uninitialized Pointer =================\n\n";

    /*
        Never use an uninitialized pointer.

        It contains an unknown (garbage) memory address.

        Accessing (*pointer) would cause Undefined Behavior.
    */

    int* p {}; // This is how we are generating pointers

    cout << "Value stored in p   : " << p << endl; // compiler makes it nullptr but in vanilla cpp it would be garbage.
    cout << "Address of p itself : " << &p << endl;
    cout << "Size of p           : " << sizeof(p) << " bytes\n";

    // ---------------------------------------------------------

    cout << "\n================ Example 3 : nullptr =================\n\n";

    p = nullptr;

    cout << "After assigning nullptr\n";
    cout << "Value stored in p   : " << p << endl;

    // ---------------------------------------------------------

    cout << "\n================ Example 4 : Pointer Sizes =================\n\n";

    int* p1 {nullptr};
    double* p2 {nullptr};
    unsigned long long* p3 {nullptr};
    vector<string>* p4 {nullptr};
    string* p5 {nullptr};

    cout << "sizeof(int*)                : " << sizeof(p1) << endl;
    cout << "sizeof(double*)             : " << sizeof(p2) << endl;
    cout << "sizeof(unsigned long long*) : " << sizeof(p3) << endl;
    cout << "sizeof(vector<string>*)     : " << sizeof(p4) << endl;
    cout << "sizeof(string*)             : " << sizeof(p5) << endl;

    /*
        Notice:

        Every pointer has exactly the same size.

        Why?

        Because every pointer stores ONLY a memory address.

        On a 64-bit computer:

            sizeof(pointer) == 8 bytes

        regardless of the object's type.
    */

    // ---------------------------------------------------------

    cout << "\n================ Example 5 : Storing Addresses =================\n\n";

    int score {95};

    int* score_ptr {nullptr};

    score_ptr = &score;

    cout << "score                 : " << score << endl;
    cout << "Address of score      : " << &score << endl;

    cout << endl;

    cout << "score_ptr stores      : " << score_ptr << endl;
    cout << "Address of score_ptr  : " << &score_ptr << endl;
    cout << "value of score_ptr    : " << *score_ptr << endl; 
    /*
        score_ptr stores

                +------------------+
                | 0x61FF08         |
                +------------------+

        That address belongs to score.
    */

    // ---------------------------------------------------------

    cout << "\n================ Example 6 : Type Safety =================\n\n";

    double temperature {36.7};

    /*
        The following assignment is illegal.

        score_ptr = &temperature;

        because

            int*  != double*

        Pointer types must match the object's type.
    */

    cout << "Temperature value : " << temperature << endl;

    // ---------------------------------------------------------

    cout << "\n================ Program Finished =================\n";

    return 0;
}