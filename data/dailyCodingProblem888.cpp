#include <bits/stdc++.h>
using namespace std;

/*
Given a list of points, a central point, and an integer k,
find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)],
the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
*/

struct PointDistance{
    pair<int, int> point;
    int distance_sq;
};

struct Comparetor{
    bool operator () (PointDistance& p1, PointDistance& p2){
        return p1.distance_sq < p2.distance_sq;
    }
};

int getDistanceSq(pair<int, int>& pt, pair<int, int>& central){
    return (
        (pt.first - central.first)*(pt.first - central.first) +
        (pt.second - central.second)*(pt.second - central.second)
    );
}

vector<pair<int, int>> nearestKPoints(
    vector<pair<int, int>> points,
    pair<int, int> central,
    int k
){
    priority_queue<PointDistance, vector<PointDistance>, Comparetor> pq;
    vector<pair<int, int>> ans;

    for(auto& pt : points){
        pq.push({pt, getDistanceSq(pt, central)});
        if(pq.size() > k){
            pq.pop();
        }
    }

    while(!pq.empty()){
        auto pt = pq.top().point;
        pq.pop();
        ans.push_back(pt);
    }

    return ans;
}

// main function
int main(){
    auto ans = nearestKPoints({{0, 0}, {5, 4}, {3, 1}}, {1, 2}, 2);

    for(auto it : ans){
        cout << it.first << ", " << it.second << "\n";
    }

    return 0;
}
