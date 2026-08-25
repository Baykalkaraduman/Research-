#include "Decay.h"
#include <iostream>
#include <cmath>

Decay::Decay(const Particle* productDef) 
    : PhysicsProcess("Decay"), rng(std::random_device{}()), decayProductDef(productDef) {}

void Decay::doIt(Track& track, const Material& material, double stepLength, std::vector<Track>& secondaries) {
    double lifetime = track.getParticleDefinition()->getLifetime();
    if (lifetime < 0.0) return; 

    double mass = track.getParticleDefinition()->getMass();
    double gamma = (track.getKineticEnergy() / mass) + 1.0;
    double beta = std::sqrt(1.0 - (1.0 / (gamma * gamma)));
    
    double dt = stepLength / (beta * 30.0);
    double probability = 1.0 - std::exp(-dt / (gamma * lifetime));

    std::uniform_real_distribution<double> distProb(0.0, 1.0);
    
    if (distProb(rng) < probability) {
        std::cout << "    [" << processName << "] *** DECAY TRIGGERED! ***\n";
        
        // 1. Generate random angles for isotropic emission
        std::uniform_real_distribution<double> distTheta(0.0, M_PI);   // Polar angle: 0 to pi
        std::uniform_real_distribution<double> distPhi(0.0, 2.0 * M_PI); // Azimuthal angle: 0 to 2pi
        
        double theta = distTheta(rng);
        double phi = distPhi(rng);

        // 2. Assign remaining kinetic energy to the secondary (Simplified toy physics)
        double productKinEnergy = track.getKineticEnergy() * 0.8; // e.g., Neutrinos carry 20% away
        double productMomentumMag = productKinEnergy; // Approx E ~ p for highly relativistic electrons
        
        // 3. Create momentum vector from angles
        Vector3D productMomentum = Vector3D::fromSpherical(productMomentumMag, theta, phi);

        // 4. Create the secondary track and push to the stack
        Track secondaryTrack(decayProductDef, track.getPosition(), productMomentum, productKinEnergy);
        secondaries.push_back(secondaryTrack);

        std::cout << "    [" << processName << "] Spawned Secondary: " << decayProductDef->getName() 
                  << " at Theta: " << theta << ", Phi: " << phi << "\n";

        // 5. Kill the parent track
        track.killTrack(); 
    }
}