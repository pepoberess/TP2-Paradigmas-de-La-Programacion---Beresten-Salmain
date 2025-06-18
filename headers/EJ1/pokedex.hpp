#pragma once

#include "pokemon.hpp"
#include "pokemonInfo.hpp"
#include <unordered_map>
#include <string>
#include <fstream>

/* Pokedex es una clase que maneja una base de datos de Pokémon, permitiendo agregar, mostrar 
   y guardar información sobre ellos. Utiliza un mapa hash para almacenar Pokémon y su información 
   asociada, y permite cargar y guardar datos desde un archivo. 
*/

class Pokedex {
private:
    std::unordered_map<Pokemon, PokemonInfo, PokemonHash> baseDatos;  // mapa hash que almacena Pokémon y su información
    std::string archivo; // nombre del archivo donde se guardan los datos

    void serializar(const Pokemon& pokemon, const PokemonInfo& info, std::ofstream& out); // serializa un Pokémon y su información en un archivo
    bool deserializar(std::ifstream& in, Pokemon& pokemon, PokemonInfo& info); // deserializa un Pokémon y su información desde un archivo

public:
    Pokedex() = default; // constructor por defecto
    Pokedex(const std::string& archivo); // constructor que recibe el nombre del archivo para guardar los datos

    void agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info); // agrega un Pokémon y su información a la base de datos y lo guarda en el archivo
    void mostrar(const Pokemon& pokemon) const; // muestra la información de un Pokémon específico, si está registrado
    void mostrarTodos() const; // muestra la información de todos los Pokémon registrados en la base de datos
};