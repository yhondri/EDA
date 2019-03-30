//
//  main.cpp
//  juez21
//
//  Created by Yhondri Josué Acosta Novas on 30/03/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

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


    T minElem() const {
        if (this->empty()) throw std::domain_error("El arbol vacio no tiene raiz.");

        T minimoElem = this->raiz->elem;
        minElem(this->raiz, minimoElem);
        return minimoElem;
    }


    private:
    //Recorremos el árbol en postorder y añadimos solo las hojas.
    static void minElem(Link a, T &minimoElem) {
        if (a != nullptr) {
            minElem(a->left, minimoElem);
            minElem(a->right, minimoElem);

            minimoElem = min(minimoElem, a->elem);
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


bool resuelveCaso() {
    char tipoArbol;
    cin >> tipoArbol;

    if (!cin) { // fin de la entrada
        return false;
    }

    if (tipoArbol == 'N') {
        bintree_ext<int> nuevoArbol = leerArbolext(-1);
        if (!nuevoArbol.empty()) {
            cout << nuevoArbol.minElem();
        }
    } else {
        bintree_ext<string> nuevoArbol = leerArbolext(string("#"));
        if (!nuevoArbol.empty()) {
            cout << nuevoArbol.minElem();
        }
    }

    cout << "\n";

    return true;
}


int main(int argc, const char * argv[]) {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez21/juez21/casos");
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
