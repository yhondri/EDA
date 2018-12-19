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
    cout << numSoluciones << endl;
}
/**
 Comprobamos que hemos colocados todas las piezas de la torre,
 esto es que hemos rellenado todos los huecos del array solucion.
 */
bool esSolucion(int k, int n) {
    return (k == (n-1));
}

bool esValida(const vector<int> &lucesDisponibles,
              const vector<int> &lucesInstaladas,
              const vector<int> &solucion, int k, int &longitudCableDeLuces,
              int consumoActual, int consumoMaximo) {
    
    int sumaActual = 0;
    for (int i = 0; i < k; i++) {
        if (solucion[i] != solucion[k]) {
            sumaActual++;//Si la pieza es diferente al color actual, la sumamos. 
        }
    }
    
    if (lucesInstaladas[solucion[k]] > (sumaActual+1)) {
        return false;//Comprobamos si el número de piezas colocadas del color solucion[k], es mayor al resto de piezas colocadas.
    } else if ((k-2 >= 0) && (solucion[k-2] == solucion[k-1] && (solucion[k-1] == solucion[k]))) {
        return false;  // Comprobamos si se han colocado más de 2 piezas iguales seguidas.
    } else if (consumoActual > consumoMaximo) {
        return false;
    } else if (k > ((int)solucion.size())-1) {
        return false;
    } else {
        return true;
    }
}

void vueltaAtras(const vector<int> &lucesDisponibles, vector<int> &lucesInstaladas, vector<int> solucion,
                 vector<int> &consumoLucesDisponibles, int consumoActual, int consumoMaximo,
                 int numColores, int &k, int longitudCableDeLuces, int &numSoluciones) {
    
    for (int i = 0; i < numColores; i++) { //i = luz seleccionada.
        solucion[k] = i; //Guarda la solución (palabra distinta) hasta el nivel k.
        lucesInstaladas[i]++; //Guarda cuántas luces he puesto de cada color.
        consumoActual += consumoLucesDisponibles[i];

//        cout << "I: " << i <<  " k: " << k << endl;
        if (esValida(lucesDisponibles, lucesInstaladas, solucion, k, longitudCableDeLuces, consumoActual, consumoMaximo)) {
            if (esSolucion(k, longitudCableDeLuces)) {
//                    cout << "I: " << numSoluciones << " ----- ";
//                    for (int i = 0; i < longitudCableDeLuces; i++) { //i = luz seleccionada.
//                        cout << solucion[i] << " ";
//                    }
//                    cout << endl;
          
                numSoluciones++;
            } else {
                vueltaAtras(lucesDisponibles, lucesInstaladas, solucion,
                            consumoLucesDisponibles, consumoActual, consumoMaximo,
                            numColores, ++k, longitudCableDeLuces, numSoluciones);
                k--;
            }
        }
        
        consumoActual -= consumoLucesDisponibles[i];
        lucesInstaladas[i]--;
    }
}

void construirLuces(int longitudCableDeLuces, int numColores, int consumoMaximo, vector<int> &consumoLucesDisponibles) {
    vector<int> lucesDisponibles(numColores);
    vector<int> lucesInstaladas(numColores);
    vector<int> solucion(longitudCableDeLuces);
    int numSoluciones = 0, consumoActual = 0, k = 0;

    vueltaAtras(lucesDisponibles, lucesInstaladas, solucion,
                consumoLucesDisponibles, consumoActual, consumoMaximo,
                numColores, k, longitudCableDeLuces, numSoluciones);
    
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
