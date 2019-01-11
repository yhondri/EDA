//
//  main.cpp
//  juez28
//
//  Created by Yhondri Josué Acosta Novas on 08/01/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

void resolverCaso(const vector<int> &datos, int numDatos, int numMaxTrenesAtracar) {
    int botinMayor = 0, botinActual, posicionPrimerVagon = 0;
    for (int i = 0; i < numMaxTrenesAtracar; i++) {
        botinMayor += datos[i]; //Sumamos primeros K elementos (k = numMaxTrenesAtracar);
    }

    botinActual = botinMayor;

    for (int i = numMaxTrenesAtracar; i < numDatos; i++) {
        botinActual += (datos[i] - datos[i-numMaxTrenesAtracar]); //Quitamos la primera posición que hemos añadido al subvector.

        if (botinActual >= botinMayor) {
            botinMayor = botinActual;
            posicionPrimerVagon = ((i+1)-numMaxTrenesAtracar);
        }
    }

    cout << posicionPrimerVagon << " " << botinMayor << endl;
}

int maxSum(const vector<int> &datos, int n, int k)
{
    // k must be greater
    if (n < k)
    {
        cout << "Invalid";
        return -1;
    }

    // Compute sum of first window of size k
    int res = 0;
    for (int i=0; i<k; i++)
        res += datos[i];

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int curr_sum = res;
    for (int i=k; i<n; i++)
    {
        curr_sum += datos[i] - datos[i-k];
        res = max(res, curr_sum);
    }

    return res;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Downloads/eda/2_3/juez/juez28/juez28/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numCasos;

    cin >> numCasos;

    while (numCasos > 0) {
        int numDatos, numMaxTrenesAtracar;
        cin >> numDatos >> numMaxTrenesAtracar;

        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);

//       cout << maxSum(datos, numDatos, numMaxTrenesAtracar) << endl;
        resolverCaso(datos, numDatos, numMaxTrenesAtracar);

        numCasos--;

    }


#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif

    return 0;
}

void leerDatos(vector<int> &datos, int numDatos) {
    int nuevoDato;
    for (int i = 0; i < numDatos; i++) {
        cin >> nuevoDato;
        datos[i] = nuevoDato;
    }
}
