#pragma once

#include <vector>
#include <memory>
#include "Volume.h"
#include "Track.h"
#include "PhysicsProcess.h"

// ==============================================================================
// Class: RunManager
// Manages geometry, physics processes, and the main event stepping loop.
// Updated to support secondary particle generation and a Track Stack.
// ==============================================================================
class RunManager {
private:
    std::vector<std::unique_ptr<Volume>> geometryDB;
    std::vector<std::unique_ptr<PhysicsProcess>> physicsList;

public:
    RunManager() = default;
    ~RunManager() = default;

    // ==========================================================================
    // Registration Methods
    // ==========================================================================
    void addVolume(std::unique_ptr<Volume> vol);
    void addPhysicsProcess(std::unique_ptr<PhysicsProcess> process);

    Volume* getVolumeAt(const Vector3D& point) const;

    // ==========================================================================
    // Simulation Execution
    // ==========================================================================
    // Renamed to simulateEvent. Takes the primary track as a constant reference 
    // and handles all subsequent secondary particles using an internal stack.
    void simulateEvent(const Track& primaryTrack, double stepLength, int maxSteps);
};