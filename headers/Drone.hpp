#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class Drone{
private:
    int id;
    std::mutex* zones;
    std::mutex& print_mtx;
public:
     Drone(int i, std::mutex* z, std::mutex& pm) : id(i), zones(z), print_mtx(pm) {}
     void fly();
};