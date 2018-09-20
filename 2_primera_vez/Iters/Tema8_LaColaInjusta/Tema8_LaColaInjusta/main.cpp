//
//  main.cpp
//  Tema8_LaColaInjusta
//
//  Created by Yhondri on 23/6/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include "Queue.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int numCasos;
    int n;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++){
        Queue<int>* q = new Queue<int>();
        cin >> n;
        while (n != -1){
            q->push_back(n);
            cin >> n;
        }
        cin >> n;
        cout << *q;
        q->reverseFirstK(n);
        cout << *q;
        delete q;
    }
    return 0;
}
