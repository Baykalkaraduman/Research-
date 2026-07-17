#include <iostream>
#include <cstring>      // strlen, strcpy, strcat, strcmp
#include <cctype>       // toupper, tolower, isalpha, isdigit

using namespace std;

/*
==========================================================
                C-Style Strings
==========================================================

A C-style string is simply an array of characters that
ends with a special character:

        '\0'

called the null terminator.

Example:

"H e l l o \0"

Functions from <cstring> use this null character to know
where the string ends.
*/

int main() {

    //-----------------------------------------------------
    // Character Arrays
    //-----------------------------------------------------

    char first_name[20]{};
    char last_name[20]{};

    char full_name[50]{};
    char temp[50]{};

    //-----------------------------------------------------
    // Reading Strings
    //-----------------------------------------------------

    cout << "Enter your first name : ";
    cin >> first_name;

    cout << "Enter your last name  : ";
    cin >> last_name;

    cout << "\n--------------------------------------\n";

    //-----------------------------------------------------
    // strlen()
    //-----------------------------------------------------

    cout << "First name : "
         << first_name
         << endl;

    cout << "Length = "
         << strlen(first_name)
         << endl;

    cout << "\nLast name : "
         << last_name
         << endl;

    cout << "Length = "
         << strlen(last_name)
         << endl;

    //-----------------------------------------------------
    // Added
    // sizeof vs strlen
    //-----------------------------------------------------

    cout << "\nsizeof(first_name) = "
         << sizeof(first_name)
         << endl;

    cout << "strlen(first_name) = "
         << strlen(first_name)
         << endl;

    /*
        sizeof -> allocated array size

        strlen -> actual text length
    */

    //-----------------------------------------------------
    // strcpy()
    //-----------------------------------------------------

    strcpy(full_name, first_name);

    //-----------------------------------------------------
    // strcat()
    //-----------------------------------------------------

    strcat(full_name, " ");
    strcat(full_name, last_name);

    cout << "\nFull name : "
         << full_name
         << endl;

    //-----------------------------------------------------
    // getline()
    //-----------------------------------------------------

    cin.ignore();               // Added

    cout << "\nEnter your full name again : ";

    cin.getline(full_name, 50);

    cout << "You entered : "
         << full_name
         << endl;

    //-----------------------------------------------------
    // strcmp()
    //-----------------------------------------------------

    strcpy(temp, full_name);

    if (strcmp(temp, full_name) == 0)

        cout << "\nStrings are identical.\n";

    else

        cout << "\nStrings are different.\n";

    //-----------------------------------------------------
    // toupper()
    //-----------------------------------------------------

    for (size_t i{0}; i < strlen(full_name); ++i)

        if (isalpha(full_name[i]))

            full_name[i] = toupper(full_name[i]);

    cout << "\nUppercase version : "
         << full_name
         << endl;

    //-----------------------------------------------------
    // Added
    // tolower()
    //-----------------------------------------------------

    for (size_t i{0}; i < strlen(full_name); ++i)

        if (isalpha(full_name[i]))

            full_name[i] = tolower(full_name[i]);

    cout << "Lowercase version : "
         << full_name
         << endl;

    //-----------------------------------------------------
    // strcmp() return value
    //-----------------------------------------------------

    cout << "\nstrcmp(temp, full_name) = "
         << strcmp(temp, full_name)
         << endl;

    cout << "strcmp(full_name, temp) = "
         << strcmp(full_name, temp)
         << endl;

    /*
        0  -> equal

        <0 -> first string comes first alphabetically

        >0 -> second string comes first
    */

    //-----------------------------------------------------
    // Added
    // Character classification
    //-----------------------------------------------------

    char character{};

    cout << "\nEnter a single character : ";
    cin >> character;

    if (isalpha(character))
        cout << "It is a letter.\n";

    if (isdigit(character))
        cout << "It is a digit.\n";

    //-----------------------------------------------------
    // End
    //-----------------------------------------------------

    cout << "\nProgram Finished.\n";

    return 0;
}