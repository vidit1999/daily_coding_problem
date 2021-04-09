#include <bits/stdc++.h>
#define V 4
using namespace std;

/*
Given an undirected graph G, check whether it is bipartite. Recall that a graph
is bipartite if its vertices can be divided into two independent sets, U and V,
such that no edge connects vertices of the same set.
*/

bool isBipartiteUtil(int G[][V], int src, int colorArr[V]){
	colorArr[src] = 1;
	queue<int> q;
	q.push(src);
	
	while(!q.empty()){
		int node1 = q.front();
		q.pop();
		
		for(int node2=0;node2<V;node2++){
			if(G[node1][node2] && colorArr[node2] == -1){
				colorArr[node2] = 1 - colorArr[node1];
				q.push(node2);
			}
			else if(G[node1][node2] && colorArr[node1] == colorArr[node2])
				return false;
		}
	}
	
	return true;
}

bool isBipartite(int G[][V]){
	int colorArr[V] = { -1 };
	
	for(int i=0;i<V;i++)
		if(colorArr[i] == -1)
			if(!isBipartiteUtil(G, i, colorArr))
				return false;
	return true;
}

// main function
int main(){
	int G[][V] = {
		{0, 1, 0, 1},
		{1, 0, 1, 0},
		{0, 1, 0, 1},
		{1, 0, 1, 0}
	};
	
	if(isBipartite(G))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}