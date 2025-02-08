cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Untitled4)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(Untitled4 src/main.cpp)

# Include directories
include_directories(lib)

# Add the source files for the libraries
add_library(Servo_controller Servo_controller.cpp)
add_library(leadscrew_controller leadscrew_controller.cpp)
add_library(game_controller game_controller.cpp)
add_library(Pair Pair.cpp)

# Link the libraries to the executable
target_link_libraries(Untitled4 Servo_controller leadscrew_controller game_controller Pair)