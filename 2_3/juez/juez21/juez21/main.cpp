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
bool esAproximadamenteUnDegradado(vector<int> &datos, int numInicio, int numFinal, int &suma);
vector<int> getSumColumnas(vector<vector<int>> &datos, int numFilas, int numColumnas);

int esDegradado(vector<vector<int>> &datos, int numFila, int numInicio, int numFinal);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez21/juez21/casos");
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
    int tempSuma;
    for (int i = 0; i < numFilas && result; i++) {
        tempSuma = 0;
        //            result = (esDegradado(datos, i, 0, numColumnas) >= 0);
        result = esAproximadamenteUnDegradado(datos.at(i), 0, numColumnas-1, tempSuma);
    }

    return result;
}

int esDegradado(vector<int> &datos, int numFila, int numInicio, int numFinal) {
    int izq, der;
    if (numFinal-numInicio <= 2) {
        izq = datos[numInicio];
        der = datos[numFinal-1];
    } else {
        int mitad = (numFinal+numInicio)/2;
        izq = esDegradado(datos, numFila, numInicio, mitad);
        der = esDegradado(datos, numFila, mitad, numFinal);

        if (izq < 0 || der < 0) {
            return false;
        }
    }

    if (izq < der) {
        return izq + der;
    } else {
        return -1;
    }
}

bool esAproximadamenteUnDegradado(vector<int> &datos, int numInicio, int numFinal, int &suma) {
    if (numFinal-numInicio <= 2) {
        suma = datos[numInicio] + datos[numFinal];
        return datos[numInicio] < datos[numFinal];
    } else {
        int mitad = (numFinal+numInicio)/2;
        int sumaLadoIzquierdo = 0, sumaLadoDerecho = 0;
        bool ladoIzqEsAproximadamenteUnDegradado = esAproximadamenteUnDegradado(datos, numInicio, mitad, sumaLadoIzquierdo);
        bool ladoDrEsAproximadamenteUnDegradado = esAproximadamenteUnDegradado(datos, mitad+1, numFinal, sumaLadoDerecho);
        suma = sumaLadoIzquierdo + sumaLadoDerecho;
        return ladoIzqEsAproximadamenteUnDegradado && ladoDrEsAproximadamenteUnDegradado && sumaLadoIzquierdo < sumaLadoDerecho;
    }
}
