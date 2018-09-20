//
//  main.cpp
//  DyV01
//
//  Created by Yhondri on 8/2/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>

// DyV01.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include <string>
using namespace std;

char encontrarPreso(char presos[], int n, int preso);

int main() {
    int numCasos = 0;
//    cout << "Introduce el número de casos: " << endl;
    cin >> numCasos;
    while (numCasos > 0) {
        string presos;
//        cout << "Introduce presos Inicial y final" << endl;
        char presoInicial;
        char presoFinal;
        cin >> presoInicial;
        cin >> presoFinal;
        int n = presoFinal - presoInicial;
//        cout << "Introduce presos econtrados" << endl;
        char* presosPresentes = new char[n];
        for (int i = 0; i < n; i++) {
            cin >> presosPresentes[i];
        }
        
        if (presosPresentes[0] != presoInicial){
            cout << presoInicial << endl;
        }
        else if (presosPresentes[n-1] != presoFinal)
        {
            cout << presoFinal << endl;
        }
        else {
            cout << encontrarPreso(presosPresentes, n, 0) << endl;
        }
        
        numCasos--;
    }
    return 0;
}

char encontrarPreso(char presos[], int n, int preso) {
    if ((presos[preso + 1] - presos[preso]) > 1){
        return (char)(presos[preso] + 1);
    }
    else {
        return encontrarPreso(presos, n, preso + 1);
    }
}
