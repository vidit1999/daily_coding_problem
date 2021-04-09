#include <bits/stdc++.h>
using namespace std;

/*
A graph is minimally-connected if it is connected and there is no edge that can be removed while
still leaving the graph connected. For example, any binary tree is minimally-connected.

Given an undirected graph, check if the graph is minimally-connected.
You can choose to represent the graph as either an adjacency matrix or adjacency list.
*/

class Graph{
	int V;
	list<int> *adj;
	bool isCyclic(int u, bool visited[], int parent);
	
	public:
	Graph(int v);
	~Graph();
	void addEdge(int u, int v);
	bool isMinimallyConnected();
};

Graph::Graph(int v){
	V = v;
	adj = new list<int>[V];
}

Graph::~Graph(){
	delete [] adj;
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::isCyclic(int v, bool visited[], int parent){
	visited[v] = true;
	
	for(int it : adj[v]){
		if(!visited[it]){
			if(isCyclic(it, visited, v))
				return true;
		}
		else if(it != parent)
			return true;
	}
	
	return false;
}

bool Graph::isMinimallyConnected(){
	bool visited[V];
	for(int i=0;i<V;i++)
		visited[i] = false;
	
	if(isCyclic(0, visited, -1)) return false;
	
	for(bool i : visited)
		if(!i) return false;
	
	return true;
}

// main function
int main(){
	Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
	
	if(g1.isMinimallyConnected())
		cout << "Yes\n";
	else
		cout << "No\n";
	
	Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
	
	if(g2.isMinimallyConnected())
		cout << "Yes\n";
	else
		cout << "No\n";
	
	return 0;
}