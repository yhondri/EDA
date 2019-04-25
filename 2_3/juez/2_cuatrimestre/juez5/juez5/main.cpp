//
//  main.cpp
//  juez5
//
//  Created by Yhondri on 23/04/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "conjunto.h"
#include <sstream>

using namespace std;

bool resuelveCaso() {

    string caseType;
    getline(cin, caseType);
    
    if (!cin) {
        return false;
    }
    
    int numValues;
    cin >> numValues;
    
    if (caseType == "N") {
        set<int> values;
        values.setNumElemMaxAInsertar(numValues);
        
        int newValue;
        while (cin >> newValue && newValue != -1) {
            values.insertNewValueB(newValue);
        }
        
        string t;
        getline(cin,t);

        values.printB();

    } else {
        set<string> values;
        values.setNumElemMaxAInsertar(numValues);

        string t;
        getline(cin,t);
        getline(cin,t);

        istringstream iss(t);
        string word;
        while(iss >> word && word != "FIN") {
            values.insertNewValueB(word);
        }
        
        values.printB();
    }
    
    cout << "\n";
    
    return true;
}

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez5/juez5/casos");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso()) { }
    
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    return 0;
}
