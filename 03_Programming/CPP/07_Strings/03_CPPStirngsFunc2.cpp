#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    string s1 {"Apple"};
    string s2 {"Banana"};
    string s3 {};
    string full_name {};

    cout << boolalpha;

    // ==========================================================
    // Substring
    // ==========================================================

    cout << "\n========== Substring ==========\n";

    s1 = "This is a test";

    cout << "Original string : " << s1 << endl;

    cout << "substr(0,4)  : " << s1.substr(0,4) << endl;
    cout << "substr(5,2)  : " << s1.substr(5,2) << endl;
    cout << "substr(10,4) : " << s1.substr(10,4) << endl;

    // added
    cout << "substr(8)    : " << s1.substr(8) << endl;

    // ==========================================================
    // Erase
    // ==========================================================

    cout << "\n========== erase() ==========\n";

    s1 = "This is a test";

    cout << "Original : " << s1 << endl;

    s1.erase(0,5);

    cout << "After erase(0,5): " << s1 << endl;

    // added
    s1 = "Programming";
    s1.erase(3);

    cout << "erase(3): " << s1 << endl;

    // ==========================================================
    // Insert
    // ==========================================================

    cout << "\n========== insert() ==========\n";

    s1 = "Oyun";

    s1.insert(0,"K");

    cout << s1 << endl;

    // added
    s1.insert(5," Engine");

    cout << s1 << endl;

    // ==========================================================
    // Replace
    // ==========================================================

    cout << "\n========== replace() ==========\n";

    s1 = "I like Java";

    cout << "Before : " << s1 << endl;

    s1.replace(7,4,"C++");          // added

    cout << "After  : " << s1 << endl;

    // ==========================================================
    // find()
    // ==========================================================

    cout << "\n========== find() ==========\n";

    s1 = "The secret word is boo";

    string word {};

    cout << "Enter a word to search: ";
    cin >> word;

    size_t position = s1.find(word);

    if(position != string::npos)
        cout << "Found \"" << word
             << "\" at position "
             << position << endl;
    else
        cout << word << " not found.\n";

    // added
    cout << "Searching for \"secret\" -> "
         << s1.find("secret") << endl;

    // ==========================================================
    // rfind()
    // ==========================================================

    cout << "\n========== rfind() ==========\n";

    s1 = "one two three two one";

    cout << s1 << endl;

    cout << "Last occurrence of \"two\" : "
         << s1.rfind("two") << endl;       // added

    // ==========================================================
    // find_first_of()
    // ==========================================================

    cout << "\n========== find_first_of() ==========\n";

    s1 = "Physics";

    size_t pos = s1.find_first_of("aeiou");

    if(pos != string::npos)
        cout << "First vowel is "
             << s1[pos]
             << " at index "
             << pos << endl;      // added

    // ==========================================================
    // getline()
    // ==========================================================

    cout << "\n========== getline() ==========\n";

    cin.ignore();

    cout << "Enter your full name: ";

    getline(cin, full_name);

    cout << "Hello " << full_name << endl;

    // ==========================================================
    // append()
    // ==========================================================

    cout << "\n========== append() ==========\n";

    s1 = "Modern";

    s1.append(" C++");          // added

    cout << s1 << endl;

    // ==========================================================
    // push_back()
    // ==========================================================

    cout << "\n========== push_back() ==========\n";

    s1 = "Hello";

    s1.push_back('!');          // added

    cout << s1 << endl;

    // ==========================================================
    // pop_back()
    // ==========================================================

    cout << "\n========== pop_back() ==========\n";

    s1.pop_back();              // added

    cout << s1 << endl;

    // ==========================================================
    // clear()
    // ==========================================================

    cout << "\n========== clear() ==========\n";

    s1.clear();

    cout << "Length : " << s1.length() << endl;
    cout << "Empty? : " << s1.empty() << endl;

    // ==========================================================
    // swap()
    // ==========================================================

    cout << "\n========== swap() ==========\n";

    s1 = "Apple";
    s2 = "Banana";

    cout << "Before swap\n";
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    s1.swap(s2);

    cout << "\nAfter swap\n";
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    // ==========================================================
    // Empty
    // ==========================================================

    cout << "\n========== empty() ==========\n";

    cout << s1.empty() << endl;

    s1.clear();

    cout << s1.empty() << endl;

    // ==========================================================
    // Capacity (advanced)
    // ==========================================================

    cout << "\n========== capacity() ==========\n";

    string text = "Physics";

    cout << "Length   : " << text.length() << endl;
    cout << "Capacity : " << text.capacity() << endl;      // added

    // ==========================================================
    // Resize
    // ==========================================================

    cout << "\n========== resize() ==========\n";

    text.resize(15,'*');         // added

    cout << text << endl;

    text.resize(5);

    cout << text << endl;

    // ==========================================================
    // Summary Example
    // ==========================================================

    cout << "\n========== Summary ==========\n";

    string language = "C++";

    language += " Programming";

    cout << language << endl;

    cout << "Length : "
         << language.length()
         << endl;

    cout << "Contains \"Programming\" ? "
         << (language.find("Programming") != string::npos)
         << endl;

    return 0;
}