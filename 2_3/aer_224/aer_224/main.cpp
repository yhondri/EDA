//
//  main.cpp
//  aer_224
//
//  Created by Yhondri Josué Acosta Novas on 16/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    //    ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_224/aer_224/casos"); //MacBook Pro;
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_224/aer_224/casos");//Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    
    long long numCortezas;
    
    while (cin >> numCortezas && numCortezas > 0) {
        long long nuevaCorteza;
        stack<long long> cortezas;
        
        for (int i = 0; i < numCortezas; i++) {
            cin >> nuevaCorteza;
            cortezas.push(nuevaCorteza);
        }
        
        long long cortezaMayor = 0, posicionCortezaMayor = 0, acumulador = 0;
        
        if (numCortezas > 1) {
            acumulador += cortezas.top();
            cortezas.pop();
        }
        for (int i = 1; i < numCortezas; i++) {
            long long valorActual = cortezas.top();
            
            if (valorActual == acumulador) {
                cortezaMayor = valorActual;
                posicionCortezaMayor = cortezas.size();
            }
            
            acumulador += valorActual;
            cortezas.pop();
        }
        
        if (cortezaMayor != 0) {
            cout << "SI " << posicionCortezaMayor << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    
    return 0;
}
