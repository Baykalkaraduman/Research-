#pragma once

#include "PhysicsProcess.h"
#include <random>

// ==============================================================================
// Derived Class: Decay
// Simulates the spontaneous decay of unstable particles.
// ==============================================================================
class Decay : public PhysicsProcess {
private:
    std::mt19937 rng; // Standard mersenne_twister_engine for random numbers
    const Particle* decayProductDef; // The particle type this decays into (e.g., Electron)

public:
    // Constructor requires the definition of the product particle
    Decay(const Particle* productDef);
    void doIt(Track& track, const Material& material, double stepLength, std::vector<Track>& secondaries) override;
};