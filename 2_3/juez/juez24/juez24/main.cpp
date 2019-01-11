//
//  main.cpp
//  juez24
//
//  Created by Yhondri  on 16/12/18.
//  Copyright © 2018 Yhondri . All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//void leerDatos(vector<vector<int>> &datos, int numFilas, int numColumnas);
//
//bool esSolucionValida(vector<int> numProductosComprados, int i) {
//    return (numProductosComprados[i] <  3);
//}
///**
// Si ya hemos comprado todos los productos, es una solución.
//*/
// bool esSolucion(int k, int numColumnas) {
//    return (k == numColumnas);
//}
//
///**
// Guardamos la mejor solución hasta ahora.
// */
//void tratarSolucion(vector<int> &mejorSolucion, int &mejorCoste, vector<int> &solucion, int costeActual, int numColumnas) {
//    if (costeActual < mejorCoste || mejorCoste == -1) {
//        mejorCoste = costeActual;
//        for (int i = 0; i < numColumnas; i++) {
//            mejorSolucion[i] = solucion[i];
//        }
//    }
//}
//
///**
// Devuelve true si el coste que llevamos hasta ahora, es mejor que el mejor coste que tenemos.
// */
//bool esFactible(int costeActual, int mejorCoste) {
//    return (costeActual < mejorCoste || mejorCoste == -1);
//}
//
///**
//
// numProductosComprados: Número productos comprados en cada súpermercado.
// */
//void vueltaAtras(vector<vector<int>> &productos, int numFilas, int numColumnas, vector<int> &numProductosComprados,
//                 int &k, vector<int> &mejorSolucion, int &mejorCoste, vector<int> &solucion, int &costeActual) {
//    for (int i = 0; i < numFilas; i++) {
//        if (numProductosComprados[i] < 3) {
//            numProductosComprados[i]++; //Sumamos un producto comprado en el súpermercado i.
//            solucion[k] = i;
//            costeActual += productos[i][k];
//            k++;
//
//            if (esSolucion(k, numColumnas)) {
//                tratarSolucion(mejorSolucion, mejorCoste, solucion, costeActual, numColumnas);
//            } else if(esFactible(costeActual, mejorCoste)) {
//                vueltaAtras(productos, numFilas, numColumnas, numProductosComprados, k, mejorSolucion, mejorCoste, solucion, costeActual);
//            }
//
//            k--;
//            numProductosComprados[i]--; //Quitamos un producto comprado en el súpermercado i.
//            costeActual -= productos[i][k];
//
//        }
//    }
//}
//
//void calcularCosteMinimo(vector<vector<int>> &productos, int numFilas, int numColumnas){
//    vector<int> numProductosComprados(numFilas);
//    vector<int> mejorSolucion(numColumnas);
//    vector<int> solucion(numColumnas);
//
//    int mejorCoste = -1, costeActual = 0, k = 0;
//
//    vueltaAtras(productos, numFilas, numColumnas, numProductosComprados, k, mejorSolucion, mejorCoste, solucion, costeActual);
//
//    if (mejorCoste == -1) {
//        cout << "Sin solucion factible" << endl;
//    } else {
//        cout << mejorCoste << endl;
//    }
//}
//
//
//int main(int argc, const char * argv[]) {
//    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Downloads/eda/2_3/juez/juez24/juez24/casos");
////    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/juez24/juez24/casos"); //Mac mini
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
//
//    int numCasos, numSupermercados, numProductos;
//    cin >> numCasos;
//
//    while (numCasos > 0) {
//        cin >> numSupermercados >> numProductos;
//
//        vector<vector<int>> supermercados(numSupermercados);
//        leerDatos(supermercados, numSupermercados, numProductos);
//
//        calcularCosteMinimo(supermercados, numSupermercados, numProductos);
//
//        numCasos--;
//    }
//
//
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
//
//    return 0;
//}
//
//void leerDatos(vector<vector<int>> &datos, int numFilas, int numColumnas) {
//    for(int i = 0; i < numFilas; i++) {
//        datos[i] = vector<int>(numColumnas);
//    }
//
//    for (int i = 0; i < numFilas; i++) {
//        for (int j = 0; j < numColumnas; j++) {
//            cin >> datos[i][j];
//        }
//    }
//}
//


