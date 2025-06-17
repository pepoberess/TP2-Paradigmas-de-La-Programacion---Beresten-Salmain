#include "pokedex.hpp"
#include <iostream>
#include <sstream>

Pokedex::Pokedex(const std::string& a) : archivo(a) {
    cargarArchivo();
}

void Pokedex::cargarArchivo() {
    std::ifstream in(archivo);
    if (!in.is_open()) return;

    std::string linea;
    while (std::getline(in, linea)) {
        std::stringstream ss(linea);
        std::string nombre, tipo, descripcion;
        int experiencia;
        std::getline(ss, nombre, ',');
        ss >> experiencia;
        ss.ignore(1);
        std::getline(ss, tipo, ',');
        std::getline(ss, descripcion, ',');

        std::unordered_map<std::string, int> ataques;
        for (int i = 0; i < 3; ++i) {
            std::string ataque;
            int dano;
            std::getline(ss, ataque, ':');
            ss >> dano;
            ss.ignore(1);
            ataques[ataque] = dano;
        }

        std::array<int, 3> niveles;
        for (long unsigned int i = 0; i < 3; ++i) {
            ss >> niveles[i];
            if (i < 2) ss.ignore(1);
        }

        Pokemon p(nombre, experiencia);
        PokemonInfo info(tipo, descripcion, ataques, niveles);
        baseDatos[p] = info;
    }
    in.close();
}

void Pokedex::guardarArchivo(const Pokemon& pokemon, const PokemonInfo& info) {
    if (archivo.empty()) return;
    std::ofstream out(archivo, std::ios::app);
    if (!out.is_open()) return;

    out << pokemon.getName() << "," << pokemon.getExperience() << ","
        << info.getType() << "," << info.getDescription() << ",";

    int count = 0;
    for (const auto& [nombre, dano] : info.getAtacks()) {
        out << nombre << ":" << dano;
        if (++count < 3) out << ",";
    }
    out << ",";

    const auto& niveles = info.getXPlevels();
    out << niveles[0] << "," << niveles[1] << "," << niveles[2] << "\n";

    out.close();
}

void Pokedex::agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info) {
    if (baseDatos.find(pokemon) == baseDatos.end()) {
        baseDatos[pokemon] = info;
        guardarArchivo(pokemon, info);
    } else {
        std::cout << "El Pokemon \"" << pokemon.getName() << "\" ya esta registrado en la Pokedex.\n";
    }
}



void Pokedex::mostrar(const Pokemon& pokemon) const {
    auto it = baseDatos.find(pokemon);
    if (it == baseDatos.end()) {
        std::cout << "Pokemon desconocido!" << std::endl;
        return;
    }

    const PokemonInfo& info = it->second;
    std::cout << "Pokemon: " << pokemon.getName() << "\n";
    std::cout << "Experiencia: " << pokemon.getExperience() << "\n";
    std::cout << "Tipo: " << info.getType() << "\n";
    std::cout << "Descripcion: " << info.getDescription() << "\n";

    std::cout << "Ataques disponibles:\n";
    for (const auto& [ataque, dano] : info.getAtacks()) {
        std::cout << " - " << ataque << ": " << dano << " dano\n";
    }

    std::cout << "Experiencia para proximos niveles: ";
    for (int exp : info.getXPlevels()) {
        std::cout << exp << " ";
    }
    std::cout << "\n";
}

void Pokedex::mostrarTodos() const {
    for (const auto& [pokemon, info] : baseDatos) {
        mostrar(pokemon);
        std::cout << "-----------------------\n";
    }
}
