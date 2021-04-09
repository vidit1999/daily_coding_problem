#include <bits/stdc++.h>
#define V 4
using namespace std;

/*
Given an undirected graph represented as an adjacency matrix and an integer k,
write a function to determine whether each vertex in the graph can be colored
such that no two adjacent vertices share the same color using at most k colors
*/

// checks if the color c is safe for node v
// by checking colors of its neighbours
bool isSafe(int v, int color[], int c, int graph[V][V]){
	for(int i=0;i<V;i++)
		if(graph[v][i] && color[i] == c)
			return false;
	return true;
}

// utility function for graphColoring
bool graphColoringUtil(int graph[V][V], int k, int color[], int v){
	if(v == V)
		return true;
	for(int c=1;c<=k;c++){
		if(isSafe(v, color, c, graph)){
			color[v] = c;
			if(graphColoringUtil(graph, k, color, v+1))
				return true;
			color[v] = 0;
		}
	}
	return false;
}

void graphColoring(int graph[V][V], int k){
	int color[V] = { 0 };
	if(graphColoringUtil(graph, k, color, 0) == false){
		cout << "Solution does not exist\n";
	}
	else{
		cout << "Solution exists.\n";
		cout << "These are the sequence of colors : ";
		for(int i=0;i<V;i++)
			cout << color[i] << " ";
		cout << "\n";
	}
}

/* Create following graph and test whether it is 3 colorable 
      (3)---(2) 
       |   / | 
       |  /  | 
       | /   | 
      (0)---(1) 
*/

// main function
int main(){
	int graph[V][V] = {
		{0,1,1,1},
		{1,0,1,0},
		{1,1,0,1},
		{1,0,1,0}
	};
	int k = 3;
	graphColoring(graph, k);
	return 0;
}