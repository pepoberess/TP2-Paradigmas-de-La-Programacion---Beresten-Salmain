#include "pokedex.hpp"
#include <iostream>
#include <sstream>

Pokedex::Pokedex(const std::string& a) : archivo(a) { // Constructor que inicializa el nombre del archivo
    cargarArchivo();
}

void Pokedex::cargarArchivo() { 
    // Carga los datos desde el archivo al iniciar la Pokedex.
    std::ifstream in(archivo); //Abre el archivo 
    if (!in.is_open()) return; // Si no se puede abrir el archivo, no hace nada.

    std::string linea;
    while (std::getline(in, linea)) { // Lee cada línea del archivo
        std::stringstream ss(linea);
        std::string nombre, tipo, descripcion;
        int experiencia;
        std::getline(ss, nombre, ','); // Obtiene el nombre del Pokémon hasta la coma
        ss >> experiencia; // Obtiene la experiencia del Pokémon
        ss.ignore(1); // Ignora la coma siguiente
        std::getline(ss, tipo, ','); // Obtiene el tipo del Pokémon hasta la coma
        std::getline(ss, descripcion, ','); // Obtiene la descripción del Pokémon hasta la coma

        std::unordered_map<std::string, int> ataques;
        for (int i = 0; i < 3; ++i) { // Lee hasta 3 ataques del Pokémon
            std::string ataque; 
            int dano;
            std::getline(ss, ataque, ':'); // Obtiene el nombre del ataque hasta los dos puntos
            ss >> dano; // Obtiene el daño del ataque
            ss.ignore(1); // Ignora la coma siguiente
            ataques[ataque] = dano; // Almacena el ataque y su daño en el mapa
        }

        std::array<int, 3> niveles; 
        for (long unsigned int i = 0; i < 3; ++i) { // Lee los niveles de experiencia del Pokémon
            ss >> niveles[i]; 
            if (i < 2) ss.ignore(1); // Ignora la coma siguiente, excepto para el último nivel
        }

        Pokemon p(nombre, experiencia); // Crea un objeto Pokémon con el nombre y la experiencia leída
        PokemonInfo info(tipo, descripcion, ataques, niveles); // Crea un objeto PokemonInfo con el tipo, 
                                                               // descripción, ataques y niveles leídos
        baseDatos[p] = info; // Almacena el Pokémon y su información en la base de datos
    }
    in.close(); // Cierra el archivo después de leer todos los datos.
}

void Pokedex::guardarArchivo(const Pokemon& pokemon, const PokemonInfo& info) {
    // Guarda un Pokémon y su información en el archivo.
    if (archivo.empty()) return;
    std::ofstream out(archivo, std::ios::app); // Abre el archivo en modo de adición (append)
    if (!out.is_open()) return;

    // Escribe los datos del Pokémon en el formato: nombre, experiencia, tipo, descripción, ataques y niveles de experiencia
    out << pokemon.getName() << "," << pokemon.getExperience() << ","
        << info.getType() << "," << info.getDescription() << ",";

    int count = 0;
    for (const auto& [nombre, dano] : info.getAtacks()) { // Recorre los ataques del Pokémon
        out << nombre << ":" << dano; // Escribe el nombre del ataque y su daño
        if (++count < 3) out << ",";
    }
    out << ",";

    const auto& niveles = info.getXPlevels();
    out << niveles[0] << "," << niveles[1] << "," << niveles[2] << "\n";

    out.close(); // Cierra el archivo después de escribir los datos.
}

void Pokedex::agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info) { 
    // Agrega un Pokémon y su información a la base de datos y lo guarda en el archivo.
    if (baseDatos.find(pokemon) == baseDatos.end()) { // Verifica si el Pokémon ya está registrado
        baseDatos[pokemon] = info;
        guardarArchivo(pokemon, info); // Guarda el Pokémon y su información en el archivo
    } else {
        std::cout << "El Pokemon \"" << pokemon.getName() << "\" ya esta registrado en la Pokedex.\n";
    }
}



void Pokedex::mostrar(const Pokemon& pokemon) const {
    // Muestra la información de un Pokémon específico, si está registrado.
    auto it = baseDatos.find(pokemon); // Busca el Pokémon en la base de datos
    if (it == baseDatos.end()) { // Si el Pokémon no está registrado, muestra un mensaje de error
        std::cout << "Pokemon desconocido!" << std::endl;
        return;
    }

    const PokemonInfo& info = it->second; // Obtiene la información del Pokémon encontrado
    std::cout << "Pokemon: " << pokemon.getName() << "\n"; // Muestra el nombre del Pokémon
    std::cout << "Experiencia: " << pokemon.getExperience() << "\n"; // Muestra la experiencia del Pokémon
    std::cout << "Tipo: " << info.getType() << "\n"; // Muestra el tipo del Pokémon
    std::cout << "Descripcion: " << info.getDescription() << "\n"; // Muestra la descripción del Pokémon

    std::cout << "Ataques disponibles:\n"; 
    for (const auto& [ataque, dano] : info.getAtacks()) { // Recorre los ataques del Pokémon y muestra su nombre y daño
        std::cout << " - " << ataque << ": " << dano << " dano\n";
    }

    std::cout << "Experiencia para proximos niveles: ";
    for (int exp : info.getXPlevels()) { // Recorre los niveles de experiencia del Pokémon y los muestra
        std::cout << exp << " ";
    }
    std::cout << "\n";
}

void Pokedex::mostrarTodos() const {
    // Muestra la información de todos los Pokémon registrados en la base de datos.
    for (const auto& [pokemon, info] : baseDatos) {
        mostrar(pokemon); //Llama a la función mostrar para cada Pokémon en la base de datos
        std::cout << "-----------------------\n";
    }
}
