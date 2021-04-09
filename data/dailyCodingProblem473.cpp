#include <bits/stdc++.h>
using namespace std;

/*
Write an algorithm that computes the reversal of a directed graph.
For example, if a graph consists of A -> B -> C,
it should become A <- B <- C
*/

// add edge to a graph
void addEdge(vector<int> adj[], int src, int dest){
	adj[src].push_back(dest);
}

// transpose a graph
void transposeGraph(vector<int> adj[], vector<int> trans[], int v){
	for(int i=0;i<v;i++)
		for(int j=0;j<adj[i].size();j++)
			addEdge(trans, adj[i][j], i);
}

// print a graph
void showGraph(vector<int> adj[], int v){
	for(int i=0;i<v;i++){
		cout << i << " --- ";
		for(int j=0;j<adj[i].size();j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}
}

// main function
int main(){
	int v = 3;
	vector<int> adj[v];
	
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
	addEdge(adj, 2, 0);
	
	vector<int> trans[v];
	transposeGraph(adj, trans, v);
	showGraph(trans, v);
	return 0;
}