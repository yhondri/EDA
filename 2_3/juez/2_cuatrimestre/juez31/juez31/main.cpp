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
#include <vector>
#include <algorithm>
#include "treemap_eda.h"

using namespace std;

void toLower(string &word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
}

bool resolverCaso() {
    
    int numLineas;
    cin >> numLineas;
    string temp;
    getline(cin, temp); //Para limpiar la primera línea.
    
    if (!cin) {
        return false;
    }
    
    string line, clave;
    map<string, vector<int>> palabras;
    
    int lineaActual = 1;
    
    while (numLineas > 0) {
        getline(cin, line);
        istringstream iss(line);
        
        while (iss >> clave) {
            if (clave.length() > 2) {
                
                toLower(clave);
                
                if (palabras.find(clave) == palabras.end()) { //insertamos la palabra por primera vez
                    palabras[clave].push_back(lineaActual);
                } else {
                    if(palabras[clave].back() != lineaActual) { //Solo metemos si ya no hemos metido la palabra en esta línea
                        palabras[clave].push_back(lineaActual);
                    }
                }
            }
        }
        
        lineaActual++;
        numLineas--;
    }
    
    //Limpiamos última línea.
    cin >> numLineas;
    getline(cin, temp);
    
    for(const auto& value : palabras) {
        cout << value.clave << " ";
        
        for (int page : value.valor) {
            cout << page << " ";
        }
        
        cout << "\n";
    }
    
    cout << "----" << "\n";
    
    return true;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez31/juez31/casos");
    //    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez29/juez29/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    while (resolverCaso()) {}
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
