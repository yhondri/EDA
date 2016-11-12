//
//  main.cpp
//  Iter6
//
//  Created by Yhondri on 12/11/16.
//  Copyright © 2016 Yhondri. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    bool seguir = true;
    string nextWord;
    while (seguir) {
        cin >> nextWord;
        if(nextWord != "XXX" ) {
            int i = 0;
            bool isOrdered = true;
            while (((unsigned)i) < nextWord.length()) {
                if (((unsigned)i+1) < nextWord.length()) {
                    if (nextWord.at(i) > nextWord.at(i+1)) {
                        isOrdered = false;
                    }
                }
                i++;
            }
            if (isOrdered) {
                cout << "SI" << endl;
            }else {
                cout << "NO" << endl;
            }
        }else {
            seguir = false;
        }
        nextWord = "";
    }
    return 0;
}
