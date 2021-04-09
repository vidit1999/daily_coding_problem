#include <bits/stdc++.h>
using namespace std;

/*
A classroom consists of N students, whose friendships can be represented in an adjacency list.
For example, the following descibes a situation where 0 is friends with
1 and 2, 3 is friends with 6, and so on.

{0: [1, 2],
 1: [0, 5],
 2: [0],
 3: [6],
 4: [],
 5: [1],
 6: [3]} 

Each student can be placed in a friend group, which can be
defined as the transitive closure of that student's friendship relations.
In other words, this is the smallest set such that no student in the group
has any friends outside this group. For the example above, the friend
groups would be {0, 1, 2, 5}, {3, 6}, {4}.

Given a friendship list such as the one above,
determine the number of friend groups in the class.
*/

void dfs(int u, unordered_set<int>& visited, unordered_map<int, vector<int>>& graph){
	visited.insert(u);
	
	for(int friend_num : graph[u]){
		if(visited.find(friend_num) == visited.end()){
			dfs(friend_num, visited, graph);
		}
	}
}

int friendGroupCount(unordered_map<int, vector<int>> graph){
	int count = 0;
	unordered_set<int> visited;
	
	for(auto it : graph){
		if(visited.find(it.first) == visited.end()){
			count++;
			dfs(it.first, visited, graph);
		}
	}
	
	return count;
}

// main function
int main(){
	unordered_map<int, vector<int>> graph = {
		{0, {1, 2}},
		{1, {0, 5}},
		{2, {0}},
		{3, {6}},
		{4, {}},
		{5, {1}},
		{6, {3}},
	};
	
	cout << friendGroupCount(graph) << "\n";
	
	return 0;
}