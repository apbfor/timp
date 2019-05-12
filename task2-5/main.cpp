//
// Created by apbfor on 05.05.19.
//

#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    for(int i=0; i<=26; i++){
        if((i%12)+1==12)
            cout << i <<' ';
    }

    return 0;
}