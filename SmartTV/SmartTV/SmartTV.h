//
//  SmartTV.h
//  SmartTV
//
//  Created by Yhondri on 11/9/17.
//  Copyright © 2017 Yhondri . All rights reserved.
//

#ifndef SmartTV_h
#define SmartTV_h
#include "TreeMap.h"

using namespace std;

typedef int Fecha;
class Hora {
public:
    Hora();
};

class FechaYHora {
public:
    FechaYHora();
};

class Grabacion {
public:
    Grabacion(std::string nombre, Fecha fecha, Hora hora, int tiempo) : nombre(""), fecha(Fecha()), hora(Hora()) {
        tiempo = 0;
    }
    
private:
    string nombre;
    Fecha fecha;
    Hora hora;
    int duracion;
};

class SmartTV {
    
    
private:
    TreeMap<string,Grabacion> grabadas;
    TreeMap<FechaYHora,Grabacion> programadas;
    
    bool mustDelete(Grabacion grabacion) {
        
        return false;
    }
    
public:
    void grabar(std::string nombre, Fecha fecha, Hora hora, int tiempo) {
        if (!grabadas.contains(nombre)) {
            auto grabacionEncontrada = grabadas.find(nombre);
            Grabacion grabacion = grabacionEncontrada.value();
            Grabacion grabacionTemporal = Grabacion(nombre, fecha, hora, tiempo);
        }
        
        
    }
};







#endif /* SmartTV_h */
