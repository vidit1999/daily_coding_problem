#include <bits/stdc++.h>
using namespace std;

/*
Suppose you are given two lists of n points, one list p1, p2, ..., pn on the line y = 0
and the other list q1, q2, ..., qn on the line y = 1. Imagine a set of n line segments
connecting each point pi to qi. Write an algorithm to determine
how many pairs of the line segments intersect.
*/

struct Line{
	int p, q;
};

struct Compare{
	bool operator () (Line l1, Line l2){
		return l2.q < l1.q;
	}
};

int numberOfIntersections(vector<Line> lines){
	set<Line, Compare> s = {};
	int count = 0;
	
	for(auto line : lines){
		count += distance(s.begin(), s.insert(line).first);
	}
	
	return count;
}

// main function
int main(){
	vector<Line> lines = {{0,1}, {1,2}, {2,3}, {3,4}, {4,0}};
	cout << numberOfIntersections(lines) << "\n";
	return 0;
}