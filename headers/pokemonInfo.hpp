#pragma once 

#include <string>
#include <map>
#include <array>
#include <ostream>
#include <unordered_map>

class PokemonInfo {
    private:
        std::string type;
        std::string description;
        std::unordered_map<std::string, int> atacks;
        std::array<int, 3> XPlevels;
    public:
        PokemonInfo() = default;
        PokemonInfo(const std::string& type, const std::string& description,
                    const std::unordered_map<std::string, int>& atacks, const std::array<int, 3>& XPlevels);

        std::string getType() const;
        std::string getDescription() const;
        std::unordered_map<std::string, int> getAtacks() const;
        std::array<int, 3> getXPlevels() const;        
};