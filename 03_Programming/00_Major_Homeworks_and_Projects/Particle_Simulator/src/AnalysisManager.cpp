#include "AnalysisManager.h"

// Now we actually include the ROOT headers in the .cpp file
#include <TFile.h>
#include <TH1D.h>
#include <iostream>

AnalysisManager::AnalysisManager(const std::string& filename) {
    // RECREATE: Overwrite the file if it already exists
    outputFile = std::make_unique<TFile>(filename.c_str(), "RECREATE");
    
    // Initialize pointers to nullptr for safety
    hEnergyDeposition = nullptr;
    hDecayPositionZ = nullptr;
    hTimeOfFlight = nullptr;
    
    std::cout << "[AnalysisManager] Output file created: " << filename << "\n";
}

AnalysisManager::~AnalysisManager() {
    // Memory cleanup is handled by unique_ptr for TFile, 
    // ROOT automatically deletes histograms attached to the file when closed.
}

void AnalysisManager::initializeHistograms() {
    // Ensure we are writing to the correct file directory in memory
    outputFile->cd();
    
    // TH1D(name, title, bins, x_min, x_max)
    hEnergyDeposition = new TH1D("hEdep", "Energy Deposition;Energy (GeV);Counts", 100, 0.0, 1.0);
    hDecayPositionZ   = new TH1D("hDecayZ", "Decay Vertex Position;Z (cm);Counts", 100, -50.0, 50.0);
    hTimeOfFlight     = new TH1D("hTOF", "Time of Flight;Time (ns);Counts", 100, 0.0, 10.0);
    
    std::cout << "[AnalysisManager] Histograms initialized.\n";
}

void AnalysisManager::fillEnergyDeposition(double edep) {
    if (hEnergyDeposition && edep > 0.0) {
        hEnergyDeposition->Fill(edep);
    }
}

void AnalysisManager::fillDecayPosition(double zPos) {
    if (hDecayPositionZ) {
        hDecayPositionZ->Fill(zPos);
    }
}

void AnalysisManager::fillTimeOfFlight(double time) {
    if (hTimeOfFlight) {
        hTimeOfFlight->Fill(time);
    }
}

void AnalysisManager::saveAndClose() {
    if (outputFile && outputFile->IsOpen()) {
        outputFile->cd();
        outputFile->Write(); // Write all attached histograms to the file
        outputFile->Close();
        std::cout << "[AnalysisManager] Data saved successfully. File closed.\n";
    }
}