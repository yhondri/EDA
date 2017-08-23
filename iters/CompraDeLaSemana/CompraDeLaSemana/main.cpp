//
//  main.cpp
//  CompraDeLaSemana
//
//  Created by Yhondri on 22/8/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

void showData(int** productos, int filas, int columnas);

int main(int argc, const char * argv[]) {
    
    int numCasos = 0;
    cin >> numCasos;
    
    while (numCasos > 0) {
        
        int numSupermercados, numProductos;
        cin >> numSupermercados;
        cin >> numProductos;
        
        int** productos = new int*[numSupermercados];
        for (int i = 0; i < numSupermercados; i++) {
            productos[i] = new int[numProductos];
        }
        for (int i = 0; i < numSupermercados; i++) {
            for (int j = 0; j < numProductos; j++) {
                cin >> productos[i][j];
            }
        }
        showData(productos, numSupermercados, numProductos);
        numCasos--;
    }
    
    return 0;
}

void showData(int** productos, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << productos[i][j] << " ";
        }
        cout << endl;
    }
}
