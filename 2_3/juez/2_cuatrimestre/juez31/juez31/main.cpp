//
//  main.cpp
//  juez31
//
//  Created by Yhondri on 05/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

void toLower(string &word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
}

bool resolverCaso() {
    int numLineas;
    cin >> numLineas;
    
    if (!cin || numLineas == 0) {
        return false;
    }
    
    string temp;
    getline(cin, temp); //Para limpiar la primera línea.
    
    
    string line, clave;
    map<string, set<int>> palabras;
    
    for(int i = 1; i <= numLineas; i++) {
        getline(cin, line);
        istringstream iss(line);
        
        while (iss >> clave) {
            if (clave.length() > 2) {
                
                toLower(clave);
                
                palabras[clave].insert(i);
            }
        }
    }
    
    for(const auto& value : palabras) {
        cout << value.first;
        
        for (int page : value.second) {
            cout << " " << page;
        }
        
        cout << "\n";
    }
    
    cout << "----\n";
    
    //Limpiamos última línea.
    //    cin >> numLineas;
    getline(cin, temp);
    
    return true;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE

    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez31/juez31/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
////
    while (resolverCaso()) {}
////
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
//        system("PAUSE");
#endif
    
    return 0;
}
