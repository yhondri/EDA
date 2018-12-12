//
//  main.cpp
//  LabRec03
//
//  Created by Yhondri Josué Acosta Novas on 11/12/2018.
//  Copyright © 2018 Yhondri. All rights reserved.
//

#include <iostream>

#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
int encuentraMenorDiferencia(vector<int> &datos, int numInicio, int numFinal, int x);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/laboratorios/LabRec03/LabRec03/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos, x, numElementos;
    cin >> numCasos;

    while (numCasos > 0) {
        cin >> x >> numElementos;
        vector<int> datos(numElementos);
        leerDatos(datos, numElementos);

        cout << encuentraMenorDiferencia(datos, 0, (int)datos.size()-1, x) << endl;

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

int encuentraMenorDiferencia(vector<int> &datos, int numInicio, int numFinal, int x) {
    int resultLadoIzq, resultLadoDer;
    if (numFinal-numInicio <= 1) {
        return datos[numInicio];
    } else {
        int mitad = (numFinal+numInicio)/2;
        resultLadoIzq = encuentraMenorDiferencia(datos, numInicio, mitad, x); //Miramos lado izquierdo.
        resultLadoDer = encuentraMenorDiferencia(datos, mitad, numFinal, x); //Miramos lado derecho.

        if (abs(x-resultLadoIzq) == abs(x-resultLadoDer)) {
            if (resultLadoIzq < resultLadoDer) {
                return resultLadoIzq;
            } else {
                return resultLadoDer;
            }
        }else if (abs(x-resultLadoIzq) < abs(x-resultLadoDer)) {
            return resultLadoIzq;
        } else {
            return resultLadoDer;
        }
    }
}

