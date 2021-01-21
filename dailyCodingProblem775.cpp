#include <bits/stdc++.h>
using namespace std;

/*
Given an array of time intervals (start, end) for classroom
lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

int minimumRooms(vector<pair<int, int>> intervals) {
    vector<pair<int, bool>> start_end;

    for(auto interval : intervals) {
        start_end.push_back({interval.first, true});
        start_end.push_back({interval.second, false});
    }

    sort(start_end.begin(), start_end.end());

    int max_count = 0, curr_count = 0;

    for(auto it : start_end) {
        if(it.second) {
            curr_count++;
        } else {
            curr_count--;
        }
        max_count = max(max_count, curr_count);
    }

    return max_count;
}

// main function
int main() {
    vector<pair<int, int>> intervals = {{30, 75}, {0, 50}, {60, 150}};

    cout << minimumRooms(intervals) << "\n";

    return 0;
}
