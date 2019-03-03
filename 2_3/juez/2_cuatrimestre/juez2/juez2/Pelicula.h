//
//  Pelicula.hpp
//  juez2
//
//  Created by Yhondri Josué Acosta Novas on 28/02/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#ifndef Pelicula_h
#define Pelicula_h

#include <stdio.h>
#include "Hora.h"

using namespace std;

class Pelicula {

private:
    Hora initHour;
    Hora duration;
    Hora endHour;
    string title;

public:
    Pelicula();
    Pelicula(Hora initHour, Hora duration, string title);

    Hora getEndHour() const;
    string getTitle() const;

    bool operator<(Pelicula const& p) const;

    void readData(istream& reader) {
        string space;
        reader >> initHour >> duration;
        getline(reader, title);
        endHour = initHour + duration;
    }

    void print(ostream& writer) {
        writer << endHour << title;
    }
};

inline istream& operator>>(istream& reader, Pelicula& pelicula) {
    pelicula.readData(reader);
    return reader;
}

inline ostream& operator<<(ostream& writer, Pelicula& pelicula) {
    pelicula.print(writer);
    return writer;
}


#endif /* Pelicula_h */
