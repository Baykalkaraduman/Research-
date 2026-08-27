# CMake: Making a Library

## Concept Overview & Core Mechanics
In Modern CMake, libraries are the structural pillars of your software architecture. Instead of compiling all your `.cpp` files directly into a single executable, you group related functionality into **Library Targets** using the `add_library()` command.

There are several types of libraries you can create:
1.  **STATIC:** The library's object code is embedded directly into the final executable at compile time (`.a` on Linux, `.lib` on Windows).
2.  **SHARED:** The library is loaded dynamically at runtime (`.so` on Linux, `.dll` on Windows, `.dylib` on macOS).
3.  **MODULE:** Plugins loaded dynamically at runtime but not linked against at compile time.
4.  **INTERFACE:** A "fictional" target. It doesn't compile any `.cpp` files. It is strictly used for header-only libraries (e.g., heavily templated C++ code) or to group compiler flags and dependencies together.
5.  **ALIAS:** Creates a new read-only name for an existing target. This is crucial for creating `Namespace::Target` aliases within your own project.

If you omit the library type (STATIC or SHARED), CMake will check the global boolean variable `BUILD_SHARED_LIBS` to decide which one to build.

## Syntax & Minimal Clean Code Examples

```cmake
# 1. Standard Static and Shared Libraries
add_library(PhysicsMath STATIC src/matrix_ops.cpp include/matrix_ops.hpp)
add_library(DetectorCore SHARED src/detector.cpp include/detector.hpp)

# 2. Letting CMake Decide (Controlled by BUILD_SHARED_LIBS)
add_library(DataParser src/parser.cpp include/parser.hpp)

# 3. Header-Only (INTERFACE) Library
# Notice there are no .cpp files, and we use the INTERFACE keyword.
add_library(TemplateUtils INTERFACE)
# We must also use INTERFACE for its properties
target_include_directories(TemplateUtils INTERFACE include/utils)

# 4. ALIAS Library (Best Practice for Namespacing)
add_library(AxionSim::PhysicsMath ALIAS PhysicsMath)
```

## Common Pitfalls & Edge Cases

*   **Anti-Pattern: Hardcoding `STATIC` or `SHARED` everywhere:** Unless a library *strictly requires* being static or shared due to architectural constraints, it is a best practice to omit the type and let the user building your code control it via `cmake -DBUILD_SHARED_LIBS=ON`.
*   **Edge Case: Mixing Target Commands on ALIAS Libraries:** You cannot use commands like `target_link_libraries` or `target_include_directories` to modify an ALIAS target. An ALIAS is strictly read-only. You must modify the original target (`PhysicsMath`), and the alias (`AxionSim::PhysicsMath`) will inherit the changes.
*   **Anti-Pattern: Forgetting `INTERFACE` constraints:** If you create an `INTERFACE` library, every single property you attach to it (includes, compile features, link libraries) MUST also use the `INTERFACE` keyword. Using `PUBLIC` or `PRIVATE` on an interface library will cause a configuration error.

## Scientific & Physics Simulation Applications

When building a high-energy physics simulation or a data analysis framework for particle detectors (e.g., CMS Phase-2 upgrades), modularity is critical. You might be writing a custom Axion detection Monte Carlo engine that relies on Geant4.

**The Architecture:**
You should separate your physics logic from your execution logic. 

1.  **Header-Only Math Utilities:** If you are porting quantum state matrix calculations (similar to QuTiP) to C++ using heavily templated libraries like Eigen, you must define this as an `INTERFACE` library.
    ```cmake
    add_library(QuantumMath INTERFACE)
    target_include_directories(QuantumMath INTERFACE include/qmath)
    ```

2.  **Core Simulation Library:** You wrap your Geant4 `DetectorConstruction` and `PrimaryGeneratorAction` classes into a static library.
    ```cmake
    add_library(Geant4Core STATIC src/Detector.cpp src/Generator.cpp)
    target_link_libraries(Geant4Core PUBLIC Geant4::Geant4)
    ```

3.  **Namespacing for Safety:** By creating ALIAS targets (e.g., `add_library(MySim::Geant4Core ALIAS Geant4Core)`), you enforce a clean namespace. Later, when you link this library to your executable (`target_link_libraries(RunMC PRIVATE MySim::Geant4Core)`), it visually matches the same standard as linking external dependencies like `ROOT::Core`.

## Key Takeaways & Cheatsheet

*   **Syntax:** `add_library(<TargetName> [STATIC | SHARED | MODULE | INTERFACE] source1.cpp ...)`
*   **INTERFACE:** Use for header-only libraries (templates, inline functions).
*   **ALIAS:** `add_library(Namespace::Target ALIAS Target)`. Use this to create professional, namespace-prefixed targets for your own code.
*   **Flexibility:** Leave out STATIC/SHARED to let `BUILD_SHARED_LIBS` control the build type globally, making your physics packages much easier for other researchers to integrate.