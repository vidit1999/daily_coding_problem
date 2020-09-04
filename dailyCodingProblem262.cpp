#include <bits/stdc++.h>
#define NIL -1
using namespace std;

/*
A bridge in a connected (undirected) graph is an edge that, if removed,
causes the graph to become disconnected. Find all the bridges in a graph.
*/

class Graph{
	int size;
	list<int> *adj;
	void bridgeUtil(int u, bool visited[], int low[], int disc[], int parent[]);
	
	public:
	Graph(int size);
	~Graph();
	void addEdge(int u, int v);
	void bridge();
};

Graph::Graph(int size){
	this->size = size;
	adj = new list<int>[size];
}

Graph::~Graph(){ delete [] adj; }

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::bridgeUtil(int u, bool visited[], int low[], int disc[], int parent[]){
	static int visit_time = 0;
	visited[u] = true;
	low[u] = disc[u] = ++visit_time;
	
	for(int v : adj[u]){
		if(!visited[v]){
			parent[v] = u;
			bridgeUtil(v, visited, low, disc, parent);
			
			low[u] = min(low[u], low[v]);
			if(low[v] > disc[u])
				cout << u << ", " << v << "\n";
		}
		else if(v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void Graph::bridge(){
	bool *visited = new bool[size];
	int *parent = new int[size];
	int *low = new int[size], *disc = new int[size];
	
	for(int i=0; i<size; i++){
        visited[i] = false;
        parent[i] = NIL;
    }
	
	for(int i=0; i<size; i++){
		if(!visited[i])
			bridgeUtil(i, visited, low, disc, parent);
	}
}

// main function
int main(){
	
	cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.bridge();
 
    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.bridge();
 
    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.bridge();
	
	return 0;
}