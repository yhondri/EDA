//
//  main.cpp
//  juez33
//
//  Created by Yhondri Josué Acosta Novas on 12/01/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
//NOMBRE y APELLIDOS


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool seguirProbando(int k, const vector<int> &costeMaximo, int costeActual, int costeMejor) {
    /*int costeAux = costeActual;
     for (int i = k+1; i < n; i++)
     {
     costeAux += costeMaximo[i];
     }

     return costeAux > costeMejor;*/

    return costeMaximo[k] + costeActual > costeMejor;
}

void tratarSolucion(int costeActual, int &costeMejor) {
    if (costeActual > costeMejor) {
        costeMejor = costeActual;
    }
}

bool esSolucion(int k, int n) {
    return k == n-1;
}

bool esValido(int k, int i, const vector<int> &maquinas, const vector<int> &carreteras, vector<bool> maquinaUsado, vector<bool> carreteraUsada) {
    //Hay que comprobar ma <= na
    return maquinas[i] <= carreteras[k] && !maquinaUsado[i] && !carreteraUsada[k];
}

void calcularCosteMaximo(const vector<int> &maquinas, const vector<int> &carreteras, int m, int n, const vector<vector<int>> &coste, int k, int &costeActual, int &costeMejor, vector<int> &sol,
                         vector<bool> &maquinaUsado, vector<bool> &carreteraUsada, const vector<int> &costeMaximo) {
    for (int i = 0; i < m && m > 0; i++)
    {
        //sol(n) guarda cual maquina limpia la nieve k
        sol[k] = i;
        if (esValido(k,i,maquinas,carreteras,maquinaUsado,carreteraUsada)) {
            costeActual += coste[i][k];
            maquinaUsado[i] = true;
            carreteraUsada[k] = true;
            if (esSolucion(k,n)) {
                tratarSolucion(costeActual,costeMejor);
            }
            else if(seguirProbando(k,costeMaximo,costeActual, costeMejor)) {
                calcularCosteMaximo(maquinas, carreteras, m, n, coste, k + 1, costeActual, costeMejor, sol,maquinaUsado,carreteraUsada, costeMaximo);
            }
            carreteraUsada[k] = false;
            maquinaUsado[i] = false;
            costeActual -= coste[i][k];
        }else if (esSolucion(k, n)) {
            tratarSolucion(costeActual, costeMejor);
        }
        else if (seguirProbando(k, costeMaximo, costeActual, costeMejor)) {
            calcularCosteMaximo(maquinas, carreteras, m, n, coste, k + 1, costeActual, costeMejor, sol, maquinaUsado, carreteraUsada, costeMaximo);
        }
    }
}

void leerDatos(vector<int> &maquinas, vector<int> &carreteras, int m, int n, vector<vector<int>> &coste, vector<int> &costeMaximoSuma) {

    for (int i = 0; i < m; i++)
    {
        cin >> maquinas[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> carreteras[i];

    }
    vector<int> costeMaximo(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> coste[i][j];
            if (coste[i][j] > costeMaximo[j] || costeMaximo[j] == 0) {
                costeMaximo[j] = coste[i][j];
            }
        }
    }

    costeMaximoSuma[n - 1] = 0;
    for (int i = n-2; i >= 0; i--)
    {
        costeMaximoSuma[i] = costeMaximoSuma[i + 1] + costeMaximo[i + 1];
    }
}

void resuelveCaso() {
    int m,n;

    cin >> m >> n;

    vector<int> maquinas(m), carreteras(n), costeMaximo(n);
    vector<vector<int>> coste(m, vector<int>(n));

    leerDatos(maquinas, carreteras, m, n, coste,costeMaximo);

    vector<int> sol(n, -1);
    vector<bool> maquinaUsado(m), carreteraUsado(n);
    int costeActual = 0, costeMejor = 0;

    calcularCosteMaximo(maquinas, carreteras, m, n, coste, 0, costeActual, costeMejor, sol, maquinaUsado,carreteraUsado,costeMaximo);

    cout << costeMejor << endl;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/juez33/juez33/casos");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif


    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}


