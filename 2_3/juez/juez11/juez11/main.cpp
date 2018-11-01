//
//  main.cpp
//  juez11
//
//  Created by Yhondri  on 29/10/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//class Llano {
//
//}

void leerDatos(vector<int> &datos, int numDatos);
void resolverProblema(vector<int> datos, int numDatos, int minValorLlano);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez11/juez11/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numDatos, minValorLlano;
    while (cin >> numDatos && cin >> minValorLlano) {
        
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);
        resolverProblema(datos, numDatos, minValorLlano);
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    int nuevoDato;
    for (int i = 0; i < numDatos; i++) {
        cin >> nuevoDato;
        datos[i] = nuevoDato;
    }
}


void resolverProblema(vector<int> datos, int numDatos, int minValorLlano) {
    
    vector<int> inicioDeLlanos; //Es el fin de cada llano de izquierda a derecha.
    int longitudLlanoActual = 1, llanoMasLargo = 0, valorMaximo = 0;
    
    for (int i = ((int)datos.size() - 1); i >= 0; i--) {
        
        if(datos[i] > valorMaximo) {
            valorMaximo = datos[i];
        }
        
        if (datos[i] >= valorMaximo) {
            if (datos[i] == datos[i-1]) {  //Sumamos longitud de llano
                longitudLlanoActual++;
            } else if (longitudLlanoActual >= minValorLlano) { //Tenemos un llano
                if (longitudLlanoActual > llanoMasLargo) {
                    llanoMasLargo = longitudLlanoActual;
                }
                
                int inicioDeLLano = ((int)datos.size()-1) - i;
                inicioDeLlanos.push_back(inicioDeLLano);
            } else {
                longitudLlanoActual = 1;
            }
        } else {
            longitudLlanoActual = 1;
        }
    }
    
    cout << llanoMasLargo << " " << inicioDeLlanos.size() << " ";
    
    for (int i = ((int)inicioDeLlanos.size() - 1); i >= 0; i--) {
        cout << inicioDeLlanos[i] << " ";
    }
    
    cout << endl;
}
