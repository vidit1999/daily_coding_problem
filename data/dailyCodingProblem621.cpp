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

The path does not have to pass through the root,
and each node can have any amount of children.
*/

class Graph{
	int V;
	vector<pair<int, int>> *adj;
	pair<int, int> bfs(int u);
	
	public:
	
	Graph(int V);
	~Graph();
	void addEdge(int u, int v, int wt);
	int longestPath();
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
	unordered_map<char, int> node_dist;
	
	queue<int> q({u});
	node_dist[u] = 0;
	
	while(!q.empty()){
		int front = q.front();
		q.pop();
		
		for(auto it : adj[front]){
			if(node_dist.find(it.first) == node_dist.end()){
				q.push(it.first);
				node_dist[it.first] = node_dist[front] + it.second;
			}
		}
	}
	
	int max_dist = INT_MIN;
	int node = u;
	
	for(auto it : node_dist){
		if(it.second > max_dist){
			max_dist = it.second;
			node = it.first;
		}
	}
	
	return {node, max_dist};
}

int Graph::longestPath(){
	pair<int, int> t1, t2;
	
	t1 = bfs('a');
	t2 = bfs(t1.first);
	
	return t2.second;
}

// main function
int main(){
	vector<pair<pair<int, int>,int>> graph_map = {
		{{'a', 'b'}, 3},
		{{'a', 'c'}, 5},
		{{'a', 'd'}, 8},
		{{'d', 'e'}, 2},
		{{'d', 'f'}, 4},
		{{'e', 'g'}, 1},
		{{'e', 'h'}, 1},
	};
	
	Graph g(8);
	
	for(auto it : graph_map){
		g.addEdge(it.first.first, it.first.second, it.second);
	}
	
	cout << g.longestPath() << "\n";
	
	return 0;
}