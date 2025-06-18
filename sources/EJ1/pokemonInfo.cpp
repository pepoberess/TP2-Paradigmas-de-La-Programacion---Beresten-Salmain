#include "pokemonInfo.hpp"

PokemonInfo::PokemonInfo(const std::string& type, const std::string& description,
                         const std::unordered_map<std::string, int>& atacks, const std::array<int, 3>& XPlevels)
    // Constructor que inicializa el tipo, descripción, ataques y niveles de experiencia del Pokémon
    : type(type), description(description), atacks(atacks), XPlevels(XPlevels) {}

std::string PokemonInfo::getType() const {
    // Obtiene el tipo del Pokémon
    return type;
}

std::string PokemonInfo::getDescription() const {
    // Obtiene la descripción del Pokémon
    return description;
}

std::unordered_map<std::string, int> PokemonInfo::getAtacks() const {
    // Obtiene el mapa de ataques del Pokémon, donde las claves son los
    // nombres de los ataques y los valores son sus niveles de poder
    return atacks;
}

std::array<int, 3> PokemonInfo::getXPlevels() const {
    // Obtiene los niveles de experiencia del Pokémon, representados como un array de 3 enteros
    return XPlevels;
}

