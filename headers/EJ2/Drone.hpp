#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

/* Drone es una clase que representa un dron que vuela en zonas específicas. 
    Cada dron tiene un ID único, un mutex para las zonas que controla y un mutex para la impresión.
    El método fly simula el vuelo del dron, donde realiza tareas en las zonas asignadas y 
    utiliza los mutex para evitar conflictos al acceder a recursos compartidos.
*/

class Drone{
private:
    int id; // Identificador único del dron.
    std::mutex* zones; // Array de mutexes que representan las zonas que el dron puede controlar.
    std::mutex& print_mtx; // Mutex para proteger la salida estándar y evitar que varios hilos escriban al mismo tiempo.
public:
    // Constructor que inicializa el ID del dron, el array de mutexes de zonas y el mutex de impresión.
     Drone(int i, std::mutex* z, std::mutex& pm) : id(i), zones(z), print_mtx(pm) {}
     void fly(); // Método que simula el vuelo del dron, realizando tareas en las zonas asignadas.
};