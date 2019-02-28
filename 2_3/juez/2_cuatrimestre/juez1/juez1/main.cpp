//
//  main.cpp
//  juez1
//
//  Created by Yhondri Josué Acosta Novas on 25/02/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "Hora.h"

using namespace std;

bool resuelveCaso();

int main(int argc, const char * argv[]) {

    //ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez1/juez1/casos");
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez1/juez1/casos");
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
    int numTrains, numHours;
    cin >> numTrains >> numHours;

    if (numTrains == 0 && numHours == 0) {
        return false;
    }

    vector<Hora> schedule(numTrains);

    for (int i = 0; i < numTrains; i++) {
        cin >> schedule[i];
    }

    for (int i = 0; i < numHours; i++) {
        try {
            Hora hour;
            cin >> hour;

            auto p = lower_bound(schedule.begin(), schedule.end(), hour);

            if (p == schedule.end()) {
                cout << "NO\n";
            } else {
                cout << *p << "\n";
            }
        } catch(invalid_argument const& x) {
            cout << "ERROR\n";
        }

    }

    cout << "---\n";

    return true;
}
