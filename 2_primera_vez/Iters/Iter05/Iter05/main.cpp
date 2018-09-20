//
//  main.cpp
//  Iter05
//
//  Created by Yhondri on 5/2/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    bool seguir = true;
    int value = 0;
    int acumulador = 0;
    while (seguir) {
        while (cin >> value && value != 0){
            acumulador += value;
            cout << acumulador << " ";
        }
        if (acumulador == 0) {
            seguir = false;
        }
        cout << endl;
        acumulador = 0;
    }
    return 0;
}
