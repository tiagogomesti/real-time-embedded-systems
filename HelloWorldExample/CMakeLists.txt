cmake_minimum_required(VERSION 3.0.0)

set(PROJECT_NAME HelloWorld)

project(
    ${PROJECT_NAME}
        LANGUAGES
            C
            CXX
)

add_executable( 
    ${PROJECT_NAME}
        hello_world.c
)

target_link_libraries(${PROJECT_NAME})