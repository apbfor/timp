//
// Created by apbfor on 12.05.19.
//

#include <cstddef>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

int main() {

    int n;
    n = 7;
    // чтение n ...
    vector < vector < pair<int,int> > > g (n);
    // чтение графа
    g[1].push_back(make_pair(2,7));
    g[1].push_back(make_pair(6,14));
    g[1].push_back(make_pair(3,9));
    g[2].push_back(make_pair(3,10));
    g[2].push_back(make_pair(4,15));
    g[3].push_back(make_pair(4,11));
    g[3].push_back(make_pair(6,2));
    g[4].push_back(make_pair(5,6));
    g[5].push_back(make_pair(6,9));

    int s = 1; // стартовая вершина

    vector<int> d (n, INF),  p (n); //хранит текущую длину d[v] кратчайшего пути из s в v, по умолчанию бесконечность
                                    // p[v] хранит предка вершины
    d[s] = 0; //длина пути из s в s равна 0
    vector<char> u (n); //здесь будем хранить, помечена вершина или ещё нет
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v])) //ищем вершину с минимальной d
                v = j;
        if (d[v] == INF) // если длина пути = бексконечности, переходим к следующей итерации
            break;
        u[v] = true; // отмечаем как посещенную

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first, // вершина, в которой оказались
                    len = g[v][j].second; // длина текущего ребра
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len; // релаксация
                p[to] = v; // предком вершины t0 является вершина v
            }
        }
    }
    for(int i=0; i<n-1; i++)
        cout << "from " << s << " to " << i+1 << " = " << d[i+1] << endl;

    vector<int> path;
    for (int v=6; v!=s; v=p[v])
        path.push_back (v);
    path.push_back (s);
    reverse(path.begin(), path.end());
    for (auto it : path)
        cout << it << ' ';
    cout << endl;

    return 0;
}