void compraMinimo(const vector<vector<int>> &v, const int &m, const int &p, vector<int> &sol, vector<int> &solMejor, vector<int> &numProductosComprado, int k, int &costeMinimo, int &costeActual, const vector<int> &minProductos);
bool esValido(vector<int> &numProductosComprado, int i);
void tratarSolucion(int costeActual, int &costeMinimo, vector<int> &sol, vector<int> &solMejor, int p);
bool esSolucion(int k, int p);
bool esPrometedor(int k, int &costeMinimo, int &costeActual, const vector<int> &minProductos, int p);
void leerDatos(vector<vector<int>> &v, int m, int p, vector<int> &minimoProducto);
void resuelveCaso(const vector<vector<int>> &v, const vector<int> &minProductos, int m, int p);

int main() {
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Downloads/eda/2_3/juez/juez24/juez24/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        int p, m;
        cin >> m >> p; //m fila p columna

        vector<vector<int>> v(m, vector<int>(p));
        vector<int> minProductos(p, -1);
        leerDatos(v, m, p, minProductos);
        resuelveCaso(v,minProductos,m,p);
    }

#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
//    system("pause");
#endif // !DOMJUDGE

    return 0;
}

void resuelveCaso(const vector<vector<int>> &v, const vector<int> &minProductos, int m, int p) {

    vector<int> sol(p), solMejor(p);
    vector<int> numProductosComprado(m);
    int costeMinimo = -1, costeActual = 0;
    compraMinimo(v,m,p,sol,solMejor, numProductosComprado,0,costeMinimo,costeActual,minProductos);

    if (costeMinimo == -1) cout << "Sin solucion factible" << endl;
    else cout << costeMinimo << endl;

}

/*
 sol contiene de que mercado es el producto i
 numProductosComprado contiene el numero de productos comprados en el mercado i
 */

void compraMinimo(const vector<vector<int>> &v, const int &m, const int &p,vector<int> &sol, vector<int> &solMejor, vector<int> &numProductosComprado, int k, int &costeMinimo, int &costeActual, const vector<int> &minProductos) {
    for (int i = 0; i < m; i++)
    {

        if (esValido(numProductosComprado, i)) {
            sol[k] = i;
            costeActual += v[i][k];
            numProductosComprado[i]++;
            if (esSolucion(k, p)) {
                tratarSolucion(costeActual,costeMinimo,sol,solMejor,p);
            }
            else if(esPrometedor(k+1, costeMinimo, costeActual, minProductos, p)){
                compraMinimo(v, m, p, sol, solMejor, numProductosComprado, k+1, costeMinimo, costeActual,minProductos);
            }
            
            costeActual -= v[i][k];
            numProductosComprado[i]--;
        }
    }
}

bool esValido(vector<int> &numProductosComprado, int i) {
    /*
     no quiere comprar m¢•as de tres productos en cada uno de los supermercados
     */

    return numProductosComprado[i] < 3;
}

bool esSolucion(int k, int p) {
    return k == p-1;
}

void tratarSolucion(int costeActual, int &costeMinimo, vector<int> &sol, vector<int> &solMejor, int p) {
    if (costeActual < costeMinimo || costeMinimo == -1) {
        costeMinimo = costeActual;
        for (int i = 0; i < p; i++)
        {
            solMejor[i] = sol[i];
        }
    }
}

bool esPrometedor(int k, int &costeMinimo, int &costeActual, const vector<int> &minProductos, int p){
    int costeAux = costeActual;
    for (int i=k; i<p; i++) {
        costeAux += minProductos[i];
    }
    return costeAux < costeMinimo || costeMinimo == -1;
}

void leerDatos(vector<vector<int>> &v, int m, int p, vector<int> &minimoProducto){

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> v[i][j];
            if(v[i][j] < minimoProducto[j] || minimoProducto[j] == -1) {
                minimoProducto[j] = v[i][j];
            }
        }
    }
}
