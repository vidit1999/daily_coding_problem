#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected graph, determine if it contains a cycle.
*/

class Graph{
	int V;
	list<int>* adj;
	bool isCyclicUtil(int v, bool visited[], int parent);
	
	public:
	Graph(int v);
	~Graph();
	void addEdge(int u, int v);
	bool isCyclic();
};

Graph::Graph(int v){
	V = v;
	adj = new list<int>[v];
}

Graph::~Graph(){
	delete [] adj;
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::isCyclicUtil(int v, bool visited[], int parent){
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
	bool *visited = new bool[V]();	
	
	for(int u=0;u<V;u++){
		if(!visited[u])
			if(isCyclicUtil(u, visited, -1))
				return true;
	}
	return false;
}

// main function
int main(){
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	
	if(g.isCyclic())
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}