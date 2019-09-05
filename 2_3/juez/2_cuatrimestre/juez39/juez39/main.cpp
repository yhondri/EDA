//
//  main.cpp
//  juez39
//
//  Created by Yhondri on 24/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <list>
#include <stdexcept>
#include <sstream>      // std::stringstream

using namespace std;

#include "BookShop.h"

bool resuelveCaso();

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez39/juez39/casos");
    //    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez29/juez29/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

string readCommand(stringstream& ss) {
    string comando, titulo;
    ss >> titulo;
    while (ss >> comando) {
        titulo += " " + comando;
    }
    
    return titulo;
}

bool resuelveCaso() {
    int numOperaciones, numEjemplares;
    string orden, titulo;
    std::cin >> numOperaciones;
    
    if (!std::cin) {
        return false;
    }
    
    bookShop mBookShop;
    
    for (int i = 0; i < numOperaciones; i++) {
        cin >> orden;
        string s;

        try {
            if(orden == "nuevoLibro") {
                getline(cin, s);
                stringstream ss(s);
                ss >> numEjemplares;
                titulo = readCommand(ss);
                mBookShop.nuevoLibro(numEjemplares, titulo);
            } else if(orden == "comprar") {
                getline(cin, s);
                stringstream ss(s);
                titulo = readCommand(ss);
                mBookShop.comprar(titulo);
            } else if(orden == "estaLibro") {
                getline(cin, s);
                stringstream ss(s);
                titulo = readCommand(ss);
                if(mBookShop.estaLibro(titulo)) {
                    cout << "El libro " << titulo << " esta en el sistema" << "\n---\n";
                } else {
                    cout << "No existe el libro " << titulo << " en el sistema" << "\n---\n";
                }
            } else if(orden == "elimLibro") {
                getline(cin, s);
                stringstream ss(s);
                titulo = readCommand(ss);
                mBookShop.elimLibro(titulo);
            } else if(orden == "numEjemplares") {
                getline(cin, s);
                stringstream ss(s);
                titulo = readCommand(ss);
                try {
                    int numEjemplares = mBookShop.numEjemplares(titulo);
                    cout << "Existen " << numEjemplares << " ejemplares del libro " << titulo << "\n---\n";
                } catch (std::invalid_argument e) {
                    cout << "No existe el libro " << titulo << " en el sistema" << "\n---\n";
                }
            } else if(orden == "top10") {
                list<bookId> booksList = mBookShop.top10();
                int i = 0;
                for (auto it = booksList.rbegin(); it != booksList.rend() && i < 10; ++it, i++) {
                    cout << (*it) << "\n" ;
                }
//                for(auto libro : mBookShop.top10()) {
//                    cout << libro << "\n" ;
//                }
                
                cout << "---\n";
            }
        } catch (std::domain_error e) {
            cout << e.what() << "\n---\n";
        } catch (std::invalid_argument e) {
            cout << e.what() << "\n---\n";
        } catch (std::out_of_range e) {
            cout << e.what() << "\n---\n";
        }
    }
    
    cout << "------" << '\n';
    
    return true;
}
