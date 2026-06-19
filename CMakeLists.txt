cmake_minimum_required(VERSION 3.17)
project(SiliconGraphics)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

add_subdirectory(vendor/glm)

add_subdirectory(modules/graphics-engine)
add_subdirectory(modules/engine)

add_executable(SiliconGraphics tests/main.cpp)


target_link_libraries(SiliconGraphics PRIVATE GraphicsEngine glfw glm)


#TESTS

