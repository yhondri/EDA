//
//  main.cpp
//  juez9
//
//  Created by Yhondri Josué Acosta Novas on 13/03/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//
#include <iostream>
#include <fstream>
#include "queue_eda.h"

using namespace std;

bool resuelveCaso();

template <class T>
class ListaInvertida : public queue<T> {
    using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aqu�
public:
    void invertirLista() {
        Nodo *anterior = nullptr;
        Nodo *actual = this->prim; //Copiamos el primerNodo
        Nodo *siguiente;
        for(int i = 0; i < this->nelems; i++) {
            Nodo *actualTemporal = actual; // Primero guardamos el primer nodo ya que en la siguiente vuelta será el anterior.
            siguiente = actual->sig; //El siguiente nodo, será el siguiente del actual.
            actual->sig = anterior; //El siguiente del actual es nuestro nodo anterior.
            anterior = actualTemporal; //En la siguiente vuelta nuestro anterior, será nuestro nodo actual.
            actual = siguiente; //Por último en la siguiente vuelta, el nodo actual, será el sigiente.

        }
        //Y para terminar solo nos queda hacer el cambio entre el primer y el último nodo. 
        Nodo *temp = this->prim;
        this->prim = this->ult;
        this->ult = temp;
    }

    void mostrarInvertida() {
        Nodo *actual = this->prim;
        while (actual != nullptr) {
            std::cout << actual->elem << " ";
            actual = actual->sig;
        }
    }
};

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez9/juez9/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif


    while (resuelveCaso());



#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

    // leer los datos de la entrada

    if (!std::cin) {  // fin de la entrada
        return false;
    }

    int value;

    while (cin) {
        ListaInvertida<int> values;
        while (cin >> value && value != 0) {
            values.push(value);
        }

        values.invertirLista();
        values.mostrarInvertida();
        std::cout << "\n";
    }
    // escribir sol

    return true;
}
