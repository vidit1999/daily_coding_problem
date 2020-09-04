#include <bits/stdc++.h>
using namespace std;

/*
Given a list of points, a central point, and an integer k,
find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)],
the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
*/

int sqDistancePoints(pair<int, int> p1, pair<int, int> p2){
	return abs(
		(p1.first - p2.first) * (p1.first - p2.first) +
		(p1.second - p2.second) * (p1.second - p2.second)
	);
}

vector<pair<int, int>> closestK(int k, pair<int, int> central_point, vector<pair<int, int>> points){
	priority_queue<pair<int, pair<int, int>>> pq;
	
	for(auto point : points){
		pq.push({sqDistancePoints(point, central_point), point});
		if(pq.size() > k) pq.pop();
	}
	
	vector<pair<int, int>> ans;
	
	while(!pq.empty()){
		ans.push_back(pq.top().second);
		pq.pop();
	}
	
	return ans;
}

// main function
int main(){
	vector<pair<int, int>> points = {{0, 0}, {5, 4}, {3, 1}};
	pair<int, int> central_point = {1, 2};
	int k = 2;
	
	for(auto it : closestK(k, central_point, points))
		cout << it.first << ", " << it.second << "\n";
	return 0;
}