//
//  main.cpp
//  juez_1
//
//  Created by Yhondri Josué Acosta Novas on 25/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

// -----------------
//| Especificación |
// -----------------

//P = {0 < v.Length <= 10000 && forall k:: 0 <= k < v.length ==> -50 <= v[k] <= 60}
//fun picosYValles(v: array<int>) returns(int numPicos, int numValles);
//Q = {numPicos = #i: 1 <= i < v.length-1 : v[i-1] < v[i] && v[i] > v[i+1]}
//{numValles = #i: 1 <= i < v.length-1 : v[i-1] > v[i] && v[i] < v[i+1]}

// -------------
//| Invariante |
// -------------
//1 <= i <= v.length &&
//numPicos = #z: 1 <= z < i : v[z-1] < v[z] && v[z] > v[z+1] &&
//numValles = #z: 1 <= z < i: v[z-1] > v[z] && v[z] < v[z+1]

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
// entero 1 vez para poder calcular el total de picos y valles.

using namespace std;

void picosYValles(vector<int> datos, int n, int &numPicos, int &numValles);

int main(int argc, const char * argv[]) {
    //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez_1/juez_1/casos"); //MacBook Pro;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numCasos;
    cin >> numCasos;
    while (numCasos > 0) {

        int numValues, newValue;
        cin >> numValues;
        vector<int> datos;

        for (int i = 0; i < numValues; i++) {
            cin >> newValue;
            datos.push_back(newValue);
        }

        int numPicos, numValles;
        picosYValles(datos, numValues, numPicos, numValles);
        cout << numPicos << " " << numValles << endl;

        numCasos--;
    }


//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    return 0;
}

void picosYValles(vector<int> datos, int n, int &numPicos, int &numValles) {
    numPicos = 0;
    numValles = 0;

    for (int i = 1; i <= n-2; i++) { //v.length -i COTA: Siempre tiene que ser decreciente.
        if (datos[i-1] > datos[i] && datos[i] < datos[i+1]) {
            numValles++;
        } else if (datos[i-1] < datos[i] && datos[i] > datos[i+1]) {
            numPicos++;
        }
    }
}
