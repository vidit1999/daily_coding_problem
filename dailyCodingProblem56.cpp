#include <bits/stdc++.h>
#define V 4
using namespace std;

/*
Given an undirected graph represented as an adjacency matrix and an integer k,
write a function to determine whether each vertex in the graph can be colored
such that no two adjacent vertices share the same color using at most k colors.
*/

bool isSafeToColor(int graph[V][V], int color[], int v, int c){
	for(int i=0; i<V; i++){
		if(graph[i][v] && color[i] == c)
			return false;
	}
	return true;
}

bool graphColorHelper(int graph[V][V], int color[], int v, int k){
	if(v == V){
		return true;
	}
	
	for(int i=1; i<=k; i++){
        if(isSafeToColor(graph, color, v, i)){
            color[v] = i;
            if(graphColorHelper(graph, color, v+1, k)){
                return true;
            }
            color[v] = 0;
        }
	}
	
	return false;
}

bool graphColor(int graph[V][V], int k){
	if(k >= 4) return true;
	
	int color[V] = {0};
	
	if(!graphColorHelper(graph, color, 0, k)) return false;
	
	for(int i=0; i<V; i++) cout << color[i] << "\n";
	
	return true;
}

// main function
int main(){
	int graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
	int k = 3;
	
	cout << boolalpha << graphColor(graph, k) << "\n";
	
	return 0;
}