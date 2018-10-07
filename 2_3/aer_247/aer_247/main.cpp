//
//  main.cpp
//  aer_247
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
//        ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_247/aer_247/casos");//Mac Mini;
//        auto cinbuf = cin.rdbuf(in.rdbuf());
//    #endif
    
    int numCasos;
    cin >> numCasos;

    while (numCasos > 0) {
        
        int annoAnterior = 0, annoActual = 0;
        bool saliendoDeLaCrisis = true;
        cin >> annoAnterior;
        
        for (int i = 1 ; i < numCasos; i++) {
            cin >> annoActual;
            
            if (annoActual <= annoAnterior) {
                saliendoDeLaCrisis = false;
            }
            
            annoAnterior = annoActual;
        }
        
        if (saliendoDeLaCrisis) {
            cout << "SI\n";
        } else {
            cout << "NO\n";
        }
        
        cin >> numCasos;
    }
    

//    #ifndef DOMJUDGE
//        cin.rdbuf(cinbuf);
//        //    system("PAUSE");
//    #endif
    
    return 0;
}
