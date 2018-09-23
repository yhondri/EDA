//
//  main.cpp
//  aer_242
//
//  Created by Yhondri  on 23/9/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    //     ajustes para que cin extraiga directamente de un fichero
//    #ifndef DOMJUDGE
//        //    ifstream in("/Users/yhondri/Documents/University/eda/2_3/aer_117/aer_117/casos"); //MacBook Pro;
//        ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_242/aer_242/casos");  //Mac Mini;
//        auto cinbuf = cin.rdbuf(in.rdbuf());
//    #endif
    
    unsigned long long entradas;
    while((cin >> entradas) && entradas > 0) {
        int* jugadores = new int[entradas];
        
        for (int i = 0; i < entradas; i++) {
            cin >> jugadores[i];
        }
        
        unsigned long long acumulador = 0, suma = 0;
        
        for (int i = 0; i < entradas; i++) {
            suma += jugadores[i];
        }
        
        for (int i = 1; i < entradas; i++) {
            suma -= jugadores[i - 1];
            acumulador += (suma * jugadores[i - 1]);
        }
        
        cout << acumulador << "\n";
        
        delete[] jugadores;
    }
    
    // para dejar todo como estaba al principio
//    #ifndef DOMJUDGE
//        cin.rdbuf(cinbuf);
//        //    system("PAUSE");
//    #endif
    return 0;
}
