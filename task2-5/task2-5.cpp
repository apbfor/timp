//
// Created by apbfor on 05.05.19.
//

#include "task2-5.h"

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
            for (auto it : vertices)
                if (it == v) {
                    connected.push_back(util);
                    cout << endl;
                    util.clear();
                }

        }
    }
}

Graph::Graph(vector<int> node, vector<vector<int>> edge) {
    int v, w;
    for (auto it : node) {
        if (it > max)
            max = it;
        vertices.push_back(it);
    }
    this->V = max + 1;
    adj = new list<int>[this->V];


    for (auto it : edge) {
        this->addEdge(it.at(0),it.at(1));
    }
}

void Graph::DFSUtil(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    for (auto it : vertices)
        if (it == v) {
            cout << v << ' ';
            util.push_back(v);
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