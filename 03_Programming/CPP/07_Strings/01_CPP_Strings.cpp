/***********************************************************************
 * File        : StdStrings_Part1.cpp
 * Topic       : Modern C++ Strings (Part 1)
 *
 * Description:
 * This program demonstrates the fundamentals of std::string.
 *
 * Topics Covered
 * ----------------
 * 1. Creating strings
 * 2. Different initialization methods
 * 3. Assignment
 * 4. Comparison
 * 5. Character access
 * 6. Size information
 * 7. front(), back(), empty()
 *
 * Author : Emir Karaduman
 ***********************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "=====================================================\n";
    cout << "        Modern C++ Strings - Part 1A\n";
    cout << "=====================================================\n";

    //=========================================================
    // Creating Strings
    //=========================================================

    cout << "\n========== Creating Strings ==========\n";

    // Empty string
    string s0;

    // Initialized strings
    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {"Kiwi"};

    // Copy constructor
    string s4 {s1};

    // Partial copy
    string s5 {s1, 0, 3};

    // Repeated character constructor
    string s6 (10, '*');

    cout << "s0 : \"" << s0 << "\"" << endl;
    cout << "s1 : " << s1 << endl;
    cout << "s2 : " << s2 << endl;
    cout << "s3 : " << s3 << endl;
    cout << "s4 : " << s4 << endl;
    cout << "s5 : " << s5 << endl;
    cout << "s6 : " << s6 << endl;

    //=========================================================
    // Length and Size
    //=========================================================

    cout << "\n========== length() & size() ==========\n";

    cout << "s1 = " << s1 << endl;

    cout << "length(): " << s1.length() << endl;
    cout << "size()  : " << s1.size() << endl;

    // Added
    cout << "\nBoth functions return exactly the same value.\n";
    cout << "They exist for historical reasons.\n";

    //=========================================================
    // Empty
    //=========================================================

    cout << "\n========== empty() ==========\n";

    cout << boolalpha;

    cout << "s0.empty() = " << s0.empty() << endl;
    cout << "s1.empty() = " << s1.empty() << endl;

    //=========================================================
    // Assignment
    //=========================================================

    cout << "\n========== Assignment ==========\n";

    string fruit {"Apple"};

    cout << "Initial value : " << fruit << endl;

    fruit = "Watermelon";

    cout << "After assignment : " << fruit << endl;

    string another;

    another = fruit;

    cout << "another = " << another << endl;

    another = "Orange";

    cout << "fruit   = " << fruit << endl;
    cout << "another = " << another << endl;

    cout << "\nNotice that changing one string does NOT change the other.\n";

    //=========================================================
    // Comparison
    //=========================================================

    cout << "\n========== Comparison ==========\n";

    string a {"Apple"};
    string b {"Banana"};
    string c {"Apple"};
    string d {"apple"};

    cout << boolalpha;

    cout << a << " == " << c << " : " << (a == c) << endl;
    cout << a << " != " << b << " : " << (a != b) << endl;
    cout << a << " <  " << b << " : " << (a < b) << endl;
    cout << b << " >  " << a << " : " << (b > a) << endl;
    cout << d << " >  " << a << " : " << (d > a) << endl;

    // Added
    cout << "\nStrings are compared lexicographically." << endl;
    cout << "Uppercase and lowercase letters have different ASCII values."
         << endl;

    //=========================================================
    // Character Access
    //=========================================================

    cout << "\n========== Character Access ==========\n";

    cout << "String : " << fruit << endl;

    cout << "\nUsing [] operator\n";

    cout << fruit[0] << endl;
    cout << fruit[1] << endl;
    cout << fruit[2] << endl;

    cout << "\nUsing .at()\n";

    cout << fruit.at(0) << endl;
    cout << fruit.at(1) << endl;
    cout << fruit.at(2) << endl;

    // Added
    cout << "\nDifference\n";
    cout << "[]      -> Fast but no bounds checking.\n";
    cout << ".at()   -> Safer. Throws an exception if index is invalid.\n";

    //=========================================================
    // Modifying Characters
    //=========================================================

    cout << "\n========== Modifying Characters ==========\n";

    string word {"Physics"};

    cout << "Original : " << word << endl;

    word[0] = 'p';

    cout << "After [] : " << word << endl;

    word.at(0) = 'P';

    cout << "After at(): " << word << endl;

    //=========================================================
    // front() and back()
    //=========================================================

    cout << "\n========== front() & back() ==========\n";

    cout << "String : " << word << endl;

    cout << "First character : " << word.front() << endl;
    cout << "Last character  : " << word.back() << endl;

    // Added
    cout << "\nfront() is equivalent to string[0]\n";
    cout << "back() accesses the last character directly.\n";

    //=========================================================
    // Scientific Computing Note
    //=========================================================

    cout << "\n========== Scientific Computing Note ==========\n";

    cout << "In scientific software, std::string is commonly used for:\n\n";

    cout << "- File names\n";
    cout << "- Detector names\n";
    cout << "- Branch names (ROOT)\n";
    cout << "- Particle names\n";
    cout << "- Configuration files\n";
    cout << "- Command-line arguments\n";

    cout << "\nExamples include:\n";
    cout << "ROOT\n";
    cout << "Geant4\n";
    cout << "Boost\n";
    cout << "HepMC\n";

    cout << "\n========== End of Part 1A ==========\n";

    return 0;
}