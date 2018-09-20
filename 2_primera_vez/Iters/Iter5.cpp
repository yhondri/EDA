//
//  main.cpp
//  Iter5
//
//  Created by Yhondri on 12/11/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int acumulador = 0;
    int nextValue;
    bool seguir = true;
    
    while (seguir) {
        cin >> nextValue;
        if (nextValue != 0) {
            acumulador += nextValue;
            cout << acumulador << " ";
        }else if(nextValue == 0 && acumulador > 0){
            acumulador = 0;
            cout << endl;
        }else {
            seguir = false;
        }
    }
    
    return 0;
}
