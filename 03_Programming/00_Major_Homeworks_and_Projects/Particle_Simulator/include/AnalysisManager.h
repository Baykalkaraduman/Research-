#ifndef ANALYSIS_MANAGER_H
#define ANALYSIS_MANAGER_H

#include <string>
#include <memory>

// Forward declarations for ROOT classes
class TFile;
class TH1D;

class AnalysisManager {
private:
    std::unique_ptr<TFile> outputFile;
    
    // ROOT Histograms
    TH1D* hEnergyDeposition;
    TH1D* hDecayPositionZ;
    TH1D* hTimeOfFlight;

public:
    // Constructor takes the desired output filename
    AnalysisManager(const std::string& filename);
    ~AnalysisManager();

    // Setup and wrap up
    void initializeHistograms();
    void saveAndClose();

    // Data filling methods
    void fillEnergyDeposition(double edep);
    void fillDecayPosition(double zPos);
    void fillTimeOfFlight(double time);
};

#endif // ANALYSIS_MANAGER_H