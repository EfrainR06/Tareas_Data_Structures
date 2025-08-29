cmake_minimum_required(VERSION 3.20)
project(TareasDatos)

set(CMAKE_CXX_STANDARD 20)

# FLTK configuration
set(FLTK_DIR "C:/Users/Usuario/Desktop/fltk-1.4.4")
set(FLTK_BUILD_DIR "${FLTK_DIR}/build")

include_directories(${FLTK_DIR})
include_directories(${FLTK_BUILD_DIR})
link_directories(${FLTK_BUILD_DIR}/lib)

add_executable(TareasDatos
        "SECOND HOMEWORK/punto.cpp"
        "SECOND HOMEWORK/punto.h"
        "SECOND HOMEWORK/rectangulo.cpp"
        "SECOND HOMEWORK/rectangulo.h"
        "SECOND HOMEWORK/Circulo.cpp"
        "SECOND HOMEWORK/Circulo.h"
        "SECOND HOMEWORK/fecha.cpp"
        "SECOND HOMEWORK/fecha.h"
        "SECOND HOMEWORK/tiempo.cpp"
        "SECOND HOMEWORK/tiempo.h"
        "SECOND HOMEWORK/fraccion.cpp"
        "SECOND HOMEWORK/fraccion.h"
        "SECOND HOMEWORK/vector3d.cpp"
        "SECOND HOMEWORK/vector3d.h"
        "SECOND HOMEWORK/recta.cpp"
        "SECOND HOMEWORK/recta.h"
        "SECOND HOMEWORK/empleado.cpp"
        "SECOND HOMEWORK/empleado.h"
        #"THIRD HOMEWORK/Algoritms_and_symptotic_notation.cpp"
        "FOURTH HOMEWORK/Archivo.cpp"
        "FOURTH HOMEWORK/Archivo.h"
        #"FOURTH HOMEWORK/main4thHomework.cpp"
        "SIXTH HOMEWORK/Arreglo_int.h"
        #"SIXTH HOMEWORK/main_15_08_2025.cpp"
        "SEVENTH HOMEWORK/paquetes.h"
        #"SEVENTH HOMEWORK/main_Enunciado_Seventh.cpp"
        "FIFTH HOMEWORK/Archivo_students.h"
        #"FIFTH HOMEWORK/main_homeworkFifth.cpp"
        #"IMPORTANT NOTES/important_structure_for_Quiz.cpp"
        "EIGHTH HOMEWORK/PackagesWithVectors.h"
        #"EIGHTH HOMEWORK/main8thHomework.cpp"
        "STACK NOTES/PILA.h"
        #"STACK NOTES/Stack_main.cpp"
        "STACK NOTES/Lista_paquetes.h"
        "NINTH HOMEWORK/TorreHanoi.h"
       #"NINTH HOMEWORK/mainWithFltk.cpp"
        "TENTH HOMEWORK/ColaCircular_main.cpp"
)
target_link_libraries(TareasDatos
        fltk
        fltk_forms
        fltk_images
        fltk_gl
        ws2_32
        gdiplus
        comctl32
)
