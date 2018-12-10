//
//  main.cpp
//  LabRec02
//
//  Created by Yhondri Josué Acosta Novas on 06/12/2018.
//  Copyright © 2018 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
int esSuficientementeDisperso(vector<int> &datos, int posInicial, int posFinal, int k);
//int esSuficientementeDisperso(vector<int> &datos, int posInicial, int posFinal, int k);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/laboratorios/LabRec02/LabRec02/casos");
////    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/laboratorios/LabRec02/LabRec02/casos"); MINI
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numTiradas, valorDispersion;

    while (cin >> numTiradas && cin >> valorDispersion) {
        vector<int> datos(numTiradas);
        leerDatos(datos, numTiradas);

        int result = esSuficientementeDisperso(datos, 0, numTiradas, valorDispersion);

        if (result >= 0) {
            cout << "SI";
        } else {
            cout << "NO";
        }

        cout << endl;
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

int esSuficientementeDisperso(vector<int> &datos, int posInicial, int posFinal, int k) {
    int ladoIzquierdo, ladoDerecho;

    if (posFinal-posInicial <= 1) {
        return datos[posInicial];
    } else {
        int mitad = (posFinal+posInicial)/2;
        ladoIzquierdo = esSuficientementeDisperso(datos, posInicial, mitad, k); //Miramos lado izquierdo.
        ladoDerecho = esSuficientementeDisperso(datos, mitad, posFinal, k); //Miramos lado derecho.

        if (ladoIzquierdo < 0 || ladoDerecho < 0 || (abs(ladoIzquierdo-ladoDerecho) < k)) { //En caso de no cumplir la condición devolvemos -1, es decir, no es aproximadamenteDegradado.
            return -1;
        }

        return ladoIzquierdo+ladoDerecho;
    }
}
