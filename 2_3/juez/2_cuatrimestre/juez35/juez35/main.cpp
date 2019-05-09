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
#include <list>
#include <utility>

using namespace std;

bool resuelveCaso();

using DNI = string;

class carnet_puntos {
    
private:
    typedef struct {
        int puntos;
        list<DNI>:: iterator itLista;
    }infoConductor;
    
    unordered_map<DNI, infoConductor> conductores;
    
    //Int número de puntos
    //list usuarios con esos puntos.
    unordered_map<int, list<DNI>> usuariosPorPuntos;
    
public:
    void listarConductores() {
        for (auto keyMap : conductores) {
            cout << keyMap.clave << "\n";
        }
    }
    
    void nuevo(string dni) {
        if(conductores.count(dni) > 0) {
            throw std::domain_error("Conductor duplicado");
        }
        
        conductores[dni].puntos = 15;
        
        list<DNI> &lista = usuariosPorPuntos[conductores[dni].puntos]; //Devuelve la lista
        lista.push_front(dni); //Añadimos un nuevo usuario con esos puntos.
        
        conductores[dni].itLista = lista.begin(); //Añadimos la referencia a esa lista.
    }
    
    void quitar(string dni, int puntos) {
        if (conductores.count(dni) == 0) {
            throw std::domain_error("Conductor inexistente");
        }
        
        if(puntos < 0 || puntos > 15) {
            throw std::domain_error("Puntos no validos");
        }
        
        int puntosAntes = conductores[dni].puntos;
        
        if (puntosAntes-puntos < 0) {
            conductores[dni].puntos = 0;
        } else {
            conductores[dni].puntos -= puntos;
        }
        
        //No hace falta volver a introducirlo en la lista si los puntos son los mismos
        if (conductores[dni].puntos != puntosAntes) {
            list<DNI> &listaPuntosAntiguos = usuariosPorPuntos[puntosAntes]; //Devuelve la lista
            listaPuntosAntiguos.erase(conductores[dni].itLista);
            
            list<DNI> &listaPuntosNuevos = usuariosPorPuntos[conductores[dni].puntos]; //Devuelve la lista
            listaPuntosNuevos.push_front(dni); //Añadimos un nuevo usuario con esos puntos.
            conductores[dni].itLista = listaPuntosNuevos.begin(); //Añadimos la referencia a esa lista.
        }
    }
    
    void recuperar(string dni, int puntos) {
        if (conductores.count(dni) == 0) {
            throw std::domain_error("Conductor inexistente");
        }
        
        if(puntos < 0 || puntos > 15) {
            throw std::domain_error("Puntos no validos");
        }
        
        int puntosAntes = conductores[dni].puntos;
        
        if (puntosAntes+puntos > 15) {
            conductores[dni].puntos = 15;
        } else {
            conductores[dni].puntos += puntos;
        }
        
        //No hace falta volver a introducirlo en la lista si los puntos son los mismos
        if (conductores[dni].puntos != puntosAntes) {
            list<DNI> &listaPuntosAntiguos = usuariosPorPuntos[puntosAntes]; //Devuelve la lista
            listaPuntosAntiguos.erase(conductores[dni].itLista);
            
            list<DNI> &listaPuntosNuevos = usuariosPorPuntos[conductores[dni].puntos]; //Devuelve la lista
            listaPuntosNuevos.push_front(dni); //Añadimos un nuevo usuario con esos puntos.
            conductores[dni].itLista = listaPuntosNuevos.begin(); //Añadimos la referencia a esa lista.
        }
    }
    
    int consultar(string dni) {
        if (conductores.count(dni) == 0) {
            throw std::domain_error("Conductor inexistente");
        }
        
        return conductores[dni].puntos;
    }
    
    int cuantos_con_puntos(int puntos) {
        if(puntos < 0 || puntos > 15) {
            throw std::domain_error("Puntos no validos");
        }
        
        return (int)usuariosPorPuntos[puntos].size();
    }
    
    list<DNI> lista_por_puntos(int puntos) {
        if(puntos < 0 || puntos > 15) {
            throw std::domain_error("Puntos no validos");
        }
        
        return usuariosPorPuntos[puntos];
    }
};

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez35/juez35/casos");
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
                dgt.recuperar(dni, punt);
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
                auto const& lista = dgt.lista_por_puntos(punt);
                cout << "Tienen " << punt << " puntos:";
                for (auto const& dni : lista)
                    cout << ' ' << dni;
                cout << '\n';
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





/**

nuevo 123A
nuevo 456B
nuevo 666
cuantos_con_puntos 15
cuantos_con_puntos 0
lista_por_puntos 15
quitar 666 15
lista_por_puntos 0
quitar 456B 9
consultar 456B
quitar 123A 10
recuperar 123A 1
lista_por_puntos 6
recuperar 123A 1
lista_por_puntos 6
lista_por_puntos 7
FIN
nuevo 123A
nuevo 123A
cuantos_con_puntos 20
quitar 456B 2
FIN
nuevo 123A
quitar 123A 2
recuperar 123A 98792
consultar 123A
lista_por_puntos -7
cuantos_con_puntos -9
FIN
*/
