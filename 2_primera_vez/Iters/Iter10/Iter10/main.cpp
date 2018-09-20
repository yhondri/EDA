//
//  main.cpp
//  Iter10
//
//  Created by Yhondri on 13/11/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

void segmentoMayor(int array[], int arraySize);

int main(int argc, const char * argv[]) {
    int numberOfCases;
    cin >> numberOfCases;
    while (numberOfCases > 0) {
        
        int arraySize = 0;
        cin >> arraySize;
        int array[arraySize];
        //        int array[7] = {6, 2, 3, 1, 0, 8, 12};
        for (int i = 0; i < arraySize; i++) {
            cin >> array[i];
        }
        segmentoMayor(array, arraySize);
        numberOfCases--;
    }
    return 0;
}

void segmentoMayor(int array[], int arraySize) {
    int indexFinalSegmento = 0;
    int indexInicialSegmento = 0;
    int indexFinalSegmentoAuxiliar = 0;
    int indexInicialSegmentoAuxiliar = 0;
    int segmentoMayor = 0;
    int segmentoActual = 0;
    
    int i = 0;
    while (i < arraySize) {
        if (array[i]%2 == 0) {
            segmentoActual++;
            indexFinalSegmentoAuxiliar = i;
        }else {
            if (segmentoActual > segmentoMayor) {
                segmentoMayor = segmentoActual;
                indexInicialSegmento = indexInicialSegmentoAuxiliar;
                indexFinalSegmento = indexFinalSegmentoAuxiliar;
            }
            segmentoActual = 0;
            indexInicialSegmentoAuxiliar = i+1;
            indexFinalSegmentoAuxiliar = i+1;
        }
        i++;
    }
    if ((segmentoActual > segmentoMayor) || (segmentoActual == segmentoMayor)) {
        segmentoMayor = segmentoActual;
        indexInicialSegmento = indexInicialSegmentoAuxiliar;
        indexFinalSegmento = indexFinalSegmentoAuxiliar + 1;
    }
    else {
        indexFinalSegmento += 1;
    }
    
    if (segmentoMayor > 0) {
        cout << segmentoMayor << " -> [" << indexInicialSegmento << "," << indexFinalSegmento << ")" <<  endl;
    }else {
        cout << "Vacio" << endl;
    }
    
}
