#include <bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

/*
In a directed graph, each node is assigned an uppercase letter.
We define a path's value as the number of most frequently-occurring
letter along that path. For example, if a path in the graph goes
through "ABACA", the value of the path is 3, since there are 3 occurrences of 'A' on the path.

Given a graph with n nodes and m directed edges, return the
largest value path of the graph. If the largest value is infinite, then return null.

The graph is represented with a string and an edge list.
The i-th character represents the uppercase letter of
the i-th node. Each tuple in the edge list (i, j) means
there is a directed edge from the i-th node to the j-th node.
Self-edges are possible, as well as multi-edges.

For example, the following input graph:

ABACA
[(0, 1),
 (0, 2),
 (2, 3),
 (3, 4)]

Would have maximum value 3 using the path of vertices [0, 2, 3, 4], (A, A, C, A).

The following input graph:

A
[(0, 0)]

Should return null, since we have an infinite loop.
*/

unordered_map<int, vector<int>> constructGraph(vector<pair<int, int>> edges){
	unordered_map<int, vector<int>> graph;
	
	for(auto it : edges){
		graph[it.first].push_back(it.second);
	}
	
	return graph;
}

void dfs(
	int node, bool visited[], string& s,
	unordered_map<int, vector<int>>& graph,
	int value_path_count[][ALPHABET_SIZE]
){
	visited[node] = true;
	
	for(int neighbour : graph[node]){
		if(!visited[neighbour]){
			dfs(neighbour, visited, s, graph, value_path_count);
		}
	}
	
	for(int neighbour : graph[node]){
		for(int i=0; i<ALPHABET_SIZE; i++){
			value_path_count[node][i] = max(
				value_path_count[node][i],
				value_path_count[neighbour][i]
			);
		}
	}
	
	value_path_count[node][s[node] - 'A']++;
}

int largestValuePath(string s, vector<pair<int, int>> edges){
	auto graph = constructGraph(edges);
	int value_path_count[s.length()][ALPHABET_SIZE];
	bool visited[s.length()];
    
    memset(value_path_count, 0, sizeof(value_path_count));
    memset(visited, false, sizeof(visited));
	
	for(int i=0; i<s.length(); i++){
		if(!visited[i])
			dfs(i, visited, s, graph, value_path_count);
	}
	
    int largest_val = 1;

	for(int i=0; i<s.length(); i++){
		for(int j=0; j<ALPHABET_SIZE; j++){
			largest_val = max(value_path_count[i][j], largest_val);
		}
	}
	
	return (largest_val == 1)? -1 : largest_val;
}

// main function
int main(){
    string s = "ABACA";
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {2, 3},
        {3, 4}
    };

    cout << largestValuePath(s, edges) << "\n";

	return 0;
}