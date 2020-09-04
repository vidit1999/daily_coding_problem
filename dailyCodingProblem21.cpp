#include <bits/stdc++.h>
using namespace std;

/*
Given an array of time intervals (start, end) for classroom lectures
(possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

int roomsRequired(vector<pair<int, int>> intervals){
	vector<pair<int, bool>> times;
	
	for(auto interval : intervals){
		times.push_back({interval.first, true});
		times.push_back({interval.second, false});
	}
	
	sort(times.begin(), times.end());
	
    int max_count = 0, count = 0;

    for(auto it : times){
        if(it.second) count++;
        else count--;
        max_count = max(max_count, count);
    }
	
	return max_count;
}

// main function
int main(){
    vector<pair<int, int>> intervals = {{30, 75}, {0, 50}, {60, 150}};
    cout << roomsRequired(intervals) << "\n";
	return 0;
}