#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>

struct Tarea{
    int idSensor;
    int idTarea;
    std::string descripcionTarea;
};

std::queue<Tarea> tareas;
std::mutex cola_mtx;  // protege la cola
std::condition_variable cvCola;  // sincroniza productores/consumidores
std::mutex print_mtx; // protege los cout

int sensoresTerminados = 0;
const int sensoresTotales = 3;

void Reportar(int idSensor){
    for (int i = 0; i < 5; i++) {
        Tarea tarea{ idSensor, i, "Tarea del sensor " + std::to_string(idSensor) + " número " + std::to_string(i) };

        {
            std::lock_guard<std::mutex> lock(print_mtx);
            std::cout << "Sensor " << idSensor << " generó tarea " << i << "\n";
        }
        
        {
            std::lock_guard<std::mutex> lock(cola_mtx);
            tareas.push(tarea);
        }

        cvCola.notify_one(); // avisa que hay una nueva tarea

        std::this_thread::sleep_for(std::chrono::milliseconds(175));
    }

    {
        std::lock_guard<std::mutex> lock(cola_mtx);
        sensoresTerminados++;
    }

    cvCola.notify_all(); // por si robots están esperando
}


void Procesar(int idRobot) {
    while (true) {
        std::unique_lock<std::mutex> cola_lock(cola_mtx);
        cvCola.wait(cola_lock, [] { return !tareas.empty() || sensoresTerminados == sensoresTotales; });

        if (tareas.empty()) break;  // si ya no hay tareas y no habrá más

        Tarea tarea = tareas.front();
        tareas.pop();
        cola_lock.unlock();

        {
            std::lock_guard<std::mutex> lock(print_mtx);
            std::cout << "Robot " << idRobot << " procesando tarea " << tarea.idTarea << " del sensor " << tarea.idSensor << "\n";
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    {
        std::lock_guard<std::mutex> lock(print_mtx);
        std::cout << "Robot " << idRobot << " terminó\n";
    }
}

int main(){
    const int n = 3;

    std::vector<std::thread> sensores;
    std::vector<std::thread> robots;

    for (int i = 0; i < n; ++i)
        sensores.emplace_back(Reportar, i);

    for (int i = 0; i < n; ++i)
        robots.emplace_back(Procesar, i);

    for (auto& s : sensores) s.join();
    for (auto& r : robots) r.join();

    std::cout << "Todas las tareas han sido procesadas!";

    return 0;

}