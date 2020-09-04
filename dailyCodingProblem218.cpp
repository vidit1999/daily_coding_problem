#include <bits/stdc++.h>
using namespace std;

/*
Write an algorithm that computes the reversal of a directed graph.
For example, if a graph consists of A -> B -> C, it should become A <- B <- C.
*/

void addEdge(vector<int> graph[], int src, int dest){
	graph[src].push_back(dest);
}

void reverseGraph(vector<int> graph[], vector<int> reverse_graph[], int v){
	for(int i=0; i<v; i++){
		for(int j : graph[i])
			addEdge(reverse_graph, j, i);
	}
}

void printGraph(vector<int> graph[], int v){
	for(int i=0; i<v; i++){
		cout << i << " ---> ";
		for(int j : graph[i])
			cout << j << " ";
		cout << "\n";
	}
}

// main function
int main(){
	int v = 5;
	vector<int> graph[v];
	
	addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 4, 1);
    addEdge(graph, 4, 3);
	printGraph(graph, v);
	cout << "\n";
	
	vector<int> reverse_graph[v];
	reverseGraph(graph, reverse_graph, v);
	printGraph(reverse_graph, v);
	
	return 0;
}