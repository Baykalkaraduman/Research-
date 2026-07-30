#include <iostream>
#include <string>
#include "Particle.h"

using namespace std;

int main () {

    //========================================================
    // Generating an electron and testing getters and setters
    //========================================================

    Particle electron;
    electron.set_id(10);
    electron.set_name("Electron");
    electron.set_mass(0.000511);
    electron.set_charge(-1);
    electron.set_momentum(0.0013);
    electron.set_detector_layer(0);
    electron.set_alive(1);
    cout << electron.get_id() << "\n";
    cout << electron.get_name() << "\n";
    cout << electron.get_mass() << "\n";
    cout << electron.get_charge() << "\n";
    cout << electron.get_momentum() << "\n";
    cout << electron.get_layer() << "\n";
    cout << electron.get_alive() << "\n";

    //========================================================
    // Generating a Particles using All-Args Constructor
    //========================================================

    Particle proton {34, "Proton", 0.93827, 1, 2.1, 0, 1};
    Particle down {24, "Down Quark", 0.047, -0.333339};
    Particle up {22, "Up Quark", 0.0216, 0.666669};

    //========================================================
    // Generating a Particles using Copy Constructor
    //========================================================

    Particle positron {electron};
    positron.set_charge(1);
    
    //========================================================
    // Testing Display Function
    //========================================================
    
    proton.display();

    display_particle(proton);



    return 0;
}