# C++ Throwing Exceptions from Functions

## Concept Overview & Core Mechanics
In professional C++ architecture, error detection and error handling are strictly separated. 
* **The Function's Job (Detection):** A low-level function (e.g., a math calculation, file reader, or database query) detects when something goes wrong and uses `throw` to sound the alarm. It does *not* handle the error itself.
* **The Caller's Job (Handling):** The higher-level code (e.g., UI, main simulation loop) calls the function inside a `try` block and uses `catch` to decide what to do (e.g., show an error message, retry, or safely shut down).

**Stack Unwinding:**
When a function throws an exception, C++ immediately aborts that function. It then travels backwards up the Call Stack, looking for a function that has a matching `catch` block. During this journey, it automatically calls the destructors for all local variables that go out of scope. This process is called **Stack Unwinding** and guarantees memory safety (especially if you use smart pointers).

## Syntax & Minimal Clean Code Examples

### 1. The Low-Level Function (Throws)
Using standard C++ exception classes (`<stdexcept>`) is the industry standard.

```cpp
#include <stdexcept>
#include <cmath>

// This function only calculates. If it fails, it throws an object.
double computeSquareRoot(double value) {
    if (value < 0.0) {
        throw std::invalid_argument("Cannot compute square root of a negative number.");
    }
    return std::sqrt(value);
}
```

### 2. The High-Level Caller (Catches)
```cpp
#include <iostream>

int main() {
    try {
        // The caller attempts the operation
        double result = computeSquareRoot(-5.0); 
        std::cout << "Result: " << result << "\n";
    } 
    catch (const std::invalid_argument& ex) {
        // The caller decides how to handle the failure
        std::cerr << "Simulation Error: " << ex.what() << "\n";
    }
    
    return 0;
}
```

## Common Pitfalls & Edge Cases

* **Uncaught Exceptions (`std::terminate`):**
  * *Anti-pattern:* Throwing an exception from a function but forgetting to wrap the caller in a `try-catch` block.
  * *Consequence:* The exception bubbles all the way up the stack, escapes `main()`, and crashes the program instantly via `std::terminate()`. Always catch what you expect to be thrown.
* **Catching Base Classes First:**
  * *Edge Case:* If you have multiple `catch` blocks, always catch derived exceptions (e.g., `std::invalid_argument`) BEFORE base exceptions (e.g., `std::exception`). C++ checks catch blocks sequentially. If the base class is first, it acts as a black hole and catches everything, making the derived blocks unreachable.
* **The `noexcept` Keyword:**
  * *Best Practice:* If a function is mathematically guaranteed *never* to throw an exception, mark it with `noexcept` (e.g., `void printData() noexcept;`). This allows the compiler to heavily optimize the function because it doesn't need to inject hidden stack-unwinding setup code.

## Scientific & Physics Simulation Applications

Throwing from functions is how robust computational libraries (like Eigen, Boost.Math, or custom physics kernels) communicate with the user's application.

* **Physics Kernel Decoupling:**
  * **Scenario:** A core physics engine computes particle collisions. It doesn't know if it's being run in a graphical game, a terminal script, or a web server.
  * **Application:** If a `ParticleSystem::step()` function detects corrupted data (like `NaN` velocity), it `throw std::runtime_error("Velocity overflow");`. It doesn't use `std::cout` (because a web server has no terminal). The game engine catches it and shows a pop-up, or the terminal catches it and logs to a text file.
* **Numerical Bounds Checking:**
  * **Scenario:** Accessing elements in a highly optimized 3D fluid grid. 
  * **Application:** `double getPressure(int x, int y, int z)` checks bounds. If `x > MAX_X`, it throws an `std::out_of_range`. This ensures silent memory corruption never happens.
* **Parsing Configuration Files:**
  * When a simulation boots up, it reads an XML/JSON config file. A function `parseGravity(JSON data)` will throw `std::invalid_argument` if the gravity value is missing. The `main()` bootloader catches this, aborts the startup cleanly, and alerts the user to fix their config file.

## Key Takeaways & Cheatsheet

* **Detect in Functions, Handle in Callers:** Keep your math/logic functions pure; let the caller handle the UI/logging.
* **Stack Unwinding:** C++ cleans up local variables automatically as it hunts for a `catch` block.
* **Throw by Value, Catch by Reference:** e.g., `throw std::runtime_error("Error");` and `catch (const std::exception& e)`.
* **Standard Exceptions:** Include `<stdexcept>` and use descriptive exception objects instead of throwing raw integers or strings.