#include "Particle.h"

int Particle::num_particle{0}; // int önce geliyor çünkü Particle sınıfından olması soyadı gibi oluyor değişkenin.

Particle::Particle (int id_val, //Default Values Construct construct prototypeta headerda deklere edildi.
        std::string name_val,
        double mass_val,
        double charge_val,
        double momentum_val,
        int layer_id,
        bool alive_yn)
    : particle_id{id_val}, name{name_val},
    mass{mass_val}, charge{charge_val},
    momentum{momentum_val}, detector_layer{layer_id}, alive{alive_yn}
    {
        ++num_particle;
    }

Particle::Particle (const Particle &source) 
: Particle{source.particle_id, source.name, source.mass,
source.charge, source.momentum, source.detector_layer, source.alive} {

}

Particle::Particle (Particle &&source) {}

Particle::~Particle()
{
    --num_particle;
}

void Particle::display () {
    std::cout << "\n+---------------------------------------------------+\n";
    std::cout << "Particle id       : " << get_id() << std::endl;
    std::cout << "Particle name     : " << get_name() << std::endl;
    std::cout << "Particle mass     : " << get_mass() << std::endl;
    std::cout << "Particle charge   : " << get_charge() << std::endl;
    std::cout << "Particle momentum : " << get_momentum() << std::endl;
    std::cout << "Particle layer    : " << get_layer() << std::endl;
    std::cout << "Particle living   : " << get_alive() << std::endl;
    std::cout << "\n+---------------------------------------------------+\n";
}

void display_particle (const Particle &particle) {
    std::cout << "\n+---------------------------------------------------+\n";
    std::cout << "Particle id       : " << particle.get_id() << std::endl;
    std::cout << "Particle name     : " << particle.get_name() << std::endl;
    std::cout << "Particle mass     : " << particle.get_mass() << std::endl;
    std::cout << "Particle charge   : " << particle.get_charge() << std::endl;
    std::cout << "Particle momentum : " << particle.get_momentum() << std::endl;
    std::cout << "Particle layer    : " << particle.get_layer() << std::endl;
    std::cout << "Particle living   : " << particle.get_alive() << std::endl;
    std::cout << "\n+---------------------------------------------------+\n";
 
}

// Static Member Function Definiton
int Particle::get_num_particle() {return num_particle;}