//
//  main.cpp
//  juez8
//
//  Created by Yhondri Josué Acosta Novas on 09/03/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "queue_eda.h"

using namespace std;

template <class T>
class ListaDuplica : public queue<T> {
    using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aquÌ
public:
    void print(std::ostream & o = std::cout) const {
        if (!this->empty()) {// la lista no est· vacÌa
            Nodo *actualNodo = this->prim;

            for (int i = 0; i < this->nelems; i++) {
                o << actualNodo->elem;
                
                if (actualNodo->sig != nullptr) {
                   o << " ";
                }

                actualNodo = actualNodo->sig;
            }
        }
    }

    // Duplicar los nodos de una lista
    void duplica() {
        int tempNumElem = this->nelems;
        Nodo *actualNodo = this->prim;

        for (int i = 0; i < tempNumElem; i++) {
            if (actualNodo != nullptr) {
                T elem = actualNodo->elem;
                Nodo *nuevo = new Nodo(elem);
                nuevo->sig = actualNodo->sig;
                actualNodo->sig = nuevo;
                actualNodo = nuevo->sig;
            }
        }

        this->nelems *= 2;
    }
};

template <class T>
inline std::ostream& operator<<(std::ostream & o, ListaDuplica<T> const& a) {
    a.print(o);
    return o;
}


bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!cin) return false;
    ListaDuplica<int> lista;
    // creamos la lista
    while (n != 0) {
        lista.push(n);
        std::cin >> n;
    }
    // la duplicamos
    lista.duplica();
    // y la mostramos
    std::cout << lista << '\n';
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez8/juez8/casos"); //MacBookPro
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
//    system("PAUSE");
#endif
    return 0;
}
