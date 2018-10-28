//
//  main.cpp
//  juez_2
//
//  Created by Yhondri Josué Acosta Novas on 25/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int colones(int v[], int n);

int main(int argc, const char * argv[]) {
    //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez_2/juez_2/casos"); //MacBook Pro;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numCasos = 0;
    cin >> numCasos;
    while (numCasos > 0){
        int n = 0;
        cin >> n;
        int *v = new int[n];
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }

        cout << colones(v, n) << endl;

        numCasos--;
    }

//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    return 0;
}

int colones(int v[], int n) {
    int numColones = 0, min = v[n-1];
    for (int i = n-1; i > 0; i--) {
        if (v[i-1] > v[i] || min < v[i-1]) {
            numColones++;


            if (v[i] < min) {
                min = v[i];
            }
        }

    }

    return numColones;
}
