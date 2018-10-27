//
//  main.cpp
//  InsertSort
//
//  Created by Yhondri Josué Acosta Novas on 27/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int> &a);

int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> arrayDesordenado;
    arrayDesordenado.push_back(10);
    arrayDesordenado.push_back(3);
    arrayDesordenado.push_back(5);

    for (int i = 0; i < arrayDesordenado.size(); i++) {
        cout << arrayDesordenado[i] << " ";
    }

    cout << endl;

    insertSort(arrayDesordenado);

    for (int i = 0; i < arrayDesordenado.size(); i++) {
        cout << arrayDesordenado[i] << " ";
    }

    cout << endl;

    return 0;
}


void insertSort(vector<int> &a) {
    int j, value;
    for(int i = 1 ; i < a.size(); i++) { //Recorremos la lista n veces donde n es el tamaño del array.
        value = a[i];
        for (j = i - 1; j >= 0 && a[j] > value; j--) { //En el caso peor, este bucle se ejecutará n-1 veces.
            a[j + 1] = a[j];
        }
        a[j + 1] = value;
    }
}
