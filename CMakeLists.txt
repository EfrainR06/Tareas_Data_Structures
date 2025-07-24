cmake_minimum_required(VERSION 3.31)
project(TareasDatos)

set(CMAKE_CXX_STANDARD 20)

add_executable(TareasDatos main.cpp
        Tarea_tipo_guardados.cpp
        Tarea_argc_argv.cpp)
