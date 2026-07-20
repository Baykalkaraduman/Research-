/*
============================================================
Topic      : Pointer Arithmetic
Author     : Emir Karaduman

Description:
    Demonstrates pointer arithmetic in C++.

Concepts covered

    • Incrementing pointers
    • Traversing arrays
    • Sentinel values
    • Post-increment dereferencing
    • Pointer comparison
    • Object comparison
    • Pointer subtraction
============================================================
*/

#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "================ Example 1 : Traversing an Array =================\n\n";

    int scores[] {100, 95, 89, 68, -1};

    /*
        -1 is our sentinel value.

        Instead of storing the size,
        we stop when we encounter -1.
    */

    int* score_ptr {scores};

    while (*score_ptr != -1) {

        cout << "Address : "
             << score_ptr
             << "   Value : "
             << *score_ptr
             << endl;

        score_ptr++;
    }

    // ------------------------------------------------------------

    cout << "\n================ Example 2 : Post-Increment Dereference =================\n\n";

    score_ptr = scores;

    while (*score_ptr != -1)
        cout << *score_ptr++ << endl;

    /*
        This expression

            *score_ptr++

        is interpreted as

            *(score_ptr++)

        NOT

            (*score_ptr)++

        The pointer moves,
        not the stored value.
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 3 : Pointer Comparison =================\n\n";

    string s1 {"Frank"};
    string s2 {"Frank"};
    string s3 {"James"};

    string* p1 {&s1};
    string* p2 {&s2};
    string* p3 {&s1};

    cout << boolalpha;

    cout << "p1 == p2 : "
         << (p1 == p2)
         << endl;

    cout << "p1 == p3 : "
         << (p1 == p3)
         << endl;

    /*
        p1 and p2

        point to different objects.

        Therefore

        false

        p1 and p3

        point to exactly the same object.

        Therefore

        true
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 4 : Comparing Objects =================\n\n";

    cout << "*p1 == *p2 : "
         << (*p1 == *p2)
         << endl;

    cout << "*p1 == *p3 : "
         << (*p1 == *p3)
         << endl;

    /*
        Now we compare the strings.

        Frank == Frank

        true
    */

    p3 = &s3;

    cout << "*p1 == *p3 : "
         << (*p1 == *p3)
         << endl;

    /*
        Frank

        vs

        James

        false
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 5 : Pointer Subtraction =================\n\n";

    char name[] {"Frank"};

    char* char_ptr1 {&name[0]};
    char* char_ptr2 {&name[3]};

    cout << "Character 1 : "
         << *char_ptr1
         << endl;

    cout << "Character 2 : "
         << *char_ptr2
         << endl;

    cout << "\nDistance : "
         << (char_ptr2 - char_ptr1)
         << " characters"
         << endl;

    /*
        Pointer subtraction returns

        number of elements

        NOT

        number of bytes.
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 6 : Pointer Movement =================\n\n";

    score_ptr = scores;

    cout << "Initial Address : "
         << score_ptr
         << endl;

    score_ptr++;

    cout << "After ++ : "
         << score_ptr
         << endl;

    score_ptr++;

    cout << "After another ++ : "
         << score_ptr
         << endl;

    // ------------------------------------------------------------

    cout << "\n================ Example 7 : Pointer Arithmetic Formula =================\n\n";

    score_ptr = scores;

    cout << "*score_ptr       = "
         << *score_ptr
         << endl;

    cout << "*(score_ptr+1)   = "
         << *(score_ptr + 1)
         << endl;

    cout << "*(score_ptr+2)   = "
         << *(score_ptr + 2)
         << endl;

    cout << "*(score_ptr+3)   = "
         << *(score_ptr + 3)
         << endl;

    /*
        Pointer arithmetic

        pointer + n

        moves

        n × sizeof(type)

        bytes.
    */

    // ------------------------------------------------------------

    cout << "\n================ Summary =================\n\n";

    cout << "Pointer arithmetic moves by sizeof(type)." << endl;
    cout << "Pointers compare addresses." << endl;
    cout << "Dereferenced pointers compare values." << endl;
    cout << "Pointer subtraction returns element distance." << endl;
    cout << "*ptr++ moves the pointer after reading the current value." << endl;

    return 0;
}