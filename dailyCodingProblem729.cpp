#include <bits/stdc++.h>
using namespace std;

/*
You have access to ranked lists of songs for various users.
Each song is represented as an integer, and more preferred
songs appear earlier in each list. For example, the list
[4, 1, 7] indicates that a user likes song 4 the best,
followed by songs 1 and 7.

Given a set of these ranked lists, interleave them to
create a playlist that satisfies everyone's priorities.

For example, suppose your input is {[1, 7, 3], [2, 1, 6, 7, 9], [3, 9, 5]}.
In this case a satisfactory playlist could be [2, 1, 6, 7, 3, 9, 5].
*/


void topologicalSortHelper(
	int u, unordered_map<int, vector<int>>& graph,
	stack<int>& s, unordered_set<int>& visited
){
	visited.insert(u);
	
	for(auto& nei : graph[u]){
		if(visited.find(nei) == visited.end()){
			topologicalSortHelper(nei, graph, s, visited);
		}
	}
	
	s.push(u);
}

vector<int> satisfactoryPlaylist(vector<vector<int>> ranked_list){
	unordered_map<int, vector<int>> graph;
	
	for(auto& it : ranked_list){
		graph[it[0]] = {};
		for(int i=1; i<it.size(); i++){
			graph[it[i-1]].push_back(it[i]);
		}
	}
	
	stack<int> s;
	unordered_set<int> visited;
	
	for(auto& it : graph){
		if(visited.find(it.first) == visited.end()){
			topologicalSortHelper(it.first, graph, s, visited);
		}
	}
	
	vector<int> ans;
	
	while(!s.empty()){
		ans.push_back(s.top());
		s.pop();
	}
	
	return ans;
}

// main function
int main(){
	auto ans = satisfactoryPlaylist({
		{1, 7, 3},
		{2, 1, 6, 7, 9},
		{3, 9, 5},
	});
	
	for(int i : ans){
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}