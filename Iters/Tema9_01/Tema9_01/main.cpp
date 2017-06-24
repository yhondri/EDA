//
//  main.cpp
//  Tema9_01
//
//  Created by Yhondri on 24/6/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include "Arbin.h"

using namespace std;

Arbin<char> leerArbol();

int main() {
    int numCasos = 0;
    cin >> numCasos;
    while (numCasos > 0) {
        Arbin<char>arbin = leerArbol();
        cout << arbin.numNodos() << " " << arbin.numHojas() << " " << arbin.altura() << endl;
        numCasos--;
    }
    
    return 0;
}

Arbin<char> leerArbol() {
    char raiz;
    cin >> raiz;
    if (raiz == '.'){
        return Arbin<char>();
    }
    else {
        Arbin<char> izquierdo = leerArbol();
        Arbin<char> derecho = leerArbol();
        return Arbin<char>(izquierdo, raiz, derecho);
    }
}
