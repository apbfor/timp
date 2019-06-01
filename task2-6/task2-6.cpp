//
// Created by apbfor on 12.05.19.
//

#include <algorithm>
#include "task2-6.h"

Graph::Graph(int size, int start) {
    this->n = size;
    this->s = start;
    this->d = new vector<int> (n, INF);
    this->g = new vector <vector <pair<int,int> > > (n);
    this->p = new vector<int> (n);
    (*d)[s] = 0;
    this->u = new vector<char> (n);
}

void Graph::dijkstra() {
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!(*u)[j] && (v == -1 || (*d)[j] < (*d)[v])) //ищем вершину с минимальной (*d)
                v = j;
        if ((*d)[v] == INF) // если длина пути = бексконечности, переходим к следующей итерации
            break;
        (*u)[v] = true; // отмечаем как посещенную

        for (size_t j=0; j<(*g)[v].size(); ++j) {
            int to = (*g)[v][j].first, // вершина, в которой оказались
                    len = (*g)[v][j].second; // длина текущего ребра
            if ((*d)[v] + len < (*d)[to]) {
                (*d)[to] = (*d)[v] + len; // релаксация
                (*p)[to] = v; // предком вершины t0 является вершина v
            }
        }
    }
}

void Graph::printDijkstra() {
    for(int i=0; i<n-1; i++)
        cout << "from " << s << " to " << i+1 << " = " << (*d)[i+1] << endl;
}

void Graph::printPath(int to) {
    for (int v=to; v!=s; v=(*p)[v])
        path.push_back (v);
    path.push_back (s);
    reverse(path.begin(), path.end());
    for (auto it : path)
        cout << it << ' ';
    cout << endl;
}

void Graph::addEdge(int from, int to, int weight) {
    if (from < 0 || to > this->n)
        throw "You can't add this edge";
    (*g)[from].push_back(make_pair(to,weight));
}

vector<int> Graph::getPath() {
    return this->path;
}