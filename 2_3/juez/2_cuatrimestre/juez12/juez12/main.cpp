//
//  main.cpp
//  juez12
//
//  Created by Yhondri on 28/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "queue_eda.h"

using namespace std;

template <class T>
class ArrayQueue : public queue<T> {
    using Nodo = typename queue<T>::Nodo;  // para poder usar Nodo aqu�
public:
    
    void calcularNumeroAlumno() {
        bool seguir = true;
        
        while (seguir) {
            
        }
    }
    
};

void resuelveCaso(int numAlumnos, int alumnosASaltar) {
    ArrayQueue<int> mArray;
    
    for (int i = 1; i <= numAlumnos; i++) {
        mArray.push(i);
    }
    
    bool seguir = true;
    int alumnosSaltados = 0;
    
    while (seguir) {
        
        if (alumnosSaltados == alumnosASaltar) {
            mArray.pop();
            alumnosSaltados = 0;
        } else {
            int i = mArray.front();
            mArray.pop();
            mArray.push(i);
            alumnosSaltados++;
        }
        
        if (mArray.size() == 1) {
            seguir = false;
        }
        
    }
    
    cout << mArray.front() << endl;
}

using namespace std;
int main(int argc, const char * argv[]) {
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez12/juez12/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numAlumnos, alumnosASaltar;
    cin >> numAlumnos >> alumnosASaltar;
    while (numAlumnos > 0 &&  alumnosASaltar > 0) {
        resuelveCaso(numAlumnos, alumnosASaltar);
        cin >> numAlumnos >> alumnosASaltar;
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}
