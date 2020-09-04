#include <bits/stdc++.h>
using namespace std;

/*
A network consists of nodes labeled 0 to N.
You are given a list of edges (a, b, t),
describing the time t it takes for a
message to be sent from node a to node b.
Whenever a node receives a message,
it immediately passes the message on
to a neighboring node, if possible.

Assuming all nodes are connected,
determine how long it will take for
every node to receive a message
that begins at node 0.

For example, given N = 5, and the following edges:

edges = [
    (0, 1, 5),
    (0, 2, 3),
    (0, 5, 4),
    (1, 3, 8),
    (2, 3, 1),
    (3, 5, 10),
    (3, 4, 5)
]
You should return 9, because propagating
the message from 0 -> 2 -> 3 -> 4
will take that much time.
*/

class Graph{
	int size;
	vector<pair<int, int>>* adj;
	void dfsUtil(int u, int& time_count, unordered_set<int>& visited);
	
	public:
	Graph(int sz);
	~Graph();
	void addEdge(int u, int v, int wt);
	int countMaxTime();
};

Graph::Graph(int sz){
	size = sz;
	adj = new vector<pair<int, int>>[size];
}

Graph::~Graph(){
	delete [] adj;
}

void Graph::addEdge(int u, int v, int wt){
	adj[u].push_back({v, wt});
}


void Graph::dfsUtil(int start, int& time_count, unordered_set<int>& visited){
	visited.insert(start);
	
	int next_node_to_visit = -1, weight = INT_MAX;
	
	for(int node : visited){
		for(auto nei : adj[node]){
			if(visited.find(nei.first) == visited.end()){
				if(nei.second < weight){
					next_node_to_visit = nei.first;
					weight = nei.second;
				}
			}
		}
	}
	
	if(next_node_to_visit == -1) return;
	
	for(int node : visited){
		for(int i=0;i<adj[node].size();i++){
			if(visited.find(adj[node][i].first) == visited.end()){
				adj[node][i].second -= weight;
				if(adj[node][i].second <= 0)
					visited.insert(adj[node][i].first);
			}
		}
	}
	
	time_count += weight;
	
	dfsUtil(next_node_to_visit, time_count, visited);
	
}

int Graph::countMaxTime(){
	int start = 0, time_count = 0;
	unordered_set<int> visited;
	dfsUtil(start, time_count, visited);
	return time_count;
}

void timeToReachAll(vector<vector<int>> edges, int n){
	Graph g(n+1);
	for(auto edge : edges){
		g.addEdge(edge[0], edge[1], edge[2]);
	}
	cout << g.countMaxTime() << "\n";
}

// main function
int main(){
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 3},
        {0, 5, 4},
        {1, 3, 8},
        {2, 3, 1},
        {3, 5, 10},
        {3, 4, 5},
    };

    timeToReachAll(edges, 5);
	return 0;
}