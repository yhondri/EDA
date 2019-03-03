//
//  Complejo.hpp
//  juez3
//
//  Created by Yhondri Josué Acosta Novas on 03/03/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#ifndef Complejo_h
#define Complejo_h

#include <stdio.h>

using namespace std;

template <class T>
class Complejo {

public:
    T getA() const;
    T getB() const;
    int numInteracciones;

    Complejo();
    Complejo(T a, T b, int numInteracciones);

    Complejo operator+(Complejo const& c) const;

    bool esDivergente();

private:
    T a;
    T b;

};

#endif /* Complejo_h */
