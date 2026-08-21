# C++ Exception Handling: `try`, `throw`, `catch`

## Concept Overview & Core Mechanics
In older languages like C, errors were handled by returning specific integer codes (e.g., returning `-1` if a function failed). This required developers to constantly check return values, tangling the "happy path" (what the program is supposed to do) with error-handling logic.

C++ introduces **Exception Handling**, an object-oriented mechanism to handle runtime anomalies. 
* **Separation of Concerns:** It completely separates the main logic from the error-handling logic.
* **Stack Unwinding:** When an exception is thrown inside a deep function call, C++ automatically aborts the current function, safely destroys all local variables (calling their destructors), and travels back up the call stack until it finds a matching `catch` block.
* **The 3 Keywords:**
  1. **`try`**: A block of code where you expect an error *might* happen.
  2. **`throw`**: The keyword used to signal that an error has occurred. It immediately aborts the current block.
  3. **`catch`**: The block of code designed to handle a specific type of thrown error.

## Syntax & Minimal Clean Code Examples

### 1. Basic Flow (Primitives)
*(Note: Throwing integers/strings is generally discouraged, but used here to demonstrate the raw mechanic).*
```cpp
void calculateSpeed(double distance, double time) {
    if (time <= 0.0) {
        throw -1; // Aborts function immediately
    }
    std::cout << "Speed: " << distance / time << "\n";
}

int main() {
    try {
        calculateSpeed(100.0, 0.0);
        std::cout << "This line will NEVER print.\n";
    } catch (int& ex) {
        std::cerr << "Error Caught! Time cannot be zero.\n";
    }
    return 0;
}
```

### 2. Modern Standard (Object-Oriented Exceptions)
Instead of primitives, modern C++ uses classes derived from `std::exception` (found in the `<stdexcept>` header).

```cpp
#include <stdexcept>
#include <iostream>

double divide(double a, double b) {
    if (b == 0) {
        // Throwing a standard exception object with a descriptive message
        throw std::invalid_argument("Division by zero error in divide().");
    }
    return a / b;
}

int main() {
    try {
        divide(10.0, 0.0);
    } catch (const std::exception& ex) {
        // Using the polymorphic .what() method to print the error string
        std::cerr << "CRITICAL FAILURE: " << ex.what() << std::endl;
    }
    return 0;
}
```

## Common Pitfalls & Edge Cases

* **Catching by Value instead of Reference:**
  * *Anti-pattern:* `catch (std::exception ex)`
  * *Why:* This copies the exception object, which is inefficient and causes "Object Slicing" (you lose the specific derived exception data).
  * *Best Practice:* Always catch by `const` reference: `catch (const std::exception& ex)`.
* **Throwing Raw Pointers:**
  * *Anti-pattern:* `throw new Exception();`
  * *Why:* The `catch` block is now responsible for calling `delete` on that pointer. If it forgets, you have a memory leak. Throw objects by value, and catch by reference!
* **Exceptions in Destructors (The Ultimate Taboo):**
  * *Rule:* **NEVER** throw an exception from inside a Destructor (`~MyClass()`). If an exception is thrown while the stack is already unwinding from a *previous* exception, the C++ runtime will immediately terminate the entire program via `std::terminate()`.
* **Resource Leaks (The Case for Smart Pointers):**
  * If you use a raw pointer (`int* p = new int;`) and an exception is thrown before `delete p;` is called, the memory is leaked. `std::unique_ptr` solves this, as its destructor is automatically called during stack unwinding.

## Scientific & Physics Simulation Applications

Exception handling is crucial for preventing silent mathematical failures or data corruption during long computations.

* **Numerical Instability in Solvers:**
  * **Scenario:** A Matrix Inversion algorithm encounters a Singular Matrix (determinant is 0).
  * **Action:** Instead of returning a matrix full of garbage `NaN` (Not-a-Number) values that will silently ruin the rest of the simulation, the solver `throw std::domain_error("Matrix is singular");`. The main simulation loop catches it, logs the exact timestep it failed, and safely shuts down or reduces the integration time-step (dt).
* **Missing Mesh/Data Files:**
  * **Scenario:** A CFD simulation requires an initial geometry file (`mesh.obj`).
  * **Action:** If `std::ifstream` fails to open the file, the loader `throw std::runtime_error("mesh.obj not found in working directory.");`. This prevents the engine from allocating Gigabytes of empty memory.
* **Out of Range Particle Access:**
  * If a physics kernel tries to access `particles.at(9999)` but only 1000 exist, `std::vector::at()` automatically throws a `std::out_of_range` exception. Handling this cleanly prevents abrupt segmentation faults.

## Key Takeaways & Cheatsheet

* **`try { ... }`**: Put your risky code here.
* **`throw X;`**: Signal an error and abort the current path.
* **`catch (const Type& ex) { ... }`**: Handle the error gracefully.
* **`<stdexcept>` header**: Contains standard exceptions like `std::runtime_error`, `std::invalid_argument`, and `std::out_of_range`.
* **Catch all block:** `catch (...) { ... }` catches literally *anything* thrown, but gives you no access to the error data. Useful as a final safety net at the bottom of `main()`.