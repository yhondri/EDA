//
//  main.cpp
//  DyV02
//
//  Created by Yhondri on 8/2/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int elevarNumero(int base, int exponente);

int main()
{
    int base;
    int exponente;
    
    cin >> base;
    cin >> exponente;
    while (base != 0 && exponente != 0){
        cout << elevarNumero(base % 31543, exponente) << endl;
        cin >> base;
        cin >> exponente;
    }
    return 0;
}

int elevarNumero(int base, int exponente) {
    if (exponente == 0) {
        return 1;
    }
    else if (exponente == 1) {
        return base;
    }
    int numElevado = elevarNumero(base, exponente / 2);
    int result = (numElevado * numElevado) % 31543;
    if (exponente % 2 == 1) {
        result = (result * base) % 31543;
    }
    return result;
}

