//
//  main.cpp
//  aer_158
//
//  Created by Yhondri  on 12/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    //        ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_132/aer_132/casos"); //MacBook Pro;
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_158/aer_158/casos");//Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numCasos;
//    scanf("%d", &numCasos);
    cin >> numCasos;
    
    while (numCasos > 0) {
        long long numMuros, muroInicial, saltosHaciaArriba = 0, saltosHaciaAbajo = 0;
        cin >> numMuros >> muroInicial;
        numMuros -= 1;
        
        while (numMuros > 0) {
            int siguienteMuro;
            cin >> siguienteMuro;
            
            if (muroInicial > siguienteMuro) {
                saltosHaciaAbajo++;
            } else if (muroInicial < siguienteMuro) {
                saltosHaciaArriba++;
            }
            
            muroInicial = siguienteMuro;
            
            numMuros--;
        }
        
        cout << saltosHaciaArriba << " " << saltosHaciaAbajo << endl;
        
        numCasos--;
    }
    
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    return 0;
}
