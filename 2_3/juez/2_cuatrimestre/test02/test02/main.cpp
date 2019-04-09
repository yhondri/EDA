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
#include <limits.h>

using namespace std;

int jerarquico(bintree<int> const& arbol, int &minValue) {
    
    if (arbol.empty()) {
        return -1;
    }
    
    if (arbol.left().empty() && arbol.right().empty()) {
        return arbol.root();
    }
    
    int left = jerarquico(arbol.left(), minValue);
    int right = jerarquico(arbol.right(), minValue);
    
    if (left != -1 && right != -1) {
        if (left >= right && arbol.root() >= left && arbol.root() >= right) {
            minValue = min(right, minValue);
            return arbol.root();
        } else {
            return -1;
        }
    } else if(left != -1 && arbol.root() >= left) {
        minValue = min(left, minValue);
        return arbol.root();
    }
    
    return -1;
}

int jerarquico(bintree<int> const& arbol) {
    if (arbol.left().empty() && arbol.right().empty()) {
        return 0;
    }
    
    int minValue = INT_MAX;
    
    int result = jerarquico(arbol, minValue);
    
    if(result > 0) {
        return minValue;
    } else {
        return -1;
    }
}

void resuelveCaso(){
    bintree<int> arbol = leerArbol(-1);
    int hoja = jerarquico(arbol);
    
    if (hoja >= 0) {
        cout << "SI " << arbol.root() - hoja << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
//    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/test02/test02/casos");
    std::ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/test02/test02/casos"); //Mac mini
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
