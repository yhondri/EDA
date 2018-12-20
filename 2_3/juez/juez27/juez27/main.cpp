//
//  main.cpp
//  juez27
//
//  Created by Yhondri  on 20/12/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <limits.h>

using namespace std;

int leerDatos(vector<vector<int>> &datos, int numFilas, int numColumnas);

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
bool esFactible(int costeActual, int mejorCoste, int n, int k, int costeMinimo) {
    int costeEstimado = costeActual + ((n - k + 1) * costeMinimo);
    return (costeEstimado < mejorCoste || mejorCoste == -1);
}

bool esValida(vector<int> numTrabajosPorFuncionario, int i) {
    return (numTrabajosPorFuncionario[i] <= 1);
}


void vueltaAtras(const vector<vector<int>> &funcionario, int numFilas, int numColumnas, vector<int> &numTrabajosPorFuncionario,
                 const int costeMinimo, int &k, vector<int> &mejorSolucion,
                 int &mejorCoste, vector<int> &solucion, int &costeActual) {
    for (int i = 0; i < numFilas; i++) {
        numTrabajosPorFuncionario[i]++; //Sumamos un trabajo al funcionario i.
        if (esValida(numTrabajosPorFuncionario, i)) {
            solucion[k] = i;
            costeActual += funcionario[i][k];
            k++;
            
            if (esSolucion(k, numColumnas)) {
                tratarSolucion(mejorSolucion, mejorCoste, solucion, costeActual, numColumnas);
            } else if(esFactible(costeActual, mejorCoste, numFilas, k, costeMinimo)) {
                vueltaAtras(funcionario, numFilas, numColumnas, numTrabajosPorFuncionario, costeMinimo, k, mejorSolucion, mejorCoste, solucion, costeActual);
            }
            
            k--;
            costeActual -= funcionario[i][k];
        }
        
        numTrabajosPorFuncionario[i]--; //Quitamos un producto comprado en el súpermercado i.
    }
}

void calcularCosteMinimo(vector<vector<int>> &productos, int numFilas, int numColumnas, int costeMinimo) {
    vector<int> numProductosComprados(numFilas);
    vector<int> mejorSolucion(numColumnas);
    vector<int> solucion(numColumnas);
    
    int mejorCoste = -1, costeActual = 0, k = 0;
    
    vueltaAtras(productos, numFilas, numColumnas, numProductosComprados, costeMinimo, k, mejorSolucion, mejorCoste, solucion, costeActual);
    
        cout << mejorCoste << endl;
    
//    cout << mejorCoste << ": ";
//    for (int i = 0; i < numFilas; i++) {
//        cout << mejorSolucion[i] << " ";
//    }
//
//    cout << endl;
    
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez27/juez27/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numFuncionarios;
    while (cin >> numFuncionarios && numFuncionarios > 0) {
        vector<vector<int>> funcionarios(numFuncionarios);
        int costeMinimo = leerDatos(funcionarios, numFuncionarios, numFuncionarios);
        calcularCosteMinimo(funcionarios, numFuncionarios, numFuncionarios, costeMinimo);
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

int leerDatos(vector<vector<int>> &datos, int numFilas, int numColumnas) {
    for(int i = 0; i < numFilas; i++) {
        datos[i] = vector<int>(numColumnas);
    }
    
    int costeMinimo = INT_MAX;
    
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            cin >> datos[i][j];
            
            if(costeMinimo > datos[i][j]) {
                costeMinimo = datos[i][j];
            }
        }
    }
    
    return costeMinimo;
}

