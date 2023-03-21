cmake_minimum_required(VERSION 3.0.0)
set(PROJECT_NAME TwoProcs)

project(
    ${PROJECT_NAME}
        LANGUAGES
            C
            CXX
)

add_executable( 
    ${PROJECT_NAME}
        pthread.c
)

target_link_libraries(
    ${PROJECT_NAME}
        pthread
)
