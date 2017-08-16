//
//  main.cpp
//  Tema09-04
//
//  Created by Yhondri  on 16/8/17.
//  Copyright © 2017 Yhondri . All rights reserved.
//

#include <iostream>
#include "Arbin.h"

using namespace std;

template <class T>
Arbin<T> leerArbol(const T& repVacio){
    T elem;
    cin >> elem;
    if (elem == repVacio)
        return Arbin<T>();
    else{
        Arbin<T> hi = leerArbol(repVacio);
        Arbin<T> hd = leerArbol(repVacio);
        return Arbin<T>(hi,elem,hd);
    }
}

int main(int argc, const char * argv[]) {

    int numCasos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        Arbin<char> arbol = leerArbol('.');
        cout << "Num Nodos " << arbol.numNodos() << " Num Hojas " << arbol.numHojas() << " Altura " << arbol.altura() << endl;
        numCasos--;
    }
    
    return 0;
}
