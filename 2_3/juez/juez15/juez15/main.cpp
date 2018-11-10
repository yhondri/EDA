//
//  main.cpp
//  juez15
//
//  Created by Yhondri  on 10/11/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<char> leerDatos();
char presoFugado(vector<char> datos, char presoInicial, char presoFinal);
char presoFugado(vector<char> presos, char presoInicial, char presoFinal, int indiceInicio, int indiceFinal);

char presoFugado(vector<char> presos, char presoInicial, char presoFinal, int i) {
    char idFugado;
    
    if (presos[0] != presoInicial) {
        idFugado = presoInicial;
    } else if(presos[presos.size()-1] != presoFinal) {
        idFugado = presoFinal;
    } else if (presos[i+1] - presos[i] > 1) {
        idFugado = (char) (presos[i]+1);
    } else {
        idFugado = presoFugado(presos, presoInicial, presoFinal, i+1);
    }
    
    return idFugado;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez15/juez15/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCasos;
    cin >> numCasos;
    string temp;
    getline(cin, temp);
    while (numCasos) {
        
        string fugados;
        getline(cin, fugados);
        
        char letraInicial = fugados[0];
        char letraFinal = ' ';
        
        if (fugados.size() > 2) {
            letraFinal = fugados[2]; //Puede que solo haya 1 preso;
        }
        
        vector<char> presos = leerDatos();
        
        cout << presoFugado(presos, letraInicial, letraFinal, 0) << endl;
        
        numCasos--;
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

vector<char> leerDatos() {
    string fugados;
    getline(cin, fugados);
    vector<char>datos;
    
    for (int i = 0; i < fugados.size(); i++) {
        if (fugados[i] != ' ') {
            datos.push_back(fugados[i]);
        }
    }
    
    return datos;
}


char presoFugado(vector<char> datos, char presoInicial, char presoFinal) {
    return presoFugado(datos, presoInicial, presoFinal, 0, (int)datos.size()-1);
}

/*
 Búsqueda binaria.
 Cogemos un punto medio del array. Y comprobamos ese punto intermedio con la posición inicial y final del array.
 Si la diferencia entre punto inicial || punto final con el punto intermedio es > 1, quiere decir que la letra que nos falta está:
 - En el lado derecho sí: array[puntoMedio] - array[puntoInicial] > 1.
 - En el lado izquierdo sí: array[puntoFinal] - array[puntoMedio] > 1.
 
 Esto es porque:
 a e
 a b c e

 Cogemos punto intermedio b, a - b = 1..... e - b > 1... Quiere decir que la letra que buscamos está hacía la derecha, y así.
 
 Como ejemplo...
 Letra inicial a, Letra Final e, y te dan un array de 4 letras...(tendría que ser un array de 5 letras, a b c d e).

**/
char presoFugado(vector<char> presos, char presoInicial, char presoFinal, int indiceInicio, int indiceFinal) {
    if (presos[0] != presoInicial) {
        return presoInicial;
    } else if(presos[presos.size()-1] != presoFinal) {
        return presoFinal;
    }
    
    
    int index = (indiceInicio+indiceFinal)/2;
    if(index-1 >= 0 && ((presos[index] - presos[indiceInicio]) > 1)) {
        return presoFugado(presos, presoInicial, presoFinal, indiceInicio, index); //Hacía la izquierda.
    } else if(index+1 < presos.size() && ((presos[indiceFinal] - presos[index]) > 1)) {
        return presoFugado(presos, presoInicial, presoFinal, index, indiceFinal); //Hacía la derecha.
    }
    
    return presos[index];
}
