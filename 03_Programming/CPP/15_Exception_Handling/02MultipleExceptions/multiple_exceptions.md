# C++ Multiple Exceptions & Handler Ordering

## Concept Overview & Core Mechanics
In robust applications, a single block of code or a single function might fail for several different reasons. C++ allows you to throw different types of exceptions and set up multiple `catch` blocks to handle each specific failure case independently.

* **Type Matching:** When an exception is thrown, the C++ runtime searches sequentially (from top to bottom) through the attached `catch` blocks. It executes the **first** block that matches the type of the thrown object.
* **Catch-All Handler:** Sometimes you want a final safety net for exceptions you didn't explicitly anticipate. C++ provides a special syntax `catch (...)` (literally three dots) that acts as a default handler for *any* exception type.
* **Polymorphic Catching:** In modern C++, exceptions are usually derived from a base class (`std::exception`). The order in which you arrange your catch blocks is critically important when inheritance is involved.

## Syntax & Minimal Clean Code Examples

### Standard Multiple Handlers with a Catch-All
*(Using standard exception classes instead of primitives like `int` or `string`)*

```cpp
#include <iostream>
#include <stdexcept>
#include <vector>

void processSimulationData(int dataSize, int index) {
    if (dataSize < 0)
        throw std::invalid_argument("Data size cannot be negative.");
    if (index >= dataSize)
        throw std::out_of_range("Index exceeds data bounds.");
    if (dataSize == 0)
        throw 0; // Legacy code throwing primitive integer
}

int main() {
    try {
        processSimulationData(-5, 10);
    } 
    catch (const std::invalid_argument& ex) {
        std::cerr << "Argument Error: " << ex.what() << "\n";
    } 
    catch (const std::out_of_range& ex) {
        std::cerr << "Bounds Error: " << ex.what() << "\n";
    } 
    catch (...) { 
        // The Catch-All block MUST be the very last catch block.
        // It catches the thrown '0' or any other unhandled types.
        std::cerr << "Unknown exception caught! Emergency shutdown.\n";
    }
    return 0;
}
```

## Common Pitfalls & Edge Cases

* **The Catch Block Ordering Trap (Base vs. Derived):**
  * *Anti-pattern:* Putting a base class `catch` block *before* a derived class `catch` block.
    ```cpp
    try { /* ... */ }
    catch (const std::exception& ex) { /* Catches EVERYTHING derived from std::exception */ }
    catch (const std::runtime_error& ex) { /* UNREACHABLE CODE! */ }
    ```
  * *Why:* C++ checks top-to-bottom. Since `std::runtime_error` IS-A `std::exception`, the first block catches it. The specific `runtime_error` block will never execute.
  * *Best Practice:* Always order catch blocks from the **most specific** (derived) to the **least specific** (base).
* **Catching by Value Instead of Reference:**
  * *Anti-pattern:* `catch (std::exception ex)`. If you catch by value and a derived exception (like `std::out_of_range`) was thrown, the object gets "sliced" into a generic `std::exception`. You lose the specific data. Always use `catch (const std::exception& ex)`.
* **Putting `catch(...)` First:**
  * The compiler will actively reject `catch(...)` if it is not placed at the very end of the `try-catch` chain.

## Scientific & Physics Simulation Applications

Multiple exceptions allow a simulation engine to decide whether a failure is recoverable (requires adjusting parameters) or fatal (requires an immediate abort).

* **Numerical ODE Solvers (e.g., Runge-Kutta):**
  * **Scenario:** A physics timestep evaluation fails. 
  * **Handling:**
    1. `catch(const DivergenceError& ex)`: The math exploded (e.g., velocity went to infinity). *Action:* The engine catches this, cuts the timestep (`dt = dt / 2.0`), and tries the step again. (Recoverable).
    2. `catch(const MemoryAllocationError& ex)`: RAM is full. *Action:* Dump the current simulation state to the hard drive immediately and exit the program. (Fatal).
* **Mesh Geometry Parsing:**
  * **Scenario:** Loading a 3D model for aerodynamic simulation.
  * **Handling:**
    1. `catch (const std::ios_base::failure& ex)`: The file doesn't exist on disk. *Action:* Prompt the user for a new file path.
    2. `catch (const DegenerateTriangleError& ex)`: The mesh has zero-area triangles. *Action:* Launch the automatic mesh-repair tool instead of crashing.
    3. `catch (...)`: Unknown corruption. Abort.

## Key Takeaways & Cheatsheet

* **Sequential Checking:** `catch` blocks are evaluated strictly top-to-bottom. The first match wins.
* **Hierarchy Rule:** Always catch **Derived classes FIRST**, and **Base classes LAST**.
* **Catch-All:** `catch (...)` acts as a default safety net. It must be the final block.
* **No Slicing:** Always catch exception objects by reference (e.g., `const MyException& e`).
* **Design Pattern:** Throw specific exception types (like classes) rather than generic primitives (`int`, `string`) so you can isolate and handle exact failure modes cleanly.