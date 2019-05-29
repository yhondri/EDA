//
//  main.cpp
//  juez14
//
//  Created by Yhondri on 28/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "queue_eda.h"
#include "deque_eda.h"
#include <sstream>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void transformar(deque<char> mqueMitadInicial) {
    if (!mqueMitadInicial.empty()) {
        char letter2;
        char letter1 = mqueMitadInicial.front();
        mqueMitadInicial.pop_front();
        string frase = string(1, letter1);
        
        int i = 1;
        
        while(!mqueMitadInicial.empty()) {
            
            if (!mqueMitadInicial.empty()) {
                letter2 = mqueMitadInicial.front();
                mqueMitadInicial.pop_front();
                
                cout << letter1 << " - " << letter2 << endl;
                
                if (!isVowel(letter1) && !isVowel(letter2)) {
                    int tempi = i;
                    while ((!isVowel(letter1) && !isVowel(letter2))) {
                        char letterTemp = letter1;
                        letter1 = letter2;
                        letter2 = letterTemp;
                        
                        frase[tempi-1] = letter1;
                        frase += string(1, letter2);
                        letter1 = letter2;
                        
                        tempi--;
                    }
                } else {
                    frase += string(1, letter2);
                    letter1 = letter2;
                }
            }
            
            i++;
        }
        
        cout << frase;
    }
}

bool resuelveCaso() {
    
    string linea, s;
    getline(cin, s);
    
    if (!cin) {
        return false;
    }
    
    deque<char> mqueMitadInicial;
    deque<char> mqueMitadFinal;
    
    for(int i = 0; i < s.length(); i++) {
        if (i%2 == 0) {
            mqueMitadInicial.push_back(s[i]);
        } else {
            mqueMitadFinal.push_front(s[i]);
        }
    }
    
    transformar(mqueMitadInicial);
    transformar(mqueMitadFinal);
    
    cout << endl;
    
    return true;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez14/juez14/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso()) {}
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
