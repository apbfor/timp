//
// Created by apbfor on 05.05.19.
//

// C++ program to print connected components in
// an undirected graph
#include<iostream>
#include <list>
#include <vector>
#include "task2-5.h"

using namespace std;




// Drive program to test above
int main() {

    // Create a graph given in the above diagram
    Graph g(6); // 6 vertices numbered from 0 to 5
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 5);

    try {
        Graph b({4, 7, 8, 9, 11, 15, 56, 6, 3, 2, 1}, {{4,  7},
                                                       {7,  9},
                                                       {15, 11},
                                                       {1,   2},
                                                       {2,   3},
                                                       {3,  7}});
        cout << "Following are connected components \n";
        b.connectedComponents();

        cout << endl << endl << "~~~~~~~~~~~~~~~" << endl;
    }
    catch(std::out_of_range){
        cout << "Maybe you didn't add edge correctly " << endl;
    }


    return 0;
}