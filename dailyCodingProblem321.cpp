#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer N, find the smallest number of steps it will take to reach 1.

There are two kinds of permitted steps:

You may decrement N to N - 1.
If a * b = N, you may decrement N to the larger of a and b.

For example, given 100, you can reach 1 in five steps
with the following route: 100 -> 10 -> 9 -> 3 -> 2 -> 1.
*/

struct point{
	int val, dist;
};

int minSteps(int n){
	queue<point> q;
	unordered_set<int> us;
	q.push({n, 0});
	
	while(!q.empty()){
		auto pt = q.front();
		q.pop();
		if(pt.val == 1) return pt.dist;
		
		if(us.find(pt.val-1) == us.end()){
			q.push({pt.val-1, pt.dist+1});
			us.insert(pt.val-1);
		}
		
		for(int i=2;i*i<=pt.val;i++){
			if(pt.val%i == 0 && us.find(pt.val/i) == us.end()){
				q.push({pt.val/i, pt.dist+1});
				us.insert(pt.val/i);
			}
		}
	}
	
	return -1;
}

// main function
int main(){
	cout << minSteps(100) << "\n";
	return 0;
}