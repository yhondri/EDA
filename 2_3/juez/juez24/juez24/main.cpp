//
//  main.cpp
//  juez24
//
//  Created by Yhondri  on 16/12/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<vector<int>> &datos, int numFilas, int numColumnas);

bool esSolucionValida(vector<int> numProductosComprados, int i) {
    return (numProductosComprados[i] <  3);
}
/**
 Si ya hemos comprado todos los productos, es una solución.
*/
 bool esSolucion(int k, int numColumnas) {
    return (k == numColumnas);
}

/**
 Guardamos la mejor solución hasta ahora.
 */
void tratarSolucion(vector<int> &mejorSolucion, int &mejorCoste, vector<int> &solucion, int costeActual, int numColumnas) {
    if (costeActual < mejorCoste || mejorCoste == -1) {
        mejorCoste = costeActual;
        for (int i = 0; i < numColumnas; i++) {
            mejorSolucion[i] = solucion[i];
        }
    }
}

/**
 Devuelve true si el coste que llevamos hasta ahora, es mejor que el mejor coste que tenemos.
 */
bool esFactible(int costeActual, int mejorCoste) {
    return (costeActual < mejorCoste || mejorCoste == -1);
}

/**
 
 numProductosComprados: Número productos comprados en cada súpermercado.
 */
void vueltaAtras(vector<vector<int>> &productos, int numFilas, int numColumnas, vector<int> &numProductosComprados,
                 int &k, vector<int> &mejorSolucion, int &mejorCoste, vector<int> &solucion, int &costeActual) {
    for (int i = 0; i < numFilas; i++) {
        if (numProductosComprados[i] < 3) {
            numProductosComprados[i]++; //Sumamos un producto comprado en el súpermercado i.
            solucion[k] = i;
            costeActual += productos[i][k];
            k++;
            
            if (esSolucion(k, numColumnas)) {
                tratarSolucion(mejorSolucion, mejorCoste, solucion, costeActual, numColumnas);
            } else if(esFactible(costeActual, mejorCoste)) {
                vueltaAtras(productos, numFilas, numColumnas, numProductosComprados, k, mejorSolucion, mejorCoste, solucion, costeActual);
            }
            
            k--;
            numProductosComprados[i]--; //Quitamos un producto comprado en el súpermercado i.
            costeActual -= productos[i][k];
            
        }
    }
}

void calcularCosteMinimo(vector<vector<int>> &productos, int numFilas, int numColumnas){
    vector<int> numProductosComprados(numFilas);
    vector<int> mejorSolucion(numColumnas);
    vector<int> solucion(numColumnas);

    int mejorCoste = -1, costeActual = 0, k = 0;

    vueltaAtras(productos, numFilas, numColumnas, numProductosComprados, k, mejorSolucion, mejorCoste, solucion, costeActual);
    
    if (mejorCoste == -1) {
        cout << "Sin solucion factible" << endl;
    } else {
        cout << mejorCoste << endl;
    }
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez24/juez24/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos, numSupermercados, numProductos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numSupermercados >> numProductos;
        
        vector<vector<int>> supermercados(numSupermercados);
        leerDatos(supermercados, numSupermercados, numProductos);
        
        calcularCosteMinimo(supermercados, numSupermercados, numProductos);
        
        numCasos--;
    }
    
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

void leerDatos(vector<vector<int>> &datos, int numFilas, int numColumnas) {
    for(int i = 0; i < numFilas; i++) {
        datos[i] = vector<int>(numColumnas);
    }
    
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            cin >> datos[i][j];
        }
    }
}

