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

