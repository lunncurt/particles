cmake_minimum_required(VERSION 3.14)
project(particles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

set(SOURCE_FILES
    src/main.cpp
    src/particle-system/part.cpp
    src/particle-system/physics.cpp)

add_executable(exec ${SOURCE_FILES})
include_directories(/opt/homebrew/Cellar/sfml/2.6.1/include)

find_package(SFML 2.6.1 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(exec sfml-system sfml-window sfml-graphics)
