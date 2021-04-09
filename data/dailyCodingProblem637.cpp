#include <bits/stdc++.h>
using namespace std;

/*
Given a list of possibly overlapping intervals, return a new list of
intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)],
you should return [(1, 3), (4, 10), (20, 25)].
*/

vector<pair<int, int>> mergedIntervals(vector<pair<int, int>> intervals){
	if(intervals.empty()) return {};
	
	sort(intervals.begin(), intervals.end());
	
	stack<pair<int, int>> s;
	s.push(intervals[0]);
	
	for(int i=1; i<intervals.size(); i++){
		auto top = s.top();
		if(intervals[i].first <= top.second){
			top.second = max(top.second, intervals[i].second);
			s.pop();
			s.push(top);
		}
		else{
			s.push(intervals[i]);
		}
	}
	
	vector<pair<int, int>> ans;
	
	while(!s.empty()){
		ans.push_back(s.top());
		s.pop();
	}
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

// main function
int main(){
	vector<pair<int, int>> intervals = {
		{1, 3}, {5, 8}, {4, 10}, {20, 25}
	};
	
	for(auto interval : mergedIntervals(intervals)){
		cout << interval.first << ", " << interval.second << "\n";
	}
	return 0;
}