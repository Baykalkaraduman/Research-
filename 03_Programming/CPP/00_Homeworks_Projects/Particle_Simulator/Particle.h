#pragma once

#include <string>
#include <iostream>

// ==============================================================================
// Base Class: Particle
// Represents the immutable, static physical properties of a particle type.
// Equivalent to G4ParticleDefinition in Geant4.
// ==============================================================================
class Particle {
protected:
    int pdg_id;          // Particle Data Group (PDG) ID (e.g., 11 for e-, 22 for gamma)
    std::string name;    // Particle nomenclature
    double mass;         // Rest mass in GeV/c^2
    double charge;       // Electrical charge in units of elementary charge (e)
    double spin;         // Spin quantum number (e.g., 0.5 for fermions, 1.0 for bosons)
    double lifetime;     // Mean lifetime in nanoseconds (ns). Use -1.0 for stable particles.

public:
    // All-args Constructor
    Particle(int p_pdg_id, std::string p_name, double p_mass, double p_charge, double p_spin, double p_lifetime);

    // ==========================================================================
    // CRITICAL: Virtual Destructor
    // Required for safe polymorphic deletion of derived classes.
    // ==========================================================================
    virtual ~Particle() = default; 

    // Getters
    int getPdgId() const;
    std::string getName() const;
    double getMass() const;
    double getCharge() const;
    double getSpin() const;
    double getLifetime() const;
    
    // Utility method to check if the particle decays
    bool isStable() const;

    // ==========================================================================
    // Virtual Function for Polymorphism
    // ==========================================================================
    virtual void display() const;
};