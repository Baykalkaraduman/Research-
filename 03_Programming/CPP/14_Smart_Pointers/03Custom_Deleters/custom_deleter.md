# C++ Smart Pointers & Custom Deleters

## Concept Overview & Core Mechanics
By default, when a smart pointer (`std::unique_ptr` or `std::shared_ptr`) goes out of scope and its managed object needs to be destroyed, the smart pointer simply executes `delete ptr;` (or `delete[] ptr;`). 

However, in real-world engineering, resource management isn't just about RAM. You might need to close a file handle, disconnect from a database, release a thread lock (Mutex), or free memory allocated by an external legacy C library (like OpenGL or a hardware driver) that uses `free()` instead of `delete`. **Custom Deleters** allow you to override the default destruction behavior and inject your own cleanup logic.

## Syntax & Minimal Clean Code Examples

### 1. `std::shared_ptr` with a Custom Deleter
For `shared_ptr`, the type of the deleter is erased at compile-time (Type Erasure). You simply pass the deleter (function or lambda) as the second argument to the constructor.
**Note:** You *cannot* use `std::make_shared` when providing a custom deleter.

```cpp
#include <memory>
#include <iostream>

// Using a Lambda Expression (Modern C++ Best Practice)
void sharedPointerExample() {
    std::shared_ptr<int> ptr(new int{42}, [](int* p) {
        std::cout << "Custom cleaning up shared_ptr\n";
        delete p; // Don't forget to actually free the memory!
    });
}
```

### 2. `std::unique_ptr` with a Custom Deleter (The Tricky Part!)
Because `unique_ptr` is designed for zero overhead, it does not use Type Erasure. The type of the deleter **MUST** be explicitly specified in the template parameter list `<Type, DeleterType>`.

```cpp
#include <memory>
#include <iostream>

void uniquePointerExample() {
    // 1. Define the lambda
    auto customDeleter = [](int* p) {
        std::cout << "Custom cleaning up unique_ptr\n";
        delete p;
    };
    
    // 2. Specify the type of the lambda using decltype
    std::unique_ptr<int, decltype(customDeleter)> ptr(new int{42}, customDeleter);
}
```

## Common Pitfalls & Edge Cases

* **Forgetting `delete` inside the Custom Deleter:**
  * *Anti-pattern:* Writing a custom deleter just to print a log message but forgetting to write `delete ptr;`.
  * *Consequence:* A massive memory leak. The smart pointer executed your logic, but since you didn't tell it to free the memory, the RAM is permanently occupied.
* **Trying to use `std::make_shared` or `std::make_unique`:**
  * *Anti-pattern:* `std::make_shared<Test>(100, myDeleter);`
  * *Why it fails:* `make_shared` allocates the object and the control block simultaneously and implicitly uses the default `delete`. If you need a custom deleter, you must fall back to the raw `new` operator.
* **Mixing `new[]` with a regular `delete`:**
  * *Edge Case:* If you allocate an array `new int[100]` but your custom deleter uses `delete ptr;` instead of `delete[] ptr;`, you will get Undefined Behavior (usually a crash). (Note: Modern C++ handles arrays directly via `std::unique_ptr<int[]>`, so custom deleters for arrays are rarely needed now).

## Scientific & Physics Simulation Applications

Custom deleters are the ultimate bridge between modern C++ architecture and high-performance legacy C-APIs (which are heavily used in scientific computing).

* **GPU Programming (CUDA / OpenCL Integration):**
  * **Scenario:** You allocate a massive array on the VRAM (GPU memory). Standard `delete` will crash because the memory is on the GPU, not the CPU RAM.
  * **Application:** 
    ```cpp
    auto cudaDeleter = [](float* d_ptr) { cudaFree(d_ptr); };
    std::unique_ptr<float, decltype(cudaDeleter)> d_array(allocateOnGPU(), cudaDeleter);
    ```
    This ensures GPU memory never leaks when a physics function exits or throws an exception.
* **File & I/O Handling (Data Logging):**
  * **Scenario:** Wrapping standard C file I/O (`FILE*`) into a smart pointer to ensure telemetry files are always closed safely.
  * **Application:**
    ```cpp
    auto fileDeleter = [](FILE* f) { if (f) fclose(f); };
    std::unique_ptr<FILE, decltype(fileDeleter)> file(fopen("simulation_results.csv", "w"), fileDeleter);
    ```
* **Custom Memory Pools / Arenas:**
  * In real-time fluid dynamics simulations, constantly calling `new` and `delete` for millions of particles causes CPU cache fragmentation. Instead, you use a pre-allocated "Memory Pool". When a particle dies, the custom deleter doesn't call `delete`; instead, it signals the Memory Pool to mark that slot as "available" for the next particle.

## Key Takeaways & Cheatsheet

* **What it is:** A function/lambda that executes *instead* of the default `delete` when the smart pointer expires.
* **`shared_ptr` syntax:** `std::shared_ptr<T> p(new T{}, lambda_deleter);`
* **`unique_ptr` syntax:** `std::unique_ptr<T, decltype(lambda_deleter)> p(new T{}, lambda_deleter);`
* **No `make_shared` / `make_unique`:** You must use the raw `new` keyword to bind a custom deleter.
* **Ultimate Responsibility:** If your custom deleter manages raw heap memory, YOU are responsible for explicitly calling `delete ptr;` inside the deleter function.