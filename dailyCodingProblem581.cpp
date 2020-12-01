#include <bits/stdc++.h>
using namespace std;

/*
Given two rectangles on a 2D graph, return the area of their intersection.
If the rectangles don't intersect, return 0.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
}
and

{
    "top_left": (0, 5),
    "dimensions" (4, 3) # width, height
}

return 6.
*/


int rectangleIntersectionArea(
	pair<pair<int, int>, pair<int, int>> rect1,
	pair<pair<int, int>, pair<int, int>> rect2
){
	pair<int, int> l1 = rect1.first,
	r1 = {rect1.first.first + rect1.second.second, rect1.first.second - rect1.second.first},
	l2 = rect2.first,
	r2 = {rect2.first.first + rect2.second.second, rect2.first.second - rect2.second.first};
	
	int intersect_x1 = max(l1.first, l2.first), intersect_y1 = min(l1.second, l2.second);
	int intersect_x2 = min(r1.first, r2.first), intersect_y2 = max(r1.second, r2.second);
		
	return (
		max(0, intersect_x2 - intersect_x1) * \
		max(0, intersect_y1 - intersect_y2)
	);
}


// main function
int main(){
	cout << rectangleIntersectionArea(
		{{1, 4}, {3, 3}},
		{{0, 5}, {4, 3}}
	) << "\n";
	return 0;
}