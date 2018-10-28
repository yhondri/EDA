//
//  main.cpp
//  juez_5
//
//  Created by Yhondri Josué Acosta Novas on 23/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

//Posición más a la derecha que cumple la condición.
//0 1 0 1 0 1 0 0
//N N N N N S ----> S es la posición correcta en este caso.

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
int problema5(vector<int> datos, int numDatos);
void resuelveCaso();

int main(int argc, const char * argv[]) {
    //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez5/juez_5/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numCasos, numDatos;
    cin >> numCasos;
    while (numCasos > 0) {
        cin >> numDatos;
        
        vector<int> datos;
        leerDatos(datos, numDatos);

        cout << problema5(datos, numDatos) << endl;
        
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

int problema5(vector<int> datos, int numDatos) {
    int contadorDeCeros = 0, contadorDeUnos = 0, resultado = -1;
    
    for (int i = 0; i < numDatos; i++) {
        if (datos[i] == 0) {
            contadorDeCeros++;
        } else if(datos[i] == 1) {
            contadorDeUnos++;
        }
        
        if (contadorDeCeros == contadorDeUnos) {
            resultado = i;
        }
    }
    
    return resultado;
}


void resuelveCaso() {

    int p = -1, contadorDeCeros = 0, contadorDeUnos = 0, numValores;
    cin >> numValores;

    for (int i = 0; i < numValores; i++) {
        int nuevoValor;
        cin >> nuevoValor;

        if (nuevoValor == 0) {
            contadorDeCeros++;
        } else if(nuevoValor == 1) {
            contadorDeUnos++;
        }

        if (contadorDeCeros == contadorDeUnos) {
            p = i;
        }
    }

    cout << p << endl;
}
