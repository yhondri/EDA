 //
//  main.cpp
//  VueltaAtrasPalabras
//
//  Created by Yhondri  on 21/8/17.
//  Copyright © 2017 Yhondri . All rights reserved.
//

#include <iostream>

using namespace std;

void variaciones(int n, int m);
void variaciones(int solucion[], int k, int n, int m);
bool esValida(int solucion[], int k);
bool esSolucion(int k, int m);
void tratarSolucion(int solucion[], int m);

int main(int argc, const char * argv[]) {
    variaciones(27,5);
    return 0;
}

void variaciones(int n, int m){
    int solucion[m];
    variaciones(solucion, 0, n, m);
}

void variaciones(int solucion[], int k, int n, int m) {
    for(int letra = 0; letra < n; letra++) {
        solucion[k] = letra;
        if(esValida(solucion, k)) {
            if(esSolucion(k, m))
                tratarSolucion(solucion,m);
            else
                variaciones(solucion, k + 1, n, m);
        }
    }
}

bool esValida(int solucion[], int k) {
    int i = 0;
    while(i < k && solucion[i] != solucion[k])
        i++;
    return i == k;
}

bool esSolucion(int k, int m) {
    return k == (m - 1);
}

void tratarSolucion(int solucion[], int m) {
    cout << "Solucion: ";
    for(int i = 0; i < m; i++)
        cout << solucion[i] << " ";
    cout << endl;
}
