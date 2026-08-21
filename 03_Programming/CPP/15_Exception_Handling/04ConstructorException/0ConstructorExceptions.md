# C++ Constructor Exceptions & Smart Pointers

## Concept Overview & Core Mechanics
In C++, constructors do not have a return type. Therefore, if an object cannot be initialized to a valid state (e.g., given a negative account balance, or a missing config file), the **only** way to signal failure is to `throw` an exception from the constructor.

When a constructor throws an exception:
1. **No Zombie Objects:** The object is considered "unconstructed". It never formally exists.
2. **Destructor is Bypassed:** Because the object was never fully constructed, its destructor will **never** be called.
3. **Memory Safety with `std::make_unique`:** If you attempt to allocate the object dynamically using `std::make_unique` and the constructor throws, the C++ runtime intercepts the failure and safely deallocates the raw memory chunk it just reserved. You do not get a memory leak.

## Syntax & Minimal Clean Code Examples

### Defining the Exception & Throwing in Constructor
```cpp
#include <iostream>
#include <memory>
#include <stdexcept>

// 1. Exception Class
class HardwareFailureException : public std::exception {
public:
    const char* what() const noexcept override { return "Failed to connect to GPU"; }
};

// 2. Class throwing from constructor
class CUDASolver {
public:
    CUDASolver(bool gpu_available) {
        if (!gpu_available) {
            // Aborts instantiation immediately
            throw HardwareFailureException();
        }
        std::cout << "GPU Solver Initialized.\n";
    }
    ~CUDASolver() { std::cout << "GPU Solver Destroyed.\n"; }
};
```

### Catching and Memory Safety
```cpp
int main() {
    try {
        // Attempting to create object via smart pointer
        std::unique_ptr<CUDASolver> solver = std::make_unique<CUDASolver>(false);
    } 
    catch (const HardwareFailureException& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        // Memory allocated by make_unique is freed automatically!
    }
    return 0;
}
```

## Common Pitfalls & Edge Cases

* **The Raw Pointer Memory Leak inside Constructors:**
  * *Anti-pattern:* If a class has raw pointers as members (`int* data;`), allocates them early in the constructor (`data = new int[100];`), and *then* throws an exception later in the same constructor.
  * *Consequence:* The destructor is never called! The `data` array leaks permanently.
  * *Best Practice:* Use `std::unique_ptr` for class members. Even if the constructor throws halfway through, C++ will automatically clean up any class members that were completely constructed *before* the exception was thrown.
* **Catching Exceptions inside the Constructor (Without Re-throwing):**
  * *Anti-pattern:* Wrapping the constructor's logic in a `try-catch`, catching the error, and doing nothing (`catch(...) {}`).
  * *Consequence:* The constructor finishes executing normally. The caller thinks the object is fine, resulting in a dangerous "Zombie Object" running through your simulation. Always `throw;` again if you catch inside a constructor.

## Scientific & Physics Simulation Applications

Constructor exceptions guarantee that your mathematical models and physics engines never start calculating with physically impossible parameters.

* **Domain Validation (CFD / FEA):**
  * **Scenario:** Creating a 3D simulation grid (e.g., `Grid3D(sizeX, sizeY, sizeZ)`).
  * **Action:** If any dimension is $\le 0$, throw `std::invalid_argument`. This prevents the engine from trying to allocate massive tensors with negative dimensions, which would instantly crash the OS memory manager.
* **Sensor / Hardware Telemetry Initialization:**
  * **Scenario:** A `LidarSensor` class opens a COM port in its constructor to read physical hardware data.
  * **Action:** If the port is locked, it throws `PortUnavailableException`. The main drone/robot software catches this and falls back to camera-based navigation instead of using a broken LiDAR object.
* **Parsing Initial Conditions:**
  * In N-Body simulations, if a `Particle` object is instantiated with a mass of $0.0$, throwing an exception immediately prevents a `DivideByZero` error deep inside the gravity integration loop (e.g., $F = G \frac{m_1 m_2}{r^2}$) millions of iterations later.

## Key Takeaways & Cheatsheet

* **Constructor Failure = Throw:** It is the standard and safest way to stop an object from being created.
* **No Destructor:** The destructor is bypassed if the constructor throws.
* **Smart Pointers are King:** Combining `std::make_unique` with constructor exceptions guarantees perfect memory safety.
* **Protect Class Members:** Use smart pointers for member variables to prevent memory leaks if the class's constructor fails halfway through.