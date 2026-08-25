#pragma once

#include "Particle.h"
#include "Vector3D.h"

// ==============================================================================
// Class: Track
// Represents a particle propagating through the simulation geometry.
// Holds dynamic state (position, momentum, time) and a pointer to static properties.
// Equivalent to G4Track in Geant4.
// ==============================================================================
class Track {
private:
    // Pointer to the immutable physical properties of the particle type.
    // 'const' ensures we cannot accidentally change the mass of an electron mid-flight!
    const Particle* particleDefinition; 

    // Dynamic Kinematic State
    Vector3D position;      // Position in 3D space (e.g., cm or mm)
    Vector3D momentum;      // Momentum vector (e.g., GeV/c)
    double kineticEnergy;   // Kinetic energy (GeV)
    double globalTime;      // Time since the start of the event (ns)
    
    // Status flag
    bool isAlive;           // True if particle is moving, False if it stopped/decayed

public:
    // Constructor requires the particle definition and initial kinematics
    Track(const Particle* pDef, const Vector3D& initPos, const Vector3D& initMom, double initKinEnergy);

    // ==========================================================================
    // Getters
    // ==========================================================================
    const Particle* getParticleDefinition() const;
    Vector3D getPosition() const;
    Vector3D getMomentum() const;
    double getKineticEnergy() const;
    double getGlobalTime() const;
    bool getTrackStatus() const;

    // ==========================================================================
    // Setters / Updaters (Called by physics processes and stepping manager)
    // ==========================================================================
    void updatePosition(const Vector3D& newPos);
    void updateMomentum(const Vector3D& newMom);
    void addTime(double deltaTime);
    void deductEnergy(double energyLoss);
    
    // Kill the track (e.g., when it hits a wall, loses all energy, or decays)
    void killTrack();

    // Display track state
    void displayState() const;
};