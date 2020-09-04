#include <bits/stdc++.h>
using namespace std;

/*
Given a collection of intervals, find the minimum number of intervals
you need to remove to make the rest of the intervals non-overlapping.

Intervals can "touch", such as [0, 1] and [1, 2], but they
won't be considered overlapping.

For example, given the intervals (7, 9), (2, 4), (5, 8),
return 1 as the last interval can be removed and the
first two won't overlap.

The intervals are not necessarily sorted in any order.
*/

bool compare(pair<int, int> p1, pair<int, int> p2){
	return p2.second > p1.second;
}

int minRemoveInterval(vector<pair<int, int>> intervals){
	sort(intervals.begin(), intervals.end(), compare);
	
	int min_remove = 0, end = INT_MIN;
	
	for(auto interval : intervals){
		if(interval.first < end)
			min_remove++;
		else
			end = interval.second;
	}
	
	return min_remove;
}

// main function
int main(){
	cout << minRemoveInterval({
		{7,9},
		{2,4},
		{5, 8},
	}) << "\n";
	return 0;
}