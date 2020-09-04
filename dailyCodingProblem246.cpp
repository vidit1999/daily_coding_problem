#include <bits/stdc++.h>
#define CHARS 26
using namespace std;

/*
Given a list of words, determine whether the words can be chained to form a circle.
A word X can be placed in front of another word Y in a circle if the last character
of X is same as the first character of Y.

For example, the words ['chair', 'height', 'racket', touch', 'tunic'] can
form the following circle: chair --> racket --> touch --> height --> tunic --> chair.
*/

class Graph{
	int V;
	list<int> *adj;
	int *in_deg;
	
	public:
	
	Graph(int V);
	~Graph();
	void addEdge(int u, int v);
	void DFSUtil(int u, bool visited[]);
	bool isSC();
	bool isEulerian();
	Graph getTranspose();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	in_deg = new int[V]();
}

Graph::~Graph(){
	delete [] adj;
	delete [] in_deg;
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	(in_deg[v])++;
}

void Graph::DFSUtil(int u, bool visited[]){
	visited[u] = true;
	
	for(int i : adj[u]){
		if(!visited[i])
			DFSUtil(i, visited);
	}
}

Graph Graph::getTranspose(){
	Graph trans(V);
	
	for(int i=0; i<V; i++){
		for(int v : adj[i]){
			trans.adj[v].push_back(i);
			(trans.in_deg[i])++;
		}
	}
	
	return trans;
}

bool Graph::isSC(){
	bool visited[V];
	for(int i=0; i<V; i++)
		visited[i] = false;
	
	int n;
	for(n=0; n<V; n++){
		if(adj[n].size() > 0)
			break;
	}
	
	DFSUtil(n, visited);
	
	for(int i=0; i<V; i++){
		if(adj[i].size() > 0 && !visited[i])
			return false;
	}
	
	for(int i=0; i<V; i++)
		visited[i] = false;
	
	Graph tr = getTranspose();
	
	tr.DFSUtil(n, visited);
	
	for(int i=0; i<V; i++){
		if(adj[i].size() > 0 && !visited[i])
			return false;
	}
	
	return true;
}

bool Graph::isEulerian(){
	if(!isSC()) return false;
	
	for(int i=0; i<V; i++)
		if(adj[i].size() != in_deg[i])
			return false;
	
	return true;
}

bool canBeChained(string arr[], int n){
	Graph g(CHARS);
	
	for(int i=0; i<n; i++){
		string s = arr[i];
		g.addEdge(s[0]-'a', s[s.length()-1]-'a');
	}
	
	return g.isEulerian();
}

// main function
int main(){
	string arr1[] =  {"for", "geek", "rig", "kaf"}; 
    int n1 = sizeof(arr1)/sizeof(arr1[0]); 
    canBeChained(arr1, n1)?  cout << "Can be chained \n" : 
                           cout << "Can't be chained \n"; 
  
    string arr2[] =  {"aab", "abb"}; 
    int n2 = sizeof(arr2)/sizeof(arr2[0]); 
    canBeChained(arr2, n2)?  cout << "Can be chained \n" : 
                           cout << "Can't be chained \n"; 
	return 0;
}