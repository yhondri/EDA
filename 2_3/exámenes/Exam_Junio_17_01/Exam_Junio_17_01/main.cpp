//
//  main.cpp
//  Exam_Junio_17_01
//
//  Created by Yhondri on 30/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include "list_eda.h"
#include <stdexcept>
#include <fstream>

using namespace std;

template <class T>
class listExtendida : public list<T> {
protected:
    using Nodo = typename list<T>::Nodo;
    
public:
    void desplaza(unsigned int pos, unsigned int dist) {
        if (pos < 0 || pos >= this->nelems) {
            throw domain_error("Posicion inexistente");
        }
        
        if (pos == dist) {
            return;
        }
        
        Nodo *nodoInicial = this->fantasma->sig;
        Nodo *nodoADesplazar = this->fantasma->sig;
        int posicionADesplazar = pos - dist;
        int contador = 1;
        
        while (contador <= pos) {
            if (posicionADesplazar == contador) {
                nodoInicial = nodoADesplazar;
            } else {
                nodoADesplazar = nodoADesplazar->sig;
            }
            contador++;
        }

        nodoADesplazar->ant->sig = nodoADesplazar->sig;
        Nodo *anteriorPrimero = nodoInicial->ant;
        anteriorPrimero->sig = nodoADesplazar;
        nodoADesplazar->sig = nodoInicial;
    }
    
};

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/exámenes/Exam_Junio_17_01/Exam_Junio_17_01/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    listExtendida<int> lista;
    int numElem, pos, dist;
    cin >> numElem >> pos >> dist;
    
    for (int i = 0; i < numElem; i++) {
        int value;
        cin >> value;
        lista.push_back(value);
    }
    
    lista.desplaza(pos, dist);
    
    for (auto value : lista) {
        cout << value << " ";
    }
    
    cout << endl;
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
