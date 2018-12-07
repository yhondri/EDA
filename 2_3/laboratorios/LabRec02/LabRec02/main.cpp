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
bool esSuficientementeDisperso(vector<int> &datos, int posInicial, int posFinal, int k);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/laboratorios/LabRec02/LabRec02/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numTiradas, valorDispersion;

    while (cin >> numTiradas && cin >> valorDispersion) {
        vector<int> datos(numTiradas);
        leerDatos(datos, numTiradas);

        bool result = esSuficientementeDisperso(datos, 0, numTiradas-1, valorDispersion);

        if (result) {
            cout << "SI";
        } else {
            cout << "NO";
        }

        cout << endl;
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

bool esSuficientementeDisperso(vector<int> &datos, int posInicial, int posFinal, int k) {
    int numElementos = (posFinal-posInicial);
    int diferencia = abs(datos[posInicial] - datos[posFinal]);

    if (diferencia >= k) {
        if (numElementos < 2) {
            return true;
        } else {
            int mitad = (posInicial+posFinal)/2;
            //Miramos mitad derecha y mitad izquierda. 
            return esSuficientementeDisperso(datos, posInicial, mitad, k) &&
            esSuficientementeDisperso(datos, mitad+1, posFinal, k);
        }
    }

    return false;
}
