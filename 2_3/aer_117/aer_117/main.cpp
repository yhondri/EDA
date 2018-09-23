//
//  main.cpp
//  aer_117
//
//  Created by Yhondri  on 23/9/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
   
//     ajustes para que cin extraiga directamente de un fichero
//    #ifndef DOMJUDGE
//    //    ifstream in("/Users/yhondri/Documents/University/eda/2_3/aer_117/aer_117/casos"); //MacBook Pro;
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_117/aer_117/casos");  //Mac Mini;
//        auto cinbuf = cin.rdbuf(in.rdbuf());
//    #endif
//
    int numCasos;
    cin >> numCasos;
    
    string nuevaPersona;
    cin.ignore();
    while (numCasos > 0) {
        getline(cin, nuevaPersona);
        // Find position of ':' using find()
        size_t pos = nuevaPersona.find(" ");
        
        cout << "Hola, " << nuevaPersona.substr(pos + 1) << ".\n";
        
        numCasos--;
    }
    
    // para dejar todo como estaba al principio
//    #ifndef DOMJUDGE
//        cin.rdbuf(cinbuf);
//        //    system("PAUSE");
//    #endif
////
    return 0;
}
