//
//  main.cpp
//  juez38
//
//  Created by Yhondri on 13/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <list>
#include <vector>
#include "iPud.h"


using namespace std;

using cancionId = string;

class cancionInfo {
public:
    string nombre;
    string artista;
    int duracion;
    list<cancionId>:: iterator itPlaylist;
    list<cancionId>:: iterator itRecientes;

    cancionInfo(string n, string a, int d, list<cancionId>:: iterator itP,
                list<cancionId>:: iterator itR) : nombre(n), artista(a),
    duracion(d), itPlaylist(itP), itRecientes(itR) {}
    
    cancionInfo() = default;
};

class iPud2 {
private:
    unordered_map<cancionId, cancionInfo> biblioteca;
    list<cancionId> playlist;
    list<cancionId> recientes;
    int tiempoTotalPlaylist;
    
public:
    void addSong(string cancion, string artista, int duracion) {
        if (biblioteca.count(cancion) > 0) {
            throw domain_error("ERROR addSong");
        }
        
        biblioteca[cancion] = cancionInfo(cancion, artista, duracion, playlist.end(), recientes.end());
    }
    
    void addToPlaylist(string cancion) {
        if (biblioteca.count(cancion) == 0) {
            throw domain_error("ERROR addToPlaylist");
        }
        
        list<cancionId>::iterator itEnd = playlist.end();
        
        //La canción no está en la play list
        if(biblioteca[cancion].itPlaylist == itEnd) {
            biblioteca[cancion].itPlaylist = playlist.insert(playlist.end(), cancion);
            
            tiempoTotalPlaylist += biblioteca[cancion].duracion;
        }
    }
    
    pair<bool, string> current() {
        if (playlist.size() == 0) {
           return make_pair(false, "No hay canciones en la lista");
        }
        
        return make_pair(true, playlist.front());
    }
    
    void play() {
        if (playlist.size() > 0) {
            string cancion = playlist.front();
            playlist.pop_front();
            
           tiempoTotalPlaylist -= biblioteca[cancion].duracion;
            
            if (biblioteca[cancion].itRecientes != recientes.end()) {
                recientes.erase(biblioteca[cancion].itRecientes);
            }
            
            biblioteca[cancion].itRecientes = recientes.insert(recientes.begin(), cancion);
            //Sacamos la canción de la playList.
            biblioteca[cancion].itPlaylist = playlist.end();
        }
    }
    
    int totalTime() {
        return tiempoTotalPlaylist;
    }
    
    list<cancionId> recent(int n) {
        list<cancionId> result;
        
        int i = 0;
        for (auto it = recientes.begin(); it != recientes.end() && i < n; ++it, i++) {
            result.push_back(*it);
        }
        
        return result;
    }
    
    void deleteSong(string cancion) {
        if (biblioteca.count(cancion) == 0) {
            return;
        }
        
        if (!recientes.empty() && biblioteca[cancion].itRecientes != recientes.end()) {
            recientes.erase(biblioteca[cancion].itRecientes);
        }
        
        if (!playlist.empty() && biblioteca[cancion].itPlaylist != playlist.end()) {
            playlist.erase(biblioteca[cancion].itPlaylist);
            tiempoTotalPlaylist -= biblioteca[cancion].duracion;
        }
        
      
        biblioteca.erase(cancion);
    }
};

bool resuelveCaso();



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso2() {
    string orden, cancion, artista;
    int duracion, n;
    iPud mp3;
    
    cin >> orden;
    
    if (!std::cin)  // fin de la entrada
        return false;
    
    while (orden != "FIN"){
        try{
            if (orden == "addSong"){
                cin >> cancion >> artista >> duracion;
                mp3.addCancion(cancion, artista, duracion);
            }
            else if (orden == "addToPlaylist"){
                cin >> cancion;
                mp3.addToPlaylist(cancion);
            }
            else if (orden == "play"){
                cancion = mp3.play();
                if (cancion != "ERROR"){
                    cout << "Sonando " << cancion << endl;
                }
                else{
                    cout << "No hay canciones en la lista" << endl;
                }
            }
            else if (orden == "totalTime"){
                cout << "Tiempo total " << mp3.totalTime() << endl;
            }
            else if (orden == "deleteSong"){
                cin >> cancion;
                mp3.deleteSong(cancion);
            }
            else if (orden == "current"){
                mp3.current();
            }
            else if (orden == "recent"){
                cin >> n;
                list<string> lista = mp3.recent(n);
                if (lista.empty()){
                    cout << "No hay canciones recientes" << endl;
                }
                else{
                    cout << "Las " << n << " mas recientes" << endl;
                    for (auto const &i : lista){
                        cout << "    " << i << endl;
                    }
                }
            }
            
            cin >> orden;
        }
        
        catch (domain_error e){
            cout << e.what() << endl;
            cin >> orden;
        }
    }
    cout << "----" << endl;
    
    return true;
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez38/juez38/casos");
    //    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez29/juez29/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso2());
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}

bool resuelveCaso() {
    std::string orden, cancionId, artista;
    int duracion, n;
    std::cin >> orden;
    if (!std::cin)
        return false;
    
    iPud2 ipod;
    
    while (orden != "FIN") {
        try {
            if (orden == "addSong") {
                cin >> cancionId >> artista >> duracion;
                ipod.addSong(cancionId, artista, duracion);
            } else if (orden == "addToPlaylist") {
                cin >> cancionId;
                ipod.addToPlaylist(cancionId);
            } else if (orden == "play") {
                pair<bool, string> result = ipod.current();
                if (result.first) {
                    cout << "Sonando " << result.second << "\n";
                    ipod.play();
                } else {
                    cout << result.second << "\n";
                }
            } else if (orden == "totalTime") {
                int result = ipod.totalTime();
                cout << "Tiempo total " << result << endl;
            } else if (orden == "current") {
                pair<bool, string> result = ipod.current();
                if (!result.first) {
                    cout << "ERROR current\n";
                }
            } else if (orden == "recent") {
                cin >> n;
                list<string> result = ipod.recent(n);
                
                if (result.size() > 0) {
                    cout << "Las " << result.size() << " mas recientes" << endl;
                    for (auto titulo : result) {
                        cout << "    " << titulo << endl;
                    }
                } else {
                    cout << "No hay canciones recientes" << endl;
                }
            } else if (orden == "deleteSong") {
                cin >> cancionId;
                ipod.deleteSong(cancionId);
            }
//            else {
//                cout << "OPERACION DESCONOCIDA: " << orden << "\n";
//            }
        } catch (std::domain_error e) {
            std::cout << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "----\n";
    return true;
}
