//
//  main.cpp
//  SmartTV
//
//  Created by Yhondri  on 11/9/17.
//  Copyright © 2017 Yhondri . All rights reserved.
//

#include <iostream>
#include "List.h"

using namespace std;

int main(int argc, const char * argv[]) {
    /* Tests
     programar concierto 5 23:55 60
     grabacionesProgramadas 4 6
     programar pelicula 5 22:00 120
     grabacionesProgramadas 4 6
     */
//    SmartTV tv;
//    string op;
//    string nombre;
//    Fecha f, f2;
//    Hora h;
//    int dur;
//    List<Grabacion> listaGrabs;
//    
//    cin >> op;
//    while (op != "salir"){
//        if (op == "grabar"){
//            // El nombre no puede tener espacios
//            cin >> nombre >> f >> h >> dur;
//            tv.grabar(nombre,f,h,dur);
//        } else if (op == "eliminarGrabacion"){
//            cin >> nombre;
//            tv.eliminarGrabacion(nombre);
//        } else if (op == "grabacionesRealizadas"){
//            tv.grabacionesRealizadas(listaGrabs);
//            for (auto& g : listaGrabs)
//                cout << g.nombre << endl << FechaYHora(g.fecha,g.hora).toString() << endl
//                << g.duracion << " minutos" << endl;
//            cout << endl;
//        } else if (op == "programar"){
//            // El nombre no puede tener espacios
//            cin >> nombre >> f >> h >> dur;
//            try{
//                tv.programar(nombre,f,h,dur);
//            } catch (ExcepcionTAD& e){
//                cout << e << endl;
//            }
//        } else if (op == "grabacionesProgramadas"){
//            cin >> f >> f2;
//            tv.grabacionesProgramadas(f,f2,listaGrabs);
//            for (auto& g : listaGrabs)
//                cout << g.nombre << endl << FechaYHora(g.fecha,g.hora).toString() << endl
//                << g.duracion << " minutos" << endl;
//            cout << endl;
//        }
//        cin >> op;
//    }
    return 0;
}
