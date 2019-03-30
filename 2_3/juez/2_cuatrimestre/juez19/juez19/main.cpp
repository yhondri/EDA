//
//  main.cpp
//  juez19
//
//  Created by Yhondri Josué Acosta Novas on 30/03/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//


//Alumno: Yhondri Josué Acosta Novas

#include <iostream>
#include "bintree_eda.h"
#include <fstream>

using namespace std;

template <class T>
class bintree_ext : public bintree<T> {
    using Link = typename bintree<T>::Link;
    public:
    bintree_ext() : bintree<T>() {}
    bintree_ext(bintree_ext<T> const& l, T const& e, bintree_ext<T> const& r) : bintree<T>(l, e, r) {}

    int nodos() {
        return nodos(this->raiz);
    }

    int hojas() {
        return hojas(this->raiz);
    }

    int altura() {
        return altura(this->raiz);
    }

    private:

    int nodos(Link r) {
        if (r == nullptr) {
            return 0;
        } else {
            return 1 + nodos(r->left) + nodos(r->right);
        }
    }

    int hojas(Link r) {
        if (r == nullptr) {
            return 0;
        } else if(r->left == nullptr && r->right == nullptr) {
            return 1;
        } else {
            return hojas(r->left) + hojas(r->right);
        }
    }

    int altura(Link r) {
        if (r == nullptr) {
            return 0;
        } else {
            return 1 + std::max(altura(r->left), altura(r->right));
        }
    }
};

// lee un árbol binario de la entrada estándar
// Transparencia 10 del tema "Tipos de datos arborescentes"
template <typename T>
bintree_ext<T> leerArbolext(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    } else { // leer recursivamente los hijos
        auto iz = leerArbolext(vacio);
        auto dr = leerArbolext(vacio);
        return {iz, raiz, dr};
    }
}

void resuelveCaso() {
    bintree_ext<char> nuevoArbol = leerArbolext('.');
    cout << nuevoArbol.nodos() << " " << nuevoArbol.hojas() << " " << nuevoArbol.altura() << "\n";
}

int main(int argc, const char * argv[]) {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez19/juez19/casos");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}
