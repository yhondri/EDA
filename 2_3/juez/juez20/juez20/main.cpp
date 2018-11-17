//
//  main.cpp
//  juez20
//
//  Created by Yhondri Josué Acosta Novas on 15/11/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

void resolverCaso(vector<int> datos, int numDatos, int alturaSospechoso);
int buscarIz(vector<int>datos, int alturaSospechosho, int indice, int indiceFinal);
int buscarDr(vector<int>datos, int alturaSospechosho, int indice, int indiceFinal);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez20/juez20/casos");
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez20/juez20/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numDatos, alturaSospechoso;

    while (cin >> numDatos) {
        cin >> alturaSospechoso;
        
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);

        resolverCaso(datos, numDatos, alturaSospechoso);
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

void resolverCaso(vector<int> datos, int numDatos, int alturaSospechoso) {
    int posicionMitadIzquierda = -1, posicionMitadDerecha = -1;

    posicionMitadIzquierda = buscarIz(datos, alturaSospechoso, 0, numDatos-1);
    posicionMitadDerecha = buscarDr(datos, alturaSospechoso, 0, numDatos-1);
    
    if (posicionMitadIzquierda != -1) {
        cout << posicionMitadIzquierda;
    }
    if (posicionMitadIzquierda != posicionMitadDerecha) {
        
        if (posicionMitadDerecha != -1 && posicionMitadIzquierda != -1) {
            cout << " " << posicionMitadDerecha;
        } else if(posicionMitadDerecha != -1 && posicionMitadIzquierda == -1) {
            cout << posicionMitadDerecha;
        }
    }
    
    if (posicionMitadDerecha == -1 && posicionMitadIzquierda == -1) {
        cout << "NO EXISTE";
    }
    
    cout << endl;
}

int buscarIz(vector<int>datos, int alturaSospechosho, int indice, int indiceFinal) {
    if (indiceFinal >= indice) {
        int mitad = indice + ((indiceFinal-indice)/2);
        
        if ((mitad == 0 || alturaSospechosho > datos[mitad-1]) && datos[mitad] == alturaSospechosho) {
            return mitad;
        } else if(alturaSospechosho > datos[mitad]) {
            return buscarIz(datos, alturaSospechosho, mitad+1, indiceFinal); // Hacía la derecha
        } else {
            return buscarIz(datos, alturaSospechosho, indice, mitad-1); // Hacía la izquierda
        }
    }
    
    return -1;
}

int buscarDr(vector<int>datos, int alturaSospechosho, int indice, int indiceFinal) {
    if (indiceFinal >= indice) {
        int mitad = indice + ((indiceFinal-indice)/2);
        
        if ((mitad == ((int)datos.size()-1) || alturaSospechosho < datos[mitad+1]) && datos[mitad] == alturaSospechosho) {
            return mitad;
        } else if(alturaSospechosho < datos[mitad]) {
            return buscarDr(datos, alturaSospechosho, indice, mitad-1); // Hacía la izquierda
        } else {
            return buscarDr(datos, alturaSospechosho, mitad+1, indiceFinal); // Hacía la derecha
        }
    }
    
    return -1;
}
