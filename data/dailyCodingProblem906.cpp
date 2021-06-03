#include <bits/stdc++.h>
using namespace std;

/*
Given a set of points (x, y) on a 2D cartesian plane, find the two closest points.
For example, given the points [(1, 1), (-1, -1), (3, 4), (6, 1), (-1, -6), (-4, -3)],
return [(-1, -1), (1, 1)].
*/

struct Point{
	int x, y;
};

float dist(Point p1, Point p2){
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// O(n^2) time | O(1) space
pair<Point, Point> closestPoint(vector<Point> points){
	float min_distance = INT_MAX;
	pair<Point, Point> ans = {{0, 0}, {0, 0}};
	
	for(int i=0; i<points.size(); i++){
		for(int j=0; j<points.size(); j++){
			if(i != j){
				float dist_points = dist(points[i], points[j]);
				if(min_distance > dist_points){
					min_distance = dist_points;
					ans = {points[i], points[j]};
				}
			}
		}
	}
	
	return ans;
}

// main function
int main(){
	vector<Point> v = {{1, 1}, {-1, -1}, {3, 4}, {6, 1}, {-1, -6}, {-4, -3}};
	auto ans = closestPoint(v);
	cout << ans.first.x << ", " << ans.first.y << "\n";
	cout << ans.second.x << ", " << ans.second.y << "\n";
	return 0;
}