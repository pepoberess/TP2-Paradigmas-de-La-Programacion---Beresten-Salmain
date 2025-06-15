#include "../headers/pokemonInfo.hpp"

PokemonInfo::PokemonInfo(const std::string& type, const std::string& description,
                         const std::unordered_map<std::string, int>& atacks, const std::array<int, 3>& XPlevels)
    : type(type), description(description), atacks(atacks), XPlevels(XPlevels) {}

std::string PokemonInfo::getType() const {
    return type;
}

std::string PokemonInfo::getDescription() const {
    return description;
}

std::unordered_map<std::string, int> PokemonInfo::getAtacks() const {
    return atacks;
}

std::array<int, 3> PokemonInfo::getXPlevels() const {
    return XPlevels;
}

