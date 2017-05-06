//
//  main.cpp
//  TADTema07
//
//  Created by Yhondri on 6/5/17.
//  Copyright © 2017 Yhondri. All rights reserved.
//

#include <iostream>
#include "DateTests.h"
#include "SetOfInts1.h"
#include "SetTests.h"
#include "SetOfInts3.h"

using namespace std;

void ejercicio3Tema7();
void fillSetOfInts(SetOfInts3 &setOfInts);
void getMins(int numbOfMins, SetOfInts3 &setOfInts);

int main(int argc, const char * argv[]) {
   	//testSmallSet();
    //testSetOfInts();
    //testGenericSet();
    //testDate1();
    //testDate2();
    //testDate3();
    //testDate4();
    
    //testCompareSet1();
    //testLessThanSet3();
    ejercicio3Tema7();

    return 0;
}

void ejercicio3Tema7() {
    SetOfInts3 setOfInts = SetOfInts3();
    int numbOfMins;
    cin >> numbOfMins;
    while (numbOfMins != 0) {
        fillSetOfInts(setOfInts);
        getMins(numbOfMins, setOfInts);
        cout << setOfInts << endl;
        cin >> numbOfMins;
    }
    
}

void fillSetOfInts(SetOfInts3 &setOfInts) {
    int newValue;
    cin >> newValue;
    while (newValue != -1) {
        setOfInts.add(newValue);
        cin >> newValue;
    }
}

void getMins(int numbOfMins, SetOfInts3 &setOfInts) {
    int size = setOfInts.getSize();
    while (size>0) {
        if (size>numbOfMins) {
            setOfInts.removeMax();
        }
        size--;
    }
}
