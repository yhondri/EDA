//
//  main.cpp
//  aer_316
//
//  Created by Yhondri Josué Acosta Novas on 06/12/2018.
//  Copyright © 2018 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
void resolverCaso(vector<int> datos, int numDatos);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/aer_316/aer_316/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos, numDatos;
    cin >> numCasos;

    while (numCasos > 0) {
        cin >> numDatos;

        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);

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

void resolverCaso(vector<int> datos, int numDatos) {

}
