//
//  main.cpp
//  aer_ 169
//
//  Created by Yhondri Josué Acosta Novas on 23/10/2018.
//  Copyright © 2018 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void resuelveCaso();

int main(int argc, const char * argv[]) {
    //        ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//    ifstream in("/Users/yhondri/Documents/universidad/eda/eda/2_3/aer_ 169/aer_ 169/casos"); //MacBook Pro;
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif

    int numCasos;
    cin >> numCasos;
    string temp;
    getline(cin, temp);

    while (numCasos > 0) {
        resuelveCaso();
        numCasos--;
    }


//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
//    //    system("PAUSE");
//#endif
    return 0;
}

string tolow(string a) {
    for(int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
    }
    return a;
}

string readString() {
    string newValue;
    getline(cin, newValue);
    return tolow(newValue);
}

string splitString(string value, string delimiter) {
    return value.substr(0, value.find(delimiter));
}

string readAndFormat() {
    string newValue = readString();
    return splitString(newValue, ",");
}

void resuelveCaso() {
    int people = 0, alone = 0;
    bool hasBrothers = false;
    string name, otherName;
    name = readAndFormat();
    while (name != "====") {
        people += 1;
        otherName = readAndFormat();
        if (otherName != name) {
            if (!hasBrothers) {
                alone += 1;
            }
            hasBrothers = false;
            name = otherName;
        } else {
            hasBrothers = true;
        }
    }

//    print("\(people) \(people - alone)\n");
    cout << people << " " << (people - alone) << endl;

 /**   string participante1 = "", participante2 = "";
    int numParticipantes = 0, foreverAlone = 0;

    string delimiter = ",";
    bool seguir = true;

    do {
        bool tieneHermanos = false;

        if (participante1 == "") {
            getline(cin, participante1);
            participante1 = participante1.substr(0, participante1.find(delimiter));

            if (participante1 != "====") {
                numParticipantes++;
            }
        }

        do {
            getline(cin, participante2);
            participante2 = participante2.substr(0, participante2.find(delimiter));

            if (participante1 == "====" || participante2 == "====" ) {
                seguir = false;
                tieneHermanos = false;
            } else {
                if (tolow(participante1) == tolow(participante2)) {
                    tieneHermanos = true;
                } else {
                    tieneHermanos = false;
                    foreverAlone++;
                }
                numParticipantes++;
            }
        } while (tieneHermanos);

        foreverAlone++;

        participante1 = participante2;

    } while (seguir);

    cout << numParticipantes << " " << numParticipantes - foreverAlone << endl;*/
}

//1 2 2 3 4 4 5 32 32 32 32
