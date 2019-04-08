//
//  main.cpp
//  juez25
//
//  Created by Yhondri on 07/04/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
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
    
    bool esPrimo(int value) {
        if (value == 1) {
            return false;
        }
        
        int i = 2;
        while (i*i <= value) {
            if (value % i == 0) {
                return false;
            }
            
            i += 1;
        }
        
        return true;
    }
    
    struct AlturaNode {
        AlturaNode(int v, int a) : value(v), altura(a) {};
        int value, altura;
    };
    
    bool calcularBarrera (int &mulTiploDe7, int &altura) {
        if (this->esPrimo(this->raiz->elem)) {
            return false;
        }
        
        std::vector<AlturaNode> alturas;
        bool encontrado = false;
        
        if (!this->empty()) {
            std::queue<Link> pendientes;
            pendientes.push(this->raiz);
            
            while (!pendientes.empty() && !encontrado) {
                Link sig = pendientes.front();
                pendientes.pop();
                if (sig->elem % 7 == 0) {
                    encontrado = true;
                    mulTiploDe7 = sig->elem;
                } else if (sig->left != nullptr && sig->right != nullptr) {
                    altura++;
                    
                    if(!this->esPrimo(sig->left->elem)) {
                        pendientes.push(sig->left);
                        alturas.push_back(AlturaNode(sig->left->elem, altura));
                    }
                    
                    if(!this->esPrimo(sig->right->elem)) {
                        pendientes.push(sig->right);
                        alturas.push_back(AlturaNode(sig->right->elem, altura));
                    }
                }
            }
        }
        
        if (encontrado) {
            for (int i = 0; i < (int)alturas.size(); i++) {
                if (mulTiploDe7 == alturas[i].value) {
                    altura = alturas[i].altura;
                    break;
                }
            }
        }
        
        return encontrado;
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
    
    int multiploDe7 = 0, altura = 1;
    
    if (nuevoArbol.calcularBarrera(multiploDe7, altura)) {
        cout << multiploDe7 << " " << altura << "\n";
    } else {
        cout << "NO HAY" << "\n";
    }
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez25/juez25/casos");
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
