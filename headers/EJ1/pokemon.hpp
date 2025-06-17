#pragma once

#include <string>

class Pokemon {
    private:
        std::string name;
        int experience;

    public:
        Pokemon(const std::string& name, int experience);
        std::string getName() const;
        int getExperience() const;

        bool operator==(const Pokemon& other) const;
};

// Functor de hash para Pokemon

struct PokemonHash {
    std::size_t operator()(const Pokemon& p) const;
};