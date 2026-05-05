project(GraphicsEngine)


add_library(GraphicsEngine STATIC)

target_sources(GraphicsEngine
    PRIVATE
        src/graphics/Graphics.cpp
        src/utils/SpUtils.cpp
        src/math/Math.cpp
        src/graphics/Scene.cpp
        src/math/Matrix.cpp
        src/math/Vector.cpp
        glad/glad.c
    PUBLIC
        FILE_SET HEADERS
        FILES

        glad/glad.h
        glad/khrplatform.h
        src/graphics/Graphics.h
        src/utils/SpUtils.h
        src/math/Math.h
        src/graphics/Scene.h
        src/math/Matrix.h
        src/math/Vector.h
)

find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(GraphicsEngine PRIVATE glfw)

target_include_directories(GraphicsEngine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
