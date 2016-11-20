//
//  main.cpp
//  Iter11
//
//  Created by Yhondri on 20/11/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

bool resuelve();
bool parImpar(int v[], int n, bool &existe, int &position);

int main() {
    while (resuelve());
    return 0;
}

bool parImpar(int v[], int n, bool &existe, int &position) {
    bool par = true;
    
    for (int i = 0; i < n; i++) {
        if (!par && existe) {
            if (v[i] % 2 == 0) {
                existe = false;
            }
        } else {
            if (v[i] % 2 != 0) {
                par = false;
                position = i;
            }
        }
    }
    if (par) {
        position = n;
    }
    return existe;
}


bool resuelve() {
    // Leer datos
    int n;
    int max;
    
    cin >> max;
    for (int j = 0; j < max; j++) {
        cin >> n;
        int v[n];
        for (int i=0; i<n; i++) {
            cin >> v[i];
        }
        
        int position = 0;
        bool existe = true;
        if (parImpar(v, n, existe, position)) {
            cout << "Si " << position << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return false;
}
