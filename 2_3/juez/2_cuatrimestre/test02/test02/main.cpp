//
//  main.cpp
//  test02
//
//  Created by Yhondri on 08/04/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include "bintree_eda.h"
#include <fstream>

using namespace std;

int jerarquico(bintree<int> const& arbol) {
    
    
    return -1;
}

void resuelveCaso(){
    bintree<int> nuevoArbol = leerArbol(-1);

}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/test02/test02/casos");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    return 0;
}
