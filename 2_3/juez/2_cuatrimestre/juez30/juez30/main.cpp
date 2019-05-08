//
//  main.cpp
//  juez30
//
//  Created by Yhondri on 30/04/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

// Yhondri Josué Acosta Novas

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "treemap_eda.h"
#include <list>

using namespace std;

map<string, int> leerDatos() {
    string line, clave;
    int value;
    map<string, int> datos;
    
    getline(cin, line);
    istringstream iss(line);
    
    while ( iss >> clave && iss >> value) {
        datos[clave] = value;
    }
    
    return datos;
}

/**
 Al ser una implementación mediante Treemap, los valores que contienen están ordenados.
 */
void resolverCaso(map<string, int> originalMap) {
    vector<string> nuevasClaves;
    vector<string> clavesEliminadas;
    vector<string> clavesValorCambiado;
    
    map<string, list<string>> result;
    
    string line, clave;
    int value;
    
    getline(cin, line);
    istringstream iss(line);
    
    while (iss >> clave && iss >> value) {
        if (originalMap.find(clave) == originalMap.end()) { // Nueva clave
            result["+"].push_back(clave);
        } else if(originalMap.find(clave) != originalMap.end()) { // Clave encontrada)
            if (originalMap[clave] != value) {
                result["*"].push_back(clave);
            }
            
            originalMap.erase(clave);
        }
    }
    
    for (auto mapKey : originalMap) {
        result["-"].push_back(mapKey.clave);
    }
    
   /** auto itOriginal = originalMap.cbegin(), end_m1 = originalMap.cend(),
    itUpdated = updatedMap.cbegin(), end_m2 = updatedMap.cend();
    
    while(itOriginal != end_m1 && itUpdated != end_m2) {
        if (updatedMap.find(itOriginal->clave) != updatedMap.end()) { // Clave encontrada
            if (updatedMap[itOriginal->clave] != originalMap[itOriginal->clave]) {
                clavesValorCambiado.push_back(itOriginal->clave);
            }
            
            ++itUpdated;
        } else {
            clavesEliminadas.push_back(itOriginal->clave);
        }
        
        ++itOriginal;
    }
    
    while (itOriginal != end_m1) {
        clavesEliminadas.push_back(itOriginal->clave);
        ++itOriginal;
    }
    
    while (itUpdated != end_m2) {
        nuevasClaves.push_back(itUpdated->clave);
        ++itUpdated;
    }
    */
    result["+"].sort();
    result["-"].sort();
    result["*"].sort();

    if (result["+"].size() > 0) {
        cout << "+ ";
        
        for (auto value : result["+"]) {
            cout << value << " ";
        }
        
        cout << "\n";
    }
    
    if (result["-"].size() > 0) {
        cout << "- ";
        
        for (auto value : result["-"]) {
            cout << value << " ";
        }
        
        cout << "\n";
    }
    
    if (result["*"].size() > 0) {
        cout << "* ";
        
        for (auto value : result["*"]) {
            cout << value << " ";
        }
        
        cout << "\n";
    }
    if (result["+"].size() == 0 && result["-"].size() == 0 && result["*"].size() == 0) {
        cout << "Sin cambios\n";
    }
    
    cout << "----\n";
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez30/juez30/casos");
    //    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez29/juez29/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos;
    cin >> numCasos;
    string temp;
    getline(cin, temp); //Para limpiar la primera línea.
    
    while (numCasos > 0) {
        map<string, int> originalMap = leerDatos();
        
        resolverCaso(originalMap);
        
        numCasos--;
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
