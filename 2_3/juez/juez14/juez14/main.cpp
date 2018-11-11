//
//  main.cpp
//  juez14
//
//  Created by Yhondri Josué Acosta Novas on 06/11/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

int findMin(vector<int> datos, int i);
int findMin(vector<int>datos, int indiceInicio, int indiceFinal);

int findMin(vector<int> datos) {
   return findMin(datos, 0, (int)datos.size()-1);
}

int findMin(vector<int>datos, int indiceInicio, int indiceFinal) {
    int index = abs(indiceInicio+indiceFinal)/2;
    if(index-1 >= 0 && datos[index-1] < datos[index]) {
        if (index-1 == 0) {
            return datos[index-1];
        }
        return findMin(datos, indiceInicio, index); //Hacía la izquierda.
    } else if(index+1 < datos.size() && datos[index+1] < datos[index]) {
        if (index+1 == datos.size()-1) {
            return datos[index+1];
        }
        return findMin(datos, index, indiceFinal); //Hacía la derecha.
    }
    
    return datos[index];
}

//int findMin(vector<int>datos, int indiceInicio, int indiceFinal) {
//    if(indiceFinal-1 >= 0 && datos[indiceFinal-1] < datos[indiceFinal]) {
//        return findMin(datos, 0, indiceFinal/2);
//    } else if(indiceFinal+1 < datos.size() && datos[indiceFinal+1] < datos[indiceFinal]) {
//        return findMin(datos, indiceFinal, (int)datos.size()-1);
//    }
//
//    return datos[indiceFinal];
//}


//int findMin(vector<int>datos, int i) {
//    if(i-1 >= 0 && datos[i-1] < datos[i]) {
//        return findMin(datos, i-1);
//    } else if(i+1 < datos.size() && datos[i+1] < datos[i]) {
//        return findMin(datos, i+1);
//    }
//    return datos[i];
//
//}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez10/juez10/casos");
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez14/juez14/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numDatos, numCasos;
    cin >> numCasos;
    
    while (numCasos > 0) {
        cin >> numDatos;

        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);
        
        int minFound = findMin(datos);
        
        cout << minFound << endl;
        
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
