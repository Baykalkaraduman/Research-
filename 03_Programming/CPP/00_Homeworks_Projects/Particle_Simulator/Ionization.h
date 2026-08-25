#pragma once

#include "PhysicsProcess.h"

// ==============================================================================
// Derived Class: Ionization
// Mocks the continuous energy loss of a charged particle in a medium.
// Conceptually similar to G4eIonisation.
// ==============================================================================
class Ionization : public PhysicsProcess {
public:
    Ionization();

    // Overrides the base class method to implement ionization logic
    virtual void doIt(Track& track, const Material& material, double stepLength, std::vector<Track>& secondaries) override;
};