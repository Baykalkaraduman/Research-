#pragma once

#include <string>
#include <vector>
#include "Track.h"
#include "Material.h"

// ==============================================================================
// Abstract Base Class: PhysicsProcess
// Defines the interface for all physics interactions in the simulation.
// Equivalent to G4VProcess in Geant4.
// ==============================================================================
class PhysicsProcess {
protected:
    std::string processName;

public:
    explicit PhysicsProcess(std::string name) : processName(std::move(name)) {}
    
    virtual ~PhysicsProcess() = default;

    // ==========================================================================
    // PURE VIRTUAL FUNCTION (= 0)
    // Applies the physics interaction to the particle track.
    // Derived classes will implement specific formulas (like dE/dx or scattering).
    // ==========================================================================
virtual void doIt(Track& track, const Material& material, double stepLength, std::vector<Track>& secondaries) = 0;

    std::string getName() const { return processName; }
};