#include <bits/stdc++.h>
using namespace std;

/*
Given a set of points (x, y) on a 2D cartesian plane, find the two closest points.
For example, given the points [(1, 1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)],
return [(-1, -1), (1, 1)].
*/

int distSquare(pair<int, int> p1, pair<int, int> p2){
	return (
		(p1.first - p2.first)*(p1.first - p2.first) +
		(p1.second - p2.second)*(p1.second - p2.second)
	);
}

pair<pair<int, int>, pair<int, int>> closestPoints(vector<pair<int, int>> arr){
	int min_dist = INT_MAX;
	pair<pair<int, int>, pair<int, int>> ans;
	
	for(int i=0; i<arr.size(); i++){
		for(int j=i+1; j<arr.size(); j++){
			int dist_sq = distSquare(arr[i], arr[j]);
			
			if(dist_sq < min_dist){
				min_dist = dist_sq;
				ans = {arr[i], arr[j]};
			}
		}
	}
	
	return ans;
}

// main function
int main(){
	vector<pair<int, int>> arr = {{1, 1}, {-1, -1}, {3, 4}, {6, 1}, {-1, -6}, {-4, -3}};
	auto ans = closestPoints(arr);
	
	cout << ans.first.first << ", " << ans.first.second << "\n";
	cout << ans.second.first << ", " << ans.second.second << "\n";
	
	return 0;
}