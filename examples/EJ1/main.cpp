#include "pokedex.hpp"
#include <iostream>

int main() {
    Pokedex pokedex("pokedex.txt");

    pokedex.agregarPokemon(
        Pokemon("Squirtle", 100),
        PokemonInfo("Agua", "Una tortuga pequena que lanza chorros de agua.",
            {{"Pistola Agua", 4}, {"Hidrobomba", 6}, {"Danza Lluvia", 5}},
            {0, 400, 1000})
    );

    pokedex.agregarPokemon(
        Pokemon("Bulbasaur", 270),
        PokemonInfo("Planta", "Tiene una semilla en su lomo que crece con el tiempo",
            {{"Latigazo", 4}, {"Hoja Afilada", 6}, {"Rayo Solar", 5}},
            {0, 300, 1100})
    );

    pokedex.agregarPokemon(
        Pokemon("Charmander", 633),
        PokemonInfo("Fuego", "Una lagartija con una llama en su cola",
            {{"Ascuas", 4}, {"Lanzallamas", 6}, {"Giro Fuego", 5}},
            {0, 250, 1300})
    );

    std::cout << "\nMostrar todos los Pokemons:\n";
    pokedex.mostrarTodos();

    std::cout << "\nMostrar Squirtle (experiencia distinta):\n";
    pokedex.mostrar(Pokemon("Squirtle", 870));

    std::cout << "\nMostrar Pikachu (no registrado):\n";
    pokedex.mostrar(Pokemon("Pikachu", 390));

    return 0;
}