#include "Track.h"
#include <iostream>

// ==============================================================================
// Constructor Implementation
// ==============================================================================
Track::Track(const Particle* pDef, const Vector3D& initPos, const Vector3D& initMom, double initKinEnergy)
    : particleDefinition(pDef), 
      position(initPos), 
      momentum(initMom), 
      kineticEnergy(initKinEnergy), 
      globalTime(0.0), 
      isAlive(true) 
{
    // The track starts at global time t = 0.0 with the given initial kinematics.
}

// ==============================================================================
// Getters
// ==============================================================================
const Particle* Track::getParticleDefinition() const { return particleDefinition; }
Vector3D Track::getPosition() const { return position; }
Vector3D Track::getMomentum() const { return momentum; }
double Track::getKineticEnergy() const { return kineticEnergy; }
bool Track::getTrackStatus() const { return isAlive; }

// We alias getTime to return globalTime to keep RunManager/AnalysisManager happy
double Track::getTime() const { return globalTime; }
double Track::getGlobalTime() const { return globalTime; }

// ==============================================================================
// Setters / Kinematic Updaters
// ==============================================================================
void Track::updatePosition(const Vector3D& newPos) {
    position = newPos;
}

void Track::updateMomentum(const Vector3D& newMom) {
    momentum = newMom;
}

// Unified time updater
void Track::addTime(double deltaTime) {
    globalTime += deltaTime;
}

void Track::deductEnergy(double energyLoss) {
    kineticEnergy -= energyLoss;
    // If kinetic energy drops to zero or below, the particle stops.
    if (kineticEnergy <= 0.0) {
        kineticEnergy = 0.0;
        killTrack();
    }
}

void Track::killTrack() {
    isAlive = false;
}

// ==============================================================================
// Display Utility
// ==============================================================================
void Track::displayState() const {
    std::cout << "  [Track State] Time: " << globalTime << " ns | Alive: " << (isAlive ? "Yes" : "No") << "\n";
    std::cout << "  -> Position : "; position.display(); std::cout << " cm\n";
    std::cout << "  -> Momentum : "; momentum.display(); std::cout << " GeV/c\n";
    std::cout << "  -> KinEnergy: " << kineticEnergy << " GeV\n";
    std::cout << "  --------------------------------------------------\n";
}