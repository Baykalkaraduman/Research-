#include <iostream>
#include <vector>
#include "Mystring.h"

using namespace std;

int main() {

    Mystring a {"Hello"};       // overloaded constructor
    Mystring b;                 // no-args constructor
    b = a;                      // copy assignment // !!!
    b.display();
    b = "This is a test";       // copy assginment // !!!
    b.display();


    Mystring empty;             // no-args constructor
    Mystring muz {"Muz"};       // overloaded constructor
    Mystring stooges {muz};     // copy constructor

    empty = stooges;            // copy assignment

    empty.display();            // Muz : 3
    muz.display();              // Muz : 3
    stooges.display();          // Muz : 3

    stooges = "Muz, Tuz, Buz";
    stooges.display();          // Muz, Tuz, Buz : 13

    vector<Mystring> stooges_vec;
    stooges_vec.push_back("Muz");
    stooges_vec.push_back("Tuz");
    stooges_vec.push_back("Buz");

    cout << "============ Loop 1 ============" << endl;
    for(const Mystring &s : stooges_vec)
        s.display();                        // Tuz Muz Buz
    
    cout << "============ Loop 2 ============" << endl;
    for(Mystring &s : stooges_vec)
        s = "Changed";

    cout << "============ Loop 3 ============" << endl;
    for(const Mystring &s : stooges_vec)
        s.display();                       // Changed Changed Changed
    


    return 0;
}