#include <bits/stdc++.h>
using namespace std;

/*
Given a tree where each edge has a weight, compute the length of the longest path in the tree.

For example, given the following tree:

   a
  /|\
 b c d
    / \
   e   f
  / \
 g   h

and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1,
the longest path would be c -> a -> d -> f, with a length of 17.
*/

class Graph{
	int V;
	vector<pair<int, int>> *adj;
	pair<int, int> bfs(int u);
	
	public:
	
	Graph(int V);
	~Graph();
	void addEdge(int u, int v, int wt);
	int longestPathSum();
};

Graph::Graph(int V){
	this->V = V;
	adj = new vector<pair<int, int>>[V];
}

Graph::~Graph(){ delete [] adj; }

void Graph::addEdge(int u, int v, int wt){
	adj[u].push_back({v, wt});
	adj[v].push_back({u, wt});
}

pair<int, int> Graph::bfs(int u){
	unordered_map<int, int> path_sum;
	int max_node = INT_MIN, max_sum = INT_MIN;
	
	queue<int> q({u});
	path_sum[u] = 0;
	
	while(!q.empty()){
		int node = q.front(); q.pop();
		
		for(auto it : adj[node]){
			if(path_sum.find(it.first) == path_sum.end()){
				q.push(it.first);
				path_sum[it.first] = path_sum[node] + it.second;
			}
		}
	}
	
	for(auto it : path_sum){
		if(it.second > max_sum){
			max_node = it.first;
			max_sum = it.second;
		}
	}
	
	return {max_node, max_sum};
}

int Graph::longestPathSum(){
	auto t1 = bfs('a');
	auto t2 = bfs(t1.first);
	
	return t2.second;
}

// main function
int main(){
	vector<pair<pair<int, int>, int>> v = {
		{{'a', 'b'}, 3},
		{{'a', 'c'}, 5},
		{{'a', 'd'}, 8},
		{{'d', 'e'}, 2},
		{{'d', 'f'}, 4},
		{{'e', 'g'}, 1},
		{{'e', 'h'}, 1}
	};
	
	Graph g(8);
	
	for(auto it : v){
		g.addEdge(it.first.first, it.first.second, it.second);
	}
	
	cout << g.longestPathSum() << "\n";
	return 0;
}