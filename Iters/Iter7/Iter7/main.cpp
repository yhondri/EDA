//
//  main.cpp
//  Iter7
//
//  Created by Yhondri on 12/11/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int totalDays(int cantidadTotal, int acumulado, int day1, int day2);

int main(int argc, const char * argv[]) {
    
    int numeroDeCasos = 0;
    cin >> numeroDeCasos;
    while (numeroDeCasos > 0) {
        int cantidadQuiero;
        cin >> cantidadQuiero;
        int days = 0;
        if (cantidadQuiero > 0) {
            days = totalDays(cantidadQuiero, 1, 1, 0);
        }
        cout << days << endl;
        numeroDeCasos--;
    }
    
    return 0;
}

int totalDays(int cantidadQuiero, int acumulado, int day1, int day2) {
    int days = 1;
    int totalAcumuladoDia = (day2 * 2) + day1;
    if (acumulado < cantidadQuiero) {
        acumulado += totalAcumuladoDia;
        days += totalDays(cantidadQuiero, acumulado, totalAcumuladoDia, day1);
    }
    
    return days;
}
