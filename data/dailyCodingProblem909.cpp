#include <bits/stdc++.h>
using namespace std;

/*
Given a set of closed intervals, find the smallest set of numbers that
covers all the intervals. If there are multiple smallest sets, return any of them.

For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9],
one set of numbers that covers all these intervals is {3, 6}.
*/

vector<int> minSetInterval(vector<pair<int,int>> intervals){
	if(intervals.empty()) return {};

	sort(
		intervals.begin(), intervals.end(),
		[](pair<int, int>& p1, pair<int, int>& p2){
			return p1.second < p2.second;
		}
	);

	vector<int> ans = {intervals[0].second};
	int prev = intervals[0].second;

	for(auto it : intervals){
		if(it.first > prev){
			ans.push_back(it.second);
			prev = it.second;
		}
	}

	return ans;
}

void testFunc(vector<vector<pair<int, int>>> v){
	for(auto intervals : v){
		auto ans = minSetInterval(intervals);
		for(int i : ans){
			cout << i << " ";
		}
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{{0, 3}, {2, 6}, {3, 4}, {6, 9}},
		{{0, 2}, {3, 5}, {7, 9}},
		{{0, 5}, {1, 4}, {2, 3}},
		{{1, 2}, {1, 3}, {3, 4}, {4, 5}, {3, 6}},
		{{1, 3}}
	});
	return 0;
}