//
//  main.cpp
//  evc_1f
//
//  Created by Yhondri on 31/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include "queue_eda.h"
#include <fstream>
#include <stdexcept>
#include "Hora.h"

using namespace std;

bool resuelveCaso();

template <class T>
class queueExtendida : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
    
public:
    
    void ordenarCrecienteMente() {
        Nodo *nodo1 = this->prim;
        Nodo *nodo2 = this->prim->sig;
        
        while (nodo1 != nullptr && nodo2 != nullptr) {
            if (nodo2->elem < nodo1->elem) {
                nodo1->sig = nodo2->sig;
                nodo2 = nodo2->sig;
                this->nelems -= 1;
            } else {
                nodo1 = nodo2;
                nodo2 = nodo2->sig;
            }
        }
        
        nodo1->sig = nodo2;
    }
    
};

int main(int argc, const char * argv[]) {
    
    //ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/laboratorios/evc_1f/evc_1f/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    
    return 0;
}


bool resuelveCaso() {
    int numelementos;
    cin >> numelementos;
    
    if (numelementos == 0) {
        return false;
    }
    
    Hora hora;
    queueExtendida<Hora> horas;
    
    for (int i = 0; i < numelementos; i++) {
        cin >> hora;
        horas.push(hora);
    }
    
    horas.ordenarCrecienteMente();
    
    while (!horas.empty()) {
        Hora hora = horas.front();
        horas.pop();
        
        cout << hora << " ";
    }
    
    cout << endl;
    
    return true;
}
