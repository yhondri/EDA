//
//  main.cpp
//  juez6
//
//  Created by Yhondri Josué Acosta Novas on 03/03/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "stack_eda.h"

using namespace std;

bool resuelveCaso();

int main(int argc, const char * argv[]) {

    //ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez6/juez6/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}

const char LLAVE_ABIERTA = '{';
const char PARENTESIS_ABIERTO = '(';
const char CORCHETE_ABIERTO = '[';
const char LLAVE_CERRADA = '}';
const char PARENTESIS_CERRADO = ')';
const char CORCHETE_CERRADO = ']';

bool resuelveCaso() {
    stack<char> characterSequences;
    bool equilibrado = true, endProgram = false;

    string newLine;
    getline(cin, newLine);

    if(!cin) {
        endProgram = true;
    } else {
        for(char& newCharacter : newLine) {
            if (newCharacter == LLAVE_ABIERTA || newCharacter == PARENTESIS_ABIERTO || newCharacter == CORCHETE_ABIERTO) {
                characterSequences.push(newCharacter);
            }
            if (newCharacter == LLAVE_CERRADA || newCharacter == PARENTESIS_CERRADO || newCharacter == CORCHETE_CERRADO) {
                if (characterSequences.empty()) {
                    equilibrado = false;
                } else if (newCharacter == LLAVE_CERRADA && characterSequences.top() != LLAVE_ABIERTA) {
                    equilibrado = false;
                } else if (newCharacter == PARENTESIS_CERRADO && characterSequences.top() != PARENTESIS_ABIERTO) {
                    equilibrado = false;
                } else if (newCharacter == CORCHETE_CERRADO && characterSequences.top() != CORCHETE_ABIERTO) {
                    equilibrado = false;
                }

                if (!characterSequences.empty()) {
                    characterSequences.pop();
                }
            }
        }

        if (equilibrado && characterSequences.empty()) {
            cout << "SI\n";
        } else {
            cout << "NO\n";
        }
    }

    return !endProgram;
}
