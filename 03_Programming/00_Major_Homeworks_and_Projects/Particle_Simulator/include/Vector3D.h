#pragma once

#include <iostream>
#include <cmath>

// ==============================================================================
// Struct: Vector3D
// Updated with basic kinematics math (magnitudes and spherical conversions).
// ==============================================================================
struct Vector3D {
    double x, y, z;

    Vector3D(double valX = 0.0, double valY = 0.0, double valZ = 0.0) 
        : x(valX), y(valY), z(valZ) {}

    // Calculate the magnitude (length) of the vector
    double mag() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Generate a new vector from spherical coordinates
    // r: magnitude (momentum), theta: polar angle [0, pi], phi: azimuthal angle [0, 2pi]
    static Vector3D fromSpherical(double r, double theta, double phi) {
        return Vector3D(
            r * std::sin(theta) * std::cos(phi),
            r * std::sin(theta) * std::sin(phi),
            r * std::cos(theta)
        );
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")";
    }
};