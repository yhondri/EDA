//
//  main.cpp
//  juez_5
//
//  Created by Yhondri Josué Acosta Novas on 23/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>

//Posición más a la derecha que cumple la condición.
//0 1 0 1 0 1 0 0
//N N N N N S ----> S es la posición correcta en este caso.

using namespace std;

void resuelveCaso();

int main(int argc, const char * argv[]) {
    //        ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez_5/juez_5/casos"); //MacBook Pro;
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    cin >> numCasos;
    while (numCasos > 0) {
        resuelveCaso();
        numCasos--;
    }


#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    return 0;
}

void resuelveCaso() {

    int p = -1, contadorDeCeros = 0, contadorDeUnos = 0, numValores;
    cin >> numValores;

    for (int i = 0; i < numValores; i++) {
        int nuevoValor;
        cin >> nuevoValor;

        if (nuevoValor == 0) {
            contadorDeCeros++;
        } else if(nuevoValor == 1) {
            contadorDeUnos++;
        }

        if (contadorDeCeros == contadorDeUnos) {
            p = i;
        }
    }

    cout << p << endl;
}
