#include <bits/stdc++.h>
using namespace std;

/*
We're given a hashmap associating each courseId key with a
list of courseIds values, which represents that the prerequisites
of courseId are courseIds. Return a sorted ordering of courses
such that we can finish all courses.

Return null if there is no such ordering.

For example, given
{'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []},
should return ['CSC100', 'CSC200', 'CSCS300'].
*/

void topologicalSort(
	string s, unordered_map<string, vector<string>>& graph,
	unordered_set<string>& visited, vector<string>& v
){
	visited.insert(s);

	for(string nei : graph[s]){
		if(visited.find(nei) == visited.end()){
			topologicalSort(nei, graph, visited, v);
		}
	}

	v.push_back(s);
}

vector<string> courseOrdering(unordered_map<string, vector<string>>& graph){
	unordered_set<string> visited;
	vector<string> v;

	for(auto course : graph){
		if(visited.find(course.first) == visited.end()){
			topologicalSort(course.first, graph, visited, v);
		}
	}

	return v;
}

// main function
int main(){
	unordered_map<string, vector<string>> graph = {
		{"CSC300", {"CSC100", "CSC200"}},
		{"CSC200", {"CSC100"}},
		{"CSC100", {}}
	};

	for(string courseId : courseOrdering(graph)){
		cout << courseId << "\n";
	}
	return 0;
}