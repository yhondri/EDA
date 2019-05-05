//
//  main.cpp
//  Videoclub
//
//  Created by Yhondri on 02/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <set>
#include "hashmap_eda.h"

using namespace std;


struct Pelicula {
    
public:
    Pelicula() : peliculaId(""), totalCopias(0), copiasAlquiladas(0) {}
    
    Pelicula(string const& id, int tCopias) : peliculaId(id), totalCopias(tCopias), copiasAlquiladas(0) {}

    string getId() const {
        return peliculaId;
    }
    
    void setId(string id) {
        peliculaId = id;
    }
    
    void setTotalCopias(int numCopias) {
        totalCopias = numCopias;
        copiasAlquiladas = 0;
    }
    
    int getTotalCopias() const {
        return totalCopias;
    }
    
    void annadirNuevasCopias(int numNuevasCopias) {
        totalCopias += numNuevasCopias;
    }

    int getCopiasAlquiladas() const {
        return copiasAlquiladas;
    }
    
    void alquilarCopia() {
        if((copiasAlquiladas+1) > totalCopias) {
            throw invalid_argument("No hay más copias disponibles de esta película");
        }
        
       copiasAlquiladas++;
    }
    
    void devolverCopia() {
        if(copiasAlquiladas-1 < 0) {
            throw invalid_argument("Error, se está excediendo el número de copias disponibles");
        }
        
        copiasAlquiladas--;
    }
    
    bool hayCopiasDisponibles() {
        return (totalCopias - copiasAlquiladas > 0);
    }
    
    bool hayCopiasAlquiladas() {
        return (copiasAlquiladas > 0);
    }
    
private:
    string peliculaId;
    int totalCopias;
    int copiasAlquiladas;
};

class Videoclub {
public:
    
    void annadirNuevaCopia(string peliculaId, int numCopiasNuevas) {
        peliculas[peliculaId].annadirNuevasCopias(numCopiasNuevas);
        cout << "Copias añadidas correctamente" << endl;
    }
    
    void crearNuevoSocio(string socioId) {
        if (socios.find(socioId) == socios.end()) {
            socios.insert(socioId);
            cout << "Se ha creado el nuevo socio." << endl;

        } else {
            cout << "Error: Ya existe un socio con este Id." << endl;
        }
    }
    
    void alquilarPelicula(string peliculaId, string socioId) {
        if (socios.find(socioId) == socios.end()) {
            // Socio no existe
            cout << "El socio no existe" << endl;
            
            return;
        }
        
        if (peliculas.find(peliculaId) == peliculas.end()) {
            // Socio no existe
            cout << "La pelicula no existe" << endl;
            
            return;
        }
        
        if (!peliculas[peliculaId].hayCopiasDisponibles()) {
            cout << "No hay copias disponibles de esta película" << endl;
            
            return;
        }
        
        socios[socioId].insert(peliculaId); //Añadimos película alquilada al socio.
        
        peliculas[peliculaId].alquilarCopia(); //Alquilamos copia.
        
        
        cout << "Copia alquilada satisfactoriamente" << endl;
    }
    
    void devolverCopiaPelicula(string peliculaId, string socioId) {
        if (socios.find(socioId) == socios.end()) {
            // Socio no existe
            cout << "El socio no existe" << endl;
            
            return;
        }
        
        if (peliculas.find(peliculaId) == peliculas.end()) {
            // Socio no existe
            cout << "La pelicula no existe" << endl;
            
            return;
        }
        
        socios[socioId].erase(peliculaId); //Quitamos la copia alquilada al socio.
        
        peliculas[peliculaId].devolverCopia(); //Devolvemos copia.
        
        cout << "Copia devuelta satisfactoriamente" << endl;
    }
    
    void eliminarTodasLasCopiasDeLaPelicula(string peliculaId) {
        if (peliculas.find(peliculaId) == peliculas.end()) {
            // Socio no existe
            cout << "La pelicula no existe" << endl;
            
            return;
        }
        
        if (peliculas[peliculaId].hayCopiasAlquiladas()) {
            cout << "No se pueden eliminar todas las copias de una película debido a que existen películas alquiladas." << endl;
        } else {
            peliculas[peliculaId].setTotalCopias(0);
            cout << "Se han eliminado todas las copias satisfactoriamente" << endl;
        }
    }
    
