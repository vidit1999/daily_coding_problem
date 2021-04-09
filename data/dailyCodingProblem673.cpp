#include <bits/stdc++.h>
using namespace std;

/*
Given a list of points, a central point, and an integer k,
find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)],
the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
*/

int calcDistSq(pair<int, int>& p1, pair<int, int>& p2){
    return (
        (p1.first - p2.first)*(p1.first - p2.first) +
        (p1.second - p2.second)*(p1.second - p2.second)
    );
}

vector<pair<int, int>> kNearestPoints(vector<pair<int, int>>& points, pair<int, int>& cpoint, int k){
    priority_queue<pair<int, pair<int, int>>> pq;
    vector<pair<int, int>> ans;

    for(auto& point : points){
        int distSq = calcDistSq(cpoint, point);
        pq.push({distSq, point});
        if(pq.size() > k) pq.pop();
    }

    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}

// main function
int main(){
    vector<pair<int, int>> points = {{0, 0}, {5, 4}, {3, 1}};
    pair<int, int> cpoint = {1, 2};
    int k = 2;

    for(auto it : kNearestPoints(points, cpoint, k)){
        cout << it.first << ", " << it.second << "\n";
    }

	return 0;
}