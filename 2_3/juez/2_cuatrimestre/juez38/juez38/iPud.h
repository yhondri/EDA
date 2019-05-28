#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

using cancion = string;

class iPud {
    
private:
    //se puede poner dentro o fuera de la clase
    struct infoCancion{
        string artista;
        int duracion;
        list<cancion> ::iterator it_Playlist;
        list<cancion> ::iterator it_Recientes;
    };
    
    unordered_map<string, infoCancion> ipud;
    list<cancion> recientes;
    list<cancion> playlist;
    int tiempoTotal;
    
public:
    iPud(){
        tiempoTotal = 0;
    }
    
    void addCancion(cancion c, string artista, int d){
        
        if (ipud.count(c) > 0)
            throw domain_error("ERROR addSong");
        
        ipud.insert({ c, { artista, d, playlist.end(), recientes.end() } });
        
    }
    
    void addToPlaylist(cancion c){
        if (ipud.count(c) == 0)
            throw domain_error("ERROR addToPlaylist");
        
        //si no existe en la playlist
        if (ipud[c].it_Playlist == playlist.end()){
            
            ipud[c].it_Playlist = playlist.insert(playlist.end(), c);
            // el iterador no hay que actualizarlo porque ya está apuntando al objeto insertado
            tiempoTotal += ipud[c].duracion;
        }
    }
    
    
    
    cancion play(){
        if (!playlist.empty()){
            cancion actual = playlist.front();
            playlist.pop_front();
            
            //si ya estaba antes en recientes
            if (ipud[actual].it_Recientes != recientes.end())
                recientes.erase(ipud[actual].it_Recientes);
            
            ipud[actual].it_Recientes = recientes.insert(recientes.begin(), actual);
            tiempoTotal -= ipud[actual].duracion;
            ipud[actual].it_Playlist = playlist.end();
            
            return actual;
        }
        else{
            return "ERROR";
        }
    }
    
    cancion current(){
        if (!playlist.empty()){
            return playlist.front();
        }
        else{
            throw domain_error("ERROR current");
        }
    }
    
    int totalTime(){
        
        if (!playlist.empty()){
            return tiempoTotal;
        }
        else{
            return 0;
        }
    }
    
    list<cancion> recent(int &N){
        list<cancion> lista;
        
        if (N > 0 && recientes.size() > 0){
            if (recientes.size() < N){
                N = recientes.size();
                return recientes;
            }
            else{
                int cont = 0;
                for(auto const &i : recientes){
                    if (cont < N){
                        lista.push_back(i);
                        cont++;
                    }
                }
                //auto rec_it = recientes.begin();
                
                return lista;
            }
        }
        else{
            return lista;
        }
    }
    
    void deleteSong(cancion c){
        
        if (ipud.count(c)>0){
            
            if (!recientes.empty() && ipud[c].it_Recientes != recientes.end()){
                recientes.erase(ipud[c].it_Recientes);
                ipud[c].it_Recientes = recientes.end();
                
            }
            if (!playlist.empty() && ipud[c].it_Playlist != playlist.end()){
                playlist.erase(ipud[c].it_Playlist);
                tiempoTotal -= ipud[c].duracion;
                ipud[c].it_Playlist = playlist.end();
            }
            ipud.erase(c);
        }
    }
};
