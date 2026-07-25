#include <iostream>
#include <string>
//using namespace std;

class Player {
private:
    std::string name; //Initialization order must be same with the attributes order.
    int health;
    int xp;
public:
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int healt_val, int xp_val);
};

Player::Player() : name{"None"}, health{0}, xp{0} { // This is how you properly initialize a constructor!!!

}
//If for instance you had the code block belove 
//Player::Player() {
//    name = "None";
//    health = 0;
//    xp = 0;
//}
// This is not correctly initialized but assigned. The debugger would have assign garbage data at ln:20 if we hadn't the ln:16
// If there was an initialization at ln:7 std::string name{"XXX"} we would have that value until after the ln:22 which might cause errors

Player::Player(std::string name_val) 
: name{name_val}, health{0}, xp{0} { // This is how you properly initialize a constructor!!!

}

Player::Player(std::string name_val, int health_val, int xp_val) 
: name{name_val}, health{health_val}, xp{xp_val} { // This is how you properly initialize a constructor!!!

}

int main() {
    Player empty;
    Player emir {"Emir"};
    Player villain {"Villain", 100, 15};

    return 0;
}