#include "Drone.hpp"

#include <vector>

int main(){
    const int n = 5;

    std::vector<std::thread> threads;
    std::mutex zones[n];
    std::mutex print_mtx;
    std::vector<Drone> drones;

    for (long unsigned int i = 0; i < n; i++){
        drones.emplace_back(i, zones, print_mtx);
    }

    for (unsigned long int i = 0; i < n; i++){
        threads.emplace_back(&Drone::fly, &drones[i]);
    }

    for(auto& h : threads){
        h.join();
    }

    return 0;
}