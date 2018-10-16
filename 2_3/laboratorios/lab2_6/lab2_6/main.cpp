//
//  main.cpp
//  lab2_6
//
//  Created by Yhondri Josué Acosta Novas on 16/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int mprimerCero(vector<int> valores) {

    int i = 0;

    while (i < valores.size() && valores[i] != 0) {
        i++;
    }

    if (valores[i] == 0) {
        return i;
    } else {
        return (int)valores.size();
    }
}


//EJERCICIO 6-. INVARIANTE
//method mprimerCero(v:array<int>) returns (i:int)
//ensures 0 <= i <= v.Length
//ensures  esPrimerCero(v[0..v.Length],i)
//{
//
//    var i := 0;
//
//    while (i < v.Length && v[i] != 0)
//        decreases i
//        invariant 0 <= i <= v.Lenght
//        invariant v[i] != 0
//    {
//        i := i + 1;
//    }
//
//}


//EJERCICIO 7-.
bool mparesEntreA(vector<int> valores, int c, int f) {
    int i = 0;

    while (i < valores.size() && (valores[i]%2 == 0)) {
        i++;
    }

    return i == (valores.size() - 1);
}

//EJERCICIO 7-. INVARIANTE
//method mprimerCero(v:array<int>) returns (i:int)
//ensures 0 <= c < f
//ensures 0 <= i <= v.Length
//ensures  mparesEntreA(v[0..v.Length],i)
//{
//
//    var i := 0;
//
//    while (i < v.Length && (v[i]%2 == 0))
//        decreases v.Length - i
//        invariant 0 <= i <= v.Lenght
//        invariant v[i-1] >= 0
//    {
//        i := i + 1;
//    }
//
//}


bool mgaspariforme(vector<int> valores) {
    bool esGasparisforme = true;
    bool acumulado = 0;

    for (int i = 0; i < valores.size() && esGasparisforme; i++) {
        acumulado += valores[i];

        if (acumulado != 0) {
            esGasparisforme = false;
        }
    }

    return esGasparisforme;
}



int main(int argc, const char * argv[]) {
    // insert code here...

    vector<int> testVector;
        testVector.push_back(2);
        testVector.push_back(2);
        testVector.push_back(0);
        testVector.push_back(1);
    //
    //    bool sonPares = mparesEntreA(testVector, 0, 2);

//    testVector.push_back(0);
//    testVector.push_back(0);
    //    testVector.push_back(-1); //No es gaspariforme porque una de las sumas parciales es < 0;
    //    testVector.push_back(1); //No es gaspariforme porque la suma total es > 0;

    bool esGasparisforme = mgaspariforme(testVector);

    int primer = mprimerCero(testVector);


    return 0;
}
