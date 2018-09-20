//
//  main.cpp
//  Backtraking01
//
//  Created by Yhondri on 9/2/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

bool esValida(int* supermercados, int k);
bool esSolucion(int k, int productos);
int valorDeCesta(int* solucion, int n);
int vueltaAtras(int** productos, int filas, int columnas, int* supermercados, int* solucion, int k, int &minCoste);
void visualizarDatos(int** productos, int filas, int columnas);

int main(int argc, const char * argv[]) {
    
    int numCasos = 0;
    cout << "Introduce numCasos " << endl;
    cin >> numCasos;
    while (numCasos > 0) {
        int filas = 0;
        int columnas = 0;
        cin >> filas;
        cin >> columnas;
        int** productos = new int *[filas];
        for (int i = 0; i < filas; i++) {
            productos[i] = new int[columnas];
        }
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cin >> productos[i][j];
            }
        }
        cout << endl;
        int* supermercados = new int[filas];
        int* solucion = new int[columnas];
        int minCoste = INT_MAX;
        cout << vueltaAtras(productos, filas, columnas, supermercados, solucion, 0, minCoste) << endl;
        numCasos--;
    }
    return 0;
}

int vueltaAtras(int** productos, int filas, int columnas, int* supermercados, int* solucion, int k, int &minCoste) {
    for (int i = 0; i < filas; i++) {
        if (esValida(supermercados, i)) {
            supermercados[i]++;
            solucion[k] = productos[i][k];
            if (esSolucion(k, columnas)) {
                int nuevoCoste = valorDeCesta(solucion, columnas);
                if (nuevoCoste < minCoste) {
                    minCoste = nuevoCoste;
                }
            }else {
                vueltaAtras(productos, filas, columnas, supermercados, solucion, k + 1, minCoste);
            }
            supermercados[i]--;
            solucion[k] -= productos[i][k];
        }
    }
    return minCoste;
}

bool esValida(int* supermercados, int k) {
    return supermercados[k] < 3;
}

bool esSolucion(int k, int productos) {
    return k == productos - 1;
}

int valorDeCesta(int* solucion, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += solucion[i];
    }
    return total;
}

void visualizarDatos(int** productos, int filas, int columnas){
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << productos[i][j] << " ";
        }
        cout << endl;
    }
}
