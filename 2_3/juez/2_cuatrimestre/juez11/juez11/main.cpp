//
//  main.cpp
//  juez11
//
//  Created by Yhondri Josué Acosta Novas on 16/03/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "queue_eda.h"

using namespace std;

void resuelveCaso();

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

    void insert(ArrayQueue<T> &lista) {
        Nodo *nodoActualListaPrincipal = this->prim;
        Nodo *nodoAnterior = nullptr;
        Nodo *nodoAInsertar = lista.prim;

        int posListaAInsertar = 0;

        while (nodoActualListaPrincipal != nullptr && nodoAInsertar != nullptr) {
            if (nodoActualListaPrincipal->elem > nodoAInsertar->elem) {
                Nodo *aux; // Guardo el 3.
                Nodo *aux2;

                if (nodoAnterior == nullptr) {
                    aux = nodoActualListaPrincipal; // Guardo el 3.
                    aux2 = nodoAInsertar->sig;

                    this->prim = nodoAInsertar;
                    this->prim->sig = aux;

                    nodoAnterior = nodoAInsertar;
                    nodoAInsertar = aux2;
                } else {
                    aux = nodoActualListaPrincipal; // Guardo el 3.
                    aux2 = nodoAInsertar->sig;

                    nodoAnterior->sig = nodoAInsertar; //Asigno el nodo a insertar.
                    nodoAnterior->sig->sig = aux;

                    nodoAnterior = nodoAInsertar;
                    nodoAInsertar = aux2;
                    nodoActualListaPrincipal = aux;
                }

                posListaAInsertar++;
            } else if (nodoActualListaPrincipal->elem == nodoAInsertar->elem) {
                Nodo *aux = nodoActualListaPrincipal->sig; // Guardo el 3.
                Nodo *aux2 = nodoAInsertar->sig;

                nodoAnterior = nodoAInsertar;

                nodoActualListaPrincipal->sig = nodoAInsertar;
                nodoActualListaPrincipal->sig->sig = aux;

                nodoAInsertar = aux2; //En la siguiente siguienteVuelta

                posListaAInsertar++;
            } else {
                nodoAnterior = nodoActualListaPrincipal;
                nodoActualListaPrincipal = nodoActualListaPrincipal->sig;
            }
        }

        if (posListaAInsertar < lista.size()) {
            if (nodoAnterior == nullptr) {
                this->prim = nodoAInsertar;
            } else {
                nodoAnterior->sig = nodoAInsertar;
            }
        }

        lista.prim = nullptr;
        this->nelems += lista.size();
        //        while (posActual <= this->nelems && posListaAInsertar <= lista.nelems) {
        //            if(nodoAInsertar->elem < nodoListaPrincipal->elem) {
        //                Nodo *nodoAux = nodoAnterior->sig;
        //                nodoAnterior->sig = nodoAInsertar;
        //                nodoAInsertar = nodoAInsertar->sig;
        //                nodoAnterior->sig->sig = nodoAux;
        //
        //                posListaAInsertar++;
        //            }
        //
        //            nodoAnterior = nodoListaPrincipal;
        //            nodoListaPrincipal = nodoListaPrincipal->sig;
        //
        //            posActual++;
        //        }
    }

    void print() {
        if (this->empty()) {
            return;
        }
        Nodo *actual = this->prim;
        while (actual != nullptr) {
            std::cout << actual->elem << " ";
            actual = actual->sig;
        }
        //        for (int i = 0; i < this->nelems; i++) {
        //            std::cout << actual->elem << " ";
        //            actual = actual->sig;
        //        }
    }
};

void leerDatos(ArrayQueue<int> &datos);


int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez11/juez11/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    while (numCasos > 0) {
        resuelveCaso();
        numCasos--;
    }

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    ArrayQueue<int> listaPrincipal;
    leerDatos(listaPrincipal);

    ArrayQueue<int> listaAInsertar;
    leerDatos(listaAInsertar);

    listaPrincipal.insert(listaAInsertar);
    listaPrincipal.print();
    //    cout << "\n";
    //    listaAInsertar.print();
    cout << "\n";
}

void leerDatos(ArrayQueue<int> &datos) {
    int value;
    while (cin >> value && value != 0) {
        datos.push(value);
    }
}
