//
//  main.cpp
//  aer_376
//
//  Created by Yhondri Josué Acosta Novas on 16/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {

    //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_376/aer_376/casos"); //MacBook Pro;
//    //                        ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_132/aer_132/casos");//Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif


    int numAlturas;

    while (cin >> numAlturas && numAlturas > 0) {
        vector<int> values;
        int nuevaAltura, numPicos = 0;

        for (int i = 0; i < numAlturas; i++) {
            cin >> nuevaAltura;
            values.push_back(nuevaAltura);
        }

        if (values[0] > values[1] && values[0] > values[values.size()-1]) {
            numPicos++;
        } else if (values[values.size()-1] > values[values.size()-2] && values[values.size()-1] > values[0]) {
            numPicos++;
        }

        for (int i = 1; i < values.size()-1; i++) {
            if (values[i] > values[i+1] && values[i] > values[i-1]) {
                numPicos++;
            }
        }

        cout << numPicos << endl;
    }



//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif

    return 0;
}
