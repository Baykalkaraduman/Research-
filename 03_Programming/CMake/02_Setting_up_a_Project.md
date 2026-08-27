# CMake: Setting Up a Project

## Concept Overview & Core Mechanics
The `project()` command is the second fundamental building block of any `CMakeLists.txt`, strictly following `cmake_minimum_required()`. 

Despite its simplicity, it performs heavy lifting behind the scenes. It does **not** create any executables or libraries. Instead, it:
1. **Initializes the Workspace:** It sets up global variables related to the project's name, version, and description.
2. **Detects Compilers:** It probes your operating system (e.g., your Linux environment) to find the appropriate compilers for the specified languages (like GCC or Clang for C++, NVCC for CUDA) and tests if they actually work.
3. **Defines Variables:** If you name your project `MyPhysicsSim` with `VERSION 1.2`, CMake automatically generates variables like `PROJECT_NAME`, `PROJECT_VERSION`, and `MyPhysicsSim_VERSION` which you can use later to configure header files or name your output binaries dynamically.

## Syntax & Minimal Clean Code Examples

Whitespace and indentation do not matter in CMake. Strings can be quoted (especially if they contain spaces). The project name must be the very first (positional) argument, followed by optional keyword arguments.

```cmake
# Standard project initialization
project(AxionDetector 
        VERSION 1.0.0
        DESCRIPTION "PT-Symmetric Cavity Axion Detector Simulation"
        LANGUAGES CXX)
```

**Understanding the Keywords:**
*   **`VERSION`**: Takes a version number (major.minor.patch.tweak).
*   **`DESCRIPTION`**: A brief string describing the project (added in CMake 3.9).
*   **`LANGUAGES`**: Specifies which compilers to look for. Options include `C`, `CXX` (C++), `Fortran`, `CUDA`, `HIP`, etc. If omitted, the default is `C CXX`.
*   **Comments**: You can add comments anywhere using the `#` symbol.

## Common Pitfalls & Edge Cases

*   **Anti-Pattern - Wrong Order:** Placing `project()` before `cmake_minimum_required()`. CMake needs to know the policy rules *before* it starts probing for C++ compilers. Reversing the order causes configuration warnings and unpredictable behavior.
*   **Edge Case - Header-Only Libraries:** If you are writing a C++ library that consists purely of `.hpp` files (templates/inline functions) or just packaging Python scripts, CMake will still waste time searching for a C and C++ compiler by default. To prevent this, explicitly tell CMake that no compilers are needed: 
    *   *Clean Code:* `project(MathUtils LANGUAGES NONE)`
*   **Anti-Pattern - Hardcoding Versions Elsewhere:** Do not hardcode your software's version in your C++ code. Define it in the `project(VERSION ...)` command and use CMake's `configure_file()` to inject this version directly into a C++ header file. This creates a single source of truth.

## Scientific & Physics Simulation Applications

When developing computational physics tools—such as integrating **Geant4** for particle tracking or building data structures for **ROOT**—you often encounter multi-language environments. 

1. **High-Performance Computing (HPC):** If your particle physics simulation requires GPU acceleration to calculate millions of Hamiltonian matrices (like those you might prototype in QuTiP), you can easily instruct CMake to prepare the NVIDIA compiler alongside C++:
    ```cmake
    project(QuantumSim VERSION 2.1 LANGUAGES CXX CUDA)
    ```
2. **Legacy Physics Code:** Many core numerical libraries (like BLAS/LAPACK or older HEP tools) are written in Fortran. Modern CMake makes interoperability trivial:
    ```cmake
    project(DetectorAnalysis LANGUAGES CXX Fortran)
    ```
3. **Reproducibility:** In scientific research, knowing *exactly* which version of the software produced a specific dataset is critical. By strictly defining `VERSION 1.2.4` in the `project()` command, you can automatically stamp this version number onto every CSV or ROOT tree output file your simulation generates.

## Key Takeaways & Cheatsheet

*   `project()` must be the second command in your file.
*   **Syntax:** `project(<NAME> [VERSION <version>] [DESCRIPTION <desc>] [LANGUAGES <language>...])`
*   It configures the environment and checks compilers; it does **not** create build targets.
*   If omitted, `LANGUAGES` defaults to `C` and `CXX`. Use `NONE` if no compilation is required.
*   Leverage the automatically generated variables (like `PROJECT_VERSION`) to maintain a single source of truth across your repository.