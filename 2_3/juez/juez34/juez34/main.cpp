//
//  main.cpp
//  juez34
//
//  Created by Yhondri Josué Acosta Novas on 14/01/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

void resolverCasos(const vector<int> &datos, int numDatos) {

    bool seguir = true;
    //    int maximoActual = -1;
    int numElementosEscalonActual = 0, numElementosEscalonAnterior = 0;
    for (int i = 0; i < numDatos-1 && seguir; i++) {
        numElementosEscalonActual++;

        if (datos[i] != datos[i+1]) {
            if (numElementosEscalonAnterior == 0 || (numElementosEscalonAnterior <= numElementosEscalonActual)) {
                numElementosEscalonAnterior = numElementosEscalonActual;
            } else {
                seguir = false;
            }

            numElementosEscalonActual = 0;
        }

        if ((i+1) == numDatos-1 && datos[i] != datos[i+1] && numElementosEscalonAnterior > 1) {
            seguir = false;
        }
    }

    if (seguir) {
        cout << "SI" << endl;
    } else {
        cout << "NO" << endl;
    }

}



bool decidirAnchoCreciente(const vector<int> &v, int n) {
    int escalon = 0,escalonAux=0;
    bool anchoCreciente = true;
    for (int i = 0; i < n && anchoCreciente; i++) {
        escalon++;
        if (v[i] != v[i + 1]) {
            if (escalonAux == 0 || escalonAux <= escalon) {
                escalonAux = escalon;
            }
            else {
                anchoCreciente = false;
            }
            escalon = 0;
        }

    }

    return anchoCreciente;
}


//bool decidirAnchoCreciente(const vector<int> &v, int n) {
//    int escalon = 0,escalonAux=0;
//    bool anchoCreciente = true;
//    for (int i = 0; i < n-1 && anchoCreciente; i++)  {
//        escalon++;
//
//        if ((i+1) < n && v[i] != v[i + 1]) {
//            if (escalonAux == 0 || escalonAux <= escalon){
//                escalonAux = escalon;
//            }
//            else {
//                anchoCreciente = false;
//            }
//            escalon = 0;
//        } else if((i+1) > n) {
//            int tu = 2;
//        }
//    }
//
//    return anchoCreciente;
//}
//

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/juez34/juez34/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numDatos;

    while (cin >> numDatos && numDatos > 0) {
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);

        if (decidirAnchoCreciente(datos, numDatos)) {
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }

//                resolverCasos(datos, numDatos);
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
