//
//  main.cpp
//  juez4
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

// -----------------
//| Especificación |
// -----------------

//P = {0 < v.Length}
//fun problema4(vector<int> datos, int numDatos, int alturaTransporte) : (inicioIntervalo: Int, finIntervalo: Int);
//Q = {numPicos = #i: 1 <= i < v.length-1 : v[i-1] < v[i] && v[i] > v[i+1]}
//{numValles = #i: 1 <= i < v.length-1 : v[i-1] > v[i] && v[i] < v[i+1]}

// -------------
//| Invariante |
// -------------
// 1 <= i <= v.length &&
// {Existe w, q = w <= q <= i < v.length-1 : v[w] >= alturaTransporte && v[q] >= alturaTransporte} &&
// intervaloMaximaLongitud = #max: (w - q)

// -------
//| Cota |
// -------
//La cota es v.length - i.
//Siendo B la condición del bucle:
// * Es mayor o igual que cero cuando B se cumple: I && B => 0.
// * Decrece al ejecutarse el bucle.

// -------
//| Coste |
// -------
// El coste del algoritmo es O(n), siendo n el tamaño del array (número de elementos), ya que tenemos que recorrer el array
// entero 1 vez para poder calcular el intervalo mayor que cumpla la condición.

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
