//
//  main.cpp
//  Iter02
//
//  Created by Yhondri on 5/2/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

void numBoletos(int v[], int n);

int main()
{
    int numCasos;
    cout << "Introduce el número de casos: " << endl;
    cin >> numCasos;
    
    while (numCasos > 0) {
        int n = 0;
        cout << "Introduce el número de boletos: " << endl;
        cin >> n;
        int *v = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        numBoletos(v, n);
        numCasos--;
    }
    return 0;
}

void numBoletos(int v[], int n) {
    int numPares = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0) {
            numPares++;
        }
    }
    cout << numPares << endl;
}
