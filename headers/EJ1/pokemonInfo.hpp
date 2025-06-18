#pragma once 

#include <string>
#include <map>
#include <array>
#include <ostream>
#include <unordered_map>

/* PokemonInfo es una clase que representa la información de un Pokémon, incluyendo su tipo, descripción, 
   ataques y niveles de experiencia. Proporciona métodos para acceder a estos datos y un constructor para 
   inicializarlos. 
*/

class PokemonInfo {
    private:
        std::string type; // Tipo del Pokémon (por ejemplo, Agua, Fuego, Planta)
        std::string description; // Breve descripción del Pokémon
        std::unordered_map<std::string, int> atacks; // Mapa que asocia nombres de ataques con sus niveles de poder
        std::array<int, 3> XPlevels; // Niveles de experiencia del Pokémon, representados como un array de 3 enteros
    public:
        PokemonInfo() = default; // Constructor por defecto
        PokemonInfo(const std::string& type, const std::string& description,
                    const std::unordered_map<std::string, int>& atacks, const std::array<int, 3>& XPlevels);
        // Constructor que inicializa el tipo, descripción, ataques y niveles de experiencia del Pokémon

        std::string getType() const; // Obtiene el tipo del Pokémon
        std::string getDescription() const; // Obtiene la descripción del Pokémon
        std::unordered_map<std::string, int> getAtacks() const; // Obtiene el mapa de ataques del Pokémon, donde las claves son 
                                                                // los nombres de los ataques y los valores son sus niveles de poder
        std::array<int, 3> getXPlevels() const; // Obtiene los niveles de experiencia del Pokémon, representados como un  
                                                // array de 3 enteros
};