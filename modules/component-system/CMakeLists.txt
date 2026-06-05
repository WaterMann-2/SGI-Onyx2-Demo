project(ComponentSystem)


add_library(ComponentSystem STATIC)

target_sources(ComponentSystem
        PRIVATE
            src/Component.cpp

        PUBLIC
            FILE_SET HEADERS
            FILES
        include/Component.h
)

target_link_libraries(ComponentSystem PRIVATE glm)

target_include_directories(ComponentSystem
    PRIVATE "src"
    PUBLIC "include"
)