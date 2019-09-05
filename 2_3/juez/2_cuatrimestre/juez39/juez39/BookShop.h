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
    
    bookInfo(bookId newId, int n) : mBookId(newId), ejemplares(n), numEjemplaresVendidos(0) {
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
//    map<int, list<bookId>> ventasMap;
    list<bookId> ventasList;
    
    public:
    bookShop() {};

    void nuevoLibro(int ejemplares, bookId libro) {
        if (booksMap.count(libro) == 0) {
//            list<bookId> &lista = ventasMap[0];
//            list<bookId>:: iterator insertResult = ventasList.insert(ventasList.begin(), libro);
            booksMap[libro] = bookInfo(libro, ejemplares);
        } else {
            bookInfo &mBook = booksMap[libro];
            int totalEjemplares = ejemplares + mBook.getEjemplares();
            mBook.setEjemplares(totalEjemplares);
        }
    }
    
    void comprar(bookId libro) {
        if (booksMap.count(libro) == 0) {
            throw invalid_argument("Libro no existente");
        }
        
        if (booksMap[libro].getEjemplares() == 0) {
            throw out_of_range("No hay ejemplares");
        }
        
        bookInfo &book = booksMap[libro];
        
        int totalEjemplares = book.getEjemplares() - 1;
        book.setEjemplares(totalEjemplares);
        
//        list<bookId> &listaPuntosVendidosAntes = ventasMap[book.getEjemplaresVendidos()];
//        listaPuntosVendidosAntes.erase(book.getItLista());
        

        list<bookId>:: iterator nuevaPos;
        if (book.getEjemplaresVendidos() > 0) {
            nuevaPos = next(book.getItLista(), 1);
            ventasList.erase(book.getItLista());
        } else {
            nuevaPos = next(ventasList.begin(), 1);
        }

        book.annadirEjemplarVendido();

//        list<bookId> &listaNuevosPuntos = ventasMap[book.getEjemplaresVendidos()];
        
        book.setItLista(ventasList.insert(nuevaPos, libro));
    }
    
    bool estaLibro(bookId libro) {
        return (booksMap.count(libro) > 0);
    }
    
    void elimLibro(bookId libro) {
        if (booksMap.count(libro) == 0) {
            return;
        }
        
        bookInfo &book = booksMap[libro];
        
        if (book.getEjemplaresVendidos() > 0) {
            ventasList.erase(book.getItLista());
        }
        
        booksMap.erase(libro);
    }
    
    int numEjemplares(bookId libro) {
        if (booksMap.count(libro) == 0) {
            throw invalid_argument("Libro no existente");
        }
        
        return booksMap[libro].getEjemplares();
    }
    
    list<bookId> top10() const {
//        int totalLibros = 0;
//        list<bookId> result;
//
//        for(auto it = ventasMap.rbegin(); it != ventasMap.rend() && totalLibros < 10; ++it) {
//            if (it->first > 0) {
//                for(auto value : it->second) {
//                    result.push_back(value);
//                    totalLibros++;
//                }
//            }
//        }
        
        return ventasList;
    }
    
};


#endif /* BookShop_h */
