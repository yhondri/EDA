//
//  main.cpp
//  juez8
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

// -----------------
//| Especificación |
// -----------------

//P = {0 >= v.Length <= 1000 && d > 0}
//fun resolverCaso(vector<int> datos, int numDatos, int numMaxRepeticiones;
//Q = {paraTodo z : 0 <=  z < v.length : v[z-1] < v[z] && (v[z-1] - v[z]) <= 1 && #v[z] < d}

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
// entero 1 vez para poder calcular el número de repeticiones y ver si se cumple la condición que la diferencia entre todos los elementos seguidos es 1 y el orden es creciente. 

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
