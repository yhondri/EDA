//
//  autoescuela.h
//  juez37
//
//  Created by Yhondri on 07/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#ifndef autoescuela_h
#define autoescuela_h

#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <stdexcept>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

using alumnoId = string;
using profesorId = string;

class alumnoInfo {
public:
    string mAlumnoId;
    int puntuacion;
    string mProfesorId;
    
    alumnoInfo() = default;
    
    alumnoInfo(string aId, int p, string pId) : mAlumnoId(aId), puntuacion(p), mProfesorId(pId) {
        
    }
    
    bool operator<(alumnoInfo const& otro) const  {
        return (mAlumnoId < otro.mAlumnoId);
    }
};

class autoescuela {

private:
    unordered_map<alumnoId, alumnoInfo> alumnos;
    unordered_map<profesorId, unordered_map<int, set<alumnoInfo>>> profesores;
    
public:
    void alta(alumnoId alumno, profesorId mProfesor) {
      if (alumnos.count(alumno) == 0) {
            alumnos[alumno] = alumnoInfo(alumno, 0, mProfesor);
           profesores[mProfesor][0].insert(alumnos[alumno]);
        } else {
            string antiguoProfesorId = alumnos[alumno].mProfesorId;
            int puntosAlumno = alumnos[alumno].puntuacion;
            //Eliminamos antiguo profesor.
            profesores[antiguoProfesorId][puntosAlumno].erase(alumnos[alumno]);
            //Añadimos nuevo profesor.
            alumnos[alumno].mProfesorId = mProfesor;
            profesores[mProfesor][puntosAlumno].insert(alumnos[alumno]);
        }
    }
    
    bool es_alumno(alumnoId alumnoId, profesorId mProfesorId) {
        if (alumnos.count(alumnoId) == 0 || profesores.count(mProfesorId) == 0) {
            return false;
        }
        
        int puntosAlumno = alumnos[alumnoId].puntuacion;
        return (profesores[mProfesorId][puntosAlumno].find(alumnos[alumnoId]) != profesores[mProfesorId][puntosAlumno].end());
    }
    
    int puntuacion(alumnoId alumnoId) {
        if (alumnos.count(alumnoId) == 0) {
            string error = "El alumno " + alumnoId + " no esta matriculado";
            throw domain_error(error);
        }
        
        return alumnos[alumnoId].puntuacion;
    }
    
    void actualizar(alumnoId alumnoId, int nuevosPuntos) {
        if (alumnos.count(alumnoId) == 0) {
            string error = "El alumno " + alumnoId + " no esta matriculado";
            throw domain_error(error);
        }
        
        string profesorId = alumnos[alumnoId].mProfesorId;
        int antiguosPuntos = alumnos[alumnoId].puntuacion;
        
        profesores[profesorId][antiguosPuntos].erase(alumnos[alumnoId]);
        
        alumnos[alumnoId].puntuacion += nuevosPuntos;

        profesores[profesorId][alumnos[alumnoId].puntuacion].insert(alumnos[alumnoId]);
    }
    
    set<alumnoId> examen(profesorId mProfesorId, int puntos) {
        if (profesores.count(mProfesorId) == 0) {
            return set<alumnoId>();
        }
        
        set<alumnoId> result;
        
        for(auto keyValue : profesores[mProfesorId]) {
            if (keyValue.first >= puntos) {
                for(auto alumno : keyValue.second) {
                    result.insert(alumno.mAlumnoId);
                }
            }
        }
        
        return result;
    }
    
    void aprobar(alumnoId alumnoId) {
        if (alumnos.count(alumnoId) == 0) {
            string error = "El alumno " + alumnoId + " no esta matriculado";
            throw domain_error(error);
        }
        
        string profesorId = alumnos[alumnoId].mProfesorId;
        int puntos = alumnos[alumnoId].puntuacion;
        
        profesores[profesorId][puntos].erase(alumnos[alumnoId]);
        alumnos.erase(alumnoId);
    }
};

#endif /* autoescuela_h */
