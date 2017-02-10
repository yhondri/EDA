//
//  main.cpp
//  ParImpar
//
//  Created by Yhondri on 9/2/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int parImpar(int v[], int n);

int main(int argc, const char * argv[]) {
    int n = 0;
    cin >> n;
    int* v = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << parImpar(v, n) << endl;
    return 0;
}

int parImpar(int v[], int n) {
    int total = 0;
    int pares = 0;
    for (int i = 0; i < n; i++) {
        if ((v[i]%2) == 0) {
            pares++;
        }
        if ((v[i]%2) == 1) {
            total += pares;
            pares = 0;
        }
    }
    return total;
}
