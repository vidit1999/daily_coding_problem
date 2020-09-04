#include <bits/stdc++.h>
using namespace std;

/*
Let X be a set of n intervals on the real line.
We say that a set of points P "stabs" X if every interval
in X contains at least one point in P. Compute the smallest set of points that stabs X.

For example, given the intervals [(1, 4), (4, 5), (7, 9), (9, 12)], you should return [4, 9].
*/

// O(nlogn) time | O(1) space
pair<int, int> stabingInterval(vector<pair<int, int>> intervals){
	sort(intervals.begin(), intervals.end());

	auto first_interval = intervals[0], last_interval = intervals[intervals.size()-1];

	return {first_interval.second, last_interval.first};
}

// O(n) time | O(1) space
pair<int, int> stabingInterval2(vector<pair<int, int>> intervals){
	pair<int, int> first_interval = {INT_MAX, INT_MAX},\
					last_interval = {INT_MIN, INT_MIN};

	for(auto interval : intervals){
		if(interval.first <= first_interval.first){
			first_interval = interval;
		}
		if(interval.second >= last_interval.second){
			last_interval = interval;
		}
	}

	return {first_interval.second, last_interval.first};
}

// main function
int main(){
	auto ans = stabingInterval2({{1, 4}, {1, 3}, {4, 5}, {7, 9}, {9, 12}, {10, 11}});
	cout << ans.first << " -- " << ans.second << "\n";
	return 0;
}