//
// Created by apbfor on 12.05.19.
//

#include <cstddef>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>
#include "task2-6.h"

using namespace std;

int main() {
    Graph a(7,1);
    a.addEdge(1,2,7);
    a.addEdge(1,6,14);
    a.addEdge(1,3,9);
    a.addEdge(2,3,10);
    a.addEdge(2,4,15);
    a.addEdge(3,4,11);
    a.addEdge(3,6,2);
    a.addEdge(4,5,6);
    a.addEdge(5,6,9);
    a.dijkstra();
    a.printDijkstra();
    a.printPath(6);


    return 0;
}