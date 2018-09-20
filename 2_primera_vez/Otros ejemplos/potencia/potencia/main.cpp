//
//  main.cpp
//  potencia
//
//  Created by Yhondri on 7/12/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int potencia(int a, int n);
int potencia(int a, int n, int acumulado, int i);

int main(int argc, const char * argv[]) {
    int a;
    int n;
    
    cout << "Introudce la base" << endl;
    cin >> a;
    
    cout << "Introudce la potencia" << endl;
    cin >> n;
    
    cout << "El resultado es" << endl;
    cout << potencia(a, n) << endl;
    cout << potencia(a, n, 1, 0) << endl;
    
    return 0;
}

int potencia(int a, int n) {
    int p;
    
    if (n == 0) {
        p = 1;
    }else {
        p = potencia(a, n-1) * a;
    }
    return p;
}

int potencia(int a, int n, int acumulado, int i) {
    int resultado;
    if(i == n) {
        resultado = acumulado;
    }else {
        resultado = potencia(a, n, acumulado*a, i+1);
    }
    return resultado;
}
