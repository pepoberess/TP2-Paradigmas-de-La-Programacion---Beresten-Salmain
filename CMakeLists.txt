cmake_minimum_required(VERSION 3.16)
project(TP2 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(headers)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall            # Todos los warnings comunes
        -Wextra          # Warnings adicionales
        -Wpedantic       # Estándar ISO puro
        -Wconversion     # Avisos por conversiones implícitas
        -Wsign-conversion# Signo diferente entre tipos
        -Wshadow         # Variables que ocultan otras
        -Wnull-dereference
        -Wdouble-promotion
        -Wformat=2       # Más estricta validación de formatos printf/scanf
        -Wmisleading-indentation
        -Wunused
        -Wnon-virtual-dtor
        -Woverloaded-virtual
        -Wduplicated-cond
        -Wduplicated-branches
        -Wlogical-op
        -Wold-style-cast
        -Wuseless-cast
        -Wzero-as-null-pointer-constant
        -Wextra-semi
        -Wcast-align
        -Wundef
    )
endif()

add_executable(drones
    examples/main.cpp
    src/Drone.cpp
)

add_executable(SR
    examples/SMPRA.cpp
)