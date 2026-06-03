project(GraphicsEngine)


add_library(GraphicsEngine STATIC)

target_sources(GraphicsEngine
    PRIVATE
        external/glad/glad.c
        src/Graphics.cpp
        src/utils/SpUtils.cpp
        src/Scene.cpp
        src/properties/Properties.cpp
    PUBLIC
        FILE_SET HEADERS
        FILES

        external/glad/glad.h
        external/glad/khrplatform.h
        include/Graphics.h
        src/utils/SpUtils.h
        include/Scene.h
        include/properties/Properties.h
)

find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(GraphicsEngine PRIVATE glm)
target_link_libraries(GraphicsEngine PRIVATE glfw)

target_include_directories(GraphicsEngine
        PRIVATE "src"
        PUBLIC "include"
)
