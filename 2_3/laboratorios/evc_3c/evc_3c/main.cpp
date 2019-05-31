//
//  main.cpp
//  evc_3c
//
//  Created by Yhondri on 30/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <list>
#include <sstream>      // std::stringstream

using namespace std;

using PalabraKey = string;

struct PalabraData {
    string key;
    int contador;
};

void resuelveCaso() {
    unordered_map<PalabraKey, PalabraData> palabraKeysMap;
    map<int, map<PalabraKey, list<int>>> palabrasContadorMap;
    
    string clave;
    int i = 1;
    while (cin >> clave && clave != "FIN") {
        int posicion = palabraKeysMap[clave].contador; //Inserta si no existe
        palabrasContadorMap[posicion].erase(clave);
        
        PalabraData& palabraData = palabraKeysMap[clave];
        palabraData.contador += 1;
        
        palabrasContadorMap[palabraData.contador][clave].push_back(i);
    }
    
//    for(auto it = palabrasContadorMap.rbegin(); i < 1; ++it, i++) {
//        auto result = it->second.rbegin();
//       for
//    }
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Downloads/evc_2f/evc_2f/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos;
    cin >> numCasos;
    
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
