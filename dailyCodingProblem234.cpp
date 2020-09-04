#include <bits/stdc++.h>
using namespace std;

/*
Recall that the minimum spanning tree is the subset of edges of a tree that connect
all its vertices with the smallest possible total edge weight.
Given an undirected graph with weighted edges, compute the maximum weight spanning tree.
*/

struct Edge{
	int src, dest, wt;
};

struct CompareEdge{
	bool operator () (Edge e1, Edge e2){
		return e2.wt > e1.wt;
	}
};

class DisjointSet{
	unordered_map<int, int> parent;
	
	public:
	DisjointSet(int N){
		for(int i=0; i<N; i++)
			parent[i] = i;
	}
	
	int Find(int k){
		if(parent[k] == k) return k;
		return Find(parent[k]);
	}
	
	void Union(int x, int y){
		int parent_x = Find(x);
		int parent_y = Find(y);
		
		parent[parent_x] = parent_y;
	}
};

vector<Edge> kruskal(vector<Edge> edges, int N){
	sort(edges.begin(), edges.end(), CompareEdge());
	
	vector<Edge> max_span_tree;
	DisjointSet ds(N);
	
	while(max_span_tree.size() != N-1){
		Edge next_edge = edges.back();
		edges.pop_back();
		
		int x = ds.Find(next_edge.src);
		int y = ds.Find(next_edge.dest);
		
		if(x != y){
			max_span_tree.push_back(next_edge);
			ds.Union(x, y);
		}
	}
	
	return max_span_tree;
}

// main function
int main(){
	vector<Edge> edges = {
		{ 0, 1, 7 }, { 1, 2, 8 }, { 0, 3, 5 }, { 1, 3, 9 },
		{ 1, 4, 7 }, { 2, 4, 5 }, { 3, 4, 15 }, { 3, 5, 6 },
		{ 4, 5, 8 }, { 4, 6, 9 }, { 5, 6, 11 }
	};
	
	int N = 7;
	for(auto edge : kruskal(edges, N)){
		cout << edge.src << " -- " << edge.dest << " -- " << edge.wt << "\n";
	}
	return 0;
}