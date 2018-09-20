//
//  main.cpp
//  Exam2016_1
//
//  Created by Yhondri on 19/1/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int parImpar(int v[], int n);

int main(int argc, const char * argv[]) {
    int n;
    cout << "Introduce el número de elementos" << endl;
    cin >> n;
    cout << "Introduce valores: " << endl;
    int v[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Nº parejas: " << parImpar(v, n) << endl;
    return 0;
}

int parImpar(int v[], int n) {
    int pares = 0;
    int resultado = 0;
    int i = 0;
    while (i < n) {
        if (v[i]%2 == 0) {
            pares++;
        }
        if (v[i]%2 == 1) {
            resultado += pares;
            pares = 0;
        }
        i++;
    }
    return resultado;
}
