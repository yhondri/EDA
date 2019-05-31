//
//  main.cpp
//  evc_2f
//
//  Created by Yhondri on 30/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "bintree_eda.h"

using namespace std;

using puntos = int;

int calcularAltSubarbolMayor(bintree<char> const &arbol, int &alturaTotal) {
    if (arbol.empty()) {
        alturaTotal = 0;
        return 0;
    }
    
    int alturaNodoIz, alturaNodoDr, subHijoIz, subHijoDr;
    
    subHijoIz = calcularAltSubarbolMayor(arbol.left(), alturaNodoIz);
    subHijoDr = calcularAltSubarbolMayor(arbol.right(), alturaNodoDr);
    
    alturaTotal = 1 + min(alturaNodoIz, alturaNodoDr);
    
    return max(alturaTotal, max(subHijoIz, subHijoDr));
}

void resuelveCaso() {
    bintree<char> arbol = leerArbol('.');
    int altura;
    cout << calcularAltSubarbolMayor(arbol, altura) << endl;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Downloads/evc_2f/evc_2f/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos;
    cin >> numCasos;
    
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
