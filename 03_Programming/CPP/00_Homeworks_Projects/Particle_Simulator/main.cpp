#include <iostream>
#include <memory>

// Include our custom engine headers
#include "Vector3D.h"
#include "Particle.h"
#include "Track.h"
#include "Material.h"
#include "Box.h"
#include "Ionization.h"
#include "Decay.h"
#include "RunManager.h"

int main() {
    std::cout << "========================================================\n";
    std::cout << "   TOY MONTE CARLO SIMULATION: BOUNDARY CROSSING        \n";
    std::cout << "========================================================\n\n";

    // ==========================================================================
    // 1. INITIALIZE MATERIALS & GEOMETRY
    // ==========================================================================
    auto lead = std::make_shared<Material>("Lead (Pb)", 11.35); 
    RunManager runManager;
    
    // Create a Lead Box. 
    // hZ = 10.0 means it spans from Z = -10.0 to Z = +10.0
    auto leadBlock = std::make_unique<Box>("Target_LeadBlock", 50.0, 50.0, 10.0, lead);
    runManager.addVolume(std::move(leadBlock));

    // ==========================================================================
    // 2. DEFINE STATIC PARTICLE PROPERTIES
    // ==========================================================================
    Particle electronDef(11, "Electron", 0.000511, -1.0, 0.5, -1.0); 
    
    // We use the short-lived Toy Muon again so you can guarantee seeing the 
    // decay happen shortly after it hits the lead block.
    Particle muonDef(13, "Toy_Muon", 0.105658, -1.0, 0.5, 0.001);

    // ==========================================================================
    // 3. REGISTER PHYSICS PROCESSES
    // ==========================================================================
    runManager.addPhysicsProcess(std::make_unique<Ionization>());
    runManager.addPhysicsProcess(std::make_unique<Decay>(&electronDef)); 

    // ==========================================================================
    // 4. INITIALIZE THE PRIMARY TRACK
    // ==========================================================================
    std::cout << ">>> INJECTING PRIMARY MUON INTO THE VACUUM >>>\n";
    
    // Start particle at Z = -20 (10 cm OUTSIDE the lead block)
    Vector3D initialPosition(0.0, 0.0, -20.0);       
    Vector3D initialMomentum(0.0, 0.0, 5.0);       
    double initialKinEnergy = 5.0;             

    Track primaryMuon(&muonDef, initialPosition, initialMomentum, initialKinEnergy);

    // ==========================================================================
    // 5. EXECUTE THE SIMULATION
    // ==========================================================================
    // We step in 2 cm intervals. 
    // Step 0 to 4: Vacuum
    // Step 5+: Inside the Lead Block
    double stepLength = 2.0; 
    int maxStepsPerTrack = 30; 
    
    runManager.simulateEvent(primaryMuon, stepLength, maxStepsPerTrack);

    return 0;
}