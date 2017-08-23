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
   /** 1
    6 10
    1820 510 370 1000 460 324 505 640 2030 409 2000 430 450 1110 606 290 530 670 2104 501 1760 502 395 1200 550 199 525 702 1830 550 2130 640 560 1307 735 450 600 720 2150 575 1143 455 505 1140 500 400 350 550 2030 399 1200 475 403 1002 560 350 502 640 2009 460*/
}
