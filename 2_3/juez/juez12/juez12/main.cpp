//
//  main.cpp
//  juez12
//
//  Created by Yhondri  on 1/11/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <limits.h>

using namespace std;

void leerDatos(vector<int> &datos, int numValores);
void resolverProblema(vector<int> datos, int numValores);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez12/juez12/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numValores;
    while (cin >> numValores) {
        vector<int> datos(numValores);
        leerDatos(datos, numValores);
        
        resolverProblema(datos, numValores);
    }
    
    
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    
    return 0;
}


void leerDatos(vector<int> &datos, int numValores) {
    for (int i = 0; i < numValores; i++) {
        cin >> datos[i];
    }
}

void resolverProblema(vector<int> datos, int numValores) {
    int sumaActual = 0, sumaMayor = INT_MIN, diaInicio = 0, diaInicioTemp = 0, diaFin = 0, longitudSecuenciaMayor = 0;
    
    for (int i = 0; i < numValores; i++) {
        sumaActual += datos[i];
        
        if (sumaMayor < sumaActual) {
            sumaMayor = sumaActual;
            diaInicio = diaInicioTemp;
            diaFin = i;
            longitudSecuenciaMayor = abs(diaInicio - diaFin)+1;
        } else if(sumaMayor == sumaActual && longitudSecuenciaMayor > (abs(diaInicioTemp - i)+1)) { //Para quedarnos con el subvector de menor longitud. 
            sumaMayor = sumaActual;
            diaInicio = diaInicioTemp;
            diaFin = i;
            longitudSecuenciaMayor = abs(diaInicio - diaFin)+1;
        }
        
        if (sumaActual <= 0) {
            sumaActual = 0;
            diaInicioTemp = i + 1;
        }
    }
    
    cout << sumaMayor << " " << diaInicio << " " << abs(diaInicio - diaFin)+1 << endl;
}
