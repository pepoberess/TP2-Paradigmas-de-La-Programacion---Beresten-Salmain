#ifndef POKEDEX_H
#define POKEDEX_H

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

    void cargarArchivo(); // carga los datos desde el archivo al iniciar la Pokedex                        
    void guardarArchivo(const Pokemon&, const PokemonInfo&); // guarda un Pokémon y su información en el archivo

public:
    Pokedex() = default; // constructor por defecto
    Pokedex(const std::string& archivo); // constructor que recibe el nombre del archivo para guardar los datos

    void agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info); // agrega un Pokémon y su información a la base de datos y lo guarda en el archivo
    void mostrar(const Pokemon& pokemon) const; // muestra la información de un Pokémon específico, si está registrado
    void mostrarTodos() const; // muestra la información de todos los Pokémon registrados en la base de datos
};

#endif
