//
//  main.cpp
//  iPud
//
//  Created by Yhondri on 25/6/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include <string>
#include "HashMap.h"
#include "List.h"
#include "Cancion.h"

using namespace std;

void reproductor();
void checkAction(string action);
void addSong();
void addToPlaylist();
void current();
void play();
void totalTime();
void recent();
void deleteSong();
void setUpRecentList(string songName);

HashMap<string, Cancion> library;
List<Cancion> playlist;
List<Cancion> recentList;

int main()
{
    reproductor();
    return 0;
}

void reproductor() {
    string commandParameter1; //Accion --> play, addSong....
    cin >> commandParameter1;
    while (true) {
        checkAction(commandParameter1);
        cin >> commandParameter1;
    }
}

void checkAction(string action) {
    if (action == "addSong") {
        addSong();
    }else if (action == "addToPlaylist") {
        addToPlaylist();
    }else if (action == "current") {
        current();
    }else if (action == "play") {
        play();
    }else if (action == "totalTime") {
        totalTime();
    }else if (action == "recent") {
        recent();
    }else if (action == "deleteSong") {
        deleteSong();
    }else if (action == "FIN") {
        cout << "---" << endl;
        library = HashMap<string, Cancion>();
        playlist = List<Cancion>();
        recentList = List<Cancion>();
    }
}

void addSong() {
    string songName; //Nombre de la caciÛn
    string author; //Autor de la canciÛn
    int duration; //DuraciÛn de la canciÛn.
    cin >> songName;
    cin >> author;
    cin >> duration;
    //	cout << "CanciÛn: " << songName << " Author: " << author << " Duration: " << duration << endl;
    if (library.contains(songName)){
        cout << "ERROR" << endl;
    }
    else {
        Cancion newSong = Cancion(songName, author, duration);
        library.insert(songName, newSong);
    }
}

void addToPlaylist() {
    string songName; //Nombre de la caciÛn
    cin >> songName;
    if (!library.contains(songName)) {
        cout << "ERROR" << endl;
    }
    else {
        List<Cancion>::ConstIterator songIterator = playlist.cbegin();
        bool found = false;
        while (!found && (songIterator != playlist.cend())){
            Cancion song = songIterator.elem();
            if (songName == song.getNombre()) {
                found = true;
            }
            songIterator.next();
        }
        if (!found){
            Cancion song = library[songName];
            playlist.push_back(song);
        }
    }
}

void current() {
    if (playlist.empty()){
        cout << "Error current" << endl;
    }else {
        cout << playlist.front().getNombre() << endl;
    }
}

void play() {
    if (playlist.empty()) {
        cout << "No hay canciones en la lista" << endl;
    }else {
        setUpRecentList(playlist.front().getNombre());//Borra la canción si existe
        recentList.push_front(playlist.front()); //Las mete LIFO
        cout << "Sonando " << playlist.front().getNombre() << endl;
        playlist.pop_front();
    }
}

void totalTime() {
    List<Cancion>::ConstIterator songIterator = playlist.cbegin();
    int time = 0;
    while (songIterator != playlist.cend()) {
        time += songIterator.elem().getDuracion();
        songIterator.next();
    }
    cout << time << endl;
}

void recent() {
    int n;
    cin >> n;
    
    cout << "Las " << n << " mas recientes" << endl;
    List<Cancion>::ConstIterator recentListIterator = recentList.cbegin();
    while (n > 0 && (recentListIterator != recentList.cend())) {
        cout << recentListIterator.elem().getNombre() << endl;
        recentListIterator.next();
        n--;
    }
}

void deleteSong() {
    string songName;
    cin >> songName;
    library.erase(songName); //Eliminamos canciÛn de la librerÌa
    List<Cancion>::Iterator playListIterator = playlist.begin();
    bool found = false;
    while (!found && playListIterator != playlist.end()) {
        if (playListIterator.elem().getNombre() == songName){
            playlist.erase(playListIterator);//Eliminamos canciÛn de la playList.
            found = true;
        }
        playListIterator.next();
    }
    setUpRecentList(songName);
}

void setUpRecentList(string songName) {
    List<Cancion>::Iterator recentListIterator = recentList.begin();
    bool found = false;
    while (!found && recentListIterator != recentList.end()) {
        if (recentListIterator.elem().getNombre() == songName) {
            recentList.erase(recentListIterator);//Eliminamos canciÛn de la playList.
            found = true;
        }
        recentListIterator.next();
    }
}
