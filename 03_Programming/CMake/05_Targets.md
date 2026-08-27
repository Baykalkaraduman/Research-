# CMake: Targets Are Your Friend (Properties & Linking)

## Concept Overview & Core Mechanics
In Modern CMake, targets (libraries and executables) are not just output files; they are **objects**. Just like in Object-Oriented Programming, you don't change global state to affect an object. Instead, you call "methods" (CMake commands starting with `target_`) to modify the properties of a specific target.

When you define a target, it needs properties to compile and link correctly:
*   Where are its header files? (`target_include_directories`)
*   What other libraries does it depend on? (`target_link_libraries`)
*   What C++ standard does it require? (`target_compile_features`)
*   What preprocessor macros does it need? (`target_compile_definitions`)

The magic of Modern CMake lies in **Transitive Dependencies**. By using visibility keywords (`PRIVATE`, `PUBLIC`, `INTERFACE`), CMake automatically propagates these properties down the dependency chain. If Target A requires Target B, CMake will automatically give Target A the include directories and compiler flags it needs to use Target B.

## Syntax & Minimal Clean Code Examples

### The Visibility Keywords
*   **`PRIVATE`**: The property is needed only to *build* the current target. It will not be passed to targets that link against this one. (e.g., internal `.cpp` dependencies).
*   **`INTERFACE`**: The property is NOT needed to build the current target, but is required for anything that *links* against it. (e.g., header-only libraries).
*   **`PUBLIC`**: The property is needed to build the current target AND is required for anything that links against it. (`PUBLIC` = `PRIVATE` + `INTERFACE`).

### Chaining Targets
```cmake
# 1. Create a library
add_library(MathEngine STATIC src/engine.cpp include/engine.hpp)

# Tell MathEngine where its headers are.
# PUBLIC means: MathEngine needs 'include/', and anyone linking MathEngine also needs 'include/'.
target_include_directories(MathEngine PUBLIC include)
target_compile_features(MathEngine PUBLIC cxx_std_17)

# 2. Create another library that depends on MathEngine
add_library(PhysicsSolver STATIC src/solver.cpp include/solver.hpp)
# By linking MathEngine PUBLICly, PhysicsSolver automatically gets the 'include/' directory and cxx_std_17!
target_link_libraries(PhysicsSolver PUBLIC MathEngine)

# 3. Create an executable
add_executable(Simulate apps/main.cpp)
# The executable uses PhysicsSolver internally. It doesn't pass it on.
target_link_libraries(Simulate PRIVATE PhysicsSolver)
```

## Common Pitfalls & Edge Cases

*   **Anti-Pattern: Mixing Classic and Modern Linking:** In ancient CMake, `target_link_libraries(target_name lib1)` lacked keywords. If you mix the old style (no keywords) with the new style (`PUBLIC`/`PRIVATE`) on the same target, CMake will throw a fatal error. **Always use keywords.**
*   **Anti-Pattern: `PRIVATE` include directories for `PUBLIC` headers:** If your library has a header file (e.g., `detector.hpp`) that users of your library need to `#include`, its path MUST be `PUBLIC` or `INTERFACE`. If you make it `PRIVATE`, the executable trying to use your library won't be able to find the header, leading to a "File not found" compilation error.
*   **Edge Case: System Includes:** If you are linking against a third-party library that throws tons of compiler warnings, you can use the `SYSTEM` keyword in `target_include_directories(MyTarget SYSTEM PUBLIC include/)`. This tells the compiler to treat those headers as system headers, suppressing their warnings.

## Scientific & Physics Simulation Applications

When building a high-energy physics framework (like an Axion detector simulation or a custom CMSSW nanoAOD analyzer), you deal with massive external frameworks like **ROOT** and **Geant4**. Transitive dependencies save you from configuration nightmares.

Imagine a structural hierarchy for an Axion Cavity Simulation:

```cmake
# 1. Define your internal Data Structures (Header-only)
add_library(AxionDataTypes INTERFACE)
target_include_directories(AxionDataTypes INTERFACE include/data)

# 2. Define the Physics Core (Requires ROOT and AxionDataTypes)
add_library(AxionPhysicsCore STATIC src/CavityModels.cpp)
target_include_directories(AxionPhysicsCore PUBLIC include/physics)

# Link ROOT and your data types. 
# PUBLIC means anyone using AxionPhysicsCore ALSO gets ROOT and AxionDataTypes automatically.
target_link_libraries(AxionPhysicsCore PUBLIC ROOT::Core ROOT::MathCore AxionDataTypes)

# 3. Define the Executable
add_executable(RunAxionSearch src/main.cpp)

# 🎯 THE MAGIC: You only need to link AxionPhysicsCore here.
# CMake will automatically configure this executable with ROOT's include paths, 
# ROOT's compiler flags, and the AxionDataTypes headers.
target_link_libraries(RunAxionSearch PRIVATE AxionPhysicsCore)
```
Without target-based CMake, you would have to manually add ROOT's include directories and link flags globally to every single executable you create. With target chaining, you encapsulate Geant4 or ROOT entirely within your physics libraries.

## Key Takeaways & Cheatsheet

*   **Think Object-Oriented:** Use `target_*` commands (`target_include_directories`, `target_compile_options`, `target_compile_definitions`) to modify targets.
*   **`PRIVATE`**: "I need this for my `.cpp` files, my dependents don't."
*   **`INTERFACE`**: "I don't need this, but anyone linking to my headers does."
*   **`PUBLIC`**: "I need this, and anyone linking to me needs it too."
*   **Automated Propagation:** Linking a target automatically pulls in its `PUBLIC` and `INTERFACE` properties, completely eliminating the need to duplicate paths across your `CMakeLists.txt`.