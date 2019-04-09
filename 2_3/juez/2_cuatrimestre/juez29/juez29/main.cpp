//
//  main.cpp
//  juez29
//
//  Created by Yhondri  on 9/4/19.
//  Copyright © 2019 Yhondri . All rights reserved.
//

// Alumno: Yhondri Josué Acosta Novas

#include <iostream>
#include <fstream>
#include "hashmap_eda.h"

using namespace std;

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez29/juez29/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        int numValues;
        cin >> numValues;
        
        unordered_map<int, int> capitulos;
        int numMaxSinRepeticiones = 0, contadorActual = 0;
        
        for (int i = 0; i < numValues; i++) {
            int value;
            cin >> value;
            
            if (capitulos.insert(value)) { //La clave no existe.
                contadorActual++;
            } else {
                numMaxSinRepeticiones = max(numMaxSinRepeticiones, contadorActual);
                contadorActual = 0;
            }
        }
        
        numMaxSinRepeticiones = max(numMaxSinRepeticiones, contadorActual);
        
        cout << numMaxSinRepeticiones << "\n";

        numCasos--;

    }
    
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
