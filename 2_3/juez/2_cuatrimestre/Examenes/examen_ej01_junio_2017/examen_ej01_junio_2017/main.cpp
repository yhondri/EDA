//
//  main.cpp
//  examen_ej01_junio_2017
//
//  Created by Yhondri on 26/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "list_eda.h"
#include <stdexcept>

using namespace std;

template <class T>
class ListaExtendida : public list<T> {
    using Nodo = typename list<T>::Nodo;  // para poder usar Nodo aqu�

public:
    void desplaza(unsigned int pos, unsigned int dist) {
        if (pos < 0 || pos > this->nelems) {
            throw std::out_of_range("Posicion inexistente");
        }
        
        if (dist == 0) {
            return;
        }
        
        int posicionNodoACambiar = pos - dist;
        Nodo *nodoIncial = nullptr;
        Nodo *nodoActual = this->fantasma->sig;
        Nodo *nodoADesplazar = nullptr;
        bool seguir = true;
        
        for (int i = 1; i <= this->nelems && seguir; i++) {
            if(i == posicionNodoACambiar) {
                nodoIncial = nodoActual;
            }
            
            if (pos == i) {
                nodoADesplazar = nodoActual;
            }
            
            nodoActual = nodoActual->sig;
        }
        
        nodoADesplazar->ant->sig = nodoADesplazar->sig;
        if (nodoIncial == nullptr) {
            nodoIncial = this->fantasma->sig;
            this->fantasma->sig = nodoADesplazar;
        } else {
            nodoIncial->ant->sig = nodoADesplazar;
        }
        
        nodoADesplazar->sig = nodoIncial;
        
//        mostrar();
    }
    
    void mostrar() {
        for (auto it = this->cbegin(); it != this->cend(); ++it) {
            cout << (*it) << " ";
        }
        cout << endl;
    }
    
};

bool resuelveCaso() {
    int pos, dist, n;
    std::cin >> pos >> dist >> n;
    
    if (!std::cin) {
        return false;
    }
    
    ListaExtendida<int> listaExtendida;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        listaExtendida.push_back(value);
    }
    
    listaExtendida.desplaza(pos, dist);
    
    for (auto it = listaExtendida.cbegin(); it != listaExtendida.cend(); ++it) {
        cout << (*it) << " ";
    }
    
    cout << endl;
    
    return true;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/Examenes/examen_ej01_junio_2017/examen_ej01_junio_2017/casos");
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
