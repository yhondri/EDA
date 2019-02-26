//
//  main.cpp
//  grupo_e_ejercicio_01
//
//  Created by Yhondri Josué Acosta Novas on 14/01/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

void resolverCaso(const vector<int> &datos, int numDatos, int longitudMinimaSegmento) {
    vector<int> segmentos;
    int longitudSegmentoActual = 0, contadorSegmentos = 0, inicioSegmento = 0;

    for (int i = 0; i <= numDatos-1; i++) {

        if (abs(datos[i] - datos[i+1]) <= 1) {
            longitudSegmentoActual++;
        } else {
            if ((longitudSegmentoActual+1) >= longitudMinimaSegmento) {
                contadorSegmentos++;
                inicioSegmento = i - longitudSegmentoActual;
                segmentos.push_back(inicioSegmento);
            }

            longitudSegmentoActual = 0;
        }
    }

    if (contadorSegmentos > 0) {
        cout << contadorSegmentos << " ";
    } else {
        cout << contadorSegmentos;
    }

    for (int i = 0; i < (int)segmentos.size(); i++) {
        cout << segmentos[i] << " ";
    }

    cout << endl;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/examenes/grupo_e_ejercicio_01/grupo_e_ejercicio_01/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numDatos, longitudMinimaSegmento;

    while (cin >> numDatos >> longitudMinimaSegmento && (numDatos != 0 && longitudMinimaSegmento != 0)) {
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);

        resolverCaso(datos, numDatos, longitudMinimaSegmento);
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
