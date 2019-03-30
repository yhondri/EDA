//
//  main.cpp
//  juez20
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

    vector<T> frontera() const {
        vector<T> fronteraVector;
        frontera(this->raiz, fronteraVector);
        return fronteraVector;
    }


    private:
    //Recorremos el árbol en postorder y añadimos solo las hojas. 
    static void frontera(Link a, std::vector<T> & post) {
        if (a != nullptr) {
            frontera(a->left, post);
            frontera(a->right, post);

            if (a->left == nullptr && a->right == nullptr) {
                post.push_back(a->elem);
            }
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
    bintree_ext<int> nuevoArbol = leerArbolext(-1);
    vector<int> frontera = nuevoArbol.frontera();

    for (int i = 0; i < frontera.size(); i++) {
        cout << frontera[i] << " ";
    }

    cout << "\n";
}

int main(int argc, const char * argv[]) {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez20/juez20/casos");
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
