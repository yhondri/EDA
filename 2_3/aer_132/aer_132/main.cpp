//
//  main.cpp
//  aer_132
//
//  Created by Yhondri Josué Acosta Novas on 11/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {

    // //        ajustes para que cin extraiga directamente de un fichero
//    #ifndef DOMJUDGE
////        ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_132/aer_132/casos"); //MacBook Pro;
//                    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_132/aer_132/casos");//Mac Mini;
//        auto cinbuf = cin.rdbuf(in.rdbuf());
//    #endif

    string frase, temp;
    while (getline(cin, frase)) {
        int longitudFrase = (int)frase.size();
        int cadenasSeguidas[longitudFrase];
        cadenasSeguidas[0] = 0;
        
        for (int i = 1; i < longitudFrase; ++i) {
            if (frase[i] == frase[i-1]) {
                cadenasSeguidas[i] = cadenasSeguidas[i-1];
            } else {
                cadenasSeguidas[i] = i;
            }
        }
        
        int numCasos;
        cin >> numCasos;
//        scanf("%d", &numCasos);

        if (numCasos==0) {
            return 0;
        }
        
        while (numCasos > 0) {
            int posicionInicio, posicionFinal;
            cin >> posicionInicio >> posicionFinal;
//            scanf("%d%d\n", &posicionInicio, &posicionFinal);
            if (posicionInicio > posicionFinal) {
                swap(posicionInicio, posicionFinal);
            }
            
            if (cadenasSeguidas[posicionFinal] <= posicionInicio) {
                cout << "SI\n";
            } else {
                cout << "NO\n";
            }
            
            numCasos--;
        }
        cout << "\n";
        getline(cin, temp);
    }
//
//    #ifndef DOMJUDGE
//        cin.rdbuf(cinbuf);
//        //    system("PAUSE");
//    #endif
}

