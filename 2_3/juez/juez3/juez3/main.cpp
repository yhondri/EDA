//
//  main.cpp
//  juez3
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

// -----------------
//| Especificación |
// -----------------
//

//P = {v != null && 0 <= p < v.Length}
//problema3 (a : array<int>, p : int) returns (b : bool);
//Q = {b == forall u, w :: 0 <= u <= p < w < a.Length ==> a[u] < a[w]}

// -------------
//| Invariante |
// -------------
//1 <= i <= v.length &&
// b == forall u, w :: 0 <= u <= p < w < a.Length ==> v[u] < a[w] &&
//maximoDeU = Existe z: 1 <= z < p < i: v[z-1] < v[z]

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
// entero en el caso peor al menos 1 vez para poder ver si todos los elementos del array a partir de la posición p  son mayores que todos los anteriores a la posición p.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
bool problema3(vector<int> datos, int p);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez3/juez3/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numCasos, numDatos, p;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numDatos >> p;
        
        vector<int> datos;
        leerDatos(datos, numDatos);
        
        if (problema3(datos, p)) {
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }
        
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

bool problema3(vector<int> datos, int p) {
    bool seguir = true;
    int maximoDeU = datos[0];
    
    for (int i = 0; i < datos.size() && seguir; i++) {
        if (i <= p && maximoDeU < datos[i]) {
            maximoDeU = datos[i];
        } else if (i > p && maximoDeU >= datos[i]) {
            seguir = false;
        }
    }
    
    return seguir;
}
