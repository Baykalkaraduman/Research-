#include <iostream>
#include <string>

using namespace std;

class Player {
private:
    std::string name;
    int health;
    int xp;
public:
    std::string get_name () {return name;}
    int get_health () {return health;}
    int get_xp () {return xp;}
    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);

    //Copy Constructor
    Player(const Player &source); // name of the class (single object in a parameter list + &source[optional] )
    // Destructor
    ~Player () {cout << "Destructor called for: " << name << endl;}
};

Player::Player(std::string name_val, int health_val, int xp_val) : name{name_val}, health{health_val}, xp{xp_val} {
    cout << "Three-args constructor for " + name << endl;
}

// Implementing the copy constructor "After the constructor ln:23"

Player::Player (const Player &source) 
//: name(source.name), health(source.health), xp(source.xp) 
: Player {source.name, source.health, source.xp} // We can use "Delegetion" for the copy constructor
{
    cout << "Copy constructor - made copy of: " << source.name << endl;
}

void display_player (Player p) { // Default way of passing parameters around so this implies the copy
    cout << "Name: " << p.get_name() << endl;
    cout << "Health: " << p.get_health() << endl;
    cout << "Xp: " << p.get_xp() << endl;
}

int main () {

    Player empty;
    Player new_object {empty}; // Copying the object using copy constructor
    display_player(empty);

    Player emir{"Emir"};
    Player hero{"Hero", 100};
    Player villain{"Villain", 100, 12};

    return 0;
}