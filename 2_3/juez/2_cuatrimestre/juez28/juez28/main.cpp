//
//  main.cpp
//  juez28
//
//  Created by Yhondri  on 9/4/19.
//  Copyright © 2019 Yhondri . All rights reserved.
//

// Alumno: Yhondri Josué Acosta Novas

#include <iostream>
#include <fstream>
#include "treemap_eda.h"

using namespace std;

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez28/juez28/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numAlumnos;
    
    while (cin >> numAlumnos && numAlumnos > 0) {
        string temp;
        getline(cin, temp);
        
        map<string, int> alumnosMap;

        while (numAlumnos > 0) {
            string nombreAlumno, resultado;
            getline(cin, nombreAlumno);
            getline(cin, resultado);

            if (resultado == "CORRECTO") {
                alumnosMap[nombreAlumno] += 1;
            } else {
                alumnosMap[nombreAlumno] -= 1;
            }
          
            numAlumnos--;
        }
        
        for (const auto &p : alumnosMap) {
            if (p.valor != 0) {
                cout << p.clave << ", " << p.valor << std::endl;
            }
        }
        
        cout << "---\n";
    }
    
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
