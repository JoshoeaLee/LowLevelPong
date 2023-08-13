cmake_minimum_required(VERSION 3.12)

project(LowLevelPong)

message(STATUS "SDL2_BINDIR: ${SDL2_BINDIR}")

# Add the path to the directory containing sdl2_ttf-config.cmake to CMAKE_PREFIX_PATH
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/lib/cmake/SDL2_ttf")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the required packages
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Add the include directories for the libraries
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})

# Create the executables
add_executable(play main.cpp)
add_executable(run_tests autotest.cpp)

# Link the libraries to the executables
target_link_libraries(play PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_TTF_LIBRARY}
)
target_link_libraries(run_tests PRIVATE
    ${SDL2_LIBRARIES}
    ${SDL2_TTF_LIBRARY}
)