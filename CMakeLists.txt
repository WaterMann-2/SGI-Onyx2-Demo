cmake_minimum_required(VERSION 3.17)
project(SiliconGraphics)

set(CMAKE_CXX_STANDARD 11)

#find_package(OpenGL 1.1 REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(SiliconGraphics src/main.cpp
        src/graphics/Graphics.cpp
        src/graphics/Graphics.h
        src/glad/glad.c
        src/glad/glad.h
        src/glad/khrplatform.h
        src/utils/SpUtils.cpp
        src/utils/SpUtils.h
        src/math/Math.cpp
        src/math/Math.h
        src/graphics/Scene.cpp
        src/graphics/Scene.h
        src/math/Matrix.cpp
        src/math/Matrix.h
)


#target_link_libraries(SiliconGraphics PRIVATE OpenGL::OpenGL)
target_link_libraries(SiliconGraphics PRIVATE glfw)