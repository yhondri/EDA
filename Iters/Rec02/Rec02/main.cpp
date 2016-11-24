//
//  main.cpp
//  Rec02
//
//  Created by Yhondri on 24/11/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int complementario(int num, int mult);

int main(int argc, const char * argv[]) {
    
    int num;
    cin >> num;
    while (num != -1) {
        cout << complementario(num, 1) << endl;
        cin >> num;
    }
    
    return 0;
}

int complementario(int num, int mult) {
    int numComplementario = 0;
    if (num < 10){
        numComplementario = (9 - num) * mult;
    }else {
        int lastDigit = (9 - num%10);
        numComplementario = complementario(num/10, mult*10) + (lastDigit * mult);
    }
    
    return numComplementario;
}
