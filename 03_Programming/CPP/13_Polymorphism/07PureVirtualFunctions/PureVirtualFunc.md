# C++ Pure Virtual Functions & Abstract Base Classes

## Concept Overview & Core Mechanics
In C++, you often want to create a general class (like `Shape` or `PhysicsSolver`) that serves only as a blueprint or interface for other classes, but should never exist as an object itself. 

* **Pure Virtual Functions:** By assigning `= 0` to a virtual function declaration, you create a *pure virtual function*. This forces any derived class to provide its own implementation of that function.
* **Abstract Base Classes (ABC):** Any class containing at least one pure virtual function automatically becomes an Abstract Base Class.
* **The Immutability of ABCs:** You **cannot instantiate** an ABC. You cannot create objects of it, pass it by value, or return it by value. You can only create pointers (`Base*`) or references (`Base&`) to it, which point to derived *Concrete* classes.
* **Concrete Classes:** A derived class that implements *all* pure virtual functions of its base class(es) is called a Concrete Class. It can be instantiated.

## Syntax & Minimal Clean Code Examples

### 1. Defining the Abstract Base Class (The Interface)
```cpp
class Integrator {
public:
    // Pure virtual function: sets a mandatory contract.
    virtual void step(double dt) = 0; 
    
    // Mandatory virtual destructor for proper polymorphic cleanup
    virtual ~Integrator() = default; 
};
```

### 2. Implementing the Concrete Class
```cpp
class RungeKutta4 : public Integrator {
public:
    // Fulfills the contract. Without this, RungeKutta4 would also be abstract.
    void step(double dt) override {
        // ... RK4 mathematical implementation ...
    }
};
```

### 3. Execution
```cpp
int main() {
    // Integrator base;                  // ERROR: Cannot instantiate abstract class
    // Integrator* ptr = new Integrator; // ERROR: Cannot instantiate abstract class
    
    Integrator* solver = new RungeKutta4(); // OK: Instantiating concrete class
    solver->step(0.016);                    // Dynamic binding routes to RK4::step()
    
    delete solver;
    return 0;
}
```

## Common Pitfalls & Edge Cases

* **Forgetting to Override All Pure Virtuals:**
  * *Anti-pattern:* If a base class has three pure virtual functions and the derived class only overrides two of them, the derived class *remains abstract*. The compiler will throw an error when you try to instantiate it.
* **Providing a Body for a Pure Virtual Function:**
  * *Edge Case:* In C++, a pure virtual function *can* actually have an implementation in the base class (`void Integrator::step(double dt) { ... }`). However, derived classes are still forced to override it, but they can explicitly call the base implementation (`Integrator::step(dt);`) if shared logic exists.
* **Missing Virtual Destructor:**
  * *Anti-pattern:* Just like regular polymorphic classes, ABCs absolutely must have a `virtual` destructor. Otherwise, deleting a concrete object via an interface pointer leaks memory.

## Scientific & Physics Simulation Applications

Abstract Base Classes are the core architectural pattern used in game engines, physics engines, and numerical analysis frameworks to decouple logic.

* **Physics Forces (Strategy Pattern):**
  * **ABC:** `class ForceGenerator { public: virtual void applyForce(Particle& p) = 0; };`
  * **Concrete:** `Gravity`, `SpringForce`, `AerodynamicDrag`.
  * **Usage:** A simulation loop holds a `std::vector<ForceGenerator*>`. You can dynamically add/remove wind or gravity without rewriting the main physics loop.
* **Numerical Solvers (Pluggable Architecture):**
  * **ABC:** `class ODESolver { public: virtual State solve(const System& sys, double dt) = 0; };`
  * **Concrete:** `EulerMethod`, `Verlet`, `RungeKutta4`.
  * **Usage:** Allows the user to select the precision vs. performance tradeoff at runtime by simply swapping the solver pointer.
* **Rendering Backends:**
  * **ABC:** `class Renderer { public: virtual void drawMesh(const Mesh& m) = 0; };`
  * **Concrete:** `OpenGLRenderer`, `VulkanRenderer`, `DirectXRenderer`.
  * **Usage:** The core engine writes purely to the `Renderer` interface, making the software entirely cross-platform.

## Key Takeaways & Cheatsheet

* **`= 0`** at the end of a virtual function makes it *pure*.
* **1 Pure Virtual Function = Abstract Class.**
* **Abstract Classes cannot be instantiated.** (No `Base b;`)
* Derived classes must implement **every single** pure virtual function to become *Concrete* (instantiable).
* Always provide a `virtual ~Base() = default;` in your ABCs.
* Pointers and references to ABCs are perfectly valid and form the basis of dynamic polymorphism.