//
// Created by apbfor on 12.05.19.
//

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    const int INF = 1000000000;
    int n = 0; //count of vert.
    vector < vector < pair<int,int> > > *g; //graph
    int s = 1; //vert for start
    vector<int> *d; //stores length of shortest path from s to v;
    vector<int> *p; //stores parent of vert;
    vector<char> *u; //stores logical - visited or not
    vector<int> path;
public:
    void addEdge(int from, int to, int weight);
    void dijkstra();
    void printDijkstra();
    Graph(int size, int start = 1);
    void printPath(int to);
    vector<int> getPath();

};