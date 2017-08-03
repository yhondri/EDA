//
//  main.cpp
//  ExamenJunio2017
//
//  Created by Yhondri  on 3/8/17.
//  Copyright © 2017 Yhondri . All rights reserved.
//

#include <iostream>
using namespace std;

void fillArray(int* array, int n);
void showArrayData(int* array, int n);
void eliminarValores(int* v, int* w, int n, int m);

int main(int argc, const char * argv[]) {
    int n;
    int m;
    
    cout << "Introudce el tamaño de los arrays" << endl;
    cin >> n;
    cin >> m;
    
    int* v = new int[n];
    int* w = new int[m];
    
    cout << "Introudce los valores de V" << endl;
    fillArray(v, n);
    cout << "Introduce los valores de W" << endl;
    fillArray(w, m);
    //    showArrayData(w, m);
    cout << endl;
    cout << endl;
    eliminarValores(v, w, n, m);
    
    return 0;
}

void eliminarValores(int* v, int* w, int n, int m) {
    int newSize = n;
    bool moverALaIzquierda = false;
    for (int i = 0, j = 0; i < n && j < m; i++) {
        if (v[i] == w[j]) {
            moverALaIzquierda = true;
            newSize--;
        }
        if (moverALaIzquierda && i+1 < n) {
            v[i] = v[i+1];
        }
        if (v[i] > w[j] && j+1 < m) {
            
            //            cout << "V[i] " << v[i] << " W[j] " << w[j] << " " << (v[i] > w[m] && j+1 < m) << " value ";
            j++;
        }
    }
    cout << "Nuevos valores new size: " << newSize << endl;
    showArrayData(v, newSize);
}

void fillArray(int* array, int n) {
    int i = 0;
    while(i < n) {
        cin >> array[i];
        i++;
    }
}

void showArrayData(int* array, int n) {
    int i = 0;
    while(i < n) {
        cout << array[i] << " ";
        i++;
    }
    cout << endl;
}
