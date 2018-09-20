//
//  main.cpp
//  Tema09-08
//
//  Created by Yhondri on 27/4/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include "List.h"
using namespace std;

void fillList(List<int> &list);

int main(int argc, const char * argv[]) {
    
    int numCasos = 0;
    cin >> numCasos;
    
    while (numCasos > 0) {
        List<int> arbinList = List<int>();
        
        numCasos--;
    }
    
   /** List<int> preOrderList = List<int>();
    List<int> inOrderList = List<int>();
    do {
        fillList(preOrderList);
        fillList(inOrderList);
        for (int i = 0; i < preOrderList.size(); i++) {
            cout << i << ": " << preOrderList.at(i) << endl;
        }
        
    } while (preOrderList.size() > 0 && inOrderList.size() > 0);
    cout << "Out " << preOrderList.size() << " -- " << inOrderList.size() << endl;*/
  
    return 0;
}

void fillList(List<int> &list) {
    int number = -1;
    do {
        if (number != -1) {
            list.push_back(number);
        }
        cin >> number;
    }while(number != -1);
}
