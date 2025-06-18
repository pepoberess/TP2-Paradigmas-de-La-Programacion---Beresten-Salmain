#include "Drone.hpp"

#include <vector>

int main(){
    // Función principal que inicia los hilos de drones.
    // Crea un número fijo de drones, cada uno con su propio mutex para zonas y
    const int n = 5; 

    std::vector<std::thread> threads; // Vector para almacenar los hilos de los drones.
    std::mutex zones[n]; // Array de mutexes para cada zona que los drones pueden usar.
    std::mutex print_mtx; // Mutex para proteger la salida estándar y evitar que varios hilos escriban al mismo tiempo.
    std::vector<Drone> drones; // Vector para almacenar los objetos Drone.

    for (unsigned long int i = 0; i < n; i++){
        // Crea un objeto Drone para cada hilo, pasando su ID, el mutex de zonas y el mutex de impresión.
        // Cada Drone tendrá acceso a su propio mutex de zona y al mutex de impresión compartido
        // para evitar conflictos al imprimir en la consola.
        drones.emplace_back(i, zones, print_mtx);
    }

    for (unsigned long int i = 0; i < n; i++){
        // Crea un hilo para cada Drone, que ejecuta su método fly.
        // Cada hilo representará un Drone volando y realizando sus tareas de forma concurrente.
        threads.emplace_back(&Drone::fly, &drones[i]);
    }

    for(auto& t : threads){
        // Espera a que todos los hilos de drones terminen su ejecución.
        // Esto asegura que el programa principal no finalice antes de que todos los drones hayan completado su vuelo.
        t.join();
    }

    return 0;
}
