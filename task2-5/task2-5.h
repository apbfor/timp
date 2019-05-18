//
// Created by apbfor on 05.05.19.
//

/*
 * 4. Граф неориентированный. Поиск в глубину с помощью списка смежности. Выделение связных компонент.
 */

#include <iostream>
#include <vector>
#include <list>

using  namespace std;


// Graph class represents a undirected graph using adjacency list representation
class Graph {
    vector<int> vertices; //for my comfort
    int max = 0;

    int V; // No. of vertices, for setting up graph

    // Pointer to an array containing adjacency lists
    list<int> *adj;

    // A function used by DFS
    void DFSUtil(int v, bool visited[]);

public:
    vector<int> onlyfortests;
    Graph(int V); // Constructor
    Graph(vector<int> node, vector<vector<int>> edge);

    void addEdge(int v, int w);

    void connectedComponents();
};