#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

vector <string> experiment_list{"Axion Detector", "Tau Framework"};

void add_experiment ();
void show_experiment ();
void search_experiment ();
void delete_experiment ();
void statistics (int counter1, int counter2, int counter3, int counter4, int counter5, int counter6);
void rnd_experiment ();

int main () {

    int option {};
    srand(time(nullptr));
    int counter1 {};
    int counter2 {};
    int counter3 {};
    int counter4 {};
    int counter5 {};
    int counter6 {};

    do {
        cout << "\nPhysics Laboratory\n";
        cout << "\n===================================\n";
        cout << "1) Add Experiment\n";
        cout << "2) Show Experiments\n";
        cout << "3) Search Experiments\n";
        cout << "4) Delete Experiments\n";
        cout << "5) Statistics\n";
        cout << "6) Random Experiment Generator\n";
        cout << "7) Exit\n";
        cout << "\n===================================\n";
        cout << "Enter an option to continue: ";
        cin >> option;

        if (option == 1) {
            counter1 += 1;
            add_experiment();
        } else if (option == 2) {
            counter2 += 1;
            show_experiment();
        } else if (option == 3) {
            counter3 += 1;
            search_experiment();
        } else if (option == 4) {
            counter4 += 1;
            delete_experiment();
        } else if (option == 5) {
            counter5 += 1;
            statistics(counter1, counter2, counter3, counter4, counter5, counter6);
        } else if (option == 6) {
            counter6 += 1;
            rnd_experiment();
        } else if (option == 7) {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Unvalid entry, please choose again! " << endl;
        }
    } while (option != 7);
    return 0;
}

void add_experiment () {
    string new_experiment {};
    cin.ignore();
    cout << "Please enter the experiment name you want to add: " << endl;
    getline(cin, new_experiment);
    experiment_list.push_back(new_experiment);
}

void show_experiment () {
    cout << "\n=========================================\n";
    for (const auto& i : experiment_list) {
        cout << i << endl;
    }
    cout << "=========================================\n";
}

void search_experiment () {
    string experiment_to_search;
    cin.ignore();
    cout << "Enter the experiment you are searching: " << endl;
    getline(cin, experiment_to_search);

    for (size_t i{0}; experiment_list.size() > i; ++i) {
        if (experiment_list[i] != experiment_to_search) {
            cout << "There is no experiment with the name " << experiment_to_search << " in the experiment list." << endl;
        } else {
            cout << experiment_to_search << " has the id: " << i << " in the experiment list." << endl;
        }
    }
}

void delete_experiment () {
    int delete_id{};
    string delete_name{};
    char delete_selection {};
    cout << "How you want to delete the experiment by name or by the id (n/i): ";
    do {
        cin >> delete_selection;
        if (delete_selection == 'n') {
            cin.ignore();
            cout << "Enter the name of the experiment you want to delete:\n";
            getline(cin, delete_name);
            experiment_list.erase(remove(experiment_list.begin(), experiment_list.end(), delete_name), experiment_list.end());
            cout << delete_name << "is removed." << endl;

        } else if (delete_selection == 'i') {
            cout << "Enter the id of the experiment you want to delete:\n";
            cin >> delete_id;

            while (delete_id < 0 || delete_id >= experiment_list.size()) {
                cout << "Invalid ID! Please enter a valid id: ";
                cin >> delete_id;
            }
            experiment_list.erase(experiment_list.begin() + delete_id);
            cout << "id: " << delete_id << " is removed." << endl;

        } else 
            cout << "Please enter a valid choice" << endl;
    } while (delete_selection != 'n' && delete_selection != 'i');
}

void statistics (int counter1, int counter2, int counter3, int counter4, int counter5, int counter6) {
    cout << "\n================================================================\n";
    cout << counter1 << " times new experiment added." << endl;
    cout << counter2 << " times list has been showed." << endl;
    cout << counter3 << " times an experiment has been searched." << endl;
    cout << counter4 << " times an experiment has been deleted." << endl;
    cout << counter5 << " times statistics has been observed." << endl;
    cout << counter6 << " times random experiment has been generated." << endl;
    cout << "There are " << experiment_list.size() << " experiments in the list." << endl;
    cout << "\n================================================================\n";
}

void rnd_experiment () {
    vector <vector<string>> experiment_name_parts
    {
        {"Tau_", "Axion_", "Electron_", "Muon_"},
        {"Beam", "Detector", "Counter", "Trigger"}
    };
    
    int random_number0 = rand() % 4;
    int random_number1 = rand() % 4;
    string new_rnd_experiment {experiment_name_parts[0][random_number0] + experiment_name_parts[1][random_number1]};
    experiment_list.push_back(new_rnd_experiment);
}