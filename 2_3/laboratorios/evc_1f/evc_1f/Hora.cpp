//
//  Hora.cpp
//  juez1
//
//  Created by Yhondri Josué Acosta Novas on 25/02/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include "Hora.h"

Hora::Hora() : hour(0), minutes(0), seconds(0) {}
Hora::Hora(int hour, int minutes, int seconds) {
    if (hour < 0 || hour > 23 || minutes < 0 || minutes > 59 || seconds < 0 || seconds > 59) {
        throw invalid_argument("ERROR");
    }

    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
}

int Hora::getHour() const {
    return hour;
}

int Hora::getMinutes() const {
    return minutes;
}

int Hora::getSeconds() const {
    return seconds;
}

bool Hora::operator<(Hora const& h) const {
    if (hour < h.hour) {
        return true;
    } else if (hour == h.hour) {
        if (minutes < h.minutes) {
            return true;
        } else if (minutes == h.minutes) {
            if (seconds < h.seconds) {
                return true;
            }
        }
    }

    return false;
}
