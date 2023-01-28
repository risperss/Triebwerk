cmake_minimum_required(VERSION 3.22)
project(triebwerk)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    src
    ./include
)

link_directories(
    ./lib
)

add_executable(triebwerk
    src/main.cpp
    src/deps/glad.c
    src/graphics/window.cpp
    src/graphics/window.hpp
    src/maths/vec2.cpp
    src/maths/vec2.hpp
    src/maths/vec3.cpp
    src/maths/vec3.hpp
)

target_link_libraries(triebwerk glfw.3.3)
