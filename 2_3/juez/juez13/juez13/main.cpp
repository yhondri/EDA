//
//  main.cpp
//  juez13
//
//  Created by Yhondri Josué Acosta Novas on 06/11/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

struct solucion {
    solucion(long long numero, long long potencia) {
        this->numero = numero;
        this->potencia = potencia;
    }

    long long numero;
    long long potencia;
};

solucion invertir(long long num) {
    if (num < 10) {
        return solucion(num, 10);
    }

    int digit = num % 10;

    solucion solucionIntervida = invertir(num/10);

    long long numInvertido = (digit * solucionIntervida.potencia) + solucionIntervida.numero;
    return solucion(numInvertido, solucionIntervida.potencia*10);
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    //    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez11/juez11/casos");
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/juez/juez13/juez13/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    long long num;
    while (cin >> num) {
        cout << invertir(num).numero << endl;
//        cout << noPares(num) << endl;
    }


//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif

    return 0;
}
