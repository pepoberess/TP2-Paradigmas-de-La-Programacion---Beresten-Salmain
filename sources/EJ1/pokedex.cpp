#include "pokedex.hpp"
#include <iostream>
#include <sstream>

Pokedex::Pokedex(const std::string& a) : archivo(a) { // Constructor que inicializa el nombre del archivo
    std::ifstream in(archivo, std::ios::binary); // Abre el archivo en modo binario
    if (!in.is_open()) return;

    while (!in.eof()) {
        Pokemon p;
        PokemonInfo info;
        if (deserializar(in, p, info)) {
            baseDatos[p] = info;
        }
    }
    in.close();
}

void Pokedex::serializar(const Pokemon& pokemon, const PokemonInfo& info, std::ofstream& out) {
    // Serializa el nombre del pokemon
    std::string nombre = pokemon.getName();
    size_t nombreLen = nombre.size();
    out.write(reinterpret_cast<const char*>(&nombreLen), sizeof(nombreLen));
    out.write(nombre.c_str(), static_cast<std::streamsize>(nombreLen));

    // Serializa la experiencia
    int experiencia = pokemon.getExperience();
    out.write(reinterpret_cast<const char*>(&experiencia), sizeof(experiencia));

    // Serializa el tipo
    std::string tipo = info.getType();
    size_t tipoLen = tipo.size();
    out.write(reinterpret_cast<const char*>(&tipoLen), sizeof(tipoLen));
    out.write(tipo.c_str(), static_cast<std::streamsize>(tipoLen));

    // Serializa la descripción
    std::string descripcion = info.getDescription();
    size_t descLen = descripcion.size();
    out.write(reinterpret_cast<const char*>(&descLen), sizeof(descLen));
    out.write(descripcion.c_str(), static_cast<std::streamsize>(descLen));

    // Serializa los ataques (asume 3 ataques)
    const auto& ataques = info.getAtacks();
    size_t numAtaques = ataques.size();
    out.write(reinterpret_cast<const char*>(&numAtaques), sizeof(numAtaques));
    for (const auto& [nombreAtaque, dano] : ataques) {
        size_t nombreAtaqueLen = nombreAtaque.size();
        out.write(reinterpret_cast<const char*>(&nombreAtaqueLen), sizeof(nombreAtaqueLen));
        out.write(nombreAtaque.c_str(), static_cast<std::streamsize>(nombreAtaqueLen));
        out.write(reinterpret_cast<const char*>(&dano), sizeof(dano));
    }

    // Serializa los niveles de experiencia (asume std::array<int, 3>)
    const auto& niveles = info.getXPlevels();
    for (int nivel : niveles) {
        out.write(reinterpret_cast<const char*>(&nivel), sizeof(nivel));
    }
}

bool Pokedex::deserializar(std::ifstream& in, Pokemon& pokemon, PokemonInfo& info) {
    if (!in.is_open() || in.eof()) return false;

    // Lee el nombre del Pokémon
    size_t nombreLen;
    in.read(reinterpret_cast<char*>(&nombreLen), sizeof(nombreLen));
    if (in.eof()) return false; // Verifica si se llegó al final del archivo
    std::string nombre(nombreLen, '\0');
    in.read(&nombre[0], static_cast<std::streamsize>(nombreLen));

    // Lee la experiencia
    int experiencia;
    in.read(reinterpret_cast<char*>(&experiencia), sizeof(experiencia));

    // Lee el tipo
    size_t tipoLen;
    in.read(reinterpret_cast<char*>(&tipoLen), sizeof(tipoLen));
    std::string tipo(tipoLen, '\0');
    in.read(&tipo[0], static_cast<std::streamsize>(tipoLen));

    // Lee la descripción
    size_t descLen;
    in.read(reinterpret_cast<char*>(&descLen), sizeof(descLen));
    std::string descripcion(descLen, '\0');
    in.read(&descripcion[0], static_cast<std::streamsize>(descLen));

    // Lee los ataques
    size_t numAtaques;
    in.read(reinterpret_cast<char*>(&numAtaques), sizeof(numAtaques));
    std::unordered_map<std::string, int> ataques;
    for (size_t i = 0; i < numAtaques; ++i) {
        size_t nombreAtaqueLen;
        in.read(reinterpret_cast<char*>(&nombreAtaqueLen), sizeof(nombreAtaqueLen));
        std::string nombreAtaque(nombreAtaqueLen, '\0');
        in.read(&nombreAtaque[0], static_cast<std::streamsize>(nombreAtaqueLen));
        int dano;
        in.read(reinterpret_cast<char*>(&dano), sizeof(dano));
        ataques[nombreAtaque] = dano;
    }

    // Lee los niveles de experiencia (asume std::array<int, 3>)
    std::array<int, 3> niveles;
    for (int& nivel : niveles) {
        in.read(reinterpret_cast<char*>(&nivel), sizeof(nivel));
    }

    // Construye los objetos
    pokemon = Pokemon(nombre, experiencia);
    info = PokemonInfo(tipo, descripcion, ataques, niveles);

    return true;
}


void Pokedex::agregarPokemon(const Pokemon& pokemon, const PokemonInfo& info) { 
    // Agrega un Pokémon y su información a la base de datos y lo guarda en el archivo.
    if (baseDatos.find(pokemon) == baseDatos.end()) { // Verifica si el Pokémon ya está registrado
        baseDatos[pokemon] = info;
        std::ofstream out(archivo, std::ios::binary | std::ios::app); // Abre el archivo en modo binario y append
        if (out.is_open()) {
            serializar(pokemon, info, out); // Guarda el Pokémon y su información en el archivo
            out.close();
        }
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
