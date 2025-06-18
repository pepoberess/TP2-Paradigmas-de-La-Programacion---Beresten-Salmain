#include "pokedex.hpp"
#include <iostream>

int main() {
    // Este ejemplo muestra cómo usar la clase Pokedex para agregar y mostrar Pokémon.
    // Se crean varios Pokémon con sus respectivas informaciones y se almacenan en un archivo.
    Pokedex pokedex("pokedex.txt"); // Inicializa la Pokedex con un archivo para guardar los datos.

    pokedex.agregarPokemon( // Agrega un Pokémon Squirtle a la Pokedex.
        Pokemon("Squirtle", 100), //Crea un Pokémon Squirtle con 100 de experiencia.
        PokemonInfo("Agua", "Una tortuga pequena que lanza chorros de agua.",
            {{"Pistola Agua", 4}, {"Hidrobomba", 6}, {"Danza Lluvia", 5}},
            {0, 400, 1000}) 
        // Crea la información del Pokémon Squirtle con tipo Agua, descripción, ataques y niveles de experiencia.
    );

    pokedex.agregarPokemon( // Agrega un Pokémon Bulbasaur a la Pokedex.
        Pokemon("Bulbasaur", 270), // Crea un Pokémon Bulbasaur con 270 de experiencia.
        PokemonInfo("Planta", "Tiene una semilla en su lomo que crece con el tiempo",
            {{"Latigazo", 4}, {"Hoja Afilada", 6}, {"Rayo Solar", 5}},
            {0, 300, 1100})
        // Crea la información del Pokémon Bulbasaur con tipo Planta, descripción, ataques y niveles de experiencia.
    );

    pokedex.agregarPokemon( // Agrega un Pokémon Charmander a la Pokedex.
        Pokemon("Charmander", 633), // Crea un Pokémon Charmander con 633 de experiencia.
        PokemonInfo("Fuego", "Una lagartija con una llama en su cola",
            {{"Ascuas", 4}, {"Lanzallamas", 6}, {"Giro Fuego", 5}},
            {0, 250, 1300})
        // Crea la información del Pokémon Charmander con tipo Fuego, descripción, ataques y niveles de experiencia.
    );

    std::cout << "\nMostrar todos los Pokemons:\n";
    pokedex.mostrarTodos(); // Muestra todos los Pokémon registrados en la Pokedex.

    std::cout << "\nMostrar Squirtle (experiencia distinta):\n";
    pokedex.mostrar(Pokemon("Squirtle", 870)); // Muestra el Pokémon Squirtle con una experiencia diferente a la registrada.

    std::cout << "\nMostrar Pikachu (no registrado):\n";
    pokedex.mostrar(Pokemon("Pikachu", 390)); // Intenta mostrar un Pokémon Pikachu que no está registrado en la Pokedex.

    return 0;
}