#include <iostream>
#include <string>
#include "Particle.h"
#include "Detector.h"

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

    Particle virtual_photon {99, "Virtual Photon", 0.0, 0.0, 52.8, 0, 1};

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

    positron.display();
    display_particle(positron);

    //========================================================
    // Testing Move Constructor 
    //========================================================
    virtual_photon.display();

    Particle interaction_photon{std::move(virtual_photon)};
    interaction_photon.set_name("New Electron and Positron");


    display_particle(interaction_photon);

    //========================================================
    // Generating an scintillator and testing getters and setters
    //========================================================

    Detector sci;
    sci.set_detector_id(1);
    sci.set_detector_name("Plasitic Scintillator");
    sci.set_detector_type("Scintillator");
    sci.set_position_x(0.0);
    sci.set_position_y(0.0);
    sci.set_position_z(0.0);
    sci.set_wideness(1.0);
    sci.set_length(1.0);
    sci.set_thickness(1.0);
    sci.set_material_id(1);
    sci.set_active(1);

    sci.get_detector_id();
    sci.get_detector_name();
    sci.get_detector_type();
    sci.get_position_x();
    sci.get_position_y();
    sci.get_position_z();
    sci.get_x_dimension();
    sci.get_y_dimension();
    sci.get_z_dimension();
    sci.get_material_id();
    cout << boolalpha;
    sci.get_active();

    //========================================================
    // Generating a Detector using All-Args Constructor
    //========================================================
    
    Detector CsI {2, "Cesium Iodide Scintillator", "Scintillator", 
        2.0, 1.0, {0, 0, 2}, {1, 1, 1}, 2, 1};

    //========================================================
    // Testing Display Function
    //========================================================

    display_detector(CsI);

    CsI.display();

    //========================================================
    // Generating a Particles using Copy Constructor
    //========================================================

    Detector NaI{CsI};
    NaI.set_position_z(5.0);

    //========================================================
    // Testing Move Constructor 
    //========================================================

    display_detector(sci);

    Detector liq_sci{std::move(sci)};
    liq_sci.set_detector_name("Liquid Scintillator");

    liq_sci.display();
    
    return 0;
}