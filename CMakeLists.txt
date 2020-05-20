cmake_minimum_required(VERSION 3.6)
project(GameOfLife C)

set(CMAKE_C_STANDARD 11)

find_package(MPI REQUIRED)

add_executable(GameOfLife main.c misc.c all.h singleProcess.c multi_process.c)

set(OpenGlLinkers -lglut -lGLU -lGL)

target_link_libraries(GameOfLife ${MPI_LIBRARIES} ${OpenGlLinkers})

include_directories(${MPI_INCLUDE_PATH})

if(MPI_COMPILE_FLAGS)
    set_target_properties(GameOfLife PROPERTIES
            COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()
if(MPI_LINK_FLAGS)
    set_target_properties(GameOfLife PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()

