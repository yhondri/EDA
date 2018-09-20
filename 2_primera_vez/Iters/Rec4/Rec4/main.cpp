//
//  main.cpp
//  Rec4
//
//  Created by Yhondri on 11/12/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

long long int fibonacci(long long n);
long long int fibFinal(int n);
long long int fibFinalAux(int n, long long i, long long f0, long long f1);

int main(int argc, const char * argv[]) {
    int n = 0;
    while (cin >> n) {
        if (n >= 0)
            cout << fibFinal(n) << endl;
    }
    return 0;
}

long long fibonacci(long long n) {
    long long resultado;
    if (n < 2) {
        resultado = n;
    }else {
        resultado  = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return resultado;
}

long long fibFinal(int n) {
    if (n < 2) {
        return n;
    }else {
        return fibFinalAux(n, 1, 0, 1);
    }
}

long long int fibFinalAux(int n, long long i, long long f0, long long f1){
    if (n == i) {
        return f1;
    }else {
        return fibFinalAux(n, i+1, f1, f0+f1);
    }
}
