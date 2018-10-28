//
//  main.cpp
//  juez3
//
//  Created by Yhondri  on 28/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
bool problema3(vector<int> datos, int p);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez3/juez3/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numCasos, numDatos, p;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numDatos >> p;
        
        vector<int> datos;
        leerDatos(datos, numDatos);
        
        if (problema3(datos, p)) {
            cout << "SI" << endl;
        } else {
            cout << "NO" << endl;
        }
        
        numCasos--;
    }
    
    
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    
    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    int nuevoDato;
    for (int i = 0; i < numDatos; i++) {
        cin >> nuevoDato;
        datos.push_back(nuevoDato);
    }
}

bool problema3(vector<int> datos, int p) {
    bool seguir = true;
    int maximoDeU = datos[0];
    
    for (int i = 0; i < datos.size() && seguir; i++) {
        if (i <= p && maximoDeU < datos[i]) {
            maximoDeU = datos[i];
        } else if (i > p && maximoDeU >= datos[i]) {
            seguir = false;
        }
    }
    
    return seguir;
}
