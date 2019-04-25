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
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez29/juez29/casos");
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez29/juez29/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        int numValues;
        cin >> numValues;
        
        unordered_map<int, int> capitulos;
        int i, numMaxSinRepeticiones = 0, inicioSegmentoActual = 0;
        for (i = 0; i < numValues; i++) {
            int value;
            cin >> value;
            
            if (capitulos.count(value) == 0 || (capitulos[value] < inicioSegmentoActual)) { //La clave no existe.
                capitulos[value] = i;
            } else {
                numMaxSinRepeticiones = max(numMaxSinRepeticiones, (i-inicioSegmentoActual));
               
                inicioSegmentoActual = capitulos[value] + 1;
                
                capitulos[value] = i;
            }
        }
        
        numMaxSinRepeticiones = max(numMaxSinRepeticiones, (i-inicioSegmentoActual));

        cout << numMaxSinRepeticiones << "\n";

        numCasos--;

    }
    
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
