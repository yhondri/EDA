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

struct ArbinInfo {
    int numNodos = 0;
    int numHojas = 0;
    int altura = 0;
};

template <class T>
void showInfo(Arbin<T> arbin, int &numNodos, int &numHojas, int &altura);
template <class T>
void showInfoAux(const Arbin<T> &arbin, int &numNodos, int &numHojas, int &altura);
template <class T>
ArbinInfo showInfo(const Arbin<T> &arbin);

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
        ArbinInfo arbinInfo = showInfo(arbol);
        cout << "Num Nodos " << arbinInfo.numNodos << " Num Hojas " << arbinInfo.numHojas << " Altura " << arbinInfo.altura << endl;
        numCasos--;
    }
    
    return 0;
}

template <class T>
ArbinInfo showInfo(const Arbin<T> &arbin) {
    if (arbin.esVacio()) {
        return ArbinInfo();
    }
    ArbinInfo arbinInfo;
    arbinInfo.numNodos += 1;
    if (arbin.hijoIz().esVacio() && arbin.hijoDr().esVacio()) {
        arbinInfo.numHojas += 1;
        arbinInfo.altura += 1;
        return arbinInfo;
    }
    
    ArbinInfo arbinInfoIz = showInfo(arbin.hijoIz());
    ArbinInfo arbinInfoDr = showInfo(arbin.hijoDr());
    
    arbinInfo.numNodos += arbinInfoIz.numNodos + arbinInfoDr.numNodos;
    arbinInfo.numHojas += arbinInfoIz.numHojas + arbinInfoDr.numHojas;
    
    if (arbinInfoIz.altura >= arbinInfoDr.altura) {
        arbinInfo.altura = arbinInfoIz.altura + 1;
    }else {
        arbinInfo.altura = arbinInfoDr.altura + 1;
    }
    return arbinInfo;
}

/**
int numNodoesAux(int contadorNodos, Nodo *ra) {
    if (ra == NULL) {
        return 0;
    }else {
        return 1 + numNodoesAux(contadorNodos, ra->_iz) + numNodoesAux(contadorNodos, ra->_dr);
    }
}

int numHojasAux(int hojas, Nodo *ra) {
    if (ra == NULL) {
        return 0;
    }else if (ra->_iz == NULL && ra->_dr == NULL) {
        return 1;
    }else {
        return numHojasAux(hojas, ra->_iz) + numHojasAux(hojas, ra->_dr);
    }
}

int alturaAux(Nodo *ra) {
    if (ra == NULL) {
        return 0;
    }else if (ra->_iz == NULL && ra->_dr == NULL) {
        return 1;
    }else {
        int alturaIz = alturaAux(ra->_iz);
        int alturaDr = alturaAux(ra->_dr);
        if (alturaIz >= alturaDr) {
            return alturaIz + 1;
        }else {
            return alturaDr + 1;
        }
    }
}
*/



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
