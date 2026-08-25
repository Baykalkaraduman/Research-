#pragma once

#include <string>
#include <memory>
#include "Material.h"
#include "Vector3D.h"

// ==============================================================================
// Abstract Base Class: Volume
// Represents a generic geometric boundary filled with a specific material.
// Combines concepts of G4VSolid and G4LogicalVolume for this toy model.
// ==============================================================================
class Volume {
protected:
    std::string name;
    
    // We use shared_ptr because multiple volumes can share the exact same Material object.
    // This prevents memory duplication (Flyweight pattern).
    std::shared_ptr<Material> material; 

public:
    Volume(std::string volName, std::shared_ptr<Material> mat)
        : name(std::move(volName)), material(std::move(mat)) {}

    // CRITICAL: Virtual Destructor for safe polymorphic memory management
    virtual ~Volume() = default;

    // ==========================================================================
    // PURE VIRTUAL FUNCTION (= 0)
    // Any derived class (like Box or Cylinder) MUST implement this logic.
    // It returns true if a given point in 3D space is inside this volume.
    // ==========================================================================
    virtual bool isInside(const Vector3D& point) const = 0;

    // Getters
    std::string getName() const { return name; }
    std::shared_ptr<Material> getMaterial() const { return material; }
};