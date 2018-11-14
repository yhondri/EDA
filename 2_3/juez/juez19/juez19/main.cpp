//
//  main.cpp
//  juez19
//
//  Created by Yhondri Josué Acosta Novas on 13/11/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool leerDatos(vector<int> &datos);
bool estaParcialMenteOrdeando(vector<int> &datos);
bool estaParcialMenteOrdeando(vector<int> &datos,
                              int minIzq,
                              int maxIz,
                              int minDer,
                              int maxDer,
                              int i,
                              int j);

bool estaParcialMenteOrdeando(vector<int> &datos) {
    if (datos.size() == 2) {
        if (datos[0] <= datos[1]) {
            return true;
        } else {
            return false;
        }
    } else {
        int minIzq = INT_MAX, maxIzq = INT_MIN, minDer = INT_MAX, maxDer = INT_MIN;
        int i = 0, j = (int)datos.size()-1;
        return estaParcialMenteOrdeando(datos, minIzq, maxIzq, minDer, maxDer, i, j);
    }
}

bool estaParcialMenteOrdeando(vector<int> &datos, int minIzq, int maxIz, int minDer, int maxDer, int i, int j) {


    return false;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez19/juez19/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    bool seguir = true;

    while (seguir) {
        vector<int> datos;
        seguir = leerDatos(datos);

    }


#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}

bool leerDatos(vector<int> &datos) {
    int nuevoDato = 0, i = 0;
    bool seguir = true;

    while (cin >> nuevoDato && nuevoDato > 0 && seguir) {
        if (nuevoDato == 0 && i == 0) {
            seguir = false;
        } else {
            datos.push_back(nuevoDato);
            i++;
        }
    }
    return  seguir;
}
