//
//  main.cpp
//  juez22
//
//  Created by Yhondri Josué Acosta Novas on 30/03/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

//Alumno: Acosta Novas Yhondri Josué

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


    int diametro() const {
        int height = 0;
        return diameter(this->raiz, height);
    }


    private:
    int diameter(Link root, int &height) const {
        if (root == nullptr) {
            height = 0;
            return 0;
        }

        int leftHeight = 0, rightHeight = 0;
        int leftDiameter = 0, righDiameter = 0;

        leftDiameter = diameter(root->left, leftHeight);
        righDiameter = diameter(root->right, rightHeight);

        height = max(leftHeight, rightHeight) + 1;

        return max(leftHeight + rightHeight + 1, max(leftDiameter, righDiameter));

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

void resuelveCaso(){
    bintree_ext<char> nuevoArbol = leerArbolext('.');
    cout << nuevoArbol.diametro() << endl;
}


int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez22/juez22/casos");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
    resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    return 0;
}
