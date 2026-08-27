# CMake: Making an Executable

## Concept Overview & Core Mechanics
In Modern CMake, the build process revolves around **Targets**. An executable is the most common type of target. The `add_executable()` command instructs CMake to generate a runnable binary (like an `.exe` on Windows or a standard ELF binary on Linux) from a specified set of source files. 

This command creates a logical CMake Target. Once created, this target becomes a distinct object in your build system. You can later attach properties to it—such as include directories, compiler flags, and linked libraries—without affecting any other executables or libraries in your project. This isolation is the cornerstone of Modern CMake.

## Syntax & Minimal Clean Code Examples

The first argument is always the name of the executable (which also becomes the name of the target). Subsequent arguments are the source files required to build it.

```cmake
# Create an executable target named 'AxionSim' from a single source file
add_executable(AxionSim src/main.cpp)

# Create a target from multiple source files and headers
add_executable(DataAnalyzer 
    src/main.cpp 
    src/DataParser.cpp 
    include/DataParser.hpp
)
```

## Common Pitfalls & Edge Cases

*   **Anti-Pattern: Using `file(GLOB)` for Source Files:** It is tempting to write `file(GLOB SOURCES "src/*.cpp")` and pass `${SOURCES}` to `add_executable`. **Do not do this.** If you add a new `.cpp` file, CMake will not automatically detect the change because the `CMakeLists.txt` file itself hasn't been modified. Always list source files explicitly.
*   **Edge Case: Omitting Header Files:** CMake only compiles source files (`.cpp`, `.cxx`, `.cc`). It technically ignores header files (`.h`, `.hpp`) passed to `add_executable()`. However, you **should** include them in the list. Why? Because modern IDEs (like CLion, VSCode, or Visual Studio) read the `CMakeLists.txt` to structure your project tree. If you omit headers, they might not appear in your IDE's project explorer.
*   **Target Name Clashes:** The target name (the first argument) must be globally unique across your entire CMake project. You cannot have a library and an executable both named `PhysicsCore`.

## Scientific & Physics Simulation Applications

In computational physics and high-energy particle simulations (e.g., using Geant4 for detector tracking or ROOT for data analysis), your project usually consists of a core library (the physics logic) and several small executables that run specific simulations or analysis tasks.

For example, when running a PT-symmetric cavity axion detection simulation on your Linux environment, you don't compile a single monolithic script. You structure your executables to represent distinct runs or analysis steps:

```cmake
# 1. The executable that runs the Geant4 Monte Carlo simulation
add_executable(RunAxionMC apps/run_mc.cpp)
# Link only what this specific executable needs
target_link_libraries(RunAxionMC PRIVATE Geant4::Geant4 PhysicsCore)

# 2. A separate executable that analyzes the output ROOT trees
add_executable(AnalyzeTauEvents apps/analyze_tau.cpp)
# Link ROOT libraries specifically to the analyzer
target_link_libraries(AnalyzeTauEvents PRIVATE ROOT::Tree ROOT::Core)

# Both executables coexist in the same build system without flag pollution.
```
By defining multiple executables, you can compile and run just the analysis part (e.g., `make AnalyzeTauEvents`) without wasting time rebuilding the heavy Monte Carlo simulator.

## Key Takeaways & Cheatsheet

*   **Syntax:** `add_executable(<TargetName> source1.cpp [source2.cpp ...])`
*   **Target Identity:** The `<TargetName>` is both the output filename and the logical identifier for future CMake commands (`target_link_libraries`, `target_include_directories`).
*   **Explicit is Better:** Always list your source files explicitly; avoid dynamic globbing.
*   **IDE Friendliness:** Include `.hpp` files in the source list so they appear correctly organized in your IDE's file explorer.