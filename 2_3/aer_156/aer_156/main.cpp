//
//  main.cpp
//  aer_156


#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    //        ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_132/aer_132/casos"); //MacBook Pro;
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_156/aer_156/casos");//Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    long long pisoInicial = 0, pisoDestino = 0;
    
    while (cin >> pisoInicial && pisoInicial >= 0) {
        int acumulador = 0;
        while ((cin >> pisoDestino) && pisoDestino != -1) {
            acumulador += abs(pisoDestino-pisoInicial);
            pisoInicial = pisoDestino;
        }
        
        cout << acumulador << endl;
    }
    
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
//
    return 0;
}
