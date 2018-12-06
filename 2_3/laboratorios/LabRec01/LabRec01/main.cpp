//
//  main.cpp
//  LabRec01
//
//  Created by Yhondri Josué Acosta Novas on 04/12/2018.
//  Copyright © 2018 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int encontrarPosicion(vector<int> datos, int numElementos);
int encontrarPosicion(vector<int> datos, int posicionInicial, int posicionFinal);
void leerDatos(vector<int> &datos, int numDatos);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/laboratorios/LabRec01/LabRec01/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos, numDatos;
    cin >> numCasos;

    while (numCasos > 0) {

        cin >> numDatos;
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);

        cout << encontrarPosicion(datos, numDatos) << endl;

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

int encontrarPosicion(vector<int> datos, int numElementos) {
    if (numElementos == 1) {
        return 0;
    }
    return encontrarPosicion(datos, 0, numElementos-1);
}

int encontrarPosicion(vector<int> datos, int posicionInicial, int posicionFinal) {
    int numElementos = (posicionFinal - posicionInicial);
    int mitad = (posicionInicial+posicionFinal)/2;


    if (numElementos <= 2) {
        if (datos[mitad-1] == datos[mitad]) {
            return mitad + 1;
        } else if (datos[mitad] == datos[mitad+1]) {
            return mitad - 1;
        } else {
            return mitad;
        }
    }

    if (mitad%2 == 0) { //Posición par datos[mitad+1] == datos[mitad]
        if (datos[mitad] == datos[mitad+1]) {
            return encontrarPosicion(datos, mitad, posicionFinal);
        } else {
            return encontrarPosicion(datos, posicionInicial, mitad);
        }
    } else {
        if (datos[mitad] == datos[mitad+1]) {
            return encontrarPosicion(datos, posicionInicial, mitad);
        } else {
            return encontrarPosicion(datos, mitad, posicionFinal);
        }
    }
}
