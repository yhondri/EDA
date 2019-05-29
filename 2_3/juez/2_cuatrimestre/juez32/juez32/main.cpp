//
//  main.cpp
//  juez32
//
//  Created by Yhondri on 30/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <list>

using namespace std;
using Deporte = string;

struct Alumno {
    list<string>:: iterator derporteIt;
};

bool resuelveCaso() {
    string value;
    cin >> value;
    
    if (!cin) {
        return false;
    }
    
    unordered_map<string, string> alumnosEliminados;
    unordered_map<Deporte, list<Alumno>> deportes;

    while (value != "_FIN_") {
        if (isupper(value[0])) {
            deportes[value];
        } else {
            
        }
        
        
        if (alumnosEliminados.count(<#const key_type &__k#>)) {
            <#statements#>
        }
        
        cin >> value;
    }
    
    
    return true;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez36/juez36/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    ////
    while(resuelveCaso()){}
    ////
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //        system("PAUSE");
#endif
    return 0;
}
