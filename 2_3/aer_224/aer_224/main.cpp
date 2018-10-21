//
//  main.cpp
//  aer_224
//
//  Created by Yhondri Josué Acosta Novas on 16/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {

    //        ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_224/aer_224/casos"); //MacBook Pro;
    //                        ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_132/aer_132/casos");//Mac Mini;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif


    long long numCortezas;

    while (cin >> numCortezas && numCortezas > 0) {
        long long nuevaCorteza;
        vector<long long> cortezas;

        for (int i = 0; i < numCortezas; i++) {
            cin >> nuevaCorteza;
            cortezas.push_back(nuevaCorteza);
        }

        long long posicionCortezaMayor = 0, j = 0, acumulador = 0;

        for(int i = 0; i < numCortezas && j < numCortezas; i++) {
            long long cortezaActual = cortezas[i];
            j = i+1;
            acumulador = 0;

            while(j <= numCortezas && acumulador < cortezaActual) {
                acumulador += cortezas[j];
                j++;
            }

            if (j == numCortezas) {
                posicionCortezaMayor = i;
            }
        }

        if (cortezas[posicionCortezaMayor] == acumulador) {
            cout << "SI " << posicionCortezaMayor+1 << endl;
        } else {
            cout << "NO" << endl;
        }
    }

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}
