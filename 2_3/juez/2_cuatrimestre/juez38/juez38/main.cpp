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
    int tiempoTotalPlaylist = 0;
    
public:
    iPud2() {};

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
        
        //La canción no está en la play list
        if(biblioteca[cancion].itPlaylist == playlist.end()) {
            biblioteca[cancion].itPlaylist = playlist.insert(playlist.end(), cancion);
            
            tiempoTotalPlaylist += biblioteca[cancion].duracion;
        }
    }
    
    string current() {
        if (playlist.empty()) {
            throw domain_error("ERROR current");
        }
        
        return playlist.front();
    }
    
    string play() {
        if (playlist.empty()) {
            throw domain_error("No hay canciones en la lista");
        }
        string cancion = playlist.front();
        playlist.pop_front();
        biblioteca[cancion].itPlaylist = playlist.end();

        if (biblioteca[cancion].itRecientes == recientes.end()) {
            //no habia reproducido nunca
            biblioteca[cancion].itRecientes = recientes.insert(recientes.begin(), cancion);
        }
        else if (biblioteca[cancion].itRecientes != recientes.end()) {
            recientes.erase(biblioteca[cancion].itRecientes);
            biblioteca[cancion].itRecientes = recientes.insert(recientes.begin(), cancion);
        }
        
        tiempoTotalPlaylist -= biblioteca[cancion].duracion;
        
        return cancion;
    }
    
    int totalTime() {
        if (playlist.empty()){
            return 0;
        }
        else{
            return tiempoTotalPlaylist;
        }
    }
    
    list<cancionId> recent(int &n) {
        if (recientes.empty()) {
            throw domain_error("No hay canciones recientes");
        }
        list<string> lista;

        auto it = recientes.begin();
        //int k = min(n, (int)recientes.size());
        n = min(n, (int)recientes.size());
        for (int i = 0; i < n; i++)
        {
            lista.push_back(it->data());
            it++;
        }
        return lista;
    }
    
    void deleteSong(string cancion) {
        if (biblioteca.count(cancion) > 0) {
        
        if (!recientes.empty() && biblioteca[cancion].itRecientes != recientes.end()) {
            recientes.erase(biblioteca[cancion].itRecientes);
        }
        
        if (!playlist.empty() && biblioteca[cancion].itPlaylist != playlist.end()) {
            playlist.erase(biblioteca[cancion].itPlaylist);
            tiempoTotalPlaylist -= biblioteca[cancion].duracion;
        }
        
        
        biblioteca.erase(cancion);
            
        }
    }
};

bool resuelveCaso();

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    
    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez38/juez38/casos");
    //    ifstream in("/Users/admin/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez29/juez29/casos");
    auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());
    
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
    //    system("PAUSE");
#endif
    
    return 0;
}


bool resuelveCaso() {
    std::string orden, s,a;
    int dur;
    std::cin >> orden;
    if (!std::cin)
        return false;
    
    iPud2 mIpud;
    
    while (orden != "FIN") {
        try {
            if (orden == "addSong") {
                cin >> s >> a >> dur;
                mIpud.addSong(s,a,dur);
            }
            else if (orden == "addToPlaylist") {
                cin >> s;
                mIpud.addToPlaylist(s);
            }
            else if (orden == "current") {
                mIpud.current();
                //cout << mIpud.current() << "\n";
            }
            else if (orden == "play") {
                cout << "Sonando " << mIpud.play() << '\n';
            }
            else if (orden == "totalTime") {
                cout << "Tiempo total " << mIpud.totalTime() << '\n';
            }
            else if (orden == "recent") {
                int r;
                cin >> r;
                auto const& lista = mIpud.recent(r);
                cout << "Las " << r << " mas recientes\n";
                for (auto const& cancion : lista)
                    cout << "    " << cancion << "\n";
            }
            else if (orden == "deleteSong") {
                cin >> s;
                mIpud.deleteSong(s);
            }
            else
                cout << "OPERACION DESCONOCIDA\n";
        }
        catch (std::domain_error e) {
            std::cout << e.what() << '\n';
        }
        catch (std::invalid_argument e) {
            std::cout << e.what() << '\n';
        }
        std::cin >> orden;
    }
    std::cout << "----\n";
    return true;
}
