//
//  main.cpp
//  ej9asc
//
//  Created by Yhondri  on 23/12/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Cancion {
    int duracion;
    int puntuacion;
    
    Cancion() : duracion(0), puntuacion(0) {}
    Cancion(int d, int p) : duracion(d), puntuacion(p) {}
};

vector<Cancion> leerDatos(int n);
void getMejorCinta(const vector<Cancion> &canciones, int n, int duracionCara);

enum CintaCara {
    N,
    A, //Cara A, la canción se graba en la cara A.
    B //Cara B, la canción se graba en la cara B.
};

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/admin/Documents/universidad/eda/2_3/laboratorios/ej9asc/ej9asc/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    int numCanciones, duracionCara;
    
    while (cin >> numCanciones && numCanciones > 0) {
        cin >> duracionCara;
        vector<Cancion> canciones = leerDatos(numCanciones);
        
        sort(canciones.begin(), canciones.end(), [](Cancion a, Cancion b) {
            return (a.puntuacion / (float) a.duracion) > (b.puntuacion / (float) b.duracion);
        });
        
        getMejorCinta(canciones, numCanciones, duracionCara);
    }
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

vector<Cancion> leerDatos(int n) {
    vector<Cancion> canciones(n);
    
    for (int i = 0; i < n; i++) {
        int duracion, puntuacion;
        cin >> duracion >> puntuacion;
        canciones[i] = Cancion(duracion, puntuacion);
    }
    
    return canciones;
}

int calculoEstimacion(const vector<Cancion> &canciones, int n, int duracionCara,
                      int k, vector<int> &duracionOcupada, int beneficioActual) {
    int hueco = duracionCara - (duracionOcupada[A] + duracionOcupada[B]);
    int estimacion = beneficioActual;
    int j = k;
  
    while (j < n && canciones[j].duracion <= hueco) {
        hueco -= canciones[j].duracion;
        estimacion += canciones[j].puntuacion;
        j++;
    }
    
    if (j < n) { // Quedan canciones por progar
        estimacion += (hueco/canciones[j].duracion)*canciones[j].puntuacion; //Cortamos la canción j.
    }
    
    return estimacion;
}

bool esSolucion(int k, int n) {
    return (k == n-1);
}

void tratarSolucion(const vector<CintaCara> &solucion, vector<CintaCara> &mejorSolucion, int n,
                    int &beneficioActual, int &beneficioMejor) {
    for (int i = 0; i < n; i++) {
        mejorSolucion[i] = solucion[i];
    }
    
    beneficioMejor = beneficioActual;
}

void cancionesVA(const vector<Cancion> &canciones, int n, int duracionCara,
                 vector<CintaCara> &solucion, int &k, vector<int> &duracionOcupada,
                 int &beneficioActual, vector<CintaCara> &mejorSolucion, int &beneficioMejor) {
    
    solucion[k] = A; //Grabamos en la cara A.
    duracionOcupada[A] += canciones[k].duracion;
    beneficioActual += canciones[k].puntuacion;
    
    if (duracionOcupada[A] <= duracionCara) {
        if (esSolucion(k, n)) {
            tratarSolucion(solucion, mejorSolucion, n, beneficioActual, beneficioMejor);
        } else {
            cancionesVA(canciones, n, duracionCara,
                        solucion, ++k, duracionOcupada,
                        beneficioActual, mejorSolucion, beneficioMejor);
        }
    }
    
    duracionOcupada[A] = duracionOcupada[A] - canciones[k].duracion;
    beneficioActual -= canciones[k].puntuacion;
    
    if (duracionOcupada[A] != duracionOcupada[B]) {
        solucion[k] = B; //Grabamos en la cara A.
        duracionOcupada[B] = duracionOcupada[B] + canciones[k].duracion;
        beneficioActual += canciones[k].puntuacion;
        
        if (duracionOcupada[B] <= duracionCara) {
            int beneficioEstimado = calculoEstimacion(canciones, n, duracionCara, k, duracionOcupada, beneficioActual);
            if (beneficioEstimado > beneficioMejor) {
                if (esSolucion(k, n)) {
                    tratarSolucion(solucion, mejorSolucion, n, beneficioActual, beneficioMejor);
                } else {
                    cancionesVA(canciones, n, duracionCara,
                                solucion, ++k, duracionOcupada,
                                beneficioActual, mejorSolucion, beneficioMejor);
                }
            }
        }
    }
    
    duracionOcupada[B] = duracionOcupada[B] - canciones[k].duracion;
    beneficioActual -= canciones[k].puntuacion;
    
    solucion[k] = N; //Grabamos en la cara A.
    int beneficioEstimado = calculoEstimacion(canciones, n, duracionCara, k, duracionOcupada, beneficioActual);
    if (beneficioEstimado > beneficioMejor) {
        if (esSolucion(k, n)) {
            tratarSolucion(solucion, mejorSolucion, n, beneficioActual, beneficioMejor);
        } else {
            cancionesVA(canciones, n, duracionCara,
                        solucion, ++k, duracionOcupada,
                        beneficioActual, mejorSolucion, beneficioMejor);
        }
    }
}

void getMejorCinta(const vector<Cancion> &canciones, int n, int duracionCara) {
    vector<CintaCara> solucion(n);
    vector<CintaCara> mejorSolucion(n);
    vector<int> duracionOcupada(3, 0);
    int beneficioActual = 0, beneficioMejor = 0, k = 0;
    
    cancionesVA(canciones, n, duracionCara, solucion, k, duracionOcupada, beneficioActual, mejorSolucion, beneficioMejor);
    
    cout << beneficioMejor << endl;
}
