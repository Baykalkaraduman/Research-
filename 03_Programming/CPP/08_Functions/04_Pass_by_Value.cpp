#include <iostream>
#include <string>
#include <vector>

using namespace std;

//-----------------------------------------------------
// Function Prototypes
//-----------------------------------------------------

void pass_by_value_int(int num);
void pass_by_value_string(string text);
void pass_by_value_vector(vector<string> names);

void print_vector(const vector<string>& names);

//-----------------------------------------------------
// Pass by Value Examples
//-----------------------------------------------------

void pass_by_value_int(int num)
{
    cout << "Address inside function : " << &num << endl;

    num = 1000;

    cout << "Value inside function   : "
         << num << endl;
}

void pass_by_value_string(string text)
{
    text = "Changed";

    cout << "String inside function  : "
         << text << endl;
}

void pass_by_value_vector(vector<string> names)
{
    names.clear();

    names.push_back("New");
    names.push_back("Vector");

    cout << "Vector inside function  : ";
    print_vector(names);
}

void print_vector(const vector<string>& names)
{
    for(const auto& item : names)
        cout << item << " ";

    cout << endl;
}

//-----------------------------------------------------
// Main
//-----------------------------------------------------

int main()
{
    cout << "================ Example 1 : Integer ================\n";

    int number {10};

    cout << "Address in main     : "
         << &number << endl;

    cout << "Before function     : "
         << number << endl;

    pass_by_value_int(number);

    cout << "After function      : "
         << number << endl;

    //-------------------------------------------------

    cout << "\n================ Example 2 : String ================\n";

    string name {"Emir"};

    cout << "Before function     : "
         << name << endl;

    pass_by_value_string(name);

    cout << "After function      : "
         << name << endl;

    //-------------------------------------------------

    cout << "\n================ Example 3 : Vector ================\n";

    vector<string> names
    {
        "Larry",
        "Moe",
        "Curly"
    };

    cout << "Before function     : ";
    print_vector(names);

    pass_by_value_vector(names);

    cout << "After function      : ";
    print_vector(names);

    //-------------------------------------------------

    cout << "\n========== Temporary Values ==========\n";

    pass_by_value_int(500);

    pass_by_value_string("Hello");

    return 0;
}