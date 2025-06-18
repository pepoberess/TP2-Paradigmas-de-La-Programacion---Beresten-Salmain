#pragma once

#include <string>

/* Pokemon es una clase que representa un Pokémon con un nombre y experiencia.
   Proporciona métodos para obtener el nombre y la experiencia del Pokémon, así como
   un operador de igualdad para comparar dos Pokémon.
*/

class Pokemon {
    private:
        std::string name; // Nombre del Pokémon
        int experience; // Experiencia del Pokémon

    public:
        Pokemon(const std::string& name, int experience); // Constructor que inicializa el nombre y la experiencia del Pokémon
        Pokemon() = default;
        std::string getName() const; // Obtiene el nombre del Pokémon
        int getExperience() const; // Obtiene la experiencia del Pokémon

        bool operator==(const Pokemon& other) const; // Operador de igualdad para comparar dos Pokémon
};

// Functor de hash para Pokemon
struct PokemonHash {
    // Función de hash para calcular un valor hash basado en el nombre y la experiencia del Pokémon
    std::size_t operator()(const Pokemon& p) const; 
};