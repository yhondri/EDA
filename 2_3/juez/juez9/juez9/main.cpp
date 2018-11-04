//
//  main.cpp
//  juez9
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

// -----------------
//| Especificación |
// -----------------

//predicate EstricCreciente (s : seq <int >)
//ensures EstricCreciente(s) == forall u , w :: 0 <= u < w < |s| ==> s[u] < s[w]
//
//method Problema02(v : array<int>) requires v != null
//requires forall k :: 0 <= k < v.Length ==> v[k] > 0 requires EstricCreciente(v[..])
//ensures forall i::0<=i<old(v.Length) && old(v[i])%2 == 0 ==> old(v[i]) in v[..] ensures 0 <= v.Length <= old(v.Length)
//ensures forall i :: 0 <= i < v.Length ==> v[i] in old(v[..])
//ensures EstricCreciente(v[..])
//modifies v

// -------------
//| Invariante |
// -------------
//1 <= i <= v.size() &&
//I = { 0 <= i <= v.size() && 0 <= z <= i && (forall w: 0 <= 2 < j : v[w] > 0 && v[w] %2 == 0}

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
// Coste es O(n) donde n es el número de elementos del array,  ya que cada vuelta que damos al bucle es constante y el bucle se repite n veces. 

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
void resolverProblema(vector<int> &datos, int numDatos);


int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez9/juez9/casos"); //MacBook Pro;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numCasos, numDatos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numDatos;
        
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);
        
        resolverProblema(datos, numDatos);
        
        numCasos--;
    }
    
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
//
    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    int nuevoDato;
    for (int i = 0; i < numDatos; i++) {
        cin >> nuevoDato;
        datos[i] = nuevoDato;
    }
}


void resolverProblema(vector<int> &datos, int numDatos) {
    int j = 0;

    for (int i = 0; i < numDatos; i++) {
        if (datos[i] %2 == 0) {
            if (i != j) {
                int temp = datos[i];
                datos[i] = datos[j];
                datos[j] = temp;
            }
            j++;
        }
    }
    
    datos.resize(j);
    
    for (int i = 0; i < datos.size(); i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}
