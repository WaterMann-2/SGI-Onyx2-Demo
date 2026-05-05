cmake_minimum_required(VERSION 3.17)
project(SiliconGraphics)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")


add_subdirectory(graphics-engine)

add_executable(SiliconGraphics tests/main.cpp)


target_link_libraries(SiliconGraphics PRIVATE GraphicsEngine)


#TESTS

add_executable(MatrixTest tests/MatrixTest.cpp)

target_link_libraries(MatrixTest PRIVATE GraphicsEngine)
add_test(Matrix_Test MatrixTest)