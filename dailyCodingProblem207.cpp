#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected graph G, check whether it is bipartite.
Recall that a graph is bipartite if its vertices can be
divided into two independent sets, U and V, such that
no edge connects vertices of the same set.
*/

void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool isBipartite(int u, vector<bool>& visited, vector<bool>& color, vector<int> adj[]){
	for(int v : adj[u]){
		if(!visited[v]){
			visited[v] = true;
			color[v] = !color[u];
			if(!isBipartite(v, visited, color, adj))
				return false;
		}
		else if(color[u] == color[v])
			return false;
	}
	
	return true;
}

// main function
int main(){
	int n = 6;
	vector<int> adj[n+1];
	vector<bool> visited(n+1, false);
	vector<bool> color(n+1, false);
	
	addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 1);
	
	visited[1] = true;
	color[1] = true;
	
	if(isBipartite(1, visited, color, adj))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}