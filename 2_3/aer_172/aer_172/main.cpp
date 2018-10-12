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
//    //        ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_132/aer_132/casos"); //MacBook Pro;
//    ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_172/aer_172/casos");//Mac Mini;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
    
    int numAsientos;
    while (cin >> numAsientos && numAsientos > 0) {
        char mesa[numAsientos];
        for (int i = 0; i < numAsientos; i++) {
            cin >> mesa[i];
        }
        
//        for (int i = 0; i < numAsientos; i++) {
//           cout << mesa[i];
//        }


        bool comeranTodos = true;
        if (numAsientos >= 3 && mesa[numAsientos-1] == 'D' && mesa[1] == 'I') { //Puesto inicial... Miramos el último y el segundo.
            comeranTodos = false;
        } else if (numAsientos >= 3 && mesa[0] == 'I' && mesa[numAsientos-2] == 'D') { //Puesto final... Miramos el primero y el penúltimo.
            comeranTodos = false;
        } else {
            for (int i = 1; i <= numAsientos - 2; i++) {
                if (mesa[i-1] == 'D' && mesa[i+1] == 'I') { //Puesto final... Miramos el primero y el penúltimo.
                    comeranTodos = false;
                }
            }
        }
        
        if (comeranTodos) {
            cout << "TODOS COMEN" << endl;
        } else {
            cout << "ALGUNO NO COME" << endl;
        }
    }
        
    //
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    
    return 0;
}
