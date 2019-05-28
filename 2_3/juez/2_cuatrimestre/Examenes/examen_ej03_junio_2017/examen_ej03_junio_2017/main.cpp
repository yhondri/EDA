//
//  main.cpp
//  examen_ej03_junio_2017
//
//  Created by Yhondri on 26/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "GestionAdmisiones.h"

using namespace std;

void mostrarInfoPaciente(PacienteInfo paciente) {
    cout << paciente.getCodigoPaciente() <<
    " " << paciente.getNombre() <<
    " " << paciente.getEdad() <<
    " " << paciente.getSintomas()
    << endl;
}

bool resuelveCaso() {
    int numOperaciones, codigoPaciente, edad;
    string orden, nombre, sintomas, gravedad;
    
    cin >> numOperaciones;
    
    if (!std::cin) {
        return false;
    }
    
    GestionAdmisiones adminisionesManager;
    
    while (numOperaciones > 0) {
        cin >> orden;
        
        try {
            if(orden == "an_paciente") {
                cin >> codigoPaciente >> nombre >> edad >> sintomas >> gravedad;
                adminisionesManager.an_pacientes(codigoPaciente, nombre, edad, sintomas, gravedad);
            } else if(orden == "info_paciente") {
                cin >> codigoPaciente;
                PacienteInfo paciente = adminisionesManager.info_paciente(codigoPaciente);
                mostrarInfoPaciente(paciente);
            } else if(orden == "info_paciente") {
                PacienteInfo paciente = adminisionesManager.siguiente();
                mostrarInfoPaciente(paciente);
            } else if(orden == "hay_pacientes") {
                if (adminisionesManager.hay_pacientes()) {
                    cout << "SI" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else if(orden == "elimina") {
                cin >> codigoPaciente;
                adminisionesManager.elimina(codigoPaciente);
            }
        } catch (std::domain_error e) {
            cout << e.what() << "\n---\n";
        }
        
        numOperaciones--;
    }
    
    return true;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/Examenes/examen_ej03_junio_2017/examen_ej03_junio_2017/casos");

    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}
