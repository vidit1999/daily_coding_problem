#include <bits/stdc++.h>
using namespace std;

/*
We're given a hashmap with a key courseId and value a list of courseIds,
which represents that the prerequsite of courseId is courseIds.
Return a sorted ordering of courses such that we can finish all courses.

Return null if there is no such ordering.

For example, given {'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []},
should return ['CSC100', 'CSC200', 'CSCS300'].
*/

vector<string> courseOrdering(unordered_map<string, vector<string>> course_map){
    unordered_map<string, vector<string>> graph;
	unordered_map<string, int> in_deg;
	queue<string> q;
	vector<string> topo_order;
	
	for(auto it : course_map){
        for(auto course : it.second) graph[course].push_back(it.first);
		in_deg[it.first] += it.second.size();
	}
	
	for(auto it : in_deg){
		if(it.second == 0)
			q.push(it.first);
	}
	
	int count = 0;
	
	while(!q.empty()){
		string front = q.front(); q.pop();
		topo_order.push_back(front);
		
		for(string neigh : graph[front]){
			if(--in_deg[neigh] == 0)
				q.push(neigh);
		}
		
		count++;
	}

	if(count != graph.size()) return {};
	
	return topo_order;
}


// main function
int main(){
	unordered_map<string, vector<string>> course_map = {
        {"CSC300", {"CSC100", "CSC200"}},
        {"CSC200", {"CSC100"}},
        {"CSC100", {}},
	};

    unordered_map<string, vector<string>> course_map2 = {
        {"CSC400", {"CSC100", "CSC200", "CSC300"}},
        {"CSC300", {"CSC100", "CSC200"}},
        {"CSC200", {"CSC100"}},
        {"CSC100", {}},
    };
    
    for(string s : courseOrdering(course_map))
        cout << s << "\n";
    
    cout << "\n";

    for(string s : courseOrdering(course_map2))
        cout << s << "\n";
	return 0;
}