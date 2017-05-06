//
//  Pair.h
//  EjemploTAD01
//
//  Created by Yhondri on 6/5/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

template <class A, class B>

class Pair {
    A _a;
    B _b;
    
public:
    
    Pair(A a, B b) {
        _a = a;
        _b = b;
    }
    
    A first() const {
        return _a;
    }
    
    B second() const {
        return _b;
    }
    
};
