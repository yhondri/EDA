//
//  main.cpp
//  juez18
//
//  Created by Yhondri Josué Acosta Novas on 13/11/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
int findNumImpar(vector<int> datos);
int findNumImpar(vector<int>datos, int index);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez18/juez18/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numDatos;

    while (cin >> numDatos && numDatos != 0) {
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);
        cout << findNumImpar(datos) << endl;
    }

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    for (int i = 0; i < numDatos; i++) {
        cin >> datos[i];
    }
}


int findNumImpar(vector<int> datos) {
    if ((int)datos.size() == 1) {
        return datos[0];
    }
    return findNumImpar(datos, 0);
}

int findNumImpar(vector<int>datos, int index) {
    if (datos[index]%2 != 0) {
        return datos[index];
    } else {
        return findNumImpar(datos, index+1);
    }
}
