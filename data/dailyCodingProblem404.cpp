#include <bits/stdc++.h>
using namespace std;

/*
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping),
find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

int maxClassRoom(vector<pair<int, int>> intervals){
	vector<pair<int, bool>> startEnd; // true for start and false for ends
	
	for(auto it : intervals){
		startEnd.push_back({it.first, true});
		startEnd.push_back({it.second, false});
	}
	
	sort(startEnd.begin(), startEnd.end());
	
	int roomCount = 0, maxCount = 1;
	
	for(auto it : startEnd){
		if(it.second)
			roomCount++;
		else
			roomCount--;
		maxCount = max(maxCount, roomCount);
	}
	
	return maxCount;
}

// main function
int main(){
	cout << maxClassRoom({{30, 75}, {0, 50}, {60, 150}}) << "\n";
	return 0;
}