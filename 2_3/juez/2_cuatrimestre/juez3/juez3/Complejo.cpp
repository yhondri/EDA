//
//  Complejo.cpp
//  juez3
//
//  Created by Yhondri Josué Acosta Novas on 03/03/2019.
//  Copyright © 2019 Yhondri. All rights reserved.
//

#include "Complejo.h"

template<typename T>
Complejo<T>::Complejo(void) {}

template<typename T>
Complejo<T>::Complejo(T a, T b, int numInteracciones) {
    this->a = a;
    this->b = b;
    this->numInteracciones = numInteracciones;
}
