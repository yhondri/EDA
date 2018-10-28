//
//  main.cpp
//  juez4
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
void problema4(vector<int> datos, int numDatos, int alturaTransporte, int &inicioInicioIntervalo, int &finIntervalo);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez4/juez4/casos"); //MacBook Pro;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
//
    int numCasos, numDatos, alturaTransporte;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numDatos >> alturaTransporte;
        
        vector<int> datos;
        leerDatos(datos, numDatos);
        
        int inicioInicioIntervalo, finIntervalo;
        problema4(datos, numDatos, alturaTransporte, inicioInicioIntervalo, finIntervalo);
        
        cout << inicioInicioIntervalo << " " << finIntervalo << endl;
        
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

void problema4(vector<int> datos, int numDatos, int alturaTransporte, int &inicioInicioIntervalo, int &finIntervalo) {
    inicioInicioIntervalo = 0;
    finIntervalo = 0;
    
    int longitudIntervaloActual = 0, inicioIntervaloActual = 0, intervaloMaximaLongitud = -1;
    
    for (int i = 0; i < numDatos; i++) {
        if (datos[i] > alturaTransporte) {
            longitudIntervaloActual++;
            
            if (longitudIntervaloActual == 1) {
                inicioIntervaloActual = i;
            }
        } else {
            if (longitudIntervaloActual > intervaloMaximaLongitud) {
                inicioInicioIntervalo = inicioIntervaloActual;
                finIntervalo = i-1;
                intervaloMaximaLongitud = longitudIntervaloActual;
            }
            
            longitudIntervaloActual = 0;
        }
        
        if (i == numDatos-1 && (longitudIntervaloActual > intervaloMaximaLongitud)) {
            inicioInicioIntervalo = inicioIntervaloActual;
            finIntervalo = i;
            intervaloMaximaLongitud = longitudIntervaloActual;
        }
    }
}
