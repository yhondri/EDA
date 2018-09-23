//
//  main.cpp
//  aer_368
//
//  Created by Yhondri  on 23/9/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //     ajustes para que cin extraiga directamente de un fichero
//        #ifndef DOMJUDGE
//        //    ifstream in("/Users/yhondri/Documents/University/eda/2_3/aer_117/aer_117/casos"); //MacBook Pro;
//        ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_368/aer_368/casos");  //Mac Mini;
//            auto cinbuf = cin.rdbuf(in.rdbuf());
//        #endif
    
    int numHuevos, capacidadOlla;
    cin >> numHuevos >> capacidadOlla;
    
    while (numHuevos > 0 && capacidadOlla > 0) {
        
        if (numHuevos <= capacidadOlla) {
            cout << "10\n";
        } else {
            int numMinutos = (int) numHuevos/capacidadOlla;
            if ((numHuevos%capacidadOlla) == 0) {
                cout << (numMinutos*10) << "\n";
            } else {
                cout << (numMinutos*10) + 10 << "\n";
            }
        }
        
        cin >> numHuevos >> capacidadOlla;
    }
    
    // para dejar todo como estaba al principio
//        #ifndef DOMJUDGE
//            cin.rdbuf(cinbuf);
//            //    system("PAUSE");
//        #endif
    
    return 0;
}
