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
void hacerCompra(int** productos, int filas, int columnas, int* productosCompradosPorSupermercado, int nivel, int* solucion, int &mejorSolucion);
int hacerCompra(int** productos, int filas, int columnas);
bool esValida(int* productosCompradosPorSupermercado, int supermercado);
bool esSolucion(int producto, int columnas);
int cestaActual(int* solucion, int n);

int main(int argc, const char * argv[]) {
    
    int numCasos = 0;
    cin >> numCasos;
    
    while (numCasos > 0) {
        
        int filas, columnas;
        cin >> filas;
        cin >> columnas;
        
        int** productos = new int*[filas];
        for (int i = 0; i < filas; i++) {
            productos[i] = new int[columnas];
        }
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cin >> productos[i][j];
            }
        }
        //        showData(productos, filas, columnas);
        int mejorSolucion = hacerCompra(productos, filas, columnas);
        cout << "Total: " << mejorSolucion << endl;
        numCasos--;
    }
    
    return 0;
}

int hacerCompra(int** productos, int filas, int columnas) {
    int solucionActual = INT_MAX;
    
     hacerCompra(productos, filas, columnas, new int[filas], 0, new int[columnas], solucionActual);
    return 0;
}

void hacerCompra(int** productos, int filas, int columnas, int* productosCompradosPorSupermercado, int nivel, int* solucion, int &mejorSolucion) {
    for (int i = 0; i < filas; i++) {
        if (esValida(productosCompradosPorSupermercado, i)) {
            productosCompradosPorSupermercado[i]++;
            solucion[nivel] = productos[i][nivel];
            if (esSolucion(nivel, columnas)) {
                int solucionActual = cestaActual(solucion, columnas);
                if (solucionActual < mejorSolucion) {
                    mejorSolucion = solucionActual;
                }
            }else {
                hacerCompra(productos, filas, columnas, productosCompradosPorSupermercado, (nivel + 1), solucion, mejorSolucion);
            }
            productosCompradosPorSupermercado[i]--;
            solucion[nivel] -= productos[i][nivel];
        }
    }
    cout << mejorSolucion << endl;
}

bool esValida(int* productosCompradosPorSupermercado, int supermercado) {
    return productosCompradosPorSupermercado[supermercado] < 3;
}

bool esSolucion(int producto, int columnas) {
    return producto == (columnas - 1);
}

int cestaActual(int* solucion, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += solucion[i];
    }
    return total;
}

void showData(int** productos, int filas, int columnas) {
    cout << endl << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << productos[i][j] << " ";
        }
        cout << endl;
    }
    /**
     
     1
     6 10
     1820 510 370 1000 460 324 505 640 2030 409
     2000 430 450 1110 606 290 530 670 2104 501
     1760 502 395 1200 550 199 525 702 1830 550
     2130 640 560 1307 735 450 600 720 2150 575
     1143 455 505 1140 500 400 350 550 2030 399
     1200 475 403 1002 560 350 502 640 2009 460
     
     */
}

