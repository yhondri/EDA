//
//  main.cpp
//  Examen2016_02
//
//  Created by Yhondri on 10/2/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

long calcularISBN(long num);
long calcularISBN(long num, int digito, long position, long suma);

int main(int argc, const char * argv[]) {
    long isbn = 0;
    cin >> isbn;
    cout << calcularISBN(isbn) << endl;
    return 0;
}

long calcularISBN(long num) {
    long suma = calcularISBN(num, 0, 0, 0);
    return (10-(suma%10))%10;
}

long calcularISBN(long num, int digito, long position, long suma) {
    int nuevoDigito = num%10;
    if (position%2 == 0) {
        nuevoDigito = (num%10) * 3;
    }
    if (num <= 10) {
        return nuevoDigito+suma;
    }else {
       return calcularISBN(num/10, nuevoDigito, position+1,  nuevoDigito+suma);
    }
}
