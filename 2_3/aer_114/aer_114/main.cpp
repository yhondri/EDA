//
//  main.cpp
//  aer_114
//
//  Created by Yhondri Josué Acosta Novas on 20/09/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {

    // ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/University/eda/2_3/aer_114/aer_114/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numCasos = 0;
    cin >> numCasos;

    while (numCasos > 0) {
        int num;
        cin >> num;

        switch (num) {
            case 0:
                cout << 1 << "\n";
                break;
            case 1:
                cout << 1 << "\n";
                break;
            case 2:
                cout << 2 << "\n";
                break;
            case 3:
                cout << 6 << "\n";
                break;
            case 4:
                cout << 4 << "\n";
                break;
            default:
                cout << 0 << "\n";
                break;
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
