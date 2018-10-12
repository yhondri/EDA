//
//  main.cpp
//  aer_172
//


#include <iostream>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//            ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_172/aer_172/casos"); //MacBook Pro;
////    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_172/aer_172/casos");//Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numAsientos;
    while (cin >> numAsientos && numAsientos > 0) {
        string mesa;
        getline(cin, mesa);

//        Da igual el orden
//        si hay uno que ha empezado comiendo por la derecha
//        y otro por la izquierda
//        alguien se va a jdoer tarde o temprano

        if (mesa.find('D') != std::string::npos && mesa.find('I') != std::string::npos) {
            cout << "ALGUNO NO COME" << endl;
        } else {
            cout << "TODOS COMEN" << endl;
        }
    }
        
    //
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif

    return 0;
}
