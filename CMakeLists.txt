cmake_minimum_required(VERSION 3.10)
project(MyPassProject LANGUAGES CXX)

# Find the LLVM package
find_package(LLVM 18.1.4 REQUIRED CONFIG)

# Set the path to the LLVM directory if it is not in the default location
# set(LLVM_DIR "/path/to/llvm/lib/cmake/llvm")

# Include the LLVM CMake files
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

# Add your pass source files
add_library(MyPass MODULE MyPass.cpp)

# Specify the required LLVM components
llvm_map_components_to_libnames(llvm_libs Core IRReader Support Passes)

# Link the pass against the LLVM libraries
target_link_libraries(MyPass PRIVATE ${llvm_libs})

# Ensure C++17 is used
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS "-Wall -fno-rtti")
