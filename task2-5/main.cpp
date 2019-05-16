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

// Graph class represents a undirected graph
// using adjacency list representation


// Method to print connected components in an undirected graph
void Graph::connectedComponents() {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int v = 0; v < V; v++)
        visited[v] = false;

    for (int v = 0; v < V; v++) {
        if (visited[v] == false) {
            // print all reachable vertices from v
            DFSUtil(v, visited);
            for(auto it : vertices)
                if(it == v)
                    cout << endl;
        }
    }
}

Graph::Graph(vector<int> node, vector<vector<int>> edge) {
    int v, w;
    int max = 0;
    for (auto it : node) {
        if (it > max)
            max = it;
        vertices.push_back(it);
    }
    this->V = max + 1;
    adj = new list<int>[this->V];

    vector<int> tmp;
    for (auto it : edge)
        for (auto it2 : it)
            tmp.push_back(it2);

    for (auto it : edge) {
        this->addEdge(it[0],it[1]);
    }
}

void Graph::DFSUtil(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    for (auto it : vertices)
        if (it == v) {
            cout << v << ' ';
            onlyfortests.push_back(v);
        }
    // Recur for all the vertices adjacent to this vertex
    for (auto it : adj[v])
        if (!visited[it])
            DFSUtil(it, visited);
}

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

// method to add an undirected edge
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

// Drive program to test above
int main() {

    // Create a graph given in the above diagram
    Graph g(6); // 6 vertices numbered from 0 to 5
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 5);

    Graph b({4,7,8,9,11,15}, { {4,7}, {7,9}, {11,15} });
    cout << "Following are connected components \n";
    b.connectedComponents();


    vector<int> vec1 = {4,7,9,8,11,15};
    vector<int> vec2 = {1,3,5,7,89};
    if (b.onlyfortests == vec1)
        cout << "true";
    else cout << "false";

    return 0;
}