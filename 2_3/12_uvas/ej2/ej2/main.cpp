//
//  main.cpp
//  ej2
//
//  Created by Yhondri Josué Acosta Novas on 31/12/2018.
//  Copyright © 2018 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Downloads/eda/2_3/12_uvas/ej2/ej2/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int fila, columna;
    vector<char> filas{'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
//    vector<int> columnas{8, 7, 6, 5, 4, 3 , 2, 1};
    while (cin >> fila >> columna && (fila > 0 && columna > 0)) {
        cout << filas[fila-1] << columna << endl;
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
