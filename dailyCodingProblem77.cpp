#include <bits/stdc++.h>
using namespace std;

/*
Given a list of possibly overlapping intervals,
return a new list of intervals where all overlapping
intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)],
you should return [(1, 3), (4, 10), (20, 25)].
*/

vector<pair<int, int>> nonOverlapping(vector<pair<int, int>> intervals){
    if(intervals.size() <= 1) return intervals;

	sort(
		intervals.begin(), intervals.end(),
		[](pair<int, int> p1, pair<int, int> p2){
			return p1.first < p2.first;
		}
	);
	
	stack<pair<int, int>> s;
    s.push(intervals[0]);

    for(int i=1; i<intervals.size(); i++){
        auto tp = s.top();
        if(tp.second >= intervals[i].first){
            s.pop();
            s.push({tp.first, max(tp.second, intervals[i].second)});
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
	vector<pair<int, int>> intervals = {{1, 3}, {5, 8}, {4, 10}, {20, 25}, {6, 15}};
	for(auto it : nonOverlapping(intervals))
        cout << it.first << ", " << it.second << "\n";
	return 0;
}