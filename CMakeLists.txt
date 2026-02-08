cmake_minimum_required(VERSION 3.17)
project(SiliconGraphics)

set(CMAKE_CXX_STANDARD 11)

#find_package(OpenGL 1.1 REQUIRED)
find_package(SDL2 REQUIRED)

add_executable(SiliconGraphics src/main.cpp
        src/graphics/Graphics.cpp
        src/graphics/Graphics.h
        src/glad/glad.c
        src/glad/glad.h
        src/glad/khrplatform.h
        src/utils/Utils.cpp
        src/utils/Utils.h
)


#target_link_libraries(SiliconGraphics PRIVATE OpenGL::OpenGL)
target_link_libraries(SiliconGraphics PRIVATE SDL2::SDL2 SDL2::SDL2main)