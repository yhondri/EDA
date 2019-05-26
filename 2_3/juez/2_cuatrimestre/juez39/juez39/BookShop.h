//
//  BookShop.h
//  juez39
//
//  Created by Yhondri on 24/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#ifndef BookShop_h
#define BookShop_h

#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <list>
#include <stdexcept>
#include <sstream>      // std::stringstream

using namespace std;

using bookId = string;

struct bookInfo {
    private:
    bookId mBookId;
    int ejemplares;
    int numEjemplaresVendidos;
    list<bookId>:: iterator itBook;
    
    public:
    bookInfo() = default;
    
    bookInfo(bookId newId, int n,  list<string>:: iterator mItBook) : mBookId(newId), ejemplares(n), numEjemplaresVendidos(0), itBook(mItBook) {
    }
    
    int getEjemplares() const {
        return ejemplares;
    }
    
    void setEjemplares(int n) {
        this->ejemplares = n;
    }
    
    list<bookId>:: iterator getItLista() {
        return itBook;
    }
    
    void setItLista(list<bookId>:: iterator it) {
        this->itBook = it;
    }
    
    int getEjemplaresVendidos() const {
        return numEjemplaresVendidos;
    }
    
    void annadirEjemplarVendido() {
        numEjemplaresVendidos++;
    }
};

class bookShop {
    private:
    unordered_map<bookId, bookInfo> booksMap;
    map<int, list<bookId>> ventasMap;
    
    public:
    void nuevoLibro(int ejemplares, bookId libro) {
        if (booksMap.count(libro) == 0) {
            list<bookId>:: iterator insertResult = ventasMap[0].insert(ventasMap[0].end(), libro);
            booksMap[libro] = bookInfo(libro, ejemplares, insertResult);
        } else {
            int totalEjemplares = ejemplares + booksMap[libro].getEjemplares();
            booksMap[libro].setEjemplares(totalEjemplares);
        }
    }
    
    void comprar(bookId libro) {
        if (booksMap.count(libro) == 0) {
            throw invalid_argument("Libro no existente");
        }
        
        if (booksMap[libro].getEjemplares() == 0) {
            throw out_of_range("No hay ejemplares");
        }
        
        int totalEjemplares = booksMap[libro].getEjemplares() - 1;
        booksMap[libro].setEjemplares(totalEjemplares);
        
        list<bookId> &listaPuntosVendidosAntes = ventasMap[booksMap[libro].getEjemplaresVendidos()];
        listaPuntosVendidosAntes.erase(booksMap[libro].getItLista());
        
        booksMap[libro].annadirEjemplarVendido();
        
        list<bookId> &listaNuevosPuntos = ventasMap[booksMap[libro].getEjemplaresVendidos()];
        booksMap[libro].setItLista(listaNuevosPuntos.insert(listaNuevosPuntos.begin(), libro));
    }
    
    bool estaLibro(bookId libro) {
        return (booksMap.count(libro) > 0);
    }
    
    void elimLibro(bookId libro) {
        if (booksMap.count(libro) == 0) {
            return;
        }
        
        ventasMap[booksMap[libro].getEjemplaresVendidos()].erase(booksMap[libro].getItLista());
        booksMap.erase(libro);
    }
    
    int numEjemplares(bookId libro) {
        if (booksMap.count(libro) == 0) {
            throw invalid_argument("Libro no existente");
        }
        
        return booksMap[libro].getEjemplares();
    }
    
    list<bookId> top10() {
        int totalLibros = 0;
        list<bookId> result;
        
        for(auto it = ventasMap.rbegin(); it != ventasMap.rend() && totalLibros < 10; ++it) {
            if (it->first > 0) {
                for(auto value : it->second) {
                    result.push_back(value);
                    totalLibros++;
                }
            }
        }
        
        return result;
    }
    
};


#endif /* BookShop_h */
