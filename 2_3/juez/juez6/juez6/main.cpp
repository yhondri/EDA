//
//  main.cpp
//  juez6
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
int posMaximo(vector<int> &datos, int numDatos);
int sumSinMaximo(vector<int> &datos);
int sumaValores(vector<int> &datos);


int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez6/juez6/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numCasos, numDatos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numDatos;
        
        vector<int> datos;
        leerDatos(datos, numDatos);

        cout << sumaValores(datos) << endl;
        
        numCasos--;
    }
    
    
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    
    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    int nuevoDato;
    for (int i = 0; i < numDatos; i++) {
        cin >> nuevoDato;
        datos.push_back(nuevoDato);
    }
}

int posMaximo(vector<int> &datos, int numDatos) {
    int posicionMaximo = 0;
    
    for (int i = 0; i < numDatos; i++) {
        if (datos[i] > datos[posicionMaximo]) {
            posicionMaximo = i;
        }
    }
    
    return posicionMaximo;
}

int sumSinMaximo(vector<int> &datos) {
    int total = 0;
    int posicionMaximo = posMaximo(datos, (int)datos.size());
    int maximo = datos[posicionMaximo];
    
    for (int i = 0; i < (int)datos.size(); i++) {
        if (datos[i] != maximo) {
            total += datos[i];
        }
    }
    
    return total;
}

int sumaValores(vector<int> &datos) {
    return sumSinMaximo(datos);
}

