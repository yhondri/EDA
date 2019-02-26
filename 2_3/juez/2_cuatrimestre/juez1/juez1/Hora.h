//
//  Hora.hpp
//  juez1
//
//  Created by Yhondri Josué Acosta Novas on 25/02/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#ifndef Hora_h
#define Hora_h

#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Hora {

private:
    int hour;
    int minutes;
    int seconds;

public:
    Hora();
    Hora(int hour, int minutes, int seconds);

    int getHour() const;
    int getMinutes() const;
    int getSeconds() const;

    bool operator<(Hora const& h) const;

    void readData(istream& reader) {
        char c;
        reader >> hour >> c >> minutes >> c >> seconds;

        if (hour < 0 || hour > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
            throw invalid_argument("ERROR");
        }
    }

    void printData(ostream& writer) {
        writer << setfill('0') << setw(2) << hour;
        writer << ":";
        writer << setfill('0') << setw(2) << minutes;
        writer << ":";
        writer << setfill('0') << setw(2) << seconds;
    }
};

#endif /* Hora_h */

inline istream& operator>>(istream& reader, Hora& hora) {
    hora.readData(reader);
    return reader;
}

inline ostream& operator<<(ostream& writer, Hora& hora) {
    hora.printData(writer);
    return writer;
}
