//
//  main.cpp
//  juez36
//
//  Created by Yhondri on 12/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "hashmap_eda.h"
#include "treemap_eda.h"
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

bool resuelveCaso();

using Medico = string;
using Paciente = string;

class Fecha {
    
public:
    Fecha(int d, int h, int m) : dia(d), hora(h), minuto(m) { }
    
    int getDia() const {
        return dia;
    }
    
    int getHora() const {
        return hora;
    }
    
    int getMinuto() const {
        return minuto;
    }
    
    bool operator <(const Fecha &rhs) const {
        if (this->dia < rhs.dia) {
            return true;
        } else if(this->dia == rhs.dia) {
            if (this->hora < rhs.hora) {
                return true;
            } else if(this->hora == rhs.hora) {
                if (this->minuto < rhs.minuto) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool operator ==(const Fecha &rhs) const {
        return (this->dia == rhs.getDia() &&
                this->hora == rhs.getHora() &&
                this->minuto == rhs.getMinuto());
    }
    
    
private:
    int dia;
    int hora;
    int minuto;
    
};

struct Cita {
    
    Cita(Fecha f, Paciente p) : fecha(f), paciente(p){}
    
private:
    Paciente paciente;
    Fecha fecha;
    
public:
    Paciente getPaciente() {
        return paciente;
    }
    
    Fecha getFecha() {
        return fecha;
    }
    
    string getHora() {
        return to_string(fecha.getHora()) + ":" + to_string(fecha.getMinuto());
    }
};

class Consultorio {
public:
    void nuevoMedico(string medicoId) {
        citas.insert(medicoId);
    }
    
    void pideConsulta(string pacienteId, string medicoId, Fecha fecha) {
        if (citas.count(medicoId) == 0) {
            throw std::domain_error("Medico no existente");
        }
        
        if (citas[medicoId].count(fecha) > 0) {
            throw std::domain_error("Fecha ocupada");
        }
        
        citas[medicoId][fecha] = pacienteId;
    }
    
    string siguientePaciente(string medicoId) {
        if (citas.count(medicoId) == 0) {
            throw std::domain_error("Medico no existente");
        }
        
        if (citas[medicoId].size() == 0) {
            throw std::domain_error("No hay pacientes");
        }
        
        map<Fecha, Paciente> citasDelMedico = citas[medicoId];
        auto citasIterador = citasDelMedico.cbegin();
        
        return (*citasIterador).valor;
    }
    
    void atiendeConsulta(string medicoId) {
        if (citas.count(medicoId) == 0) {
            throw std::domain_error("Medico no existente");
        }
        
        if (citas[medicoId].size() == 0) {
            throw std::domain_error("No hay pacientes");
        }
        
        auto citasIterador = citas[medicoId].begin();
        Fecha clave = (*citasIterador).clave;
        citas[medicoId].erase(clave);
    }
    
    vector<Cita> listaPacientes(string medicoId, int dia) {
        if (citas.count(medicoId) == 0) {
            throw std::domain_error("Medico no existente");
        }
        
        
        map<Fecha, Paciente> citasDelMedico = citas[medicoId];
        vector<Cita> listadoDeCitas;
        
        for (auto const& citasValue : citasDelMedico) {
            if (citasValue.clave.getDia() > dia) {
                break;
            }
            
            if (citasValue.clave.getDia() == dia) {
                Cita cita(citasValue.clave, citasValue.valor);
                listadoDeCitas.push_back(cita);
            }
        }
        
        return listadoDeCitas;
    }
    
private:
    unordered_map<Medico, map<Fecha, Paciente>> citas;
    
};

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez36/juez36/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    ////
    while(resuelveCaso()){}
    ////
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //        system("PAUSE");
#endif
    return 0;
}


bool resuelveCaso() {
    
    int numConsultas;
    cin >> numConsultas;
    
    if (!cin) {
        return false;
    }
    
    Consultorio consultorioMedico;
    
    while (numConsultas > 0) {
        try {
            
            string orden, medicoId, pacienteId;
            int dia, hora, minuto;
            
            cin >> orden;
            
            if (orden == "nuevoMedico") {
                cin >> medicoId;
                consultorioMedico.nuevoMedico(medicoId);
            } else if(orden == "pideConsulta") {
                cin >> pacienteId >> medicoId;
                cin >> dia >> hora >> minuto;
                consultorioMedico.pideConsulta(pacienteId, medicoId, Fecha(dia, hora, minuto));
            } else if(orden == "siguientePaciente") {
                cin >> medicoId;
                string pacienteId = consultorioMedico.siguientePaciente(medicoId);
                cout << "Siguiente paciente doctor " << medicoId << "\n" << pacienteId << endl;
                
                cout << "---" << endl;
            } else if(orden == "atiendeConsulta") {
                cin >> medicoId;
                consultorioMedico.atiendeConsulta(medicoId);
            } else if(orden == "listaPacientes") {
                cin >> medicoId;
                cin >> dia;
                vector<Cita> citas = consultorioMedico.listaPacientes(medicoId, dia);
                
                cout << "Doctor" << " " << medicoId << " dia " << dia << endl;
                
                for (Cita cita : citas) {
                    cout << cita.getPaciente() << " ";
                    cout << setfill('0') << setw(2) << cita.getFecha().getHora();
                    cout << ":";
                    cout << setfill('0') << setw(2) <<  cita.getFecha().getMinuto() << endl;
                }
                
                cout << "---" << endl;
            }
            
        } catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << '\n';
            cout << "---" << endl;
        }
        numConsultas--;
    }
    
    cout << "------" << endl;
    
    return true;
}
