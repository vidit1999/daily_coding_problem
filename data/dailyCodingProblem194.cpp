#include <bits/stdc++.h>
using namespace std;

/*
Suppose you are given two lists of n points, one list p1, p2, ..., pn on the line y = 0
and the other list q1, q2, ..., qn on the line y = 1. Imagine a set of n line segments
connecting each point pi to qi. Write an algorithm to determine how many pairs of the
line segments intersect.
*/

int countIntersectingPairs(vector<int> p, vector<int> q){
	vector<pair<int, int>> points;
	
	for(int i=0; i<p.size(); i++)
		points.push_back({p[i], q[i]});
	
	sort(points.begin(), points.end());
	
	set<int, greater<int>> s;
	int count = 0;
	
	for(auto point : points){
		auto pos = s.insert(point.second).first;
		count += distance(s.begin(), pos);
	}
	
	return count;
}


// main function
int main(){
	vector<int> p = {0, 1, 2, 3, 4};
	vector<int> q = {1, 2, 3, 4, 0};
	
	cout << countIntersectingPairs(p, q) << "\n";
	
	return 0;
}