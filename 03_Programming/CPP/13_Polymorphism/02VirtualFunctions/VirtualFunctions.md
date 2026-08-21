# C++ Dynamic Polymorphism & Virtual Functions

## Concept Overview & Core Mechanics
**Polymorphism** (specifically Dynamic or Runtime Polymorphism) allows objects of different derived classes to be treated uniformly through a pointer or reference of a common base class. 

* **Dynamic Binding (Late Binding):** In C++, function calls are normally resolved at compile-time (Static Binding). Adding the `virtual` keyword tells the compiler to defer this resolution to runtime. The compiler creates a hidden **V-Table (Virtual Table)** for the class to look up the actual object type dynamically and invoke the correct overridden function.
* **Base Class Pointers:** To achieve dynamic polymorphism, you must use base class pointers (e.g., `Account*`) or references (e.g., `Account&`). This allows a single container (like a `std::vector<Account*>`) to hold various derived objects (like `Checking`, `Savings`, `Trust`).
* **Virtual Destructors:** If a class is meant to be inherited and used polymorphically, its base destructor **must** be declared as `virtual`. This guarantees that when you call `delete` on a base class pointer, the derived class's destructor executes first, followed by the base class's destructor, preventing severe memory leaks.

---

## Syntax & Minimal Clean Code Examples

### 1. Base Class Setup (The Interface)
```cpp
class Account {
public:
    // The 'virtual' keyword enables runtime overriding
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw\n";
    }
    
    // CRITICAL: Always provide a virtual destructor in polymorphic base classes
    virtual ~Account() = default; 
};
```

### 2. Derived Class (The Implementation)
*Modern C++ Best Practice:* Always append the `override` keyword in derived classes. It tells the compiler to verify that a base virtual function is actually being overridden, preventing bugs caused by typos in function signatures.

```cpp
class Checking : public Account {
public:
    // 'override' ensures compile-time safety
    void withdraw(double amount) override { 
        std::cout << "In Checking::withdraw\n";
    }
};
```

### 3. Execution (Dynamic Allocation and Iteration)
Using modern C++ standard containers (`std::vector`) to manage collections of polymorphic objects dynamically:

```cpp
#include <iostream>
#include <vector>

int main() {
    // Storing derived objects in a vector of base class pointers
    std::vector<Account*> accounts;
    accounts.push_back(new Checking());
    accounts.push_back(new Account()); // Assuming Account is not purely abstract

    // Late binding in action
    for(Account* acc : accounts) {
        acc->withdraw(1000.0); // Output depends on the actual object type in memory
    }

    // Clean up to prevent memory leaks
    for(Account* acc : accounts) {
        delete acc; // Safely calls derived destructors because ~Account is virtual
    }

    return 0;
}
```

---

## Common Pitfalls & Edge Cases

* **Missing Virtual Destructor (Memory Leaks):**
  * *Anti-pattern:* Deleting a derived object via a base pointer when the base lacks a `virtual` destructor. The derived portion of the object (and any memory it allocated) is never cleaned up.
* **Object Slicing (Pass-by-Value):**
  * *Anti-pattern:* Defining a function like `void processAccount(Account acc);`. If you pass a `Checking` object, it gets "sliced" into a basic `Account`, losing all its derived traits and V-Table linkages.
  * *Best Practice:* Always pass polymorphic objects by pointer (`Account*`) or reference (`Account&`).
* **Accidental Overloading instead of Overriding:**
  * *Anti-pattern:* Writing `virtual void withdraw(int amount)` in the derived class instead of matching the base signature `(double amount)`. The compiler treats this as a brand-new function. The base function is not overridden.
  * *Best Practice:* Using `override` throws a compiler error if the signature doesn't match perfectly.

---

## Scientific & Physics Simulation Applications

Dynamic polymorphism is the backbone of modular computational architectures. It allows you to build generic simulation loops without writing massive `if/else` statements for every new type of entity.

* **Particle Systems & N-Body Simulations:**
  * **Base:** `class Particle { public: virtual void updatePosition(double dt) = 0; virtual ~Particle() = default; };`
  * **Derived:** `Proton`, `Electron`, `Photon`.
  * **Usage:** Maintain a single `std::vector<Particle*> universe`. The main simulation loop simply calls `p->updatePosition(dt)` on every element. Relativistic logic for a `Photon` and classical mechanics for a `Proton` are executed dynamically.
* **Numerical ODE Solvers:**
  * **Base:** `class ODESolver { public: virtual State step(const State& s, double dt) = 0; virtual ~ODESolver() = default; };`
  * **Derived:** `EulerMethod`, `RungeKutta4`, `VerletIntegration`.
  * **Usage:** Swap integration schemes at runtime without altering the core simulation logic by pointing an `ODESolver* solver` to a different algorithm.
* **Collision Detection Systems (Broad-phase/Narrow-phase):**
  * **Base:** `class Collider { public: virtual bool checkCollision(Collider* other) = 0; virtual ~Collider() = default; };`
  * **Derived:** `SphereCollider`, `AABBCollider`, `MeshCollider`.

---

## Key Takeaways & Cheatsheet

* `virtual` = "Look up the actual object type at runtime."
* Polymorphism **only** works with pointers (`*`) and references (`&`).
* Always explicitly write `override` in derived class functions.
* **Golden Rule:** If a class has at least one `virtual` function, it **must** have a `virtual` destructor.
* *Performance Note:* Dynamic binding adds a slight runtime overhead due to V-Table lookups (pointer dereferencing). In ultra-high-performance physics loops (e.g., millions of particles per frame), cache misses from pointer arrays can be a bottleneck, where Data-Oriented Design (DOD) might be preferred over standard Object-Oriented Programming (OOP).