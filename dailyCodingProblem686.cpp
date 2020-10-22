#include <bits/stdc++.h>
using namespace std;

/*
You are given a tree with an even number of nodes.
Consider each connection between a parent and child node to be an "edge".
You would like to remove some of these edges, such that
the disconnected subtrees that remain each have an even number of nodes.

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

int dfs(int u, int& ans, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited){
	visited.insert(u);
	int current_odd = 0;
	
	for(int nei : graph[u]){
		if(visited.find(nei) == visited.end()){
			int sub_tree_count = dfs(nei, ans, graph, visited);
			
			if(sub_tree_count % 2 == 0){
				ans++;
			}
			else{
				current_odd += sub_tree_count;
			}
		}
	}
	
	return 1+current_odd;
}

int maxRemove(vector<pair<int, int>> v){
	unordered_map<int, vector<int>> graph;
	unordered_set<int> visited;
	
	for(auto it : v){
		graph[it.first].push_back(it.second);
		graph[it.second].push_back(it.first);
	}
	
	int ans = 0;
	
	for(auto it : graph){
		if(visited.find(it.first) == visited.end()){
			dfs(it.first, ans, graph, visited);
			break;
		}
	}
	
	return ans;
}

// main function
int main(){
	// vector<pair<int, int>> v = {
		// {1, 2}, {1, 3},
		// {3, 4}, {3, 5},
		// {4, 6}, {4, 7}, {4, 8},
	// };
	
	vector<pair<int, int>> v = {
		{0, 2}, {0, 1}, {0, 4}, 
		{2, 3}, {4, 5}, {5, 6}, 
		{5, 7}
	};
	
	cout << maxRemove(v) << "\n";
	return 0;
}