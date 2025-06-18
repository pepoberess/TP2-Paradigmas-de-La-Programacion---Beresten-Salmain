#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>

/* Este ejemplo simula un sistema donde varios sensores generan tareas y varios robots las procesan.
   Los sensores generan 5 tareas cada uno, y los robots procesan las tareas de la cola. Se utiliza 
   una cola protegida por mutex y una variable de condición para sincronizar la producción y el 
   consumo de tareas. Los sensores notifican a los robots cuando hay nuevas tareas disponibles, 
   y los robots procesan las tareas en orden. El programa finaliza cuando todos los sensores han 
   terminado de generar tareas y todas las tareas han sido procesadas. */

struct Tarea{ // Estructura que representa una tarea generada por un sensor y que será procesada por un robot.
    int idSensor; // identificador del sensor que generó la tarea
    int idTarea; // identificador de la tarea
    std::string descripcionTarea; // descripción de la tarea
};

std::queue<Tarea> tareas; // cola de tareas generadas por los sensores y procesadas por los robots
std::mutex cola_mtx; // mutex para proteger el acceso a la cola de tareas
std::condition_variable cvCola; // variable de condición para notificar a los robots cuando hay nuevas tareas disponibles
std::mutex print_mtx; // mutex para proteger el acceso a la salida estándar

int sensoresTerminados = 0; // contador de sensores que han terminado de generar tareas
const int sensoresTotales = 3; // total de sensores que generarán tareas

void Reportar(int idSensor){ 
    // Función que simula el comportamiento de un sensor generando tareas.
    for (int i = 0; i < 5; i++) {
        // Cada sensor genera 5 tareas, cada una con un identificador único.
        Tarea tarea{ idSensor, i, "Tarea del sensor " + std::to_string(idSensor) + " número " + std::to_string(i) };

        {
            std::lock_guard<std::mutex> lock(print_mtx); // Protege la salida estándar para evitar que varios hilos escriban al mismo tiempo.
            std::cout << "Sensor " << idSensor << " generó tarea " << i << "\n";
        }
        
        {
            std::lock_guard<std::mutex> lock(cola_mtx); // Protege el acceso a la cola de tareas para evitar condiciones de carrera.
            tareas.push(tarea);
        }

        cvCola.notify_one(); // Avisa que hay una nueva tarea

        std::this_thread::sleep_for(std::chrono::milliseconds(175)); // Simula el tiempo que tarda el sensor en generar una tarea.
    }

    {
        std::lock_guard<std::mutex> lock(cola_mtx); // Protege el acceso al contador de sensores terminados.
        sensoresTerminados++; 
    }

    cvCola.notify_all(); // Avisa a todos los robots que un sensor ha terminado de generar tareas, por si hay alguno esperando.
}


void Procesar(int idRobot) {
    // Función que simula el comportamiento de un robot procesando tareas de la cola.
    // Cada robot procesa las tareas en orden, esperando a que haya tareas disponibles.
    while (true) {
        // Espera a que haya tareas disponibles o que todos los sensores hayan terminado.
        std::unique_lock<std::mutex> cola_lock(cola_mtx); // Bloquea el mutex para acceder a la cola de tareas.
        cvCola.wait(cola_lock, [] { return !tareas.empty() || sensoresTerminados == sensoresTotales; }); // Espera hasta que haya tareas o todos los sensores hayan terminado.

        if (tareas.empty()) break; // Si no hay tareas y todos los sensores han terminado, sale del bucle.

        Tarea tarea = tareas.front(); // Obtiene la tarea del frente de la cola.
        tareas.pop(); // Elimina la tarea de la cola.
        cola_lock.unlock(); // Desbloquea el mutex para permitir que otros hilos accedan a la cola.

        {
            std::lock_guard<std::mutex> lock(print_mtx); // Protege la salida estándar para evitar que varios hilos escriban al mismo tiempo.
            std::cout << "Robot " << idRobot << " procesando tarea " << tarea.idTarea << " del sensor " << tarea.idSensor << "\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(250)); // Simula el tiempo que tarda el robot en procesar la tarea.
    }

    {
        std::lock_guard<std::mutex> lock(print_mtx); // Protege la salida estándar para evitar que varios hilos escriban al mismo tiempo.
        std::cout << "Robot " << idRobot << " terminó\n";
    }
}

int main(){
    // Función principal que inicia los hilos de sensores y robots.
    const int n = 3; // Número de sensores y robots a crear.

    std::vector<std::thread> sensores; // Vector para almacenar los hilos de los sensores.
    std::vector<std::thread> robots; // Vector para almacenar los hilos de los robots.

    for (int i = 0; i < n; ++i) 
        // Crea un hilo para cada sensor, que ejecuta la función Reportar.
        sensores.emplace_back(Reportar, i);

    for (int i = 0; i < n; ++i)
        // Crea un hilo para cada robot, que ejecuta la función Procesar.
        robots.emplace_back(Procesar, i);

    for (auto& s : sensores) s.join(); // Espera a que todos los sensores terminen de generar tareas.
    for (auto& r : robots) r.join(); // Espera a que todos los robots terminen de procesar las tareas.

    std::cout << "Todas las tareas han sido procesadas!" << std::endl;

    return 0;
}