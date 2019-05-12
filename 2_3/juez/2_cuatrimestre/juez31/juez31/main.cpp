//
//  main.cpp
//  juez31
//
//  Created by Yhondri on 05/05/2019.
//  Copyright © 2019 yhondri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>
#include <map>
#include <ctype.h>

using namespace std;

void toLower(string &word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
}

struct Nada {};

void resuelveCaso() {
    int numLineas;
    scanf("%d", &numLineas);
    while( numLineas != 0){
        char removeWhiteLine;
        scanf("%c", &removeWhiteLine);
        
        map<string, map<int, Nada>> wordsMap;
        
        for (int i = 1; i <= numLineas; i++) {
            string str;
            getline(cin, str);
            
            stringstream ss(str);
            string word;
            while(ss >> word){
                if(word.length() > 2) {
                    for(unsigned int j=0; j<word.length(); j++){
                        word[j] = tolower(word[j]);
                    }
                    
                    wordsMap[word][i];
                }
            }
        }
        for (auto it = wordsMap.cbegin(); it != wordsMap.cend(); ++it){
            printf("%s", (*it).first.c_str() );
            for (auto linesIt = (*it).second.cbegin(); linesIt != (*it).second.cend(); ++linesIt){
                printf(" %d", (*linesIt).first );
            }
            printf("%s\n", "" );
        }
        printf("%s\n", "----" );
        
        scanf("%d", &numLineas );
    }
}

int main(int argc, const char * argv[]) {
    //            ajustes para que cin extraiga directamente de un fichero
//#ifndef DOMJUDGE
//
//    ifstream in("/Users/yhondri/Documents/universidad/eda/2_3/juez/2_cuatrimestre/juez31/juez31/casos");
//    auto cinbuf = cin.rdbuf(in.rdbuf());
//#endif
////
    resuelveCaso();
    ////
//#ifndef DOMJUDGE
//    cin.rdbuf(cinbuf);
////        system("PAUSE");
//#endif
    
    return 0;
}
