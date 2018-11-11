//
//  main.cpp
//  juez16
//
//  Created by Yhondri  on 11/11/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);
int findNumATachar(vector<int>datos, int numCantado);
int findNumATachar(vector<int>datos, int numCantado, int indiceInicio, int indiceFinal);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez16/juez16/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        int numDatos, numCantado;
        cin >> numDatos >> numCantado;
        
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);
        
        int result = findNumATachar(datos, numCantado);
        if (result != - 1) {
            cout << result << endl;
        } else {
            cout << "NO" << endl;
        }
        
        numCasos--;
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

int findNumATachar(vector<int>datos, int numCantado) {
    if (numCantado == datos[0]) {
        return datos[0];
    } else if((datos.size()-1 + numCantado) ==  datos[datos.size()-1]) {
        return datos[datos.size()-1];
    }
    return findNumATachar(datos, numCantado, 0, (int)datos.size()-1);
}

/*
 Buscamos el número a través de búsqueda binaria.
 Caso especial:
 Si llegamos al extremo derecho, es decir, index == indiceFinal --> Quiere decir que ya hemos recorrido la mitad del array necesaria y por lo tanto el número buscado no existe.
 Si llegamos al extremo izquierdo, es decir, index == indiceInicio --> Quiere decir que ya hemos recorrido la mitad del array necesaria y por lo tanto el número buscado no existe.
*/
int findNumATachar(vector<int>datos, int numCantado, int indiceInicio, int indiceFinal) {
    int index = (indiceInicio+indiceFinal)/2;
    if ((index + numCantado) == datos[index]) {
        return datos[index];
    } else if((index + numCantado) < datos[index] && index != indiceFinal) { //Si el index coincide con el final, quiere decir que hemos llegado al extremo, por lo tanto el número q buscamos no existe.
        return findNumATachar(datos, numCantado, indiceInicio, index); //Hacía la izquierda.
    } else if((index + numCantado) > datos[index] && index != indiceInicio) {//Si el index coincide con el inicio, quiere decir que hemos llegado al extremo, por lo tanto el número q buscamos no existe.
        return findNumATachar(datos, numCantado, index, indiceFinal); //Hacía la derecha.
    }
    
    return -1;
}


