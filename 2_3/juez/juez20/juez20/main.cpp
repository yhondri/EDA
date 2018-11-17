//
//  main.cpp
//  juez20
//
//  Created by Yhondri Josué Acosta Novas on 15/11/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

void resolverCaso(vector<int> datos, int numDatos, int alturaSospechoso);
int buscarIz(vector<int>datos, int alturaSospechosho, int index, int indexFin);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez20/juez20/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numDatos, alturaSospechoso;

    while (cin >> numDatos) {
        cin >> alturaSospechoso;
        
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);

        resolverCaso(datos, numDatos, alturaSospechoso);
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
        datos[i] = nuevoDato;
    }
}


void resolverCaso(vector<int> datos, int numDatos, int alturaSospechoso) {
    int mitad = numDatos/2;
    int posIzquierda = buscarIz(datos, alturaSospechoso, 0, mitad);
    string result = "";

    if (posIzquierda != -1) {
    }
}

int buscarIz(vector<int>datos, int alturaSospechosho, int index, int indexFin) {
    if (datos[index] == alturaSospechosho) {
        return index;
    }

    if(index == indexFin) {
        return -1; //El elemento que buscamos no está en este lado del array.
    }

    return buscarIz(datos, alturaSospechosho, index+1, indexFin);
}
