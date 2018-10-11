//
//  main.cpp
//  aer_132
//
//  Created by Yhondri Josué Acosta Novas on 11/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//
//int AuxLinea[1000001];
//int main()
//{
//    // //        ajustes para que cin extraiga directamente de un fichero
//    #ifndef DOMJUDGE
//        ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_132/aer_132/casos"); //MacBook Pro;
//        //            ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_247/aer_247/casos");//Mac Mini;
//        auto cinbuf = cin.rdbuf(in.rdbuf());
//    #endif
//
//    string Linea;
//    while(getline(cin, Linea, '\n'))
//    {
//        int LonLinea = (int)Linea.size();
//        AuxLinea[0] = 0;
//        for(int i=1; i<LonLinea; ++i) AuxLinea[i] = Linea[i]==Linea[i-1] ? AuxLinea[i-1] : i;
//
//        int NumTest;
//        scanf("%d", &NumTest);
//
//        if(NumTest==0) return 0;
//
//        while(NumTest--)
//        {
//            int Inicio, Final;
//            scanf("%d%d\n", &Inicio, &Final);
//
//            if(Inicio>Final) swap(Inicio, Final);
//            printf((AuxLinea[Final]<=Inicio ? "SI\n" : "NO\n"));
//        }
//        printf("\n");
//    }
//
//    #ifndef DOMJUDGE
//        cin.rdbuf(cinbuf);
//        //    system("PAUSE");
//    #endif
//}


int main(int argc, const char * argv[]) {

    // //        ajustes para que cin extraiga directamente de un fichero
    #ifndef DOMJUDGE
        ifstream in("//Users/yhondri/Documents/universidad/eda/eda/2_3/aer_132/aer_132/casos"); //MacBook Pro;
        //            ifstream in("/Users/admin/Documents/universidad/eda/2_3/aer_247/aer_247/casos");//Mac Mini;
        auto cinbuf = cin.rdbuf(in.rdbuf());
    #endif

    string frase, temp;
    bool entradaValida = true;

    while (getline(cin, frase) && entradaValida) {
        int numCasos;
        cin >> numCasos;

        if (numCasos == 0) {
            entradaValida = false;
        } else {

            while (numCasos > 0) {
                int indiceInicial, indiceFinal;
                cin >> indiceInicial >> indiceFinal;
                bool seguir = true;

                for (int i = indiceInicial + 1; (i <= indiceFinal) && seguir; i++) {
                    if (frase[indiceInicial] != frase[i]) {
                        seguir = false;
                    }
                }

                if (seguir) {
                    cout << "SI\n";
                } else {
                    cout << "NO\n";
                }

                numCasos--;
            }
            cout << "\n";
            getline(cin, temp);
        }
    }

    //#ifndef DOMJUDGE
    //    cin.rdbuf(cinbuf);
    //    //    system("PAUSE");
    //#endif

    return 0;
}

