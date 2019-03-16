//
//  main.cpp
//  juez10
//
//  Created by Yhondri Josué Acosta Novas on 14/03/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "queue_eda.h"

using namespace std;

bool resuelveCaso();

template <class T>
class ArrayQueue : public queue<T> {
    using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aqu�
public:
    // Duplicar los nodos de una lista
    void insert(ArrayQueue<T> &lista,int posicion) {
        if (lista.empty()) {
            return;
        }

        int inicioPos = 0;
        Nodo *inicio;
        if (posicion == 0) {
            Nodo *aux = this->prim;
            this->prim = lista.prim;
            lista.ult->sig = aux;
        } else if (posicion == this->nelems) {
            this->ult->sig = lista.prim;
        } else {
             inicio = this->prim;
            for (int i = 0; i < posicion-1; i++) {
                inicio = inicio->sig;

                inicioPos++;
            }

            Nodo *aux = inicio->sig;
            inicio->sig = lista.prim;
            lista.ult->sig = aux;
        }


        this->nelems += lista.nelems;
        lista.prim = nullptr;
        lista.nelems = 0;
    }

    void print() {
        if (this->empty()) {
            return;
        }
        Nodo *actual = this->prim;
        for (int i = 0; i < this->nelems; i++) {
            std::cout << actual->elem << " ";
            actual = actual->sig;
        }
    }
};

void leerDatos(ArrayQueue<int> &datos, int numDatos);


int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez10/juez10/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int numDatosListaPrincipal;
    cin >> numDatosListaPrincipal;
    // leer los datos de la entrada
    if (!cin) {  // fin de la entrada
        return false;
    }

    ArrayQueue<int> listaPrincipal;
    leerDatos(listaPrincipal, numDatosListaPrincipal);

    int numElementosAInsertar, posicionAPartirDeLaCualInsertar;
    cin >> numElementosAInsertar >> posicionAPartirDeLaCualInsertar;

    ArrayQueue<int> listaAInsertar;
    leerDatos(listaAInsertar, numElementosAInsertar);

    listaPrincipal.insert(listaAInsertar, posicionAPartirDeLaCualInsertar);
    listaPrincipal.print();

    cout << "\n";

    return true;
}

void leerDatos(ArrayQueue<int> &datos, int numDatos) {
    int value;
    for (int i = 0; i < numDatos; i++) {
        cin >> value;
        datos.push(value);
    }
}
