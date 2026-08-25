#include "RunManager.h"
#include "Material.h" // Required for the static Vacuum material
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
            
            // Create a dummy Vacuum material for physics processes that happen outside volumes (like Decay)
            static Material vacuum("Vacuum", 0.0); 
            Material* currentMaterial = &vacuum;
            
            if (currentVolume != nullptr) {
                currentMaterial = currentVolume->getMaterial().get();
                std::cout << "    [Geometry] Particle is inside: " << currentVolume->getName() 
                          << " (Material: " << currentMaterial->getName() << ")\n";
            } else {
                std::cout << "    [Geometry] Particle is in vacuum (Out of defined volumes).\n";
            }

            std::vector<Track> stepSecondaries;

            // =========================================================
            // 1. CAPTURE INITIAL ENERGY BEFORE PHYSICS
            // =========================================================
            double initialEnergy = currentTrack.getKineticEnergy();

            // Apply physics processes for ALL steps (Vacuum AND Material)
            for (const auto& process : physicsList) {
                // Pass either the Lead block material or the dummy Vacuum material
                process->doIt(currentTrack, *currentMaterial, stepLength, stepSecondaries);
                if (!currentTrack.getTrackStatus()) break; // Stop if particle decayed or stopped
            }

            // =========================================================
            // 2. CALCULATE AND RECORD ENERGY LOSS
            // =========================================================
            if (analysisManager != nullptr) {
                double energyLoss = initialEnergy - currentTrack.getKineticEnergy();
                // In vacuum, density is 0, so Ionization will result in energyLoss = 0.0. 
                // It will only log when energy is actually deposited in a volume.
                if (energyLoss > 0.0) {
                    analysisManager->fillEnergyDeposition(energyLoss);
                }
            }

            // =========================================================
            // 3. RECORD DECAY KINEMATICS IF PARTICLE DIED
            // =========================================================
            if (!currentTrack.getTrackStatus() && analysisManager != nullptr) {
                analysisManager->fillDecayPosition(currentTrack.getPosition().z);
                analysisManager->fillTimeOfFlight(currentTrack.getTime());
            }

            // If any secondaries were produced, push them onto the global stack
            for (const auto& sec : stepSecondaries) {
                trackStack.push_back(sec);
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
                    
                    // Advance time accurately based on velocity (approximated as momentum 'p' for this toy model)
                    double dt = stepLength / p; 
                    currentTrack.addTime(dt); 
                }
            }
            stepCounter++;
        }
    }
    std::cout << "\n=== RUN MANAGER: EVENT COMPLETED (No tracks left) ===\n";
}