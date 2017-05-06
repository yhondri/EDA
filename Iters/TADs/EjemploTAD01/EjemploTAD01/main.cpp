//
//  main.cpp
//  EjemploTAD01
//
//  Created by Yhondri on 6/5/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include <string>
#include "Pair.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Pair<int, string> p(4, "hola");
    cout << p.first() << " " << p.second() << endl;
    
    int *pointer, *q;
    pointer = new int;
    *pointer = 4;
    q = new int;
    *q = 5;
//    pointer = q;
    cout << *pointer << " " << *q << endl;
    
    return 0;
}
