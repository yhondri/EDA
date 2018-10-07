//
//  main.cpp
//  aer_219
//
//  Created by Yhondri  on 7/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    //     ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
    //    ifstream in("/Users/yhondri/Documents/University/eda/2_3/aer_117/aer_117/casos"); //MacBook Pro;
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_219/aer_219/casos");  //Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numCasos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        int acumulador = 0, numBilletes;
        
        cin >> numBilletes;
        
        for (int i = 0; i < numBilletes; i++) {
            int nuevoNumeroLoteria;
            cin >> nuevoNumeroLoteria;
            
            if (nuevoNumeroLoteria%2 == 0) {
                acumulador++;
            }
        }
        
        cout << acumulador << "\n";
        
        numCasos--;
    }
    
    
//    //     para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
//
    return 0;
}
