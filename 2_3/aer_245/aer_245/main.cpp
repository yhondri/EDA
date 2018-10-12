//
//  main.cpp
//  aer_245


#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {

    // //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_245/aer_245/casos"); //MacBook Pro;
//    //    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_172/aer_172/casos");//Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    long long numPersonajes;
    cin >> numPersonajes;

    while (numPersonajes > 0) {
        long long primero, segundo;
        cin >> primero >> segundo;
        bool sonDalton = true, ordenMenorAMayor = true;

        if (primero < segundo) {
            ordenMenorAMayor = true;
        } else if(primero > segundo) {
            ordenMenorAMayor = false;
        } else {
            sonDalton = false;
        }

        if (sonDalton) {
            primero = segundo;
            for (long long i = 3; (i <= numPersonajes); i++) {
                cin >> segundo;

                if (ordenMenorAMayor && (primero >= segundo)) {
                    sonDalton = false;
                } else if (!ordenMenorAMayor && (primero <= segundo)) {
                    sonDalton = false;
                }

                primero = segundo;
            }
        } else {
            string temp;
            getline(cin, temp);
        }

        if (sonDalton) {
            cout << "DALTON" << endl;
        } else {
            cout << "DESCONOCIDOS" << endl;
        }

        cin >> numPersonajes;
    }


    //
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif

    return 0;
}
