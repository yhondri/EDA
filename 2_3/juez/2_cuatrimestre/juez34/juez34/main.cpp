//
//  main.cpp
//  juez34
//
//  Created by Yhondri on 06/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "hashmap_eda.h"
#include <vector>

using namespace std;

bool resuelveCaso();

using DNI = string;

class carnet_puntos {
    
private:
    unordered_map<DNI, int> conductores;
    unordered_map<int, int> usuariosPorPuntos;

public:
    void nuevo(string dni) {
        if (conductores.insert(dni)) {
            conductores[dni] = 15;
            usuariosPorPuntos[conductores[dni]]++;
        } else {
            throw std::domain_error("Conductor duplicado");
        }
    }
    
    void quitar(string dni, int puntos) {
        if (conductores.count(dni) > 0) {
            
            usuariosPorPuntos[conductores[dni]]--; //Primero quitamos un conductor del número de puntos anterior
            
            if (conductores[dni]-puntos < 0) {
                conductores[dni] = 0;
            } else {
                conductores[dni] -= puntos;
            }
            
            usuariosPorPuntos[conductores[dni]]++; //Añadimos un nuevo conductor con nuevos puntos.

        } else {
            throw std::domain_error("Conductor inexistente");
        }
    }
    
    int consultar(string dni) {
        if (conductores.count(dni) > 0) {
            return conductores[dni];
        } else {
            throw std::domain_error("Conductor inexistente");
        }
    }
    
    int cuantos_con_puntos(int puntos) {
        if(puntos < 0 || puntos > 15) {
            throw std::domain_error("Puntos no validos");
        }
        
        return usuariosPorPuntos[puntos];
    }
};

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez34/juez34/casos");
    //    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez29/juez29/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}


bool resuelveCaso() {
    std::string orden, dni;
    int punt;
    std::cin >> orden;
    if (!std::cin)
        return false;
    
    carnet_puntos dgt;
    
    while (orden != "FIN") {
        try {
            if (orden == "nuevo") {
                cin >> dni;
                dgt.nuevo(dni);
            } else if (orden == "quitar") {
                cin >> dni >> punt;
                dgt.quitar(dni, punt);
            } else if (orden == "recuperar") {
                cin >> dni >> punt;
//                dgt.recuperar(dni, punt);
            } else if (orden == "consultar") {
                cin >> dni;
                punt = dgt.consultar(dni);
                cout << "Puntos de " << dni << ": " << punt << '\n';
            } else if (orden == "cuantos_con_puntos") {
                cin >> punt;
                int cuantos = dgt.cuantos_con_puntos(punt);
                cout << "Con " << punt << " puntos hay " << cuantos << '\n';
            } else if (orden == "lista_por_puntos") {
                cin >> punt;
//                auto const& lista = dgt.lista_por_puntos(punt);
//                cout << "Tienen " << punt << " puntos:";
//                for (auto const& dni : lista)
//                    cout << ' ' << dni;
//                cout << '\n';
            } else
                cout << "OPERACION DESCONOCIDA\n";
        } catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "---\n";
    return true;
}
