//
//  main.cpp
//  MaxResta
//
//  Created by TEAM DELOREAN.
//  Copyright © 2018 TEAM DELOREAN. All rights reserved.
//

// -----------------
//| Especificación |
// -----------------
// P = {N >=  2}
// fun maxResta(int A[N]) return (r: int)
// Q = {r=(max p,q : 0 p < q < N :A[p] -  A[q])}

// -------------
//| Invariante |
// -------------
// I = 2 <= i <= v.Length &&
// maximaDiferencia = (max q: 0 <= q < i: elementoMaximo - v[q]) &&
// elementoMaximo = (max p: 0 <= p < i: v[p])

// --------------
//| Verificación |
// --------------
// P ==> I
// N >= 2 ==> I
// (I && B) A{I}
// El invariante se mantiene al ejecutar el cuerpo del bucle, puesto que tenemos una distinción de casos
// hemos de demostrar:
// {I /\ B /\ v[i] > elementoMaximo} A {I}
// pmd(A,I) <==> elementoMaximo = v[i] && 2 <= i <= v.Length &&
// maximaDiferencia = (max q: 0 <= q < i: elementoMaximo - v[q])
// {I /\ B /\ elementoMaximo - v[i] > maximaDiferencia} A {I}
// pmd(A,I) <==> maximoDiferencia = elementoMaximo - v[i] && 2 <= i <= v.Length &&
// && elementoMaximo = (max p: 0 <= p < i: v[p])


// -------
//| Cota |
// -------
//La cota es v.length - i.
//Siendo B la condición del bucle:
// * Es mayor o igual que cero cuando B se cumple: I && B => 0.
// * Decrece al ejecutarse el bucle.

// -------
//| Coste |
// -------
// El coste del algoritmo es O(n), siendo n el tamaño del array (número de elementos), ya que tenemos que recorrer el array
// entero 1 vez para poder calcular la diferencia máxima.


#include <iostream>
#include <vector>

using namespace std;

//int maxResta(vector<int> &a);

int maxResta(int arr[], int arr_size);

int main(int argc, const char * argv[]) {

    int arr[] = {1, 2, 90, 10, 110};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function calling
cout << "La diferencia máxima es: " << maxResta(arr, n) << endl;

    return 0;
}


int maxResta(int v[], int n) {
    // Maxima diferencia inicial.
    int maximaDiferencia = v[1] - v[0];

    int elementoMaximo = v[0];
    for(int i = 2; i < n; i++) {

        if (elementoMaximo - v[i] > maximaDiferencia) {
            maximaDiferencia = elementoMaximo - v[i];
        } else if (v[i] > elementoMaximo) {
            elementoMaximo = v[i];
        }
    }

    return maximaDiferencia;
}
