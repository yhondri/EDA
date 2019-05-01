//
//  main.cpp
//  juez30
//
//  Created by Yhondri on 30/04/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "treemap_eda.h"

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

void resolverCaso(map<string, int> originalMap, map<string, int> updatedMap) {
    vector<string> nuevasClaves;
    vector<string> clavesEliminadas;
    vector<string> clavesValorCambiado;
    
    auto itOriginal = originalMap.cbegin(), end_m1 = originalMap.cend(),
    itUpdated = updatedMap.cbegin(), end_m2 = updatedMap.cend();
    
    while(itOriginal != end_m1 && itUpdated != end_m2) {
        if (updatedMap.find(itOriginal->clave) == updatedMap.end()) { // Clave NO encontrada, entonces eliminada
            clavesEliminadas.push_back(itOriginal->clave);
        } else if (updatedMap.find(itOriginal->clave) != updatedMap.end()) { // Clave encontrada
            if (updatedMap[itOriginal->clave] != originalMap[itOriginal->clave]) {
                clavesValorCambiado.push_back(itOriginal->clave);
            }
            ++itUpdated;
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
    
    if (nuevasClaves.size() > 0) {
        cout << "+ ";
       
        for (auto value : nuevasClaves) {
            cout << value << " ";
        }
        
        cout << "\n";
    }
    
    if (clavesEliminadas.size() > 0) {
        cout << "- ";
        
        for (auto value : clavesEliminadas) {
            cout << value << " ";
        }
        
        cout << "\n";
    }
    
    if (clavesValorCambiado.size() > 0) {
        cout << "* ";
        
        for (auto value : clavesValorCambiado) {
            cout << value << " ";
        }
        
        cout << "\n";
    }
    
    if (nuevasClaves.size() == 0 && clavesEliminadas.size() == 0 && clavesValorCambiado.size() == 0) {
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
        map<string, int> updatedMap = leerDatos();

        resolverCaso(originalMap, updatedMap);
        
        numCasos--;
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
