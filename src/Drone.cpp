#include "Drone.hpp"

void Drone::fly(){
    int left = id;
    int right = (id + 1) % 5;

    {
        std::lock_guard<std::mutex> lock(print_mtx);
        std::cout << "Dron " << id << " esperando para despegar..." << std::endl;
    }

    std::lock(zones[left], zones[right]);

    std::unique_lock<std::mutex> lock_izq(zones[left], std::adopt_lock);
    std::unique_lock<std::mutex> lock_der(zones[right], std::adopt_lock);

    {
        std::unique_lock<std::mutex> lock(print_mtx);
        std::cout << "Dron " << id << " despegando..." << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));

    {
        std::unique_lock<std::mutex> lock(print_mtx);
        std::cout << "Dron " << id << " alcanzó altura de 10m" << std::endl;
    }
}