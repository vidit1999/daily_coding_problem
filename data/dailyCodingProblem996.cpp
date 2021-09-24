#include <bits/stdc++.h>
using namespace std;

/*
Recall that the minimum spanning tree is the subset of edges of a tree that
connect all its vertices with the smallest possible total edge weight.
Given an undirected graph with weighted edges, compute the maximum weight spanning tree.
*/

struct Edge{
	int src, dest;
	int weight;
};

struct subset{
	int parent;
	int rank;
};

struct Graph{
	int V;
	int E;
	vector<Edge> edges;
};

int Find(subset subsets[], int k){
	if(subsets[k].parent != k){
		return Find(subsets, subsets[k].parent);
	}
	
	return k;
}

void Union(int x, int y, subset subsets[]){
	int x_root = Find(subsets, x);
	int y_root = Find(subsets, y);
	
	if(subsets[x_root].rank > subsets[y_root].rank){
		subsets[x_root].parent = y_root;
	}
	else if(subsets[x_root].rank < subsets[y_root].rank){
		subsets[y_root].parent = x_root;
	}
	else{
		subsets[y_root].parent = x_root;
		subsets[x_root].rank++;
	}
}

void kruskalAlgo(vector<Edge> graph, int V){
	int E = graph.size();
	Edge result[V];
	int e = 0, i = 0;
	
	sort(
		graph.begin(), graph.end(),
		[](Edge& e1, Edge& e2){
			return e1.weight > e2.weight;
		}
	);
	
	subset subsets[V];
	
	for(int i=0; i<V; i++){
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	
	while(e < V-1 && i < E){
		auto next_edge = graph[i++];
		
		int x = Find(subsets, next_edge.src);
		int y = Find(subsets, next_edge.dest);
		
		if(x != y){
			result[e++] = next_edge;
			Union(x, y, subsets);
		}
	}
	
	int max_cost = 0;
	
	for(int i=0; i<e; i++){
		cout << result[i].src << " --> " << result[i].dest << ", (" << result[i].weight << ")\n";
		max_cost += result[i].weight;
	}
	
	cout << "Max cost : " << max_cost << "\n";
}

// main function
int main(){
	vector<Edge> graph = {
		{0, 1, 10},
		{0, 2, 6},
		{0, 3, 5},
		{1, 3, 15},
		{2, 3, 4}
	};
	int V = 5;
	
	kruskalAlgo(graph, V);
	
	return 0;
}