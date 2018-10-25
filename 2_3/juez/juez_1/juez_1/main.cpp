//
//  main.cpp
//  juez_1
//
//  Created by Yhondri Josué Acosta Novas on 25/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void resuelveCaso();

int main(int argc, const char * argv[]) {
    //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez_1/juez_1/casos"); //MacBook Pro;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numCasos;
    cin >> numCasos;
    while (numCasos > 0) {
        resuelveCaso();
        numCasos--;
    }


//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    return 0;
}

void resuelveCaso() {
    int numValues, newValue;
    cin >> numValues;
    vector<int> datos;

    for (int i = 0; i < numValues; i++) {
        cin >> newValue;
        datos.push_back(newValue);
    }

    int numPicos = 0, numValles = 0;
    for (int i = 1; i <= numValues-2; i++) {
        if (datos[i-1] > datos[i] && datos[i] < datos[i+1]) {
            numValles++;
        } else if (datos[i-1] < datos[i] && datos[i] > datos[i+1]) {
            numPicos++;
        }
    }

    cout << numPicos << " " << numValles << endl;
}
