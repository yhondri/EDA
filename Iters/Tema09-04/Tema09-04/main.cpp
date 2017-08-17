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
void showInfo(Arbin<T> arbin, int &numNodos, int &numHojas, int &altura);
template <class T>
void showInfoAux(const Arbin<T> &arbin, int &numNodos, int &numHojas, int &altura);

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
        int numNodos = 0;
        int numHojas = 0;
        int altura = 0;
        showInfoAux(arbol, numNodos, numHojas, altura);
        cout << "Num Nodos " << numNodos << " Num Hojas " << numHojas << " Altura " << altura << endl;
        numCasos--;
    }
    
    return 0;
}

template <class T>
void showInfoAux(const Arbin<T> &arbin, int &numNodos, int &numHojas, int &altura) {
    if (arbin.esVacio()) {
        return;
    }
    
    numNodos += 1;
    if (arbin.hijoIz().esVacio() && arbin.hijoDr().esVacio()) {
        numHojas += 1;
        altura += 1;
        return;
    }
    
    int alturaIz = 0, alturaDr = 0;
    showInfoAux(arbin.hijoIz(), numNodos, numHojas, alturaIz);
    showInfoAux(arbin.hijoDr(), numNodos, numHojas, alturaDr);
    
    if (alturaIz > alturaDr) {
        altura = alturaIz + 1;
    }
    else {
        altura = alturaDr + 1;
    }
}
