//
//  main.cpp
//  Tema09-04
//
//  Created by Yhondri  on 16/8/17.
//  Copyright © 2017 Yhondri . All rights reserved.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int altura(int nivel){
    cout << setw((nivel * 3) + 20) << right << "--- Nivel: " << nivel << "---" << '\n';
    int numHijos;
    cin >> numHijos;
    if (numHijos == 0){
        cout << setw((nivel * 3) + 20) << right << "  numHijos es: " << numHijos << '\n';
        return 1;
    }
    else{
        int maxLocal = 0;
        for (int i = 0; i < numHijos; i++){
            cout << setw((nivel * 3) + 20) << right << "  numHijos es: " << numHijos << '\n';
            int altLocal = altura(nivel + 1);
            cout << setw((nivel * 3) + 20) << right << "  altLocal es: " << altLocal << '\n';
            maxLocal = max(altLocal, maxLocal);
            cout << setw((nivel * 3) + 20) << right << "  maxLocal es: " << maxLocal << '\n';
        }
        cout << setw((nivel * 3) + 20) << right << "  y devuelvo: " << maxLocal + 1 << '\n';
        return maxLocal + 1;
    }
}

void resuelveCaso(){
    cout << altura(0) << endl;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez17/juez17/casos");
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
