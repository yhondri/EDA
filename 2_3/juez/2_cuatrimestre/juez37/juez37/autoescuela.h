//
//  autoescuela.h
//  juez37
//
//  Created by Yhondri on 07/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#ifndef autoescuela_h
#define autoescuela_h

#include <set>
#include <unordered_map>
#include <vector>
#include <stdexcept>

using alumno = string;
using profesor = string;

class autoescuela {

private:
    unordered_map<alumno, pair<profesor, int>> alumnos;
    unordered_map<profesor, set<alumno>> profesores;
    
public:
    void alta(alumno const &mAlumno, profesor const &mProfesor) {
        auto itAlumnos = alumnos.find(mAlumno);
        
        if (itAlumnos == alumnos.end()) {
            alumnos[mAlumno] = {mProfesor, 0};
            profesores[mProfesor].insert(mAlumno);
        } else {
            profesores[itAlumnos->second.first].erase(mAlumno);
            
            itAlumnos->second.first = mProfesor;
        }
    }
    
    vector<alumno> examen(profesor &mProfesor, int n) {
        vector<alumno> v;
        
        auto itp = profesores.end();
        
        if(itp != profesores.end()) {
            for (alumno const &a :  itp->second) {
                if (alumnos.at(a).second >= n) {
                    v.push_back(a);
                }
            }
        }
        
        return v;
    }
};

#endif /* autoescuela_h */
