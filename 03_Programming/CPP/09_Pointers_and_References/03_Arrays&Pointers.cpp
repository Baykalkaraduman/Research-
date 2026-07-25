/*
============================================================
Topic      : Arrays and Pointers
Author     : Emir Karaduman

Description:
    Understanding the relationship between arrays and pointers.

Concepts covered:
    - Array names
    - Pointer initialization
    - Array indexing
    - Pointer indexing
    - Pointer arithmetic
    - Array offset notation
    - Memory layout
============================================================
*/

#include <iostream>

using namespace std;

int main() {

    cout << "================ Example 1 : Array Memory =================\n\n";

    int scores[] {100, 95, 89};

    cout << "Array name (address)      : " << scores << endl;
    cout << "Address of first element  : " << &scores[0] << endl;

    /*
        scores is NOT a pointer.

        However, in most expressions it decays into
        a pointer to its first element.
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 2 : Pointer Initialization =================\n\n";

    int* score_ptr {scores};

    cout << "score_ptr stores address : " << score_ptr << endl;

    /*
        Memory

        scores
        score_ptr

              |
              V

        +-----+-----+-----+
        |100  | 95  | 89  |
        +-----+-----+-----+
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 3 : Array Subscript =================\n\n";

    cout << "scores[0] = " << scores[0] << endl;
    cout << "scores[1] = " << scores[1] << endl;
    cout << "scores[2] = " << scores[2] << endl;

    // ------------------------------------------------------------

    cout << "\n================ Example 4 : Pointer Subscript =================\n\n";

    cout << "score_ptr[0] = " << score_ptr[0] << endl;
    cout << "score_ptr[1] = " << score_ptr[1] << endl;
    cout << "score_ptr[2] = " << score_ptr[2] << endl;

    /*
        Pointer indexing and array indexing
        produce exactly the same result.
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 5 : Pointer Offset Notation =================\n\n";

    cout << "*score_ptr       = " << *score_ptr << endl;
    cout << "*(score_ptr+1)   = " << *(score_ptr + 1) << endl;
    cout << "*(score_ptr+2)   = " << *(score_ptr + 2) << endl;

    /*
        Pointer arithmetic

        score_ptr + 1

        does NOT add 1 byte.

        It moves exactly one integer forward.
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 6 : Array Offset Notation =================\n\n";

    cout << "*scores       = " << *scores << endl;
    cout << "*(scores+1)   = " << *(scores + 1) << endl;
    cout << "*(scores+2)   = " << *(scores + 2) << endl;

    /*
        Array names can participate
        in pointer arithmetic.

        scores + i

        means

        address of scores[i]
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 7 : Address Comparison =================\n\n";

    cout << "&scores[0] = " << &scores[0] << endl;
    cout << "scores     = " << scores << endl;
    cout << "score_ptr  = " << score_ptr << endl;

    cout << boolalpha;

    cout << "\nAre they equal? "
         << (&scores[0] == score_ptr) << endl;

    // ------------------------------------------------------------

    cout << "\n================ Example 8 : Pointer Arithmetic =================\n\n";

    cout << "Current pointer : " << score_ptr << endl;

    score_ptr++;

    cout << "After ++        : " << score_ptr << endl;
    cout << "Current value   : " << *score_ptr << endl;

    score_ptr++;

    cout << "After ++ again  : " << score_ptr << endl;
    cout << "Current value   : " << *score_ptr << endl;

    /*
        Pointer arithmetic automatically jumps
        by sizeof(type).

        int*

        +1 means

        sizeof(int) bytes.
    */

    // ------------------------------------------------------------

    cout << "\n================ Example 9 : Looping with Pointer =================\n\n";

    score_ptr = scores;

    for (size_t i {0}; i < 3; ++i)
        cout << *(score_ptr + i) << " ";

    cout << endl;

    // ------------------------------------------------------------

    cout << "\n================ Example 10 : Array vs Pointer =================\n\n";

    cout << "sizeof(scores)    : " << sizeof(scores) << endl;
    cout << "sizeof(score_ptr) : " << sizeof(score_ptr) << endl;

    /*
        sizeof(scores)

        returns

            number_of_elements × sizeof(element)

        sizeof(score_ptr)

        returns

            pointer size

        usually 8 bytes on 64-bit systems.
    */

    // ------------------------------------------------------------

    cout << "\n================ Summary =================\n\n";

    cout << "scores        -> Address of first element\n";
    cout << "score_ptr     -> Pointer storing same address\n";
    cout << "scores[i]     == score_ptr[i]\n";
    cout << "*(scores+i)   == *(score_ptr+i)\n";

    return 0;
}