//
//  main.cpp
//  Rec3
//
//  Created by Yhondri on 7/12/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int ingresos(int v[], int n);
int ingresosFinal(int v[], int n, int index, int coste, int acumulador);
int ingresosNoFinal(int v[], int n, int index, int coste);

int main()
{
    int numCasos = 0;
    cin >> numCasos;
    while (numCasos > 0) {
        int n = 0;
        cin >> n;
        int* v = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << ingresos(v, n) << endl;
        numCasos--;
    }
    return 0;
}

int ingresos(int v[], int n) {
    return ingresosNoFinal(v, n, 0, 1);
}

int ingresosFinal(int v[], int n, int index, int coste, int acumulador) {
    if (index == (n/2) - 1){
        return (v[index] * coste) + (v[(n - 1) - index] * coste) + acumulador;
    }
    else {
        int result = (v[index] * coste) + (v[(n - 1) - index] * coste) + acumulador;
        return ingresosFinal(v, n, index + 1, 2 * coste, result);
    }
}

int ingresosNoFinal(int v[], int n, int index, int coste) {
    int resultado = 0;
    
    if (index <  (n / 2) - 1) {
        resultado = ingresosNoFinal(v, n, index + 1, 2 * coste);
    }
    
    return resultado + (v[index] * coste) + (v[(n - 1) - index] * coste);
}
