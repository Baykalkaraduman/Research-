#pragma once

#include <string>
#include <iostream>

// ==============================================================================
// Class: Material
// Represents the physical medium a particle travels through.
// Equivalent to G4Material.
// ==============================================================================
class Material {
private:
    std::string name;
    double density; // in g/cm^3 (for basic dE/dx calculations later)

public:
    Material(std::string matName, double matDensity) 
        : name(std::move(matName)), density(matDensity) {}

    // Getters
    std::string getName() const { return name; }
    double getDensity() const { return density; }

    void display() const {
        std::cout << "Material: " << name << " [Density: " << density << " g/cm^3]\n";
    }
};