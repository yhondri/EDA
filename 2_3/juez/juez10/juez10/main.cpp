//
//  main.cpp
//  juez10
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

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
