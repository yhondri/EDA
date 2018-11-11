//
//  main.cpp
//  juez17
//
//  Created by Yhondri  on 11/11/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
int findMin(vector<int> datos, int numDatos);
int findMin(vector<int>datos, int indiceInicio, int indiceFinal);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez17/juez17/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numDatos;
    while (cin >> numDatos) {
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);
        cout << findMin(datos, numDatos) << endl;
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    for (int i = 0; i < numDatos; i++) {
        cin >> datos[i];
    }
}

int findMin(vector<int> datos, int numDatos) {
    if (numDatos == 1) {
        return datos[0];
    }
    
    if (datos[0] > datos[(int)datos.size()-1]) {
        return datos[(int)datos.size()-1];
    }
    
    return findMin(datos, 0, (int)datos.size()-1);
}

int findMin(vector<int>datos, int indiceInicio, int indiceFinal) {
    int index = (indiceInicio+indiceFinal)/2;

    if (index == 0) {
        return datos[0];
    } else if(index == (int)datos.size()-1) {
        return datos[datos.size()-1];
    }
    if (index-1 >= 0 && (index+1 <= (int)datos.size()-1) && datos[index] < datos[index-1] && datos[index] < datos[index+1]) {
        return datos[index]; //si el valor en el que estamos es menor que sus contiguos, quiere decir que es el mínimo.
    } else if (datos[index] < datos[indiceFinal]) {
        return findMin(datos, index, indiceFinal); //Hacía la derecha.
    } else {
        return findMin(datos, indiceInicio, index); //Hacía la izquierda.
    }
}
