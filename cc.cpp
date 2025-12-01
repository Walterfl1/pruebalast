#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath> // Para operaciones estadísticas, aunque no estrictamente necesaria aquí

// =================================================================
// ESTRUCTURA BASE: JUGADOR (Player)
// =================================================================
struct Player {
    int id;
    std::string nombre;
    int nivel;
    std::string clase; // "Guerrero", "Mago", "Arquero"
    int poder; // Medida general de fuerza

    // Constructor para facilitar la inicialización
    Player(int i, const std::string& n, int lvl, const std::string& c, int p)
        : id(i), nombre(n), nivel(lvl), clase(c), poder(p) {}

    // Sobrecarga del operador < para ordenar el SET por ID (Requerimiento 1)
    bool operator<(const Player& other) const {
        return id < other.id;
    }
};

// Función de comparación para ordenar por poder (Requerimiento 7)
// Usado en std::sort
bool compararPorPoder(const Player& a, const Player& b) {
    // Orden descendente (más fuerte primero)
    return a.poder > b.poder;
}


// =================================================================
// FUNCIÓN PRINCIPAL (MAIN)
// =================================================================
int main() {
    // Datos de ejemplo para poblar las estructuras
    std::vector<Player> datos_iniciales = {
        Player(101, "GuerreroX", 50, "Guerrero", 800),
        Player(303, "MagoZ", 45, "Mago", 950),
        Player(202, "ArqueroY", 60, "Arquero", 750),
        Player(404, "MagoA", 55, "Mago", 980),
        Player(505, "GuerreroB", 70, "Guerrero", 1000)
    };

    // -----------------------------------------------------------------
    // 1. Guardar todos los jugadores en un set<Player> ordenado por id.
    // std::set mantiene los elementos ordenados automáticamente.
    // -----------------------------------------------------------------
    std::set<Player> jugadores_set;
    for (const auto& p : datos_iniciales) {
        jugadores_set.insert(p);
    }
    std::cout << "1. Jugadores en SET (ordenado por ID): " << jugadores_set.size() << " elementos." << std::endl;


    // -----------------------------------------------------------------
    // 2. Crear un map<string, set<int>> que clasifique jugadores por clase
    //    (ej: todos los IDs de los magos).
    // -----------------------------------------------------------------
    std::map<std::string, std::set<int>> clasificacion_por_clase;
    for (const auto& player : jugadores_set) {
        // La clave es la clase (string), el valor es un set<int> de IDs
        clasificacion_por_clase[player.clase].insert(player.id);
    }
    std::cout << "2. Clases: " << clasificacion_por_clase.size() << ". Mago IDs: ";
    for (int id : clasificacion_por_clase["Mago"]) {
        std::cout << id << " ";
    }
    std::cout << std::endl;


    // -----------------------------------------------------------------
    // 3. Crear un unordered_map<int, Player> para acceso rápido por ID.
    //    Acceso O(1) en promedio.
    // -----------------------------------------------------------------
    std::unordered_map<int, Player> acceso_rapido;
    for (const auto& p : jugadores_set) {
        acceso_rapido[p.id] = p;
    }
    std::cout << "3. Acceso rápido al jugador 202: " << acceso_rapido[202].nombre << std::endl;


    