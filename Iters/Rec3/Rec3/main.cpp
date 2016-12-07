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
int ingresos(int v[], int n, int i, int p);

int main(int argc, const char * argv[]) {
    int numCasos = 0;
//    cout << "Introduce número de casos" << endl;
    cin >> numCasos;
    int i = 0;
    
    while (i < numCasos) {
//        cout << "Introduce tamaño del array" << endl;
        int n;
        cin >> n;
        int v[n];
        
//        cout << "Introduce valores del array" << endl;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << ingresos(v, n) << endl;
        i++;
    }
    return 0;
}


int ingresos(int v[], int n) {
    return ingresos(v, n, 0, 1);
}

int ingresos(int v[], int n, int i, int p){
    int suma = 0;

    if (i <= (n/2) - 1) {
        suma = v[i]*p + v[(n-1)-i]*p + ingresos(v, n, i+1, 2*p);
    }
    
    
    return suma;
}