    bool existeSocioConID(string socioId) {
        return (socios.find(socioId) != socios.end());
    }
    
    void mostrarCopias(string peliculaId) {
        if (peliculas.find(peliculaId) == peliculas.end()) {
            // Socio no existe
            cout << "La pelicula no existe" << endl;
            
            return;
        }
        
        cout << "Número de copias: " << peliculas[peliculaId].getTotalCopias() << endl;
        cout << "Número de copias alquiladas: " << peliculas[peliculaId].getCopiasAlquiladas();
    }
    
    void tieneElUsuarioLaPeliculaAlquilada(string socioId, string peliculaId) {
        if (socios.find(socioId) == socios.end()) {
            // Socio no existe
            cout << "El socio no existe" << endl;
            
            return;
        }
        
        if (peliculas.find(peliculaId) == peliculas.end()) {
            // Socio no existe
            cout << "La pelicula no existe" << endl;
            
            return;
        }
        
        if (socios[socioId].find(peliculaId) == socios[socioId].end()) {
            cout << "El socio " << socioId << " no tiene la película alquilada" << endl;
        } else {
            cout << "El socio " << socioId << " tiene la película alquilada" << endl;
        }
    }

private:
    unordered_map<string, Pelicula> peliculas;
    unordered_map<string, set<string>> socios;

};

void showMenu() {
    cout << "**************" << endl;
    cout << "1-. Añadir copia de una película" << endl;
    cout << "2-. Añadir nuevo socio" << endl;
    cout << "3-. Alquilar película" << endl;
    cout << "4-. Devolver copia" << endl;
    cout << "5-. Eliminar todas las copias de una película - ***WARNING DANGER OPTION***" << endl;
    cout << "6-. Determinar si una persona es socio del club" << endl;
    cout << "7-. Mostrar el número de copias de una película" << endl;
    cout << "8-. Mostrar el número de copias alquiladas" << endl;
    cout << "9-. Determinar si una persona tiene alquilada una película" << endl;
}

int main(int argc, const char * argv[]) {
    Videoclub videoclub;
    
    showMenu();
    int opcionElegida;

    while (cin >> opcionElegida) {
        
        switch (opcionElegida) {
            case 1: {
                string peliculaId;
                int copias;
                cout << "Introduce el nombre de la película: " << endl;
                cin >> peliculaId;
            
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Introduce el número de nuevas copias: "<< endl;
                cin >> copias;
                videoclub.annadirNuevaCopia(peliculaId, copias);
                break;
            }
                
            case 2: {
                string socioId;
                cout << "Introduce el nombre del socio: " << endl;
                cin >> socioId;
                videoclub.crearNuevoSocio(socioId);
                break;
            }
                
            case 3: {
                string peliculaId, socioId;
                cout << "Introduce el nombre de la película: " << endl;
                cin >> peliculaId;
               
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Introduce el nombre del socio: " << endl;
                cin >> socioId;
                videoclub.alquilarPelicula(peliculaId, socioId);
                break;
            }
                
            case 4: {
                string peliculaId, socioId;
                cout << "Introduce el nombre de la película: " << endl;
                cin >> peliculaId;
                
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Introduce el nombre del socio: " << endl;
                cin >> socioId;
                videoclub.devolverCopiaPelicula(peliculaId, socioId);
                break;
            }
                
            case 5: {
                string peliculaId, socioId;
                cout << "Introduce el nombre de la película: " << endl;
                cin >> peliculaId;
                videoclub.eliminarTodasLasCopiasDeLaPelicula(peliculaId);
                break;
            }
                
            case 6: {
                string socioId;
                cout << "Introduce el nombre del socio: " << endl;
                cin >> socioId;
                videoclub.existeSocioConID(socioId);
                break;
            }
                
            case 7:
            case 8: {
                string peliculaId;
                cout << "Introduce el nombre de la película: " << endl;
                cin >> peliculaId;
                videoclub.mostrarCopias(peliculaId);
                break;
            }
                
            case 9: {
                string peliculaId, socioId;
                cout << "Introduce el nombre de la película: " << endl;
                cin >> peliculaId;
                
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Introduce el nombre del socio: " << endl;
                cin >> socioId;
                videoclub.tieneElUsuarioLaPeliculaAlquilada(peliculaId, socioId);
                break;
            }
        }
        
        cout << "\n\n";
        showMenu();
    }
    return 0;
}
