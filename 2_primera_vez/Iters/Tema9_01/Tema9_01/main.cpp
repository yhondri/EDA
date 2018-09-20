//
//  main.cpp
//  Tema9_01
//
//  Created by Yhondri on 24/6/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include "Arbin.h"
#include "List.h"

using namespace std;

void fillList(List<int> &arbinList);
Arbin<int> crearArbol(List<int> inOrden, List<int> preOrden);
Arbin<int> crearArbolAux(List<int> inOrden, List<int> preOrden, int inOrdenStart, int inOrdenEnd);

int main()
{
    List<int> listaPreorden;
    List<int> listaInorden;
    fillList(listaPreorden);
    fillList(listaInorden);
    
    while (!listaPreorden.empty() && !listaInorden.empty()) {
        
        Arbin<int> result = crearArbol(listaInorden, listaPreorden);
        List<int>::Iterator iterator = result.niveles()->begin();
        while (iterator != result.niveles()->end()) {
            cout << iterator.elem() << " ";
            iterator.next();
        }
        listaPreorden = List<int>();
        listaInorden = List<int>();
        fillList(listaPreorden);
        fillList(listaInorden);
    }
    
    return 0;
}


Arbin<int> crearArbol(List<int> inOrden, List<int> preOrden) {
    return crearArbolAux(inOrden, preOrden, 0, inOrden.size() - 1);
}

Arbin<int> crearArbolAux(List<int> inOrden, List<int> preOrden, int inOrdenStart, int inOrdenEnd) {
    
    static int preIndex = 0;
    
    if (inOrdenStart > inOrdenEnd) {
        return Arbin<int>();
    }
    
    if (inOrdenStart == inOrdenEnd) {
        return Arbin<int>(Arbin<int>(), preOrden.at(preIndex++), Arbin<int>());
    }
    
    int inOrdenValue = preOrden.at(preIndex++); //Probablemente se pueda mejorar utilizando iteradores.
    int inOrdenIndex;
    for (int i = inOrdenStart; i <= inOrdenEnd; i++) {
        if (inOrdenValue == inOrden.at(i)) {
            inOrdenIndex = i;
            break;
        }
    }
    
    Arbin<int> izquierdo = crearArbolAux(inOrden, preOrden, inOrdenStart, inOrdenIndex - 1);
    Arbin<int> derecho = crearArbolAux(inOrden, preOrden, inOrdenIndex + 1, inOrdenEnd);
    
    return Arbin<int>(izquierdo, inOrdenValue, derecho);
}

void fillList(List<int> &arbinList) {
    int num;
    while ((cin >> num) && num != -1) {
        arbinList.push_back(num);
    }
//    
//    for (int i = 0; i < arbinList.size(); i++) {
//        cout << arbinList.at(i) << " ";
//    }
//    cout << endl;
//    cout << "--------" << endl;
//    cout << endl;
//    cout << endl;
//    cout << endl;

}
