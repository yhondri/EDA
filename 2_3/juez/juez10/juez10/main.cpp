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
//#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez10/juez10/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numDatos;
    
    while (cin >> numDatos) {
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);
        
        resolverCaso(datos, numDatos);
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

void resolverCaso(vector<int> datos, int numDatos) {
    int inicioMayorRachaGoleadora = -1, finalMayorRachaGoleadora = -1, finalRachaActual = numDatos - 1, numRepeticionesRachaGoleadora = 0;
    
    for (int i = numDatos - 1; i >= 0; i--) {
        if (datos[i] <= 0) {
            if (finalRachaActual != i) {
                int diff = (finalRachaActual - i) - (finalMayorRachaGoleadora - inicioMayorRachaGoleadora);
                if (diff == 0) {
                    numRepeticionesRachaGoleadora++;
                } else if (diff > 0) {
                    inicioMayorRachaGoleadora = i;
                    finalMayorRachaGoleadora = finalRachaActual;
                    numRepeticionesRachaGoleadora = 1;
                }
            }
            
            finalRachaActual = i - 1;
        }
    }
    
    int diff = (finalRachaActual + 1) - (finalMayorRachaGoleadora - inicioMayorRachaGoleadora);
    if (diff == 0) {
        numRepeticionesRachaGoleadora++;
    } else if (diff > 0) {
        inicioMayorRachaGoleadora = -1;
        finalMayorRachaGoleadora = finalRachaActual;
        numRepeticionesRachaGoleadora = 1;
    }
    
    cout << (finalMayorRachaGoleadora - inicioMayorRachaGoleadora) << " " << numRepeticionesRachaGoleadora << " " << (numDatos - finalMayorRachaGoleadora - 1) << endl;
}


//void resolverCaso(vector<int> datos, int numDatos) {
//    int mayorRachaGoleadora = 0, rachaGoleadoraActual = 0, numRepeticionesRachaGoleadora = 0, partidosDesdeLaUltimaRacha = 0;
//
//    for (int i = 0; i < numDatos; i++) {
//        if (datos[i] > 0) {
//            rachaGoleadoraActual++;
//        } else {
//            if (rachaGoleadoraActual > 0 && rachaGoleadoraActual == mayorRachaGoleadora) {
//                numRepeticionesRachaGoleadora++;
//            }
//
//            if (rachaGoleadoraActual >= mayorRachaGoleadora) {
//                mayorRachaGoleadora = rachaGoleadoraActual;
//                numRepeticionesRachaGoleadora = 1;
//                partidosDesdeLaUltimaRacha = i;
//            }
//
//            rachaGoleadoraActual = 0;
//        }
//    }
//
//    if (datos[numDatos-1] > 0) {
//        if (rachaGoleadoraActual > 0 && rachaGoleadoraActual == mayorRachaGoleadora) {
//            numRepeticionesRachaGoleadora++;
//        }
//
//        if (rachaGoleadoraActual >= mayorRachaGoleadora) {
//            mayorRachaGoleadora = rachaGoleadoraActual;
//            numRepeticionesRachaGoleadora = 1;
//            partidosDesdeLaUltimaRacha = numDatos;
//        }
//
//
//        rachaGoleadoraActual = 0;
//    }
//
//    cout << mayorRachaGoleadora << " " << numRepeticionesRachaGoleadora << " " << (numDatos - partidosDesdeLaUltimaRacha) << endl;
//
//}
