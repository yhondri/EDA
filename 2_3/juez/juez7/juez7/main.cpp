//
//  main.cpp
//  juez7
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
void resolverCaso(vector<int> &datos, int numDatos);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez7/juez7/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos, numDatos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numDatos;
        
        vector<int> datos;
        leerDatos(datos, numDatos);
        
        resolverCaso(datos, numDatos);
        
        numCasos--;
    }
    
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    int nuevoDato;
    for (int i = 0; i < numDatos; i++) {
        cin >> nuevoDato;
        datos.push_back(nuevoDato);
    }
}

void resolverCaso(vector<int> &datos, int numDatos) {
    int j = 0;
    for (int i = 0; i < numDatos; i++) {
        if (datos[i] >= 0) {
            if (i != j) {
                int temp = datos[i];
                datos[i] = datos[j];
                datos[j] = temp;
            }
            j++;
        }
        
//        for (int i = 0; i < numDatos; i++) {
//            cout << datos[i] << " ";
//        }
//
//        cout << endl;
    }
    
    cout << j << endl;
    
//    for (int i = 0; i < numDatos; i++) {
//        cout << datos[i] << " ";
//    }
//    
//    cout << endl;
}
