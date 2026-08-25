#include "RunManager.h"
#include <iostream>

// ==========================================================================
// Geometry & Physics Registration
// ==========================================================================

void RunManager::addVolume(std::unique_ptr<Volume> vol) {
    geometryDB.push_back(std::move(vol));
}

void RunManager::addPhysicsProcess(std::unique_ptr<PhysicsProcess> process) {
    physicsList.push_back(std::move(process));
}

Volume* RunManager::getVolumeAt(const Vector3D& point) const {
    for (const auto& vol : geometryDB) {
        if (vol->isInside(point)) {
            return vol.get(); 
        }
    }
    return nullptr;
}

// ==========================================================================
// Main Event Simulation Loop (Track Stack & Secondaries)
// ==========================================================================

void RunManager::simulateEvent(const Track& primaryTrack, double stepLength, int maxSteps) {
    std::cout << "\n=== RUN MANAGER: EVENT START ===\n";
    
    // The Track Stack (LIFO buffer)
    std::vector<Track> trackStack;
    trackStack.push_back(primaryTrack);

    int trackCounter = 1;

    // Main Event Loop: Runs until no particles are left in the stack
    while (!trackStack.empty()) {
        // Pop the last added track from the stack
        Track currentTrack = trackStack.back();
        trackStack.pop_back();

        std::cout << "\n==================================================\n";
        std::cout << ">>> TRACKING PARTICLE " << trackCounter++ 
                  << " (" << currentTrack.getParticleDefinition()->getName() << ") >>>\n";
        std::cout << "==================================================\n";

        int stepCounter = 0;
        
        // Single Track Stepping Loop
        while (currentTrack.getTrackStatus() && stepCounter < maxSteps) {
            std::cout << "\n--- Step " << stepCounter << " ---\n";
            
            // --- DETAILED STATE OUTPUT (Time, Position, Momentum, Energy) ---
            currentTrack.displayState();

            Volume* currentVolume = getVolumeAt(currentTrack.getPosition());
            
            if (currentVolume != nullptr) {
                // Buffer to hold newly created particles in this specific step
                std::cout << "    [Geometry] Particle is inside: " << currentVolume->getName() 
                          << " (Material: " << currentVolume->getMaterial()->getName() << ")\n";
                std::vector<Track> stepSecondaries;

                // Apply physics processes (e.g., Ionization, Decay)
                for (const auto& process : physicsList) {
                    process->doIt(currentTrack, *(currentVolume->getMaterial()), stepLength, stepSecondaries);
                    if (!currentTrack.getTrackStatus()) break; // Stop if particle decayed or stopped
                }

                // If any secondaries were produced, push them onto the global stack
                for (const auto& sec : stepSecondaries) {
                    trackStack.push_back(sec);
                }
            } else {
                std::cout << "    [Geometry] Particle is in vacuum (Out of defined volumes).\n";
            }

            // Only move if the particle survived the physics processes
            if (currentTrack.getTrackStatus()) {
                // Advance position based on momentum direction
                Vector3D pos = currentTrack.getPosition();
                Vector3D mom = currentTrack.getMomentum();
                double p = mom.mag();
                
                if (p > 0.0) {
                    // Normalize momentum to get direction, multiply by step length
                    Vector3D newPos(
                        pos.x + (mom.x / p) * stepLength,
                        pos.y + (mom.y / p) * stepLength,
                        pos.z + (mom.z / p) * stepLength
                    );
                    currentTrack.updatePosition(newPos);
                }
                
                // Advance time (approx 30 cm/ns for highly relativistic particles)
                currentTrack.addTime(stepLength / 30.0); 
            }
            stepCounter++;
        }
    }
    std::cout << "\n=== RUN MANAGER: EVENT COMPLETED (No tracks left) ===\n";
}