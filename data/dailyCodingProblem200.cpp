#include <bits/stdc++.h>
using namespace std;

/*
Let X be a set of n intervals on the real line.
We say that a set of points P "stabs" X if every
interval in X contains at least one point in P.
Compute the smallest set of points that stabs X.

For example, given the intervals
[(1, 4), (4, 5), (7, 9), (9, 12)],
you should return [4, 9].
*/

bool compare_pair(pair<int, int> p1, pair<int, int> p2){
	return p1.second < p2.second;
}

vector<int> stabingPoints(vector<pair<int, int>> intervals){
	if(intervals.empty()) return {};
	
	sort(intervals.begin(), intervals.end(), compare_pair);
	
	int prev_pushed = INT_MIN;
	vector<int> ans;
	
	for(auto interval : intervals){
		if(interval.first > prev_pushed){
			ans.push_back(interval.second);
			prev_pushed = interval.second;
		}
	}
	
	return ans;
}

void testFunc(vector<vector<pair<int, int>>> v){
	for(auto intervals : v){
		for(int p : stabingPoints(intervals))
			cout << p << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{{1, 4}, {4, 5}, {7, 9}, {9, 12}},
		{{1, 2}, {1, 3}, {3, 4}, {4, 5}, {3, 6}},
	});
	return 0;
}