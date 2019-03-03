//
//  main.cpp
//  juez3
//
//  Created by Yhondri Josué Acosta Novas on 03/03/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

bool resuelveCaso();

int main(int argc, const char * argv[]) {

    //ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez3/juez3/casos");
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
    return false;
}
