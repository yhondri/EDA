//
//  GestionAdmisiones.h
//  examen_ej03_junio_2017
//
//  Created by Yhondri on 27/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#ifndef GestionAdmisiones_h
#define GestionAdmisiones_h

#include <stdio.h>
#include <unordered_map>
#include <list>

using namespace std;

using codigoPaciente = int;

enum Gravedad {Leve, Normal, Grave};

class PacienteInfo {
private:
    codigoPaciente pacienteCode;
    string nombre;
    int edad;
    string sintomas;
    Gravedad gravedad;
    list<codigoPaciente>:: iterator codPacienteIt;
    
public:
    PacienteInfo() = default;
    
    PacienteInfo(codigoPaciente pcode, string n, int e, string s, Gravedad mG) : pacienteCode(pcode), nombre(n), edad(e), sintomas(s), gravedad(mG) {
        
    }
    
    codigoPaciente getCodigoPaciente() const {
        return pacienteCode;
    }
    
    void setCodPacienteIt( list<codigoPaciente>:: iterator it) {
        this->codPacienteIt = it;
    }
    
    string getNombre() const {
        return nombre;
    }
    
    int getEdad() const {
        return edad;
    }
    
    string getSintomas() const {
        return sintomas;
    }
    
    Gravedad getGravedad() const {
        return gravedad;
    }
    
    list<codigoPaciente>:: iterator getCodPacienteIt() const {
        return codPacienteIt;
    }
    
};

class GestionAdmisiones {
private:
    unordered_map<codigoPaciente, PacienteInfo> pacientes;
    list<codigoPaciente> pacientesLevesList;
    list<codigoPaciente> pacientesNormalesList;
    list<codigoPaciente> pacientesGravesList;

public:
    void an_pacientes(codigoPaciente mCodigoPaciente, string mName, int mEdad, string mSintomas, string gravedad) {
        if (pacientes.count(mCodigoPaciente) > 0) {
            throw domain_error("Paciente duplicado");
        }
        
        Gravedad gravedadUsuario;
        
        if (gravedad == "leve") {
            gravedadUsuario = Leve;
        } else if (gravedad == "normal") {
            gravedadUsuario = Normal;
        } else {
            gravedadUsuario = Grave;
        }
        
        PacienteInfo paciente(mCodigoPaciente, mName, mEdad, mSintomas, gravedadUsuario);
        
        
        switch (gravedadUsuario) {
            case Leve:
                paciente.setCodPacienteIt(pacientesLevesList.insert(pacientesLevesList.end(), paciente.getCodigoPaciente()));
                break;
            case Normal:
                paciente.setCodPacienteIt(pacientesNormalesList.insert(pacientesNormalesList.end(), paciente.getCodigoPaciente()));
                break;
            case Grave:
                paciente.setCodPacienteIt(pacientesGravesList.insert(pacientesGravesList.end(), paciente.getCodigoPaciente()));

                break;
        }
        
        pacientes[mCodigoPaciente] = paciente;
    }
    
    PacienteInfo info_paciente(codigoPaciente mCodigoPaciente) {
        if (pacientes.count(mCodigoPaciente) == 0) {
            throw domain_error("Paciente inexistente");
        }
        
        return pacientes[mCodigoPaciente];
    }
    
    PacienteInfo siguiente() {
        if (pacientesLevesList.size() == 0 && pacientesNormalesList.size() == 0 && pacientesGravesList.size() == 0) {
            throw domain_error("No hay pacientes");
        }
        
        PacienteInfo mPaciente;
        codigoPaciente mCodigoPaciente;
        
        if (pacientesGravesList.size() > 0) {
            mCodigoPaciente = pacientesGravesList.front();
            pacientesGravesList.pop_front();
        } else if (pacientesNormalesList.size() > 0) {
            mCodigoPaciente = pacientesNormalesList.front();
            pacientesNormalesList.pop_front();
        } else {
           mCodigoPaciente = pacientesNormalesList.front();
            pacientesNormalesList.pop_front();
        }
        
        mPaciente = pacientes[mCodigoPaciente];
        pacientes.erase(mCodigoPaciente);
        
        return mPaciente;
    }
    
    bool hay_pacientes() {
        return (pacientesLevesList.size() > 0 ||
                pacientesNormalesList.size() > 0 ||
                pacientesGravesList.size() > 0);
    }
    
    void elimina(codigoPaciente mCodigoPaciente) {
        if (pacientes.count(mCodigoPaciente) == 0) {
            return;
        }
        
        PacienteInfo paciente = pacientes[mCodigoPaciente];
        
        switch (paciente.getGravedad()) {
            case Leve:
                pacientesLevesList.erase(paciente.getCodPacienteIt());
                break;
            case Normal:
                pacientesNormalesList.erase(paciente.getCodPacienteIt());
                break;
            case Grave:
                pacientesGravesList.erase(paciente.getCodPacienteIt());
                break;
        }
    }    
};

#endif /* GestionAdmisiones_h */
