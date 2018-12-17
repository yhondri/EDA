//
//  main.cpp
//  juez26
//
//  Created by Yhondri  on 17/12/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numColores);

void tratarSolucion(int numSoluciones) {
    if (numSoluciones > 0) {
        cout << numSoluciones << endl;
    } else {
        cout << "SIN SOLUCION" << endl;
    }
}
/**
 Comprobamos que hemos colocados todas las piezas de la torre,
 esto es que hemos rellenado todos los huecos del array solucion.
 */
bool esSolucion(int k, int n) {
    return (k == (n-1));
}

bool esValida(vector<int> &piezasColocadas, vector<int> &lucesDisponibles,
              vector<int> &solucion, int &k, int &longitudCableDeLuces,
              int consumoActual, int consumoMaximo) {
    
    if (piezasColocadas[solucion[k]] > (lucesDisponibles[solucion[k]]+1)) {
        return false;//Comprobamos si el número de piezas colocadas del color solucion[k], es mayor al número de piezas de ese color disponibles.
    } else if ((k-2 >= 0) && solucion[k-2] == solucion[k-1] == solucion[k]) {
        return false;  // Comprobamos si se han colocado más de 2 piezas iguales seguidas.
    } else if (consumoActual >= consumoMaximo) {
        return false;
    } else {
        return true;
    }
}

void vueltaAtras(vector<int> &piezasColocadas, vector<int> &lucesDisponibles,
                 vector<int> solucion, vector<int> &consumoLucesDisponibles, int consumoActual, int consumoMaximo,
                 int numColores, int k, int longitudCableDeLuces, int &numSoluciones) {
    
    for (int i = 0; i < numColores; i++) { //i = luz seleccionada.
        solucion[k] = i;
        piezasColocadas[i]++;
        consumoActual += consumoLucesDisponibles[i];
        
        if (esValida(piezasColocadas, lucesDisponibles, solucion, k, longitudCableDeLuces, consumoActual, consumoMaximo)) {
            if (esSolucion(k, longitudCableDeLuces)) {
                numSoluciones++;
            } else {
                vueltaAtras(piezasColocadas, lucesDisponibles, solucion,
                            consumoLucesDisponibles, consumoActual, consumoMaximo,
                            numColores, k+1, longitudCableDeLuces, numSoluciones);
            }
        }
        piezasColocadas[i]--;
        consumoActual -= consumoLucesDisponibles[i];
    }
}

void construirLuces(int longitudCableDeLuces, int numColores, int consumoMaximo, vector<int> &consumoLucesDisponibles) {
    vector<int> lucesDisponibles(numColores);
    vector<int> piezasColocadas(numColores);
    vector<int> solucion(longitudCableDeLuces);
    int numSoluciones = 0, consumoActual = 0;

    vueltaAtras(piezasColocadas, lucesDisponibles, solucion,
                consumoLucesDisponibles, consumoActual, consumoMaximo,
                numColores, 0, longitudCableDeLuces, numSoluciones);
    
    tratarSolucion(numSoluciones);
}


int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez26/juez26/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int longitudLineaLuces, numColores, consumoMaximo;
    while (cin >> longitudLineaLuces >> numColores >> consumoMaximo ) {
        vector<int> consumoDeLuces(numColores);
        leerDatos(consumoDeLuces, numColores);
        
        construirLuces(longitudLineaLuces, numColores, consumoMaximo, consumoDeLuces);
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}


void leerDatos(vector<int> &datos, int numColores) {
    for(int i = 0; i < numColores; i++) {
        cin >> datos[i];
    }
}
