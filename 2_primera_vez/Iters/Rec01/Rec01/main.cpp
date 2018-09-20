//
//  main.cpp
//  Rec01
//
//  Created by Yhondri on 24/11/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int log(int b, int n);

int main(int argc, const char * argv[]) {
    
    int casos;
    int b;
    int n;
    cin >> casos;
    
    while (casos > 0){
        cin >> b;
        cin >> n;
        cout << log(b, n) << endl;
        casos--;
    }
    
    return 0;
}

int log(int b, int n) {
    int i;
    if (b > n) {
        i = 0;
    }else {
        i = log(b, n/b) + 1;
    }
    return i;
}
