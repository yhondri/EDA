//
//  main.cpp
//  juez21
//
//  Created by Yhondri Josué Acosta Novas on 20/11/2018.
//  Copyright © 2018 com.educamos. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<vector<int>> &datos, int numFilas, int numColumnas);
void mostrarDatos(vector<vector<int>> &datos, int numFilas, int numColumnas);
bool esAproximadamenteUnDegradado(vector<vector<int>> &datos, int numFilas, int numColumnas);
int esAproximadamenteUnDegradado(vector<int> &datos, int numInicio, int numFinal);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez21/juez21/casos");
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez21/juez21/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numFilas, numColumnas;

    while (cin >> numFilas && cin >> numColumnas) {
        vector<vector<int>> datos(numFilas);
        leerDatos(datos, numFilas, numColumnas);

        bool result = esAproximadamenteUnDegradado(datos, numFilas, numColumnas);

        if (result) {
            cout << "SI" << endl;
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

void leerDatos(vector<vector<int>> &datos, int numFilas, int numColumnas) {
    for(int i = 0; i < numFilas; i++) {
        datos[i] = vector<int>(numColumnas);
    }

    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            cin >> datos[i][j];
        }
    }
}

void mostrarDatos(vector<vector<int>> &datos, int numFilas, int numColumnas) {
    for (int i = 0; i < numFilas; i++) {
        for (int j = 0; j < numColumnas; j++) {
            cout << datos[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool esAproximadamenteUnDegradado(vector<vector<int>> &datos, int numFilas, int numColumnas) {
    bool result = true;
    for (int i = 0; i < numFilas && result; i++) {
         result = (esAproximadamenteUnDegradado(datos.at(i), 0, numColumnas) >= 0);
    }

    return result;
}

int esAproximadamenteUnDegradado(vector<int> &datos, int numInicio, int numFinal) {
    int ladoIzquierdo, ladoDerecho;
    if (numFinal-numInicio <= 1) {
        return datos[numInicio];
    } else {
        int mitad = (numFinal+numInicio)/2;
        ladoIzquierdo = esAproximadamenteUnDegradado(datos, numInicio, mitad); //Miramos lado izquierdo.
        ladoDerecho = esAproximadamenteUnDegradado(datos, mitad, numFinal); //Miramos lado derecho.

        if (ladoIzquierdo < 0 || ladoDerecho < 0 || ladoIzquierdo >= ladoDerecho) { //En caso de no cumplir la condición devolvemos -1, es decir, no es aproximadamenteDegradado. 
            return -1;
        }
        
        return ladoIzquierdo+ladoDerecho;
    }
}
