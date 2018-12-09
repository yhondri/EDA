//
//  main.cpp
//  juez23
//
//  Created by Yhondri  on 9/12/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

enum Color {Azul, Rojo, Verde};
const int NUMCOLUMNAS = 3;

void construirTorresDeColores(int alturaTorre, int numPiezasAzules, int numPiezasRojas, int numPiezasVerdes);
void vueltaAtras(vector<int> piezasColocadas, vector<int> piezasDisponibles, vector<Color> solucion, int k, int n, int &numSoluciones);
bool esValida(vector<Color> solucion, vector<int> piezasDisponibles, vector<int> piezasColocadas, int k, int n);
bool esSolucion(int k, int n);
void tratarSolucion(vector<Color> solucion, int n);


int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez23/juez23/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int alturaTorre, piezasAzules, piezasRojas, piezasVerdes;
    cin >> alturaTorre >> piezasAzules >> piezasRojas >> piezasVerdes;
    while (!(alturaTorre == 0 && piezasAzules == 0 && piezasRojas == 0 && piezasVerdes == 0)) {
        construirTorresDeColores(alturaTorre, piezasAzules, piezasRojas, piezasVerdes);
        cout << endl;
        cin >> alturaTorre >> piezasAzules >> piezasRojas >> piezasVerdes;
    }
    
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

/**
 Preparamos el problema a resolver. 
 */
void construirTorresDeColores(int alturaTorre, int numPiezasAzules, int numPiezasRojas, int numPiezasVerdes) {
    vector<int> piezasDisponibles{numPiezasAzules, numPiezasRojas, numPiezasVerdes};
    vector<int> piezasColocadas(NUMCOLUMNAS);
    vector<Color> solucion(alturaTorre);
    solucion[0] = Rojo; //Primera pieza (la base) siempre roja.
    piezasColocadas[1]++; //Hemos colocado una pieza roja.
    int numSoluciones = 0;
    vueltaAtras(piezasColocadas, piezasDisponibles, solucion, 1, alturaTorre, numSoluciones);
    
    if (numSoluciones == 0) {
        cout << "SIN SOLUCION" << endl;
    }
}

void vueltaAtras(vector<int> piezasColocadas, vector<int> piezasDisponibles, vector<Color> solucion, int k, int n, int &numSoluciones) {
    for (Color colorSeleccionado = Azul; colorSeleccionado <= Verde; colorSeleccionado = Color(colorSeleccionado+1)) {
        solucion[k] = colorSeleccionado;
        piezasColocadas[colorSeleccionado]++;
        
        if (esValida(solucion, piezasDisponibles, piezasColocadas, k, n)) {
            if (esSolucion(k, n)) {
                tratarSolucion(solucion, n);
                numSoluciones++;
            } else {
                vueltaAtras(piezasColocadas, piezasDisponibles, solucion, k+1, n, numSoluciones);
            }
        }
        piezasColocadas[colorSeleccionado]--;
    }
}

/**
 Comprobamos que la solución actual cumple todas las restricciones.
 */
bool esValida(vector<Color> solucion, vector<int> piezasDisponibles, vector<int> piezasColocadas, int k, int n) {
    if (piezasColocadas[solucion[k]] > piezasDisponibles[solucion[k]]) {
        return false;//Comprobamos si el número de piezas colocadas del color solucion[k], es mayor al número de piezas de ese color disponibles.
    } else if (solucion[k-1] == Verde && solucion[k] == Verde) {
        return false; // Comprobamos si se han colocado 2 piezas verdes seguidas.
    } else if (piezasColocadas[Verde] > piezasColocadas[Azul]) {
        return false; // Comprobamos si se han colocado más piezas verdes que azules.
    } else if(piezasColocadas[Rojo] + min((n-k-1), (piezasDisponibles[Rojo]-piezasColocadas[Rojo])) <= n/2) {
        return false; // Comprobamos cuántas piezas rojas podemos colocar y miramos si no superamos la mitad n/2.
    } else {
        return true;
    }
}

/**
 Comprobamos que hemos colocados todas las piezas de la torre,
 esto es que hemos rellenado todos los huecos del array solucion.
 */
bool esSolucion(int k, int n) {
    return (k == (n-1));
}

/**
 Muestra la solución por consola.
 */
void tratarSolucion(vector<Color> solucion, int n) {
    vector<string> colores = {"azul", "rojo", "verde"};
    for (int i = 0; i < n-1; i++) {
        cout << colores[solucion[i]] << " ";
    }
    
    cout << colores[solucion[n-1]] << endl;
}

