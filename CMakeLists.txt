cmake_minimum_required(VERSION 3.10)
project(YourProjectName)

# Find GLFW package
find_package(glfw3 REQUIRED)

# Add executable
add_executable(YourExecutable main.cpp)

# Link against GLFW
target_link_libraries(YourExecutable PRIVATE glfw)

