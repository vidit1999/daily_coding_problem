#include <bits/stdc++.h>
using namespace std;

/*
A competitive runner would like to create a route that starts and ends at his house,
with the condition that the route goes entirely uphill at first, and then entirely downhill.

Given a dictionary of places of the form {location: elevation},
and a dictionary mapping paths between some of these locations
to their corresponding distances, find the length of the shortest
route satisfying the condition above. Assume the runner's home is location 0.

For example, suppose you are given the following input:

elevations = {0: 5, 1: 25, 2: 15, 3: 20, 4: 10}
paths = {
    (0, 1): 10,
    (0, 2): 8,
    (0, 3): 15,
    (1, 3): 12,
    (2, 4): 10,
    (3, 4): 5,
    (3, 0): 17,
    (4, 0): 10
}

In this case, the shortest valid
path would be 0 -> 2 -> 4 -> 0,
with a distance of 28.
*/

bool checkBitonic(
	vector<int>& path,
	unordered_map<int, int>& elevations
){
	int i;
	
	for(i=1; i<path.size(); i++){
		if(elevations[path[i]] > elevations[path[i-1]]) continue;
		else break;
	}
	
	for(;i<path.size(); i++){
		if(elevations[path[i]] < elevations[path[i-1]]) continue;
		else break;
	}
	
	if(i != path.size()) return false;
	
	return true;
}

int getPathValue(
	vector<int>& path,
	unordered_map<int, unordered_map<int, int>>& graph
){
	int value = 0;
	
	for(int i=1; i<path.size(); i++){
		value += graph[path[i-1]][path[i]];
	}
	
	return value;
}

void getShortestPaths(
	int u,
	int& start,
	int& min_value,
	vector<int>& path,
	unordered_map<int, int>& elevations,
	unordered_map<int, unordered_map<int, int>>& graph,
	unordered_set<int>& visited
){
	if(!path.empty() && u == start){
		path.push_back(u);
		
		if(checkBitonic(path, elevations)){
			min_value = min(min_value, getPathValue(path, graph));
		}
		
		path.pop_back();
		return;
	}
	
	visited.insert(u);
	path.push_back(u);
	
	for(auto it : graph[u]){
		if(it.first == start || visited.find(it.first) == visited.end()){
			getShortestPaths(it.first, start, min_value, path, elevations, graph, visited);
		}
	}
	
	path.pop_back();
	visited.erase(u);
}

int shortestRoute(
	unordered_map<int, int>& elevations,
	vector<pair<pair<int, int>, int>>& paths
){
	unordered_map<int, unordered_map<int, int>> graph;
	
	for(auto path : paths){
		if(graph[path.first.first].find(path.first.second) == graph[path.first.first].end())
			graph[path.first.first][path.first.second] = path.second;
		else{
			graph[path.first.first][path.first.second] = min(
				graph[path.first.first][path.first.second],
				path.second
			);
		}
	}
	
	vector<int> path;
	unordered_set<int> visited;
	int start = 0;
	int min_value = INT_MAX;
	
	getShortestPaths(0, start, min_value, path, elevations, graph, visited);
	
	return min_value;
}

// main function
int main(){
	unordered_map<int, int> elevations = {
		{0, 5},
		{1, 25},
		{2, 15},
		{3, 20},
		{4, 10}
	};
	
	vector<pair<pair<int, int>, int>> paths = {
		{{0, 1}, 10},
		{{0, 2}, 8},
		{{0, 3}, 15},
		{{1, 3}, 12},
		{{2, 4}, 10},
		{{3, 4}, 5},
		{{3, 0}, 17},
		{{4, 0}, 10},
	};
	
	cout << shortestRoute(elevations, paths) << "\n";
	
	return 0;
}