//
//  main.cpp
//  ej3
//
//  Created by Yhondri Josué Acosta Novas on 31/12/2018.
//  Copyright © 2018 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Downloads/eda/2_3/12_uvas/ej3/ej3/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    char letra;

    while (cin >> letra && letra != '.') {
        int numNegros = 0, numGrises = 0;

        if (letra == 'N') {
            numNegros++;
        } else {
            numGrises++;
        }

        while (cin >> letra && letra != '.') {
            if (letra == 'N') {
                numNegros++;
            } else {
                numGrises++;
            }
        }

        int restoNegros = numNegros%2;
        int restoGrises = numGrises%2;

        if (restoNegros == 0 && restoGrises == 0) {
            cout << "EMPAREJADOS" << endl;
        } else {

            if (restoNegros == 1 && restoGrises == 1) {
                cout << "PAREJA MIXTA" << endl;
            } else if(restoNegros != 0) {
                cout << "NEGRO SOLITARIO" << endl;
            } else {
                cout << "GRIS SOLITARIO" << endl;
            }

        }

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
