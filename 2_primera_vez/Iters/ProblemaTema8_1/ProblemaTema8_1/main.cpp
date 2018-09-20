//
//  main.cpp
//  ProblemaTema8_1
//
//  Created by Yhondri on 23/6/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

void checkData(stack<char> pilaCaracteres);

int main(int argc, const char * argv[]) {
    
    string cadena;

    while (getline(cin, cadena) && cadena != ".") {
        stack<char> pilaCaracteres;
        bool result = true;
        
        for (int i = 0; i < (int)cadena.length() && result == true; i++) {
            char caracter = cadena.at(i);
            if (caracter == '(' ||
                caracter == '{' ||
                caracter == '['){
                pilaCaracteres.push(caracter);
            }else if (caracter == ')' ||
                      caracter == '}' ||
                      caracter == ']'){
                if (!pilaCaracteres.empty()) {
                    if (caracter == ')') {
                        if (pilaCaracteres.top() == '(') {
                            pilaCaracteres.pop();
                        }else {
                            result = false;
                        }
                    }else if (caracter == '}') {
                        if (pilaCaracteres.top() == '{') {
                            pilaCaracteres.pop();
                        }else {
                            result = false;
                        }
                    }else if (caracter == ']') {
                        if (pilaCaracteres.top() == '[') {
                            pilaCaracteres.pop();
                        }else {
                            result = false;
                        }
                    }
                }else {
                    result = false;
                }
            }
        }
        if (result) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

void checkData(stack<char> pilaCaracteres) {
    while (!pilaCaracteres.empty()) {
        cout << pilaCaracteres.top() << endl;
        pilaCaracteres.pop();
    }
    cout << "--------" << endl;
}
