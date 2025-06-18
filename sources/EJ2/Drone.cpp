#include "Drone.hpp"

void Drone::fly(){
    // Método que simula el vuelo del dron, realizando tareas en las zonas asignadas.
    // Cada dron espera para despegar, adquiere los mutex de las zonas asignadas
    int left = id; // Zona izquierda del dron, que es el mismo ID del dron.
    int right = (id + 1) % 5; // Zona derecha del dron, que es el siguiente ID en un ciclo de 5 drones.

    {
        std::lock_guard<std::mutex> lock(print_mtx); // Protege la salida estándar para evitar que varios hilos escriban al mismo tiempo.
        std::cout << "Dron " << id << " esperando para despegar..." << std::endl;
    }

    std::lock(zones[left], zones[right]); // Bloquea los mutex de las zonas izquierda y derecha del dron.

    std::unique_lock<std::mutex> lock_left(zones[left], std::adopt_lock); // Adopta el mutex de la zona izquierda, permitiendo que se desbloquee automáticamente al salir del bloque.
    std::unique_lock<std::mutex> lock_right(zones[right], std::adopt_lock); // Adopta el mutex de la zona derecha, permitiendo que se desbloquee automáticamente al salir del bloque.

    {
        std::unique_lock<std::mutex> lock(print_mtx); // Protege la salida estándar para evitar que varios hilos escriban al mismo tiempo.
        std::cout << "Dron " << id << " despegando..." << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(5)); // Simula el tiempo que tarda el dron en despegar.

    {
        std::unique_lock<std::mutex> lock(print_mtx); // Protege la salida estándar para evitar que varios hilos escriban al mismo tiempo.
        std::cout << "Dron " << id << " alcanzó altura de 10m" << std::endl;
    }
}