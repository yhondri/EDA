//
//  main.cpp
//  VA06
//
//  Created by Yhondri on 12/1/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

void calcularMejorCoste(int** products, int* productosCompradosEnSuper, int* solucion, int rows, int columns, int k, int& mejorcoste);
bool esValida(int* productosCompradosEnSuper, int i);
bool esSolucion(int k, int nSupermercados);
int calcularCoste(int** products, int* solucion, int rows, int columns);
void fillArray(int** products, int rows, int columns);
void output(int** products, int rows, int columns);

int main(int argc, const char * argv[]) {
    int numberOfCases = 0;
    cout <<"Introduce nº casos"<< endl;
    cin >> numberOfCases;
    int i = 0;
    while (i < numberOfCases) {
        int rows = 0;
        int columns = 0;
        cout <<"Introduce filas"<< endl;
        cin >> rows;
        cout <<"Introduce columnas"<< endl;
        cin >> columns;
        int** products = new int*[rows];
        int solution[columns];
        int productosCompradosEnSuper[rows];
        for(int i = 0; i < rows; ++i){
            products[i] = new int[columns];
        }
        int mejorcoste = INT_MAX;
        fillArray(products, rows, columns);
//        output((int **)products, rows, columns);
        calcularMejorCoste(products, productosCompradosEnSuper, solution, rows, columns, 0, mejorcoste);
        cout << endl;
        cout << "Mejor coste: " << mejorcoste << endl;
        i++;
    }
    return 0;
}

/**
 - Products = LLeva todos los productos en los diferentes súpermercados. 
 - Solución: LLeva la solución que se está evaluando. 
 - Rows: Número de súpermercados. 
 - Columns: Número de productos.
 */
void calcularMejorCoste(int** products, int* productosCompradosEnSuper, int* solucion, int rows, int columns, int k, int& mejorcoste){
    for (int i = 0; i < rows; i++) {
        if (esValida(productosCompradosEnSuper, i)) {
            
        }
        
        
//        solucion[k] = i;
//        
//        for (int index = k+1; index < columns; index++) {
//            solucion[index] = 0;
//        }
//        
//        if (esValida(solucion, columns, k)) {
//            if (esSolucion(k, rows)) {
//                int costeSolucion = calcularCoste(products, solucion, rows, columns);
//                if (costeSolucion < mejorcoste) {
//                    mejorcoste = costeSolucion;
//                }
//            }else {
//                calcularMejorCoste(products, productosCompradosEnSuper, solucion, rows, columns, k+1, mejorcoste);
//            }
//        }
    }
}

/**
 - Mira si hay más de 3 compras en el mismo súpermercado.
 */
bool esValida(int* productosCompradosEnSuper, int i) {
    return !(productosCompradosEnSuper[i] > 3);
}

bool esSolucion(int k, int nSupermercados) {
    return k == nSupermercados - 1;
}

int calcularCoste(int** products, int* solucion, int rows, int columns) {
    int coste = 0;
    for (int i = 0; i < columns; i++) {
        cout << products[solucion[i]][i] << " + ";
        coste += products[solucion[i]][i];
    }
    cout << endl;
    return coste;
}

void fillArray(int** products, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> products[i][j];
        }
    }
}

void output(int** products, int rows, int columns) {
    cout <<"Array cargado: "<< endl;
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << products[i][j] << " ";
        }
        cout << endl;
    }
}
