#include "Detector.h"

Detector::Detector (int detector_id,
        std::string detector_name,
        std::string detector_type,
        double position,
        double dimension,
        std::vector<double> positions,
        std::vector<double> dimensions,
        int material_id,
        bool active) 
    : detector_id{detector_id}, detector_name{detector_name}, detector_type{detector_type},
    material_id{material_id}, active{active} {
        
        this->position = new double[3];
        this->dimension = new double[3];

        this->position[0] = 0.0; // both the type and the value is called position so we have to tell the compiler that this is the type one by using this->
        this->position[1] = 0.0;
        this->position[2] = position;

        this->dimension[0] = 1.0;
        this->dimension[1] = 1.0;
        this->dimension[2] = dimension;

        this->positions[0] = this->position[0];
        this->positions[1] = this->position[1];
        this->positions[2] = this->position[2];

        this->dimensions[0] = this->dimension[0];
        this->dimensions[0] = this->dimension[1];
        this->dimensions[0] = this->dimension[2];

        ++num_detector;
        std::cout << "Main Constructor used (Detector)" << std::endl;
    
    }

Detector::Detector(const Detector &source) 
    : detector_id{source.detector_id}, detector_name{source.detector_name}, detector_type{source.detector_type}, 
    material_id{source.material_id}, active{source.active} {

        this->position = new double[3];
        this->dimension = new double[3];

        for(size_t i{0}; i < 3; ++i) {
            position[i] = source.position[i];
            positions[i] = position[i];
        }

        for(size_t i{0}; i < 3; ++i) {
            dimension[i] = source.dimension[i];
            dimensions[i] = dimension[i];
        }
        ++num_detector;
        std::cout << "Copy Constructor used (Detector)" << std::endl;
        }

Detector::Detector(Detector &&source) 
        : detector_id{source.detector_id}, detector_name{std::move(source.detector_name)}, detector_type{std::move(source.detector_type)},
        material_id{source.material_id}, active{source.active},
        position{source.position}, dimension{source.dimension},
        positions{source.positions}, dimensions{source.dimensions} {

            source.position = nullptr;
            source.dimension = nullptr;

            ++num_detector;
            std::cout << "Move Constructor used (Detector)" << std::endl;
        }

Detector::~Detector() {

    delete[] position;
    delete[] dimension;
    --num_detector;
    std::cout << "Destructor called (Detector)" << std::endl;
}

void Detector::display () const {
    std::cout << "\n+---------------------------------------------------+\n";
    std::cout << "Detector id                    : " << get_detector_id() << std::endl;
    std::cout << "Detector name                  : " << get_detector_name() << std::endl;
    std::cout << "Detector type                  : " << get_detector_type() << std::endl;
    std::cout << "Detector positions (x, y, z)   : " << get_position_x() << " " << get_position_y() << " " << get_position_z() << std::endl;
    std::cout << "Detector dimentions (w , l, t) : " << get_x_dimension() << " " << get_y_dimension() << " " << get_z_dimension() << std::endl;
    std::cout << "Detector material              : " << get_material_id() << std::endl;
    if (get_active() == 0) {
        std::cout << "Detector living            : No" << std::endl;
    } else {
        std::cout << "Detector living            : Yes" << std::endl;
    }
    std::cout << "\n+---------------------------------------------------+\n";
}

void display_detector (const Detector &Detector) {
    std::cout << "\n+---------------------------------------------------+\n";
    std::cout << "Detector id                    : " << Detector.get_detector_id() << std::endl;
    std::cout << "Detector name                  : " << Detector.get_detector_name() << std::endl;
    std::cout << "Detector type                  : " << Detector.get_detector_type() << std::endl;
    std::cout << "Detector positions (x, y, z)   : " << Detector.get_position_x() << " " << Detector.get_position_y() << " " << Detector.get_position_z() << std::endl;
    std::cout << "Detector dimentions (w , l, t) : " << Detector.get_x_dimension() << " " << Detector.get_y_dimension() << " " << Detector.get_z_dimension() << std::endl;
    std::cout << "Detector material              : " << Detector.get_material_id() << std::endl;
    if (Detector.get_active() == 0) {
        std::cout << "Detector living            : No" << std::endl;
    } else {
        std::cout << "Detector living            : Yes" << std::endl;
    }
    std::cout << "\n+---------------------------------------------------+\n";
}
