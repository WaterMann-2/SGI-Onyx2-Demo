project(SpEngine)


add_library(SpEngine STATIC)

target_sources(SpEngine
        PRIVATE
        src/Components/Component.cpp
        src/Scene/Scene.cpp
        src/Scene/Node.cpp

        PUBLIC
            FILE_SET HEADERS
            FILES
        include/Components/Component.h
        include/Scene/Scene.h
        include/Scene/Node.h
)

target_link_libraries(SpEngine PRIVATE glm)
target_link_libraries(SpEngine PRIVATE GraphicsEngine)

target_include_directories(SpEngine
    PRIVATE "src"
    PUBLIC "include"
)