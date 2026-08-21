# C++ `std::unique_ptr` & Exclusive Ownership

## Concept Overview & Core Mechanics
`std::unique_ptr` is a smart pointer introduced in C++11 (enhanced in C++14) that enforces **Strict Exclusive Ownership**. 
* **Zero Overhead:** A `unique_ptr` compiles down to a raw pointer. There is no performance penalty or memory overhead for using it.
* **RAII (Resource Acquisition Is Initialization):** The moment the `unique_ptr` goes out of scope, it automatically calls `delete` on the underlying raw pointer. You NEVER write `delete`.
* **No Copies Allowed:** Because ownership is exclusive, two `unique_ptr`s cannot point to the same memory block. Attempting to copy them will result in a compile-time error.
* **Move Semantics:** To transfer ownership from one `unique_ptr` to another, you must explicitly use `std::move()`. The original pointer instantly becomes `nullptr`.

## Syntax & Minimal Clean Code Examples

### 1. Initialization (`make_unique`)
Always use `std::make_unique` (C++14). It combines allocation and pointer assignment safely.
```cpp
#include <memory>

// Creating a unique_ptr to a double
std::unique_ptr<double> p1 = std::make_unique<double>(9.81);

// Creating a unique_ptr to an array (automatically calls delete[] later)
std::unique_ptr<int[]> arr = std::make_unique<int[]>(100); 
```

### 2. Moving Ownership
```cpp
std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
// std::unique_ptr<int> ptr2 = ptr1; // ERROR: Cannot copy!

std::unique_ptr<int> ptr2 = std::move(ptr1); // SUCCESS: Ownership transferred.
// ptr1 is now nullptr. ptr2 now owns the memory.
```

### 3. Passing to Functions
How do you pass a `unique_ptr` to a function without copying it?
```cpp
// Option A: Passing by Reference (Good if the function modifies the pointer itself)
void modifyPointer(std::unique_ptr<Entity>& ptr) { ... }

// Option B: Passing the Raw Pointer (BEST PRACTICE if the function just needs to use the object)
// Use .get() to extract the raw pointer temporarily.
void calculatePhysics(Entity* ptr) { ... } 
// Usage: calculatePhysics(myUniquePtr.get());

// Option C: Passing by Move (Use this if the function TAKES OWNERSHIP permanently)
void storeEntity(std::unique_ptr<Entity> ptr) { ... }
// Usage: storeEntity(std::move(myUniquePtr)); 
```

## Common Pitfalls & Edge Cases

* **Using `new` instead of `make_unique` (Exception Safety Hazard):**
  * *Anti-pattern:* `process(std::unique_ptr<T>(new T()), functionThatMightThrow());`
  * *Danger:* If `functionThatMightThrow()` throws an exception *after* `new T()` allocates memory but *before* the `unique_ptr` constructor wraps it, the memory leaks. `std::make_unique` prevents this by doing it in a single, atomic step.
* **Iterating Vectors by Value:**
  * *Anti-pattern:* `for(auto obj : myVectorOfUniquePtrs)`. This attempts to copy the pointers, crashing the compiler.
  * *Best Practice:* `for(const auto& obj : myVectorOfUniquePtrs)`. Always use references (`&`).
* **Dangling Raw Pointers from `.get()`:**
  * *Anti-pattern:* Extracting the raw pointer with `.get()`, saving it somewhere, and then letting the `unique_ptr` go out of scope. The saved raw pointer will now point to deleted memory (dangling pointer), leading to undefined behavior.

## Scientific & Physics Simulation Applications

`unique_ptr` is the backbone of memory-safe high-performance simulations.

* **Simulation Managers / Game Engines:**
  * **Usage:** A `PhysicsWorld` class holds a `std::vector<std::unique_ptr<Collider>>`. When the simulation ends (or if a level is reset), the vector goes out of scope. Every single mesh, bounding box, and rigid body is automatically and perfectly destroyed. No manual cleanup loops required.
* **Large Matrix / Tensor Allocations in Numerical Solvers:**
  * **Usage:** When writing a CFD (Computational Fluid Dynamics) solver, you might allocate massive arrays on the Heap. If a matrix inversion fails and throws an exception, manual `delete` statements are skipped, causing gigabytes of RAM to leak. Wrapping the grid data in `unique_ptr<double[]>` guarantees the memory is released instantly upon the exception being thrown.
* **Factory Design Pattern:**
  * In simulations, you often have a factory function that generates physics nodes based on config files. Returning a `std::unique_ptr<Node>` clearly signals to the caller: *"You are now the exclusive owner of this object. You are responsible for its lifecycle, and it will clean itself up."*

## Key Takeaways & Cheatsheet

* **Header:** `#include <memory>`
* **Rule of Thumb:** Default to `std::unique_ptr`. Only use raw pointers (`*`) for *non-owning* observations (e.g., passing data to a read-only function).
* **Creation:** `std::make_unique<T>(...)` (Never use `new` directly).
* **Transfer:** `std::move(ptr)` (Mandatory for assignments and passing ownership).
* **Extract Raw:** `ptr.get()` (Returns the raw pointer without releasing ownership).
* **Release Ownership:** `ptr.release()` (Returns the raw pointer AND stops managing it. You must now manually `delete` it).
* **Reset:** `ptr.reset()` (Forces immediate destruction of the managed object and sets pointer to `nullptr`).