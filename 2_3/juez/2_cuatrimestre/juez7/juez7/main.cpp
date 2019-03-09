//
//  main.cpp
//  juez7
//
//  Created by Yhondri Josué Acosta Novas on 04/03/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "stack_eda.h"

using namespace std;

bool resuelveCaso();

int main(int argc, const char * argv[]) {

    //ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez7/juez7/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}

bool resuelveCaso() {
    int numNephews;
    cin >> numNephews;

    if(!cin) {
        return false;
    }

    stack<int> nephews;

    for (int i = 0; i < numNephews; i++) {
        int nephew;
        cin >> nephew;
        nephews.push(nephew);
    }

    int mejorMediano = -1, elem = -1;
    while (!nephews.empty()) {
        elem = nephews.top();
        nephews.pop();
        if (elem > mejorMediano) {
            while (!nephews.empty() && nephews.top() < elem) {
                mejorMediano = nephews.top();
                nephews.pop();
            }
//            nephews.push(elem);
        } else {
            if(elem < mejorMediano) {

            } else {

            }
        }

    }
    return true;
}
