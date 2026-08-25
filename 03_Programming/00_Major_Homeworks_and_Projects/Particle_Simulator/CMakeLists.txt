# 1. Define minimum CMake version and Project Name
cmake_minimum_required(VERSION 3.10)
project(ToyMonteCarlo CXX)

# 2. Modern C++ Standard (Required for smart pointers and ROOT 6+)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ==============================================================================
# 3. ROOT INTEGRATION
# ==============================================================================
# Find ROOT packages using the environment variables set by thisroot.sh
find_package(ROOT REQUIRED COMPONENTS Core Hist RIO Tree)

# Print a message to the terminal to confirm ROOT was found
message(STATUS "Found ROOT Version: ${ROOT_VERSION}")

# 4. Gather Source Files (This automatically picks up AnalysisManager.cpp)
file(GLOB SOURCES "src/*.cpp")

# 5. Define Executable Target
add_executable(SimulationApp app/main.cpp ${SOURCES})

# 6. Include our custom headers (This automatically picks up AnalysisManager.h)
target_include_directories(SimulationApp PRIVATE include)

# ==============================================================================
# 7. LINK ROOT LIBRARIES TO OUR EXECUTABLE
# ==============================================================================
# Tell our app where the ROOT header files (like TH1D.h, TFile.h) are located
target_include_directories(SimulationApp PUBLIC ${ROOT_INCLUDE_DIRS})

# Link the actual ROOT compiled libraries to our application
target_link_libraries(SimulationApp PUBLIC ${ROOT_LIBRARIES})