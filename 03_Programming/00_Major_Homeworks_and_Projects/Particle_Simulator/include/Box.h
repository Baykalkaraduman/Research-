#pragma once

#include "Volume.h"
#include <cmath> // For std::abs

// ==============================================================================
// Derived Class: Box
// Represents a rectangular cuboid volume centered at the origin.
// Equivalent to G4Box.
// ==============================================================================
class Box : public Volume {
private:
    // Geant4 standard: using half-lengths (hx, hy, hz) from the center.
    // A box with hx=5 cm has a total width of 10 cm (-5 to +5).
    double hx, hy, hz;

public:
    // Constructor passes the name and material UP to the base Volume class
    Box(std::string boxName, double halfX, double halfY, double halfZ, std::shared_ptr<Material> mat)
        : Volume(std::move(boxName), std::move(mat)), hx(halfX), hy(halfY), hz(halfZ) {}

    // ==========================================================================
    // OVERRIDE: Implementing the pure virtual function from Volume.
    // Checks if the absolute values of x, y, z are within the half-lengths.
    // ==========================================================================
    bool isInside(const Vector3D& point) const override {
        // If the point is exactly on the boundary, we consider it inside (<=)
        if (std::abs(point.x) <= hx && 
            std::abs(point.y) <= hy && 
            std::abs(point.z) <= hz) {
            return true;
        }
        return false;
    }
};