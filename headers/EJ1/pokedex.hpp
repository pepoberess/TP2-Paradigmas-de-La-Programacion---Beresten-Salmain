#ifndef POKEDEX_H
#define POKEDEX_H

#include "pokemon.hpp"
#include "pokemonInfo.hpp"
#include <unordered_map>
#include <string>
#include <fstream>

class Pokedex {
private:
    std::unordered_map<Pokemon, PokemonInfo, PokemonHash> baseDatos;
    std::string archivo;  // ruta del archivo

    void cargarArchivo();                            
    void guardarArchivo(const Pokemon&, const PokemonInfo&); 

public:
    Pokedex() = default;
    Pokedex(const std::string& archivo);  // constructor con archivo

    void agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info);
    void mostrar(const Pokemon& pokemon) const;
    void mostrarTodos() const;
};

#endif
