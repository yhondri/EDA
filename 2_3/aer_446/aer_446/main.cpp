//
//  main.cpp
//  aer_446
//
//  Created by Yhondri Josué Acosta Novas on 12/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

template <size_t N>
void splitString(string (&arr)[N], string str)
{
    int n = 0;
    istringstream iss(str);
    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
        arr[n] = *it;
}

int main(int argc, const char * argv[]) {

    // //        ajustes para que cin extraiga directamente de un fichero
//    #ifndef DOMJUDGE
//        ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_446/aer_446/casos"); //MacBook Pro;
//        //    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_172/aer_172/casos");//Mac Mini;
//        auto cinbuf = cin.rdbuf(in.rdbuf());
//    #endif

    int numCasos;
    cin >> numCasos;

    while (numCasos > 0) {
        string nombreNieto;
        cin >> nombreNieto;
        
        int numNombreNietos, numNombresDichos = 0, numNietosBackup;
        cin >> numNombreNietos;
        numNietosBackup = numNombreNietos;

        bool esVerdadera = true;

        while (numNombreNietos > 0) {
            string nombreNietoInventado;
            cin >> nombreNietoInventado;
            numNombreNietos--;

            if ((nombreNieto == nombreNietoInventado)) {
                if (numNietosBackup == 1 || (numNombreNietos != 0)) {
                    esVerdadera = false;
                }
            } else if(numNombreNietos == 0) {
                esVerdadera = false;
            }

            numNombresDichos++;
        }

        if (esVerdadera) {
            cout << "VERDADERA" << endl;
        } else {
            cout << "FALSA" << endl;
        }

        numCasos--;
    }

    //
//    #ifndef DOMJUDGE
//        cin.rdbuf(cinbuf);
//        //    system("PAUSE");
//    #endif

    return 0;
}
