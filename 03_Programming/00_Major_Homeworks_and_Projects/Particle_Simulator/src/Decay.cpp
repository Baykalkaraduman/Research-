#include "Decay.h"
#include <iostream>
#include <cmath>
#include <random> // Added for std::random_device and distributions

// Constructor: Initializes the random number generator and sets the decay product
Decay::Decay(const Particle* productDef) 
    : PhysicsProcess("Decay"), rng(std::random_device{}()), decayProductDef(productDef) {}

void Decay::doIt(Track& track, const Material& material, double stepLength, std::vector<Track>& secondaries) {
    double lifetime = track.getParticleDefinition()->getLifetime();
    if (lifetime < 0.0) return; // Stable particle check

    // ==========================================================================
    // 1. RELATIVISTIC KINEMATICS & TIME FACTOR
    // ==========================================================================
    double mass = track.getParticleDefinition()->getMass();
    double gamma = (track.getKineticEnergy() / mass) + 1.0;
    double beta = std::sqrt(1.0 - (1.0 / (gamma * gamma)));
    
    // dt is time spent in this step. Assuming c = 30 cm/ns.
    double dt = stepLength / (beta * 30.0);
    
    // Exponential decay probability including relativistic time dilation (gamma * lifetime)
    double probability = 1.0 - std::exp(-dt / (gamma * lifetime));

    // ==========================================================================
    // 2. MONTE CARLO STOCHASTIC TRIGGER
    // ==========================================================================
    std::uniform_real_distribution<double> distProb(0.0, 1.0);
    
    if (distProb(rng) < probability) {
        std::cout << "    [" << processName << "] *** DECAY TRIGGERED! ***\n";
        
        // Generate random angles for isotropic emission (Sphere surface)
        std::uniform_real_distribution<double> distTheta(0.0, M_PI);     // Polar angle: 0 to pi
        std::uniform_real_distribution<double> distPhi(0.0, 2.0 * M_PI); // Azimuthal angle: 0 to 2pi
        
        double theta = distTheta(rng);
        double phi = distPhi(rng);

        // ==========================================================================
        // 3. SECONDARY PARTICLE GENERATION
        // ==========================================================================
        // Assign remaining kinetic energy to the secondary (Simplified toy physics)
        double productKinEnergy = track.getKineticEnergy() * 0.8; // e.g., Neutrinos carry 20% away
        double productMomentumMag = productKinEnergy; // Approx E ~ p for highly relativistic electrons
        
        // Create momentum vector from spherical coordinates
        Vector3D productMomentum = Vector3D::fromSpherical(productMomentumMag, theta, phi);

        // Create the secondary track and push to the stack
        Track secondaryTrack(decayProductDef, track.getPosition(), productMomentum, productKinEnergy);
        secondaries.push_back(secondaryTrack);

        std::cout << "    [" << processName << "] Spawned Secondary: " << decayProductDef->getName() 
                  << " at Theta: " << theta << ", Phi: " << phi << "\n";

        // ==========================================================================
        // 4. TERMINATE PARENT TRACK
        // ==========================================================================
        track.killTrack(); 
    }
}