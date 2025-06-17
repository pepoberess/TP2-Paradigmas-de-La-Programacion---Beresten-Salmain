cmake_minimum_required(VERSION 3.16)
project(TP2 CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    headers/EJ1
    headers/EJ2
)

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

add_executable(pokemon
    examples/EJ1/main.cpp
    sources/EJ1/pokedex.cpp
    sources/EJ1/pokemon.cpp
    sources/EJ1/pokemonInfo.cpp
)

add_executable(drones
    examples/EJ2/main.cpp
    sources/EJ2/Drone.cpp
)

add_executable(SR
    examples/EJ3/main.cpp
)