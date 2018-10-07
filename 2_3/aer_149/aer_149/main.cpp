//
//  main.cpp
//  aer_149
//
//  Created by Yhondri  on 7/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    //     ajustes para que cin extraiga directamente de un fichero
//    #ifndef DOMJUDGE
//    //        ifstream in("/Users/yhondri/Documents/University/eda/2_3/aer_117/aer_117/casos"); //MacBook Pro;
//        ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_149/aer_149/casos");  //Mac Mini;
//        auto cinbuf = cin.rdbuf(in.rdbuf());
//    #endif
    
    int numToros;
    while (cin >> numToros) {
        int maximo = 0, nuevoToro;
        for (int i = 0; i < numToros; i++) {
            cin >> nuevoToro;
            
            if (nuevoToro > maximo) {
                maximo = nuevoToro;
            }
        }
        
        cout << maximo << "\n";
    }
    
    // para dejar todo como estaba al principio
//    #ifndef DOMJUDGE
//        cin.rdbuf(cinbuf);
//        //    system("PAUSE");
//    #endif

    return 0;
}
