#include <bits/stdc++.h>
using namespace std;

/*
You are in an infinite 2D grid where you can move in any of the 8 directions:

 (x,y) to
    (x+1, y),
    (x - 1, y),
    (x, y+1),
    (x, y-1),
    (x-1, y-1),
    (x+1,y+1),
    (x-1,y+1),
    (x+1,y-1)
You are given a sequence of points and the order in which
you need to cover the points. Give the minimum number of
steps in which you can achieve it. You start from the first point.

Example:

Input: [(0, 0), (1, 1), (1, 2)]
Output: 2
It takes 1 step to move from (0, 0) to (1, 1).
It takes one more step to move from (1, 1) to (1, 2).
*/

int shortestDist(pair<int, int> p1, pair<int, int> p2){
	return max(abs(p1.first - p2.first), abs(p1.second - p2.second));
}

int minSteps(pair<int, int> arr[], int n){
	if(n < 2) return -1;
	
	int steps = 0;
	for(int i=1; i<n; i++){
		steps += shortestDist(arr[i], arr[i-1]);
	}
	
	return steps;
}

// main function
int main(){
	pair<int ,int> arr[] = {{0, 0}, {1, 1}, {1, 2}};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << minSteps(arr, n) << "\n";
	
	return 0;
}