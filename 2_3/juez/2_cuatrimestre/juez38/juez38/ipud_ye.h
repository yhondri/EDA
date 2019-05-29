#ifndef ipud_h
#define ipud_h

#include <unordered_map>
#include <iostream>
#include <list>
#include <stdexcept>
#include <algorithm>
using namespace std;

class ipud {
private:
	struct info_canc{
		string artista;
		int duracion;
		list<string>::iterator itPlaylist;
		list<string>::iterator itRecientes;
	};
	unordered_map<string, info_canc> mIpud;
	list<string> playlist, recientes;
	int totalDuracion = 0;

public:
	ipud() {};

	/*
	A~nade la cancion S (un string) del artista A (un string) con duracion D (un
int) al iPud. Si ya existe una cancion con el mismo nombre la operacion dara error.
	*/
	void addSong(string c, string a, int d) {
		if (mIpud.count(c) > 0) {
			throw invalid_argument("ERROR addSong");
		}
		mIpud[c] = { a, d, playlist.end(), recientes.end() };
	}

	/*
	A~nade la cancion S al final de la lista de reproduccion. Si la cancion ya se
encontraba en la lista entonces no se a~nade (es decir, la lista no tiene canciones repetidas). Si la
cancion no esta en el iPud se devuelve error.
	*/
	void addToPlaylist(string s) {
		if (mIpud.count(s) == 0) {
			throw invalid_argument("ERROR addToPlaylist");
		}
		if (mIpud[s].itPlaylist == playlist.end()) {
			//No se encuentra la cancion en la playlist, se añade al final de la lista
			mIpud[s].itPlaylist=playlist.insert(playlist.end(), s);
			totalDuracion += mIpud[s].duracion;
		}
	}

	string current() {
		if (playlist.empty()) {
			throw invalid_argument("ERROR current");
		}
		return playlist.front();
	}


	/*
	La primera cancion de la lista de reproduccion abandona la lista de reproduccion y se
registra como reproducida. Si la lista es vaca la accion no tiene efecto.
	*/
	string play() {
		if (playlist.empty()) {
			throw invalid_argument("No hay canciones en la lista");
		}
		string c = playlist.front();
		playlist.pop_front();
		mIpud[c].itPlaylist = playlist.end();
		if (mIpud[c].itRecientes == recientes.end()) {
			//no habia reproducido nunca
			mIpud[c].itRecientes = recientes.insert(recientes.begin(), c);
		}
		else if (mIpud[c].itRecientes != recientes.end()) {
			recientes.erase(mIpud[c].itRecientes);
			mIpud[c].itRecientes = recientes.insert(recientes.begin(), c);
		}
		totalDuracion -= mIpud[c].duracion;
		return c;
	}

	int totalTime() {
		if (playlist.empty()) {
			return 0;
		}
		else {
			return totalDuracion;
		}
	}

	/*
	La lista no tiene repeticiones, de manera que si
una cancion se ha reproducido mas de una vez solo gurara la reproduccion mas reciente.
	*/
	list<string> recent(int &n) {
		list<string> lista;
		if (recientes.empty()) {
			throw invalid_argument("No hay canciones recientes");
		}
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

	void deleteSong(string s) {
		if (mIpud.count(s) > 0) {

			
			if (mIpud[s].itPlaylist != playlist.end()) {
				playlist.erase(mIpud[s].itPlaylist);
				totalDuracion = max(0, totalDuracion - mIpud[s].duracion);
			} 
			if (mIpud[s].itRecientes != recientes.end()) {
				recientes.erase(mIpud[s].itRecientes);
			}
			mIpud.erase(s);
		}
	}
};
#endif // !ipud_h
