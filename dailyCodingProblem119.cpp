#include <bits/stdc++.h>
using namespace std;

/*
Given a set of closed intervals, find the smallest set of numbers that
covers all the intervals. If there are multiple smallest sets, return any of them.

For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9],
one set of numbers that covers all these intervals is {3, 6}.
*/

pair<int, int> minInterval(vector<pair<int, int>> intervals){
	if(intervals.size() == 1) return intervals[0];
	
	sort(intervals.begin(), intervals.end());
	return {intervals.front().second, intervals.back().first};
}

void testFunc(vector<vector<pair<int, int>>> v){
	for(auto intervals : v){
		auto ans = minInterval(intervals);
		cout << ans.first << ", " << ans.second << "\n";
	}
}

// main function
int main(){
	testFunc({
		{{0, 3}, {2, 6}, {3, 4}, {6, 9}},
		{{1, 2}, {1, 3}, {3, 4}, {4, 5}, {3, 6}},
		{{1, 3}},
	});
	return 0;
}