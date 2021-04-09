#include <bits/stdc++.h>
using namespace std;

/*
The transitive closure of a graph is a measure of which vertices are reachable from other vertices.
It can be represented as a matrix M, where M[i][j] == 1 if there is a path between vertices i and j,
and otherwise 0.

For example, suppose we are given the following graph in adjacency list form:

graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]
The transitive closure of this graph would be:

[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]
Given a graph, find its transitive closure.
*/

class Graph{
    int V;
    bool **tc;
    list<int> *adj;
    void addEdge(int u, int v) {adj[u].push_back(v);}
    void DFSUtil(int u, int v);

    public:
    Graph(int V, vector<vector<int>> graph);
    void transClosure();
};

Graph::Graph(int v, vector<vector<int>> graph){
    this->V = v;
    adj = new list<int>[v];
    tc = new bool*[v];

    for(int i=0;i<v;i++){
        tc[i] = new bool[v];
        memset(tc[i], false, v*sizeof(int));
    }

    for(int i=0;i<graph.size();i++){
        for(int j : graph[i])
            addEdge(i, j);
    }
}

void Graph::DFSUtil(int u, int v){
    tc[u][v] = true;

    for(int i : adj[v])
        if(!tc[u][i])
            DFSUtil(u, i);
}

void Graph::transClosure(){
    for(int i=0;i<V;i++)
        DFSUtil(i, i);

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++)
            cout << tc[i][j]<< " ";
        cout << "\n";
    }
}

// main function
int main(){
    Graph g(4,
    {
        {0, 1, 3},
        {1, 2},
        {2},
        {3}
    });

    g.transClosure();
	return 0;
}