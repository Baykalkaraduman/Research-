# CMake: Minimum Version & Policies Lecture

## Concept Overview & Core Mechanics
The very first line of any valid `CMakeLists.txt` file must dictate the required CMake version using the `cmake_minimum_required()` command. However, this command does much more than simply verify if the system has a compatible version installed—it acts as the master switch for **CMake Policies**.

CMake policies are the mechanism by which CMake handles backward compatibility. As CMake evolves, developers fix bugs, improve dependency tracking, and introduce better behaviors. To ensure that an old `CMakeLists.txt` doesn't suddenly break when a user upgrades their CMake installation, CMake ties its behavior to the version you request. If you specify an older version, CMake will actively emulate the bugs, quirks, and legacy behaviors of that specific older version. 

In Modern CMake (version 3.12 and later), a new **version range syntax** (`VERSION min...max`) was introduced. This is a game-changer for maintainability. It tells the CMake engine: "This project requires at least the `min` version to configure and build. However, I have tested it up to the `max` version, so please apply the most modern, optimal policies available up to that `max` version."

## Syntax & Minimal Clean Code Examples

### The Modern Range Approach (Highly Recommended)
This is the standard for any new project. It guarantees that users with older systems can still build the software, while users with modern systems benefit from stricter, optimized build policies.

```cmake
# Always the absolute first line of CMakeLists.txt
# Requires at least 3.15, but uses optimal policies up to 4.4
cmake_minimum_required(VERSION 3.15...4.4)

# Only AFTER setting the minimum version, define the project
project(AxionSimulation VERSION 1.0.0 LANGUAGES CXX)
```

### The Legacy Approach (Standard but less flexible)
This locks the policies strictly to the specified version. Even if the user has CMake 3.28 installed, CMake will emulate the exact behavior of 3.15.

```cmake
cmake_minimum_required(VERSION 3.15)
```

## Common Pitfalls & Edge Cases

*   **Anti-Pattern: Too Low Minimum Version:** Setting `cmake_minimum_required(VERSION 2.8)` or `3.5` is extremely dangerous today. Starting in CMake 4.0, values below 3.5 trigger hard errors (the build will fail outright), and versions below 3.10 trigger aggressive deprecation warnings. Forcing CMake to use fragile, decade-old behaviors compromises the integrity of modern C++ compilation.
*   **Anti-Pattern: Wrong Command Order:** Calling `project()` before `cmake_minimum_required()`. The `project()` command probes the system for C/C++ compilers and sets up internal variables based on the active policies. If the minimum version (and thus the policies) is set *after* this probe, the compiler detection can yield unpredictable results or fail to enable necessary features.
*   **Edge Case: Range Syntax on Pre-3.12 Systems:** What happens if you use `VERSION 3.15...4.4` but the user is running CMake 3.11? CMake versions prior to 3.12 did not understand the `...max` syntax. However, due to a clever parser quirk, older CMake versions essentially ignore the upper bound. It won't crash; it will simply apply the 3.11 policies, providing natural backward compatibility.

## Scientific & Physics Simulation Applications

In computational physics and high-energy particle simulations, managing build environments across different institutions is a well-known challenge. 

Consider a workflow where C++ code is used alongside **ROOT** and **Geant4** for modeling photon emission profiles in PT-symmetric quantum cavities, or analyzing CMSSW HLT NanoAOD data for tau lepton reconstruction. Development typically happens on a modern personal machine (e.g., an HP Victus running a recent Linux distribution with CMake 3.28+). However, the resulting code often needs to be compiled on institutional clusters or research facilities (like the computing grids at the University of Bonn or the Turkish Accelerator and Radiation Laboratory - TARLA) which may be running older, stable enterprise distributions like CentOS with CMake 3.15.

By strictly utilizing the range `cmake_minimum_required(VERSION 3.15...3.28)`, the build system adapts gracefully. On the legacy institutional cluster, it compiles successfully using the 3.15 policies. On the modern local workstation, CMake 3.28 enforces the latest, strictest linking policies, ensuring that linking against complex imported targets like `Geant4::Geant4` or `ROOT::Core` is handled flawlessly without legacy side-effects.

## Key Takeaways & Cheatsheet

*   **Rule #1:** `cmake_minimum_required` must be line 1, before `project()`.
*   **Policies:** It's not just a version check; it defines the ruleset (policies) CMake uses for the entire project.
*   **Syntax:** Use `VERSION min...max` to maximize compatibility while enforcing modern standards.
*   **Baseline:** Avoid setting a minimum version below `3.15`. This version marks a stable era for modern C++ compilation features and target-based architecture.