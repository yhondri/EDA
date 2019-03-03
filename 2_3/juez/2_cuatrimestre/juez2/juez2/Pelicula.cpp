//
//  Pelicula.cpp
//  juez2
//
//  Created by Yhondri Josué Acosta Novas on 28/02/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include "Pelicula.h"

Pelicula::Pelicula() : initHour(), duration(), title("") {}

Pelicula::Pelicula(Hora initHour, Hora duration, string title) {
    this->initHour = initHour;
    this->duration = duration;
    this->title = title;
    this->endHour = initHour + duration;
}

Hora Pelicula::getEndHour() const {
    return endHour;
}

string Pelicula::getTitle() const {
    return title;
}

bool Pelicula::operator<(Pelicula const& p) const {
    if (this->endHour == p.getEndHour()) {
        return (this->title.compare(p.getTitle()) < 0);
    }
    return this->endHour < p.getEndHour();
}
