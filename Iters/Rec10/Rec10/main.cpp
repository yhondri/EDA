//
//  main.cpp
//  Rec10
//
//  Created by Yhondri on 15/12/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

void fillArray(char* array[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }
}

int main(int argc, const char * argv[]) {
    int numCasos = 0;
    cin >> numCasos;
    int i = 0;
    
    while (i < numCasos) {
        string primeros;
        string presidiariosString;
        getline(cin, primeros);
        int n = primeros[1] - primeros[0];
        getline(cin, presidiariosString);
        char presidiarios[] = presidiariosString;
        i++;
    }
    
    return 0;
}

char presoFugado(string primeros, string todosLosPresidiarios) {
    char fugado;

    if (todosLosPresidiarios.length() >= 2) {
        if (primeros[0] == todosLosPresidiarios[0] && primeros[1] == todosLosPresidiarios[todosLosPresidiarios.length() - 1]) {

        }
    }else {
        if (primeros[0] != todosLosPresidiarios[0]) {
            fugado = primeros[0];
        }else {
            fugado = primeros[1];
        }
    }
    
    return fugado;
}

void presoFugado(char x1, int x1Position, string todosLosPresos) {
    char fugado;
    
    if ((todosLosPresos[x1Position+1] - x1) > 1) {
        fugado = todosLosPresos[x1Position+1] - x1;
    }else {
        
    }
    
}
