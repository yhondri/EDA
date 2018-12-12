//
//  main.cpp
//  LabRec04
//
//  Created by Yhondri Josué Acosta Novas on 12/12/2018.
//  Copyright © 2018 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

void encontrarElemento(vector<int> datosA, vector<int> datosB, int posInicial, int posFinal, int numElementosA, int &elementoBuscado) {
    int m = (posInicial+posFinal)/2;
    if (posInicial == posFinal || (m == (numElementosA-1))) {
        elementoBuscado = datosA[posInicial];
    } else {
        if (datosA[m] >= datosB[m]) {
            encontrarElemento(datosA, datosB, m+1, posFinal, numElementosA, elementoBuscado);
        } else {
            encontrarElemento(datosA, datosB, posInicial, m, numElementosA, elementoBuscado);
        }
    }
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/laboratorios/LabRec04/LabRec04/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos, numDatos;
    cin >> numCasos;

    while (numCasos > 0) {
        cin >> numDatos;

        vector<int> datos1(numDatos);
        vector<int> datos2(numDatos-1);
        leerDatos(datos1, numDatos);
        leerDatos(datos2, numDatos-1);

        int elementoBuscado;

        encontrarElemento(datos1, datos2, 0, numDatos-1, numDatos, elementoBuscado);

        cout << elementoBuscado << endl;

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
        datos[i] = nuevoDato;
    }
}
