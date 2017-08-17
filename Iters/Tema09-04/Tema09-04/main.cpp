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
void showInfoAux(Arbin<T> &arbin, int &numNodos, int &numHojas, int &altura);

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
        int numNodos;
        int numHojas;
        int altura;
        showInfoAux(arbol, numNodos, numHojas, altura);
        cout << "Num Nodos " << numNodos << " Num Hojas " << numHojas << " Altura " << altura << endl;
        numCasos--;
    }
    
    return 0;
}

template <class T>
void showInfo(Arbin<T> arbin, int &numNodos, int &numHojas, int &altura) {
//    showInfo(<#Arbin<T> arbin#>, <#int &numNodos#>, <#int &numHojas#>, <#int &altura#>)
}

template <class T>
void showInfoAux(Arbin<T> &arbin, int &numNodos, int &numHojas, int &altura) {
    if (arbin == NULL) {
        numNodos = 0;
        numHojas = 0;
        altura = 0;
    }else if (arbin.hijoIz() == NULL && arbin.hijoIz() == NULL) {
        numNodos += 1;
        numHojas += 1;
        altura += 1;
    }else {
        showInfo(arbin.hijoIz(), numNodos, numHojas, altura);
        int alturaTemp = altura;
        showInfo(arbin.hijoDr(), numNodos += numNodos, numHojas += numHojas, altura);
        if (alturaTemp >= altura) {
            altura = alturaTemp + 1;
        }else {
            altura += + 1;
        }
        numNodos += 1;
    }

}
