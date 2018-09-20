//
//  main.cpp
//  Iter1
//
//  Created by Yhondri on 5/2/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

void max(int array[], int n);

int main()
{
    int numCasos = 0;
    cout << "Introduce el número de casos" << endl;
    cin >> numCasos;
    int arraySize = 0;
    while (numCasos > 0) {
        cout << "Introduce el número de valores" << endl;
        cin >> arraySize;
        int * array = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            cin >> array[i];
        }
        max(array, arraySize);
        numCasos--;
    }
    
    return 0;
}

void max(int array[], int n) {
    int max = 0;
    int acumulador = 0;
    for (int i = 0; i < n; i++){
        if (array[i] >= max) {
            if (array[i] != max) {
                acumulador = 0;
            }
            max = array[i];
            acumulador++;
        }
    }
    cout << max << " " << acumulador << endl;
}
