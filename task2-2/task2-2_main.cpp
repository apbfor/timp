//
// Created by apbfor on 03.03.19.
//

#include <iostream>
#include "task2-2.h"
#include <ctime>
#include <fstream>

using  namespace std;


int main(int argc, char* argv[]){
    Tree tree;

    srand(time(NULL));
    for(int i=0; i<1000; i++){
        tree.add(rand()%40000);
    }

    if(tree.search(8))
        cout << "elem 8 found" << endl;
    else
        cout << "elem 8 not found " << endl;

    tree.printNode();

    cout << endl << tree.minElement()<< " is min elem" << endl;
    cout << tree.maxElement()<< " is max elem" << endl;



    return 0;
}