//
//  main.cpp
//  ej4
//
//  Created by Yhondri Josué Acosta Novas on 31/12/2018.
//  Copyright © 2018 Yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */

struct Time {
    int hours;
    int minutes;
    int seconds;

    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
};

void differenceBetweenTimePeriod(struct Time start, struct Time stop, struct Time *diff) {
    if(stop.seconds > start.seconds){
        --start.minutes;
        start.seconds += 60;
    }

    diff->seconds = start.seconds - stop.seconds;
    if(stop.minutes > start.minutes){
        --start.hours;
        start.minutes += 60;
    }

    diff->minutes = start.minutes - stop.minutes;
    diff->hours = start.hours - stop.hours;


    time_t initHour =  time(NULL);
    initHour.ho
}


using namespace std;

void leerDatos(vector<int> &datos, int numDatos);

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Downloads/eda/2_3/12_uvas/ej4/ej4/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif

    int numDatos;

    while (cin >> numDatos) {
        vector<int> datos(numDatos);
        leerDatos(datos, numDatos);

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
