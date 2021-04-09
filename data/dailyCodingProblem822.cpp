#include <bits/stdc++.h>
using namespace std;

/*
Given a list of possibly overlapping intervals,
return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)],
you should return [(1, 3), (4, 10), (20, 25)].
*/

vector<pair<int, int>> mergedIntervels(vector<pair<int, int>> intervals){
    sort(
        intervals.begin(), intervals.end(),
        [](pair<int, int>& p1, pair<int, int>& p2){
            if(p1.first < p2.first) return true;
            return p1.second < p2.second;
        }
    );
    
    stack<pair<int, int>> s;
    vector<pair<int, int>> ans;
    
    for(auto& interval : intervals){
        if(s.empty()) s.push(interval);
        else{
            auto t = s.top(); s.pop();
            if(interval.first > t.second){
                s.push(t);
                s.push(interval);
            }
            else{
                s.push({t.first, max(t.second, interval.second)});
            }
        }
    }
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}

// main function
int main(){
    for(auto interval : mergedIntervels({{1, 3}, {5, 8}, {4, 10}, {20, 25}})){
        cout << interval.first << ", " << interval.second << "\n";
    }
    return 0;
}