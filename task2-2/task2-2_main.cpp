//
// Created by apbfor on 03.03.19.
//

#include <iostream>
#include "task2-2.h"
#include <ctime>
#include <fstream>

using  namespace std;


int main(){
    Tree* tree = NULL;


    for(int i = 0; i < 50; ++i)
        tree = InsertNode(tree, rand() % 500);


//    ofstream fout;
//    fout.open("asd.txt");


    PrintNode(cout, tree);
    cout << endl;
//    fout.close();

    tree = DeleteNode(tree, 5);
    tree = DeleteNode(tree, 2);
    tree = DeleteNode(tree, 9);
    tree = DeleteNode(tree, 7);
    tree = DeleteNode(tree, 7);

    Tree* search = NULL;
    search = SearchItem(tree, 7);

    if (search !=NULL) {
        cout << "searching of 7 results" << endl;
        cout << search->val << endl;
    } else
        cout << "element 7 was not found" << endl;


    cout << "min element is " << MinElement(tree)->val << endl;
    cout << "max element is " << MaxElement(tree)->val << endl << endl;


    ClearNode(tree);
    return 0;
}

