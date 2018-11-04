//
//  main.cpp
//  juez10
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//


// -----------------
//| Especificación |
// -----------------

//P = {0 >= v.size()}
//void resolverCaso(vector<int> datos, int numDatos);
//Q = {numPicos = #i: 1 <= i < v.length-1 : v[i-1] < v[i] && v[i] > v[i+1]}
//{numValles = #i: 1 <= i < v.length-1 : v[i-1] > v[i] && v[i] < v[i+1]}

// -------
//| Cota |
// -------
//La cota es v.length - i.
//Siendo B la condición del bucle:
// * Es mayor o igual que cero cuando B se cumple: I && B => 0.
// * Decrece al ejecutarse el bucle.

// -------
//| Coste |
// -------
// El coste del algoritmo es O(n), siendo n el tamaño del array (número de elementos), ya que tenemos que recorrer el array
// entero 1 vez para poder calcular el total de picos y valles.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
void resolverCaso(vector<int> datos, int numDatos);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//    #ifndef DOMJUDGE
////        ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez10/juez10/casos");
//
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez10/juez10/casos");
//        auto cinbuf = cin.rdbuf(in.rdbuf());
//    #endif
//    
    int numDatos;
    
    while (cin >> numDatos) {
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);
        
        resolverCaso(datos, numDatos);
    }
    
    
//    #ifndef DOMJUDGE
//        cin.rdbuf(cinbuf);
//        //    system("PAUSE");
//    #endif

    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    int nuevoDato;
    for (int i = 0; i < numDatos; i++) {
        cin >> nuevoDato;
        datos[i] = nuevoDato;
    }
}

void resolverCaso(vector<int> datos, int numDatos) {
    int rachaPartidosGanados = 0, mayorRachaGanados = 0,  numRepeticionesRachaGoleadora = 0, partidosDesdeLaUltimaRacha = 0;
    
    for (int i = 0; i < numDatos; i++) {
        if (datos[i] > 0) {
            rachaPartidosGanados++;

            if (mayorRachaGanados < rachaPartidosGanados) {
                mayorRachaGanados = rachaPartidosGanados;
                numRepeticionesRachaGoleadora = 1;
                partidosDesdeLaUltimaRacha = i;
            } else if(mayorRachaGanados > 0 && mayorRachaGanados == rachaPartidosGanados) {
                numRepeticionesRachaGoleadora++;
                partidosDesdeLaUltimaRacha = i;
            }
        } else {
            rachaPartidosGanados = 0;
        }
    }


    int ultimaRacha;

    if (mayorRachaGanados > 0) {
        ultimaRacha = numDatos - partidosDesdeLaUltimaRacha - 1;
    } else {
        ultimaRacha = numDatos;
    }

    cout << mayorRachaGanados << " " << numRepeticionesRachaGoleadora << " " << ultimaRacha << endl;
}
