//
//  main.cpp
//  juez26
//
//  Created by Yhondri on 29/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include "bintree_eda.h"
#include <fstream>

using namespace std;

void esABB(bintree<int> const &arbol, int &elemMayor, int &elemnMenor, bool &esArbolBB) {
    if (arbol.empty()) {
        esArbolBB = true;
    } else {
        bool esABBIz, esABBDr;
        int menorIz, menorDr, mayorIz, mayorDr;
        bintree<int> arbolIz = arbol.left();
        bintree<int> arbolDr = arbol.right();
        
        if (!arbolIz.empty() && !arbolDr.empty()) {
            esABB(arbolIz, mayorIz, menorIz, esABBIz);
            esABB(arbolDr, mayorDr, menorDr, esABBDr);
            
            if (esABBIz && esABBDr && mayorIz < arbol.root() && arbol.root() < menorDr) {
                elemMayor = mayorDr;
                elemnMenor = menorIz;
                esArbolBB = true;
            } else {
                esArbolBB = false;
            }
        } else if (!arbolIz.empty()) {
            esABB(arbolIz, mayorIz, menorIz, esABBIz);
            if (esABBIz && mayorIz < arbol.root()) {
                elemMayor = arbol.root();
                elemnMenor = menorIz;
                esArbolBB = true;
            } else {
                esArbolBB = false;
            }
        } else if (!arbolDr.empty()) {
            esABB(arbolDr, mayorDr, menorDr, esABBDr);
            if (esABBDr && arbol.root() < menorDr) {
                elemMayor = mayorDr;
                elemnMenor = arbol.root();
                esArbolBB = true;
            } else {
                esArbolBB = false;
            }
        } else {
            elemMayor = arbol.root();
            elemnMenor = arbol.root();
            esArbolBB = true;
        }
    }
}

void resuelveCaso() {
    bintree<int> arbol = leerArbol(-1);
    int elemMenor, elemMayor;
    bool result;
    esABB(arbol, elemMayor, elemMenor, result);
    
    if (result) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez26/juez26/casos");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos;
    std::cin >> numCasos;
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
