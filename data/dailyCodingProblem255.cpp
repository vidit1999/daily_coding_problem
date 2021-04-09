#include <bits/stdc++.h>
using namespace std;

/*
The transitive closure of a graph is a measure of which vertices are reachable
from other vertices. It can be represented as a matrix M, where M[i][j] == 1
if there is a path between vertices i and j, and otherwise 0.

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
	vector<int> *adj;
	void DFSUtil(int u, int v, int **tc);
	
	public:
	Graph(vector<vector<int>> graph);
	~Graph();
	void transitiveClosure();
};

Graph::Graph(vector<vector<int>> graph){
	V = graph.size();
	adj = new vector<int>[V];
	
	for(int i=0; i<V; i++){
		for(int j : graph[i])
			adj[i].push_back(j);
	}
}

Graph::~Graph(){ delete [] adj; }

void Graph::DFSUtil(int u, int v, int **tc){
	tc[u][v] = 1;
	
	for(int i : adj[v]){
		if(tc[u][i] == 0)
			DFSUtil(u, i, tc);
	}
}

void Graph::transitiveClosure(){
	int **tc = new int*[V];
    for(int i=0;i<V;i++)
        tc[i] = new int[V]();

	for(int i=0; i<V; i++)
		DFSUtil(i, i, tc);
	
	for(int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			cout << tc[i][j] << " ";
		}
		cout << "\n";
	}
}


// main function
int main(){
	vector<vector<int>> graph = {
		{0, 1, 3},
		{1, 2},
		{2},
		{3}
	};
	
	Graph g(graph);
	g.transitiveClosure();
	
	return 0;
}