//
//
//bool seguirProbando(int k, const vector<int> &costeMaximo, int costeActual, int costeMejor) {
//    /*int costeAux = costeActual;
//     for (int i = k+1; i < n; i++)
//     {
//     costeAux += costeMaximo[i];
//     }
//
//     return costeAux > costeMejor;*/
//    return ((costeMaximo[k] + costeActual) > costeMejor);
//}
//
//void tratarSolucion(int costeActual, int &costeMejor) {
//    if (costeActual > costeMejor) {
//        costeMejor = costeActual;
//    }
//}
//
//bool esSolucion(int k, int m) {
//    return k == m-1;
//}
//
//bool esValido(int k, int i, const vector<int> &maquinas, const vector<int> &carreteras, vector<bool> maquinaUsada, vector<bool> carreteraUsada) {
//    //AnchuraMáquina es <= carretera
//    return maquinas[k] <= carreteras[i] && !maquinaUsada[k] && !carreteraUsada[i];
//}
//
//bool existeUnCosteMejor(const vector<int> &calidadesMaximas, int calidadActual, int mejorCoste, int index, int carreteras) {
//    int calidadAux = calidadActual;
//
//    for (int i = index; i < carreteras; i++) {
//        calidadAux += calidadesMaximas[i];
//    }
//
//    return (calidadAux > mejorCoste || mejorCoste == -1);
//}
//
///*
//
// k = carretera.
// i = máquina.
// **/
//void calcularCosteMaximo(const vector<int> &maquinas, const vector<int> &carreteras, int m,
//                         int n, const vector<vector<int>> &calidades, int k,
//                         int &costeActual, int &costeMejor, vector<int> &sol,
//                         vector<bool> &maquinaUsada, vector<bool> &carreteraUsada, const vector<int> &calidadesMaximas) {
//    for (int i = 0; i < n; i++) {
//        //Máquina K limpia carretera i.
//        if (esValido(k, i, maquinas, carreteras, maquinaUsada, carreteraUsada)) {
//            sol[k] = i;
//            costeActual += calidades[k][i];
//            maquinaUsada[k] = true;
//            carreteraUsada[i] = true;
//            if (esSolucion(k, m)) {
//                tratarSolucion(costeActual,costeMejor);
//            } else {
//                calcularCosteMaximo(maquinas, carreteras, m, n, calidades, k + 1, costeActual, costeMejor, sol,maquinaUsada,carreteraUsada, calidadesMaximas);
//            }
//
//            carreteraUsada[i] = false;
//            maquinaUsada[k] = false;
//            costeActual -= calidades[k][i];
//        }
//    }
//}
//
//void leerDatos(vector<int> &maquinas, vector<int> &carreteras, int m, int n, vector<vector<int>> &calidades, vector<int> &calidadesMaximas) {
//
//    for (int i = 0; i < m; i++) {
//        cin >> maquinas[i];
//    }
//
//    for (int i = 0; i < n; i++) {
//        cin >> carreteras[i];
//
//    }
//
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            cin >> calidades[i][j];
//            if (calidades[i][j] > calidadesMaximas[j] || calidadesMaximas[j] == 0) {
//                calidadesMaximas[j] = calidades[i][j];
//            }
//        }
//    }
//
//    //    costeMaximoSuma[n - 1] = 0;
//    //    for (int i = n-2; i >= 0; i--)
//    //    {
//    //        costeMaximoSuma[i] = costeMaximoSuma[i + 1] + costeMaximo[i + 1];
//    //    }
//}
//
//void resuelveCaso() {
//    int m,n;
//
//    cin >> m >> n;
//
//    vector<int> maquinas(m), carreteras(n), calidadesMaximas(n);
//    vector<vector<int>> calidades(m, vector<int>(n));
//
//    leerDatos(maquinas, carreteras, m, n, calidades, calidadesMaximas);
//
//    vector<int> sol(m, -1);
//    vector<bool> maquinaUsada(m), carreteraUsada(n);
//    int costeActual = 0, costeMejor = -1;
//
//    if (m == 0) {
//        cout << 0 << endl;
//    } else {
//        calcularCosteMaximo(maquinas, carreteras, m, n, calidades, 0, costeActual, costeMejor, sol, maquinaUsada, carreteraUsada, calidadesMaximas);
//
//        cout << costeMejor << endl;
//    }
//}
//
//
