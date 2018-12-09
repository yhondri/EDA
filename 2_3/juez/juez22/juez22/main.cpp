//
//  main.cpp
//  juez22
//
//  Created by Yhondri  on 7/12/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
void mostrarDatos(vector<int> &datos, int numDatos);
void mergeSort(vector<int> &datos, int l, int r, int &acumulador);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez22/juez22/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numDatos;
    
    while (cin >> numDatos) {
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);
        
        int acumulador = 0;
        mergeSort(datos, 0, numDatos - 1, acumulador);
        
        cout << acumulador << endl;
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    for(int i = 0; i < numDatos; i++) {
        cin >> datos[i];
    }
}

void mostrarDatos(vector<int> &datos, int numDatos) {
    for(int i = 0; i < numDatos; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(vector<int> &datos, int l, int m, int r, int &acumulador) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    vector<int> L(n1), R(n2);
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) {
        L[i] = datos[l + i];
    }
    
    for (j = 0; j < n2; j++) {
        R[j] = datos[m + 1+ j];
    }
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            datos[k] = L[i];
            i++;
        } else {
            datos[k] = R[j];
            acumulador += n1 - i; //N1 = Longitud array de la izquierda.
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1) {
        datos[k] = L[i];
        i++;
        k++;
        
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2) {
        datos[k] = R[j];
        j++;
        k++;
        
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(vector<int> &datos, int l, int r, int &acumulador) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(datos, l, m, acumulador);
        mergeSort(datos, m+1, r, acumulador);
        
        merge(datos, l, m, r, acumulador);
    }
}
