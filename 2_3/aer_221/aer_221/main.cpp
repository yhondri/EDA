//
//  main.cpp
//  aer_221
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
////        ifstream in("/Users/yhondri/Documents/University/eda/2_3/aer_117/aer_117/casos"); //MacBook Pro;
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_221/aer_221/casos");  //Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
//
    int numCasos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        bool par = false, correcto = true;
        int butacas = 0, fila = 0;
        cin >> butacas;
        
        for (int j = 0; j < butacas; j ++) {
            int x;
            cin >> x;
            if(x%2 == 0 && !par) {
                fila ++;
            }
            
            if(x%2 == 0 && par) {
                correcto = false;
            }
            
            if(x%2 != 0 && !par) {
                par = true;
            }
        }
        
        if(correcto) {
            cout << "SI " << fila<<"\n";
        } else {
            cout << "NO\n";
        }
        
        
        numCasos--;
    }
    
    // para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    
    return 0;
}
