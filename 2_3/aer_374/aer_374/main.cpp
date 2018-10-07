//
//  main.cpp
//  aer_374
//
//  Created by Yhondri  on 7/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //     ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    //        ifstream in("/Users/yhondri/Documents/University/eda/2_3/aer_117/aer_117/casos"); //MacBook Pro;
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_374/aer_374/casos");  //Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numCasos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        
        unsigned long long tempMinima = 0, numVecesTempMinima = 0, tempMaxima = 0, numVecesTempMaxima = 0;
        unsigned long long nuevaTemp;
        cin >> nuevaTemp;
        
        while (nuevaTemp > 0) {
            if (nuevaTemp < tempMinima || tempMinima == 0) {
                tempMinima = nuevaTemp;
                numVecesTempMinima = 1;
            } else if (nuevaTemp == tempMinima) {
                numVecesTempMinima++;
            }
            
            if (nuevaTemp > tempMaxima) {
                tempMaxima = nuevaTemp;
                numVecesTempMaxima = 1;
            } else if (nuevaTemp == tempMaxima) {
                numVecesTempMaxima++;
            }
            
            cin >> nuevaTemp;
        }
        
        cout << tempMinima << " " << numVecesTempMinima << " " << tempMaxima << " " << numVecesTempMaxima << "\n";
        
        numCasos--;
    }
    
    
    // para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    
    return 0;
}
