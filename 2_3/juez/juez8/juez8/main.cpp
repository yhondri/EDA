//
//  main.cpp
//  juez8
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
void leerDatos(vector<int> &datos, int numDatos);
void resolverCaso(vector<int> datos, int numDatos, int numMaxRepeticiones);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez8/juez8/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    
    int numCasos, numMaxRepeticiones, numDatos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numMaxRepeticiones >> numDatos;
        
        vector<int> datos;
        leerDatos(datos, numDatos);
        
        resolverCaso(datos, numDatos, numMaxRepeticiones);
        
        numCasos--;
    }
    
    
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    
    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    int nuevoDato;
    for (int i = 0; i < numDatos; i++) {
        cin >> nuevoDato;
        datos.push_back(nuevoDato);
    }
}

void resolverCaso(vector<int> datos, int numDatos, int numMaxRepeticiones) {
    bool esCrecientePorLosPelos = true, esDivertido = true;
    int repeticionesNumActual = 0;
    
    for (int i = 0; i < numDatos && esCrecientePorLosPelos && esDivertido; i++) {
        
        if (i < numDatos-1) {
            int diferencia = abs(datos[i] - datos[i+1]);
            if (datos[i] > datos[i+1] || diferencia > 1) {
                esCrecientePorLosPelos = false;
            }
        }
  
        if (datos[i] == datos[i-1]) {
            repeticionesNumActual++;
            
            if (repeticionesNumActual > numMaxRepeticiones) {
                esDivertido = false;
            }
        } else {
            repeticionesNumActual = 1;
        }
    }
    
    if (esCrecientePorLosPelos && esDivertido) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }
}
