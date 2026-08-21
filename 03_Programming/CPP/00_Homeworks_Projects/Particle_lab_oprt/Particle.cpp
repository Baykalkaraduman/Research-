#include "Particle.h"

int Particle::num_particle{0}; // int önce geliyor çünkü Particle sınıfından olması soyadı gibi oluyor değişkenin.
// int Particle::id_num_particle{0}; // It is initialized with inline at the header file.

Particle::Particle (int id_num_particle, //Default Values Construct construct prototypeta headerda deklere edildi.
        std::string name_val,
        double mass_val,
        double charge_val,
        double momentum_val,
        int layer_id,
        bool alive_yn)
    : particle_id{id_num_particle}, name{name_val},
    mass{mass_val}, charge{charge_val},
    detector_layer{layer_id}, alive{alive_yn}
    {
        this->momentum = new double[3]; // momentum zaten pointer olduğu için double* momentum yapmadık local olduğunu göstermek için this-> kullandık.

        // Momentum vector layout // makes more sence but I wanted to use loops
        // momentum[0] -> px
        // momentum[1] -> py
        // momentum[2] -> pz

        for(size_t i{0}; i < 2; ++i) {
            *(momentum + i) = 0.0;
        }
        momentum[2] = momentum_val;
        ++num_particle;
        ++id_num_particle;
        std::cout << "Constructor is Working..." << std::endl;
    }

Particle::Particle (const Particle &source) 
: particle_id{source.particle_id}, name{source.name}, mass{source.mass}, charge{source.charge}, // detector_layer{source.layer_id} olmaz çünkü layer_id başka scopeda.
detector_layer{source.detector_layer}, alive{source.alive} { // source is an object and in order to reach the datas inside an object you always have to use the headers original attributes names.

    this->momentum = new double[3];
    for(size_t i{0}; i < 3; ++i) {
        momentum[i] = source.momentum[i];
    }
    ++num_particle; // artık ana constructorın destructoru çalışınca pointer objeleri siliniyor o yüzden her scopeda parçacık sayısını arttırmalıyız.
    ++id_num_particle;
    std::cout << "Copy Constructor is Working" << std::endl;
}

Particle::Particle (Particle &&source) noexcept
: particle_id{source.particle_id}, name{std::move(source.name)}, mass{source.mass}, charge{source.charge}, //std::move ile çok daha hızlı ve kolay bir şekilde string gibi fazla yer tutabilecek bir şeyi aktarıyoruz.
detector_layer{source.detector_layer}, alive{source.alive}, momentum{source.momentum} {

    source.momentum = nullptr; // source.momentum{nullptr}; işe yaramaz çünkü hali hazırda değeri var assignment yapmamız lazım initialization değil.
    ++num_particle;
    ++id_num_particle;
    std::cout << "Move Constructor is Working..." << std::endl;

}

Particle::~Particle()
{
    delete [] momentum; // Release dynamically allocated momentum vector. No need to add more delete lines for different objects
    --num_particle;
}

void Particle::display () const {
    std::cout << "\n+---------------------------------------------------+\n";
    std::cout << "Particle id       : " << get_id() << std::endl;
    std::cout << "Particle name     : " << get_name() << std::endl;
    std::cout << "Particle mass     : " << get_mass() << std::endl;
    std::cout << "Particle charge   : " << get_charge() << std::endl;
    std::cout << "Particle momentum : " << get_momentum() << std::endl;
    std::cout << "Particle layer    : " << get_layer() << std::endl;
    if (get_alive() == 0) {
        std::cout << "Particle living   : No" << std::endl;
    } else {
        std::cout << "Particle living   : Yes" << std::endl;
    }
    std::cout << "\n+---------------------------------------------------+\n";
}

// Assignments

Particle& Particle::operator=(const Particle &rhs) {

    if(this == &rhs)
        return *this;
    delete [] this->momentum;

    particle_id = rhs.particle_id;      // Since assignments are not constructors you cannot use initilization list
    name = rhs.name;                    // So we just simply assigning values here
    mass = rhs.mass;
    charge = rhs.charge;
    detector_layer = rhs.detector_layer;
    alive = rhs.alive;    

    momentum = new double[3];
    momentum[0] = rhs.momentum[0];
    momentum[1] = rhs.momentum[1];
    momentum[2] = rhs.momentum[2];
    return *this;
}

Particle& Particle::operator=(Particle &&rhs) {
    
    std::cout << "Equality Operator called\n";

    if(this == &rhs)
        return *this;
    
    delete [] momentum;

    particle_id = rhs.particle_id;      // Since assignments are not constructors you cannot use initilization list
    name = rhs.name;         // So we just simply assigning values here
    mass = rhs.mass;
    charge = rhs.charge;
    detector_layer = rhs.detector_layer;
    alive = rhs.alive;    

    this->momentum = rhs.momentum;
    rhs.momentum = nullptr;
    return *this;
}

bool Particle::operator==(const Particle &rhs) const {
    if(mass == rhs.mass && charge == rhs.charge && detector_layer == rhs.detector_layer && alive == rhs.alive && momentum[0] == rhs.momentum[0] 
    && momentum[1] == rhs.momentum[1] && momentum[2] == rhs.momentum[2]) {
            return 1;
    } else return 0;
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