//
//  main.cpp
//  aer_171
//
//  Created by Yhondri  on 23/9/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    //     ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    //    ifstream in("/Users/yhondri/Documents/University/eda/2_3/aer_117/aer_117/casos"); //MacBook Pro;
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_171/aer_171/casos");  //Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    size_t recorrido, numMountains;
    while (cin >> numMountains && numMountains > 0) {
        
        recorrido = numMountains;
        stack <int> mountainsStack;
        stack <int> abadiasStack;
        
        while (numMountains > 0) {
            int height;
            cin >> height;
            mountainsStack.push(height);
            numMountains--;
        }
        
        numMountains = recorrido;
        
        int maximo = 0;
        while (recorrido > 0) {
            int currentMountaint = mountainsStack.top();
            
            if (currentMountaint <= maximo) {
                numMountains--;
            } else {
                maximo = currentMountaint;
            }
            
            mountainsStack.pop();
            
            recorrido--;
        }
        
        cout << numMountains << "\n";
    }
    
    // para dejar todo como estaba al principio
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    return 0;
}
