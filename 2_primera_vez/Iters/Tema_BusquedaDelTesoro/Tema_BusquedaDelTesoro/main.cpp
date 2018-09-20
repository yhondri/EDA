//
//  main.cpp
//  Tema_BusquedaDelTesoro
//
//  Created by Yhondri on 25/6/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include "Arbin.h"

using namespace std;

Arbin<int> leerArbol() {
    int raiz;
    cin >> raiz;
    if (raiz == -1) {
        return Arbin<int>();
    }else {
        Arbin<int> iz = leerArbol();
        Arbin<int> dr = leerArbol();
        return Arbin<int>(iz, raiz, dr);
    }
}

void ganador(Arbin<int> arbin, int numDragones, int &minDragones, int &mejorCamino) {
    if (arbin.esVacio()) {
        return;
    }
    if (arbin.raiz() > 2) {
        if (minDragones == -1 || numDragones < minDragones) {
            mejorCamino = arbin.raiz();
            minDragones = numDragones;
        }
        
        return;
    }
    if (arbin.raiz() == 1) {
        numDragones += 1;
    }
    
    ganador(arbin.hijoIz(), numDragones, minDragones, mejorCamino);
    ganador(arbin.hijoDr(), numDragones, minDragones, mejorCamino);
}

int main(int argc, const char * argv[]) {
    
    int numCasos;
    cin >> numCasos;
    while (numCasos > 0) {
        Arbin<int> arbin = leerArbol();
        int minDragones = -1;
        int mejorCamino = 0;
        ganador(arbin, 0, minDragones, mejorCamino);
        cout << mejorCamino << endl;
        numCasos--;
    }
    
    return 0;
}
