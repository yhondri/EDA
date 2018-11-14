//
//  main.cpp
//  juez19
//
//  Created by Yhondri Josué Acosta Novas on 13/11/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

using namespace std;

bool leerDatos(vector<int> &datos);
bool estaParcialMenteOrdeando(vector<int> &datos);
bool estaParcialMenteOrdeando(vector<int> &datos, int min, int max);

bool estaParcialMenteOrdeando(vector<int> &datos) {
    if (datos.size() == 2) {
        if (datos[0] <= datos[1]) {
            return true;
        } else {
            return false;
        }
    } else {
        int mitad = ((int)datos.size()-1)/2;
        bool mitadIzquierda = estaParcialMenteOrdeando(datos, 0, mitad);
        bool mitadDerecha = estaParcialMenteOrdeando(datos, mitad+1, ((int)datos.size()-1));
        return mitadIzquierda && mitadDerecha;
    }
}

bool estaParcialMenteOrdeando(vector<int> &datos, int min, int max) {
    if (datos[min] > datos[max]) {
        return false;
    }
    
    if (min == max-1) {
        return true;
    }
    
    return estaParcialMenteOrdeando(datos, min+1, max-1);
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez19/juez19/casos");
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez19/juez19/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    bool seguir = true;

    while (seguir) {
        vector<int> datos;
        seguir = leerDatos(datos);

        if (seguir) {
            if (estaParcialMenteOrdeando(datos)) {
                cout << "SI" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}

bool leerDatos(vector<int> &datos) {
    int nuevoDato = 0, i = 0;
    while (cin >> nuevoDato && nuevoDato > 0) {
        datos.push_back(nuevoDato);
        i++;
    }
    return (nuevoDato == 0 && i > 0);
}
