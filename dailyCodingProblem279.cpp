#include <bits/stdc++.h>
using namespace std;

/*
A classroom consists of N students, whose friendships
can be represented in an adjacency list.
For example, the following descibes a situation where 0 is
friends with 1 and 2, 3 is friends with 6, and so on.

{0: [1, 2],
 1: [0, 5],
 2: [0],
 3: [6],
 4: [],
 5: [1],
 6: [3]} 

Each student can be placed in a friend group,
which can be defined as the transitive closure of
that student's friendship relations. In other words,
this is the smallest set such that no student in the
group has any friends outside this group.
For the example above, the friend groups
would be {0, 1, 2, 5}, {3, 6}, {4}.

Given a friendship list such as the one above,
determine the number of friend groups in the class.
*/

void dfsUtil(int v, vector<vector<int>> adj, vector<bool>& visited, vector<int>& group){
	visited[v] = true;
	group.push_back(v);
	
	for(auto it : adj[v]){
		if(!visited[it])
			dfsUtil(it, adj, visited, group);
	}
}

int countFriendGroup(vector<vector<int>> adj){
	vector<bool> visited(adj.size(), false);
	vector<vector<int>> friendGroup;
	int count = 0;
	
	for(int i=0;i<adj.size();i++){
		if(!visited[i]){
			vector<int> group;
			count++;
			dfsUtil(i, adj, visited, group);
			friendGroup.push_back(group);
		}
	}
	
	for(auto v : friendGroup){
		for(int i : v)
			cout << i << " ";
		cout << "\n";
	}
	
	return count;
}

// main function
int main(){
	vector<vector<int>> adj = {
		{1, 2},
		{0, 5},
		{0},
		{6},
		{},
		{1},
		{3}
	};
	
	cout << countFriendGroup(adj) << "\n";
	return 0;
}