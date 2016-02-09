cmake_minimum_required(VERSION 2.8.5)
project(JunctionSample)

# Add Junction (and Turf) build targets to the CMake project.
# This defines JUNCTION_ALL_INCLUDE_DIRS and JUNCTION_ALL_LIBRARIES.
add_subdirectory("../junction" junction)

# Add executable.
add_executable(JunctionSample Main.cpp)

# Set include dirs and libraries for the executable.
include_directories(${JUNCTION_ALL_INCLUDE_DIRS})
target_link_libraries(JunctionSample ${JUNCTION_ALL_LIBRARIES})
