#include <bits/stdc++.h>
using namespace std;

/*
A graph is minimally-connected if it is connected and there is no edge that can be
removed while still leaving the graph connected. For example, any binary tree is minimally-connected.

Given an undirected graph, check if the graph is minimally-connected.
You can choose to represent the graph as either an adjacency matrix or adjacency list.
*/

class Graph{
	int V;
	list<int> *adj;
	bool isCyclicUtil(int u, int parent, bool visited[]);
	
	public:
	
	Graph(int V);
	~Graph();
	void addEdge(int u, int v);
	bool isMinimallyConnected();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph(){ delete [] adj; }

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::isCyclicUtil(int u, int parent, bool visited[]){
	visited[u] = true;
	
	for(int v : adj[u]){
		if(!visited[v]){
			if(isCyclicUtil(v, u, visited))
				return true;
		}
		else if(v != parent)
			return true;
	}
	
	return false;
}

bool Graph::isMinimallyConnected(){
	bool visited[V];
	memset(visited, false, sizeof(visited));
	
	if(isCyclicUtil(0, -1, visited)){
		return false;
	}
	
	for(int u=0; u<V; u++){
		if(!visited[u])
			return false;
	}
	
	return true;
}

// main function
int main(){
	Graph g1(5);
	g1.addEdge(0,1);
	g1.addEdge(0,2);
	g1.addEdge(0,3);
	g1.addEdge(3,4);
	
	Graph g2(5);
	g2.addEdge(0,1);
	g2.addEdge(0,2);
	g2.addEdge(0,3);
	g2.addEdge(3,4);
	g2.addEdge(1,2);
	
	if(g1.isMinimallyConnected())
		cout << "Yes\n";
	else
		cout << "No\n";
	
	if(g2.isMinimallyConnected())
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}