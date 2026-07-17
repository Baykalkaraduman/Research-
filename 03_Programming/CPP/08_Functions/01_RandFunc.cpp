#include <iostream>
#include <cstdlib>      // rand(), srand()
#include <ctime>        // time()

using namespace std;

int main() {

    cout << "========== rand() Demonstration ==========\n\n";

    cout << "RAND_MAX on this system: "
         << RAND_MAX
         << endl;

    // Seed the random number generator
    srand(time(nullptr));

    ////////////////////////////////////////////////////////////////

    cout << "\n========== Example 1 : Random Integers ==========\n";

    const size_t count {10};
    const int min {1};
    const int max {6};

    for (size_t i {1}; i <= count; ++i) {

        // added
        int random_number = rand() % (max - min + 1) + min;

        cout << "Random number "
             << i
             << ": "
             << random_number
             << endl;
    }

    ////////////////////////////////////////////////////////////////

    cout << "\n========== Example 2 : Coin Toss ==========\n";      // added

    for (int i {1}; i <= 10; ++i) {

        int coin = rand() % 2;

        if (coin == 0)
            cout << "Heads\n";
        else
            cout << "Tails\n";
    }

    ////////////////////////////////////////////////////////////////

    cout << "\n========== Example 3 : Dice Simulation ==========\n";   // added

    int frequency[7] {};

    for (int i {0}; i < 1000; ++i) {

        int dice = rand() % 6 + 1;

        frequency[dice]++;
    }

    for (int i {1}; i <= 6; ++i) {

        cout << "Face "
             << i
             << " appeared "
             << frequency[i]
             << " times."
             << endl;
    }

    ////////////////////////////////////////////////////////////////

    cout << "\n========== Example 4 : Random Letters ==========\n";    // added

    for (int i {0}; i < 10; ++i) {

        char letter = 'A' + rand() % 26;

        cout << letter << " ";
    }

    cout << endl;

    ////////////////////////////////////////////////////////////////

    cout << "\n========== Example 5 : Random Password ==========\n";   // added

    for (int i {0}; i < 8; ++i) {

        char c = 'A' + rand() % 26;

        cout << c;
    }

    cout << endl;

    ////////////////////////////////////////////////////////////////

    cout << "\n========== Example 6 : Random Floating Number ==========\n"; // added

    double random_double =
        static_cast<double>(rand()) / RAND_MAX;

    cout << "Random number between 0 and 1 : "
         << random_double
         << endl;

    ////////////////////////////////////////////////////////////////

    cout << "\n========== Modern C++ Note ==========\n";        // added

    cout << "The rand() function is useful for learning,\n";
    cout << "but Modern C++ recommends using the <random> library.\n";
    cout << "We will study <random> later." << endl;

    return 0;
}