//
//  main.cpp
//  juez_2
//
//  Created by Yhondri Josué Acosta Novas on 25/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

// -----------------
//| Especificación |
// -----------------

// P = {0 < v.Length <= 100000
// fun colones(v: array<int>, int n) returns(totalColones: bool);
// Q = {colones = #i: 1 <= i < v.length-1 : v[i] < v[i-1] || min < v[i-1]}
// {min = #i: 1 <= i < v.length-1 : min < v[i]}

// -------------
//| Invariante |
// -------------
// 1 <= i <= v.length &&
// colones = #z: 1 <= z < i : v[z] < v[z-1] || min < v[z-1] &&
// min = #i: 1 <= z < i < v.length-1 : min < v[z]

// -------
//| Cota |
// -------
// La cota es v.length - i.
// Siendo B la condición del bucle:
// * Es mayor o igual que cero cuando B se cumple: I && B => 0.
// * Decrece al ejecutarse el bucle.

// -------
//| Coste |
// -------
// El coste del algoritmo es O(n), siendo n el tamaño del array (número de elementos), ya que tenemos que recorrer el array
// entero 1 vez para poder calcular el número total de colones.



#include <iostream>
#include <fstream>
using namespace std;

int colones(int v[], int n);

int main(int argc, const char * argv[]) {
    //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez_2/juez_2/casos"); //MacBook Pro;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numCasos = 0;
    cin >> numCasos;
    while (numCasos > 0){
        int n = 0;
        cin >> n;
        int *v = new int[n];
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        cout << colones(v, n) << endl;

        numCasos--;
    }

//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    return 0;
}

int colones(int v[], int n) {
    int numColones = 0, min = v[n-1];
    for (int i = n-1; i > 0; i--) {
        if (v[i-1] > v[i] || min < v[i-1]) {
            numColones++;


            if (v[i] < min) {
                min = v[i];
            }
        }

    }

    return numColones;
}
