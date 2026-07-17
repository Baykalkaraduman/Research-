/***********************************************************************
 * File        : StdStrings_Part1B.cpp
 * Topic       : Modern C++ Strings (Part 1B)
 *
 * Description:
 * This program demonstrates common std::string member functions
 * and different ways of iterating through strings.
 *
 * Topics Covered
 * ----------------
 * 1. Concatenation
 * 2. append()
 * 3. push_back()
 * 4. pop_back()
 * 5. clear()
 * 6. Index-based loops
 * 7. Range-based loops
 * 8. Range-based loops with references
 *
 * Author : Emir Karaduman
 ***********************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

    cout << "=====================================================\n";
    cout << "        Modern C++ Strings - Part 1B\n";
    cout << "=====================================================\n";

    //=========================================================
    // Concatenation using +
    //=========================================================

    cout << "\n========== Concatenation (+) ==========\n";

    string first_name {"Emir"};
    string last_name {"Karaduman"};

    string full_name = first_name + " " + last_name;

    cout << "First Name : " << first_name << endl;
    cout << "Last Name  : " << last_name << endl;
    cout << "Full Name  : " << full_name << endl;

    // Added
    cout << "\nThe '+' operator creates a brand new string." << endl;

    //=========================================================
    // += Operator
    //=========================================================

    cout << "\n========== += Operator ==========\n";

    string sentence {"Modern"};

    sentence += " C++";
    sentence += " is";
    sentence += " powerful.";

    cout << sentence << endl;

    //=========================================================
    // append()
    //=========================================================

    cout << "\n========== append() ==========\n";

    string fruit {"Apple"};

    cout << "Before append(): " << fruit << endl;

    fruit.append(" Juice");

    cout << "After append():  " << fruit << endl;

    // Added
    fruit.append(" is delicious!");

    cout << fruit << endl;

    //=========================================================
    // push_back()
    //=========================================================

    cout << "\n========== push_back() ==========\n";

    string word {"Physics"};

    cout << "Original : " << word << endl;

    word.push_back('!');

    cout << "After push_back(): " << word << endl;

    //=========================================================
    // pop_back()
    //=========================================================

    cout << "\n========== pop_back() ==========\n";

    word.pop_back();

    cout << "After pop_back(): " << word << endl;

    //=========================================================
    // clear()
    //=========================================================

    cout << "\n========== clear() ==========\n";

    string temporary {"Temporary String"};

    cout << "Before clear(): " << temporary << endl;

    temporary.clear();

    cout << "After clear() : \"" << temporary << "\"" << endl;

    cout << boolalpha;
    cout << "Is empty? " << temporary.empty() << endl;

    //=========================================================
    // Index-Based Loop
    //=========================================================

    cout << "\n========== Index-Based Loop ==========\n";

    string language {"Programming"};

    cout << "Characters:" << endl;

    for (size_t i {0}; i < language.length(); ++i) {

        cout << "Index "
             << i
             << " -> "
             << language[i]
             << endl;

    }

    //=========================================================
    // Range-Based Loop
    //=========================================================

    cout << "\n========== Range-Based Loop ==========\n";

    for (char c : language)
        cout << c << ' ';

    cout << endl;

    //=========================================================
    // Range-Based Loop using auto
    //=========================================================

    cout << "\n========== auto ==========\n";

    for (auto c : language)
        cout << c << ' ';

    cout << endl;

    //=========================================================
    // Modifying Characters with Reference
    //=========================================================

    cout << "\n========== Reference Loop ==========\n";

    string university {"istanbul"};

    cout << "Before : " << university << endl;

    // ---------------- Added ----------------
    for (char &c : university)
        c = toupper(c);

    cout << "After  : " << university << endl;

    //=========================================================
    // Read-Only Reference Loop
    //=========================================================

    cout << "\n========== const Reference ==========\n";

    // ---------------- Added ----------------
    for (const char &c : university)
        cout << "[" << c << "]";

    cout << endl;

    //=========================================================
    // Counting Characters
    //=========================================================

    cout << "\n========== Counting Characters ==========\n";

    string text {"This is a simple sentence."};

    int vowels {0};

    for(char c : text){

        c = tolower(c);

        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            ++vowels;

    }

    cout << "Text   : " << text << endl;
    cout << "Vowels : " << vowels << endl;

    //=========================================================
    // Mini Example
    //=========================================================

    cout << "\n========== Mini Example ==========\n";

    string password;

    cout << "Enter a password: ";
    cin >> password;

    if(password.empty()){

        cout << "Password cannot be empty." << endl;

    }
    else{

        cout << "Password length : "
             << password.length()
             << endl;

        cout << "First character : "
             << password.front()
             << endl;

        cout << "Last character  : "
             << password.back()
             << endl;

    }

    //=========================================================
    // Scientific Computing Notes
    //=========================================================

    cout << "\n========== Scientific Notes ==========\n";

    cout << "- Strings store ROOT branch names." << endl;
    cout << "- Strings store file paths." << endl;
    cout << "- Strings store detector names." << endl;
    cout << "- Strings store particle names." << endl;
    cout << "- Strings store configuration options." << endl;

    //=========================================================
    // Best Practices
    //=========================================================

    cout << "\n========== Best Practices ==========\n";

    cout << "✔ Prefer std::string over C-style strings.\n";
    cout << "✔ Use range-based loops whenever possible.\n";
    cout << "✔ Use references when modifying characters.\n";
    cout << "✔ Use const references when only reading.\n";
    cout << "✔ Prefer member functions over manual operations.\n";

    cout << "\n========== End of Part 1B ==========\n";

    return 0;
}