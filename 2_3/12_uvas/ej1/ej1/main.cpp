//
//  main.cpp
//  ej1
//
//  Created by Yhondri Josué Acosta Novas on 31/12/2018.
//  Copyright © 2018 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

void estimarNumUvasMalas(int totalUvas, int numA, int numB) {
    int numGrupos = (totalUvas/numB);

    //    int relacionGruposEnteros = (numGrupos*numA);
    int restoUvas = (totalUvas - (numB*((int)(totalUvas/numB))));
    float temp = ((float)numA/(float)numB);
//    float relacionResto = 1;
//    relacionResto += ((float)restoUvas)*temp;

    int relacionResto;

    if (restoUvas > numA) {
        relacionResto = numA; //todas van a ser malas.
    } else {
        relacionResto = restoUvas; //todas van a ser malas.
    }

    int total = (numGrupos * numA) + round(relacionResto);

    cout << total << endl;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/12_uvas/ej1/ej1/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numCasos, numUvasCompradas, numA, numB;
    cin >> numCasos;

    while (numCasos > 0) {
        cin >> numUvasCompradas >> numA >> numB;
        estimarNumUvasMalas(numUvasCompradas, numA, numB);
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
        datos[i] = nuevoDato;
    }
}
