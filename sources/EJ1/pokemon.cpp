#include "pokemon.hpp"

Pokemon::Pokemon(const std::string& name, int experience)
    // Constructor que inicializa el nombre y la experiencia del Pokémon
    : name(name), experience(experience) {}

std::string Pokemon::getName() const {
    // Obtiene el nombre del Pokémon
    return name;
}

int Pokemon::getExperience() const {
    // Obtiene la experiencia del Pokémon
    return experience;
}

bool Pokemon::operator==(const Pokemon& other) const {
    // Operador de igualdad para comparar dos Pokémon
    // Compara los nombres de los Pokémon para determinar si son iguales
    return name == other.name;
}

std::size_t PokemonHash::operator()(const Pokemon& p) const {
    // Función de hash para calcular un valor hash basado en el nombre del Pokémon  
    // Utiliza el nombre del Pokémon para generar un valor hash
    // Esto asegura que dos Pokémon con el mismo nombre generen el mismo hash
    return std::hash<std::string>()(p.getName());
}