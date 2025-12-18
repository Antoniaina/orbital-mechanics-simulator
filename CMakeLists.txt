cmake_minimum_required(VERSION 3.10)
project(orbital_mechanics_simulator)

set(CMAKE_CXX_STANDARD 17)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(orbital src/main.cpp)

target_link_libraries(orbital OpenGL::GL glfw)
