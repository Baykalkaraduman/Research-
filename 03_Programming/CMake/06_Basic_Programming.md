# CMake: Practical Programming, Control Flow & Scope

## Concept Overview & Core Mechanics
While Modern CMake prioritizes a declarative, target-based approach, you occasionally need procedural logic to handle conditional builds (e.g., enabling CUDA support or optional tests) or to iterate over lists of files and targets.

1. **Control Flow (`if`/`else`):** Allows conditional configuration based on system variables, environment options, or detected packages (like checking if ROOT or Geant4 is available).
2. **Loops (`foreach`):** Enables iterating over lists of items, saving you from writing repetitive target definitions.
3. **Functions vs. Macros:** This is a critical scoping distinction:
   * **`function()`**: Creates a new variable scope (like a standard function in C++). Variables created inside do not leak out, protecting your global configuration.
   * **`macro()`**: Acts like a text-replacement preprocessor directive (like a C `#define`). It does *not* create a scope, meaning any variables modified inside leak directly into the caller's scope, often causing subtle, hard-to-debug bugs.

## Syntax & Minimal Clean Code Examples

### 1. Control Flow (`if` / `else`)
```cmake
# Check if a boolean option is enabled
option(ENABLE_CUDA "Enable CUDA acceleration for simulation" ON)

if(ENABLE_CUDA)
    message(STATUS "CUDA support is active.")
    enable_language(CUDA)
else()
    message(STATUS "Compiling for CPU only.")
endif()

# Check if an external package was found
find_package(ROOT QUIET)
if(ROOT_FOUND)
    target_link_libraries(MySim PRIVATE ROOT::Core ROOT::Tree)
else()
    message(WARNING "ROOT not found. Analysis modules will be skipped.")
endif()
```

### 2. Loops (`foreach`)
```cmake
# Iterate over a list of minor simulation apps
set(SIM_APPS run_axial run_radial run_thermal)

foreach(app IN LISTS SIM_APPS)
    add_executable(${app} apps/${app}.cpp)
    target_link_libraries(${app} PRIVATE PhysicsCore)
endforeach()
```

### 3. Functions vs. Macros Definition
```cmake
# PREFERRED: Function with its own local scope
function(configure_simulation target_name)
    target_compile_features(${target_name} PUBLIC cxx_std_17)
    # Local variables stay inside this function
    set(LOCAL_FLAG "-O3") 
    target_compile_options(${target_name} PRIVATE ${LOCAL_FLAG})
endfunction()

# AVOID UNLESS NECESSARY: Macro leaks variables to caller
macro(bad_macro target_name)
    set(LEAKED_VAR "Dangerous")
endmacro()
```

## Common Pitfalls & Edge Cases

*   **Anti-Pattern: Using Macros for Encapsulation:** If you write custom helper routines in CMake using `macro()`, local variables will bleed into the calling script, potentially overwriting project names, paths, or compiler flags. **Always default to `function()`.**
*   **Anti-Pattern: Unquoted String Evaluation in `if()`:** In older CMake, writing `if(variable)` could evaluate weirdly if the variable wasn't set. Modern CMake handles this much better, but explicitly checking properties or using defined checks ensures robustness.
*   **Edge Case: `if(NOT TARGET ...)` Checks:** When building modular physics pipelines, always check if an imported target (like `Geant4::Geant4`) exists before trying to link against it to prevent hard configuration crashes on machines missing specific libraries.

## Scientific & Physics Simulation Applications

When building advanced computational packages—such as a hybrid Monte Carlo framework combining Geant4 particle tracking and QuTiP quantum state solvers—your build system must adapt to the host machine's hardware and installed dependencies.

1. **Optional Module Compilation:** If you are developing a simulation tool where the graphical visualization modules depend on OpenGL or Qt, you don't want the build to fail on a headless computing cluster (like a university research server). You use `if` blocks to safely wrap optional dependencies:
    ```cmake
    option(BUILD_GUI "Build interactive event display" ON)
    
    if(BUILD_GUI)
        find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
        target_link_libraries(SimVisualizer PRIVATE Qt5::Core Qt5::Widgets)
    endif()
    ```
2. **Batch Processing Executables:** If your data analysis pipeline processes multiple detector layers (e.g., tracking tau leptons through CMS Phase-2 upgrades), you can dynamically generate executables using a `foreach` loop instead of repeating boilerplate blocks for every single detector subsystem.

## Key Takeaways & Cheatsheet

*   **Keep it Lean:** Avoid complex procedural programming in CMake; use it strictly for configuration logic.
*   **Always prefer `function()` over `macro()`** to prevent variable leakage and scope pollution.
*   **Use `if(TARGET ...)`** to safely check for optional external libraries (like ROOT or Geant4) before linking.
*   **Use `foreach(item IN LISTS ...)`** for clean, readable iteration over source lists or sub-applications.