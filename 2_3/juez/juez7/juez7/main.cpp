//
//  main.cpp
//  juez7
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

// -----------------
//| Especificación |
// -----------------

//P = {v.Length >= 0}
//fun resolverCaso(vector<int> datos, int numDatos) : return (v: v<int>);
//Q = {Existe j, z: 1 <= j < z < v.length-1 : v[j] >= 0 && v[z] < 0}

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
// entero 1 vez para poder recolocar todos los elementos positivos y negativos.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
void resolverCaso(vector<int> &datos, int numDatos);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez7/juez7/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos, numDatos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numDatos;
        
        vector<int> datos;
        leerDatos(datos, numDatos);
        
        resolverCaso(datos, numDatos);
        
        numCasos--;
    }
    
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    int nuevoDato;
    for (int i = 0; i < numDatos; i++) {
        cin >> nuevoDato;
        datos.push_back(nuevoDato);
    }
}

void resolverCaso(vector<int> &datos, int numDatos) {
    int j = 0;
    for (int i = 0; i < numDatos; i++) {
        if (datos[i] >= 0) {
            if (i != j) {
                int temp = datos[i];
                datos[i] = datos[j];
                datos[j] = temp;
            }
            j++;
        }
        
//        for (int i = 0; i < numDatos; i++) {
//            cout << datos[i] << " ";
//        }
//
//        cout << endl;
    }
    
    cout << j << endl;
    
//    for (int i = 0; i < numDatos; i++) {
//        cout << datos[i] << " ";
//    }
//    
//    cout << endl;
}
