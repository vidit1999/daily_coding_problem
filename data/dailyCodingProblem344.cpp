#include <bits/stdc++.h>
using namespace std;

/*
You are given a tree with an even number of nodes. Consider each connection between
a parent and child node to be an "edge". You would like to remove some of these edges,
such that the disconnected subtrees that remain each have an even number of nodes.

For example, suppose your input was the following tree:

   1
  / \ 
 2   3
    / \ 
   4   5
 / | \
6  7  8

In this case, removing the edge (3, 4) satisfies our requirement.

Write a function that returns the maximum number of edges
you can remove while still satisfying this requirement.
*/


void addEdge(int u, int v, vector<int> graph[]){
	graph[u].push_back(v);
	graph[v].push_back(u);
}

int dfs(vector<int> graph[], unordered_set<int>& visited, int u, int& res){
	visited.insert(u);
	int currComponentNode = 0;
	
	for(auto node : graph[u]){
		if(visited.find(node) == visited.end()){
			int subTreeNodeCount = dfs(graph, visited, node, res);
			if(subTreeNodeCount%2 == 0) res++;
			else currComponentNode += subTreeNodeCount;
		}
	}
	
	return currComponentNode + 1;
}

int maxEdgeRemoveToMakeForest(vector<int> graph[]){
	unordered_set<int> visited;
	int res = 0;
	dfs(graph, visited, 0, res);
	return res;
}

// main function
int main(){
	int edges[][2] = {
		{0, 2}, {0, 1}, {0, 4},
		{2, 3}, {4, 5}, {5, 6},
		{5, 7}
	};
	int N = sizeof(edges)/sizeof(edges[0]);
	vector<int> graph[N+1];
	
	for(int i=0;i<N;i++)
		addEdge(edges[i][0], edges[i][1], graph);
	
	cout << maxEdgeRemoveToMakeForest(graph) << "\n";
	
	return 0;
}