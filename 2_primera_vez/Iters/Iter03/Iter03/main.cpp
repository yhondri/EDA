//
//  main.cpp
//  Iter03
//
//  Created by Yhondri on 5/2/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

void colones(int v[], int n);

int main()
{
    int numCasos = 0;
    cout << "Introduce numCasos: " << endl;
    cin >> numCasos;
    while (numCasos > 0)
    {
        int n = 0;
        cout << "Introduce num valores: " << endl;
        cin >> n;
        int *v = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        colones(v, n);
        numCasos--;
    }
    return 0;
}

void colones(int v[], int n) {
    int numColones = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1]) {
            numColones++;
        }
    }
    cout << numColones << endl;
}
