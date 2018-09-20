//
//  main.cpp
//  Tema8_03
//
//  Created by Yhondri on 24/6/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include "List.h"

using namespace std;

void reordenarLista(List<int>& sortedList);

int main(int argc, const char * argv[]) {
    
    int numCasos = 0;
    cin >> numCasos;
    
    while (numCasos > 0) {
        List<int> sortedList;
        int nuevoValor;
        while ((cin >> nuevoValor) && nuevoValor != -1) {
            sortedList.push_back(nuevoValor);
        }
        if (!sortedList.empty()) {
            reordenarLista(sortedList);
        }
        numCasos--;
    }
    return 0;
}

void reordenarLista(List<int>& sortedList) {
    List<int>::Iterator iterator = sortedList.begin();
    int anterior = sortedList.front();
    while (iterator != sortedList.end()) {
        if (iterator.elem() < anterior) {
            iterator = sortedList.erase(iterator);
        }else {
            anterior = iterator.elem();
            iterator.next();
        }
    }
    iterator = sortedList.begin();
    while (iterator != sortedList.end()) {
        cout << iterator.elem() << " ";
        iterator.next();
    }
    cout << endl;
}
