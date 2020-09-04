#include <bits/stdc++.h>
using namespace std;

/*
You are given a list of jobs to be done, where each job is represented by a start time and end time.
Two jobs are compatible if they don't overlap. Find the largest subset of compatible jobs.

For example, given the following jobs (there is no guarantee that jobs will be sorted):

[(0, 6),
(1, 4),
(3, 5),
(3, 8),
(4, 7),
(5, 9),
(6, 10),
(8, 11)]

Return:

[(1, 4),
(4, 7),
(8, 11)]
*/

bool customComapare(pair<int, int> job1, pair<int, int> job2){
	return job1.second < job2.second;
}

vector<pair<int, int>> compatibleJobs(vector<pair<int, int>> jobs){
	sort(jobs.begin(), jobs.end(), customComapare);
		
	vector<pair<int, int>> subset;
	int last = 0;
	
	for(auto it : jobs){
		if(it.first >= last){
			subset.push_back(it);
			last = it.second;
		}
	}
	
	return subset;
}

// main function
int main(){
	vector<pair<int, int>> jobs = {
		{0, 6},
		{1, 4},
		{3, 5},
		{3, 8},
		{4, 7},
		{5, 9},
		{6, 10},
		{8, 11}
	};
	
	for(auto it : compatibleJobs(jobs))
		cout << it.first << ", " << it.second << "\n";
	return 0;
}