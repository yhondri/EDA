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


int buscarIz(vector<int> v ,int inicio, int fin, int altura) {
    int m ,pos ;

    if (inicio == fin + 1) {
        if (v[inicio] == altura) { pos = inicio; }
        else { pos = -1; }
    }
    else {
        m = (inicio + fin) / 2;
        if (v[m] < altura)
            pos = buscarIz(v, m + 1, fin, altura);
        else
            pos = buscarIz(v, inicio, m - 1, altura);
    }

    return pos;
}


int buscarDr(vector<int> v, int inicio, int fin, int altura) {
    int m, pos ;
    if (inicio == fin + 1) {
        if (v[inicio-1] == altura) { pos = inicio-1; }
        else { pos = -1; }
    }
    else {
        m = (inicio + fin) / 2;
        if (v[m] <= altura)
            pos = buscarDr(v, m + 1, fin, altura);
        else
            pos = buscarDr(v, inicio, m - 1, altura);
    }
    return pos;
}

void encontrarSospechoso(int length) {
    int altura;

    cin >> altura;
    vector <int> v(length);
    for (int i = 0; i < length; i++)
    {
        cin >> v[i];
    }
    int m = (length / 2);
    int posIz=1,posDr=-1;
    if (length != 0) {
        posIz = buscarIz(v, 0, m,altura);
        posDr = buscarDr(v, m+1, length-1, altura);
    }


    if (posIz >= m) posIz = -1;
    if (posDr < m) posDr = -1;

    if (posIz != -1) cout << posIz << " ";
    if (posDr != -1) cout << posDr;
    if(posIz != -1 || posDr != -1)cout << endl;
    if (posIz == -1 && posDr == -1) cout << "NO EXISTE" << endl;
}



int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez20/juez20/casos");
    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez20/juez20/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numDatos, alturaSospechoso;

    while (cin >> numDatos) {
        cin >> alturaSospechoso;
        encontrarSospechoso(numDatos);
//        vector<int> datos(numDatos);
//        leerDatos(datos, numDatos);
//
//        resolverCaso(datos, numDatos, alturaSospechoso);
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

/**
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
*/
