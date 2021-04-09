#include <bits/stdc++.h>
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
	vector<vector<int>> adj;
	vector<int> in;
	
	bool isSC();
	void DFSUtil(int v, vector<bool>& visited);
	Graph getTranspose();
	
	public:
	
	Graph(int V);
	void addEdge(int u, int v);
	bool isEulearianCycle();
};

Graph::Graph(int V){
	this->V = V;
	adj = vector<vector<int>>(V);
	in = vector<int>(V, 0);
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
	in[v]++;
}

void Graph::DFSUtil(int v, vector<bool>& visited){
	visited[v] = true;
	
	for(int nei : adj[v]){
		if(!visited[nei])
			DFSUtil(nei, visited);
	}
}

Graph Graph::getTranspose(){
	Graph gt(V);
	
	for(int v=0; v<V; v++){
		for(int nei : adj[v]){
			gt.addEdge(nei, v);
			gt.in[v]++;
		}
	}
	
	return gt;
}

bool Graph::isSC(){
	vector<bool> visited(V, false);
	
	int non_zero;
	for(int i=0;i<V;i++)
		if(adj[i].size() > 0){
			non_zero = i;
			break;
		}
	
	DFSUtil(non_zero, visited);
	
	for(int i=0;i<V;i++){
		if(adj[i].size() > 0 && !visited[i])
			return false;
	}
	
	Graph gt = getTranspose();
	
	visited = vector<bool>(V, false);
	
	gt.DFSUtil(non_zero, visited);
	
	for(int i=0;i<V;i++){
		if(adj[i].size() > 0 && !visited[i])
			return false;
	}
	
	return true;
}

bool Graph::isEulearianCycle(){
	if(!isSC())
		return false;
	
	for(int i=0;i<V;i++)
		if(adj[i].size() != in[i])
			return false;
	
	return true;
}

bool canChainCircle(vector<string> words){
	Graph g(26);
	
	for(string s : words)
		g.addEdge(s[0]-'a', s[s.length()-1]-'a');
	
	return g.isEulearianCycle();
}

// main function
int main(){
	vector<string> words = {"chair", "height", "racket", "touch", "tunic"};
	if(canChainCircle(words))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}