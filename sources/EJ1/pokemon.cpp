#include "pokemon.hpp"

Pokemon::Pokemon(const std::string& name, int experience)
    : name(name), experience(experience) {}

std::string Pokemon::getName() const {
    return name;
}

int Pokemon::getExperience() const {
    return experience;
}

bool Pokemon::operator==(const Pokemon& other) const {
    return name == other.name;
}

std::size_t PokemonHash::operator()(const Pokemon& p) const {
    return std::hash<std::string>()(p.getName());
}