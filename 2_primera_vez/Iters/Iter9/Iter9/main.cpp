//
//  main.cpp
//  Iter9
//
//  Created by Yhondri on 15/11/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int xxxx(int a[], int n);

int main(int argc, const char * argv[]) {
    
    int numCasos = 0;
    cin >> numCasos;
    
    while (numCasos > 0) {
        int arraySize = 0;
        cin >> arraySize;
        int array[arraySize];
        
        for (int i = 0; i < arraySize; i++) {
            cin >> array[i];
        }
        
        cout << xxxx(array, arraySize) << endl;
        
        numCasos--;
    }
    return 0;
}

int xxxx(int a[], int n) {
    
    int p = 0;
    int max = a[0];
    int maxIzq = max;
    
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }else if (a[i] <= maxIzq) {
            p = i;
            maxIzq = max;
        }
    }
    
    return p;
}
