//
//  main.cpp
//  juez1
//
//  Created by Yhondri Josué Acosta Novas on 25/02/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include "Pelicula.h"

using namespace std;

bool resuelveCaso();

int main(int argc, const char * argv[]) {

    //ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez2/juez2/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}

bool resuelveCaso() {
    int numPeliculas;
    cin >> numPeliculas;

    if (numPeliculas == 0) {
        return false;
    }

    vector<Pelicula> schedule(numPeliculas);

    for (int i = 0; i < numPeliculas; i++) {
        cin >> schedule[i];
    }

    sort(schedule.begin(), schedule.end());

    for (int i = 0; i < numPeliculas; i++) {
        cout << schedule[i] << "\n";
    }

    cout << "---\n";

    return true;
}
