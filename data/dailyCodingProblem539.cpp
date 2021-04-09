#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected graph, determine if it contains a cycle.
*/

class Graph{
    int V;
    vector<int> *adj;
    bool isCyclicUtil(int v, bool visited[], int parent);

    public:
    Graph(int v);
    ~Graph();
    void addEdge(int v, int w);
    bool isCyclic();
};

Graph::Graph(int v){
    this->V = v;
    this->adj = new vector<int>[v];
}

Graph::~Graph(){
    delete [] adj;
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::isCyclicUtil(int v, bool *visited, int parent){
    visited[v] = true;

    for(auto it : adj[v]){
        if(!visited[it]){
            if(isCyclicUtil(it, visited, v))
                return true;
        }
        else if(it != parent)
            return true;
    }
    return false;
}

bool Graph::isCyclic(){
    bool* visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    
    for(int i=0;i<V;i++){
        if(!visited[i])
            if(isCyclicUtil(i, visited, -1)){
                delete [] visited;
                return true;
            }
    }

    delete [] visited;
    return false;
}

// main function
int main(){
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);

    if(g1.isCyclic())
        cout << "Yes\n";
    else
        cout << "No\n";
    
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    if(g2.isCyclic())
        cout << "Yes\n";
    else
        cout << "No\n";
	return 0;
}