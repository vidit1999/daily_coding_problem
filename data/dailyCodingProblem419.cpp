#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer N, find the smallest number of steps it will take to reach 1.

There are two kinds of permitted steps:

You may decrement N to N - 1.
If a * b = N, you may decrement N to the larger of a and b.
For example, given 100, you can reach 1 in five steps with the following route: 100 -> 10 -> 9 -> 3 -> 2 -> 1.
*/

struct point{
	int data, steps;
};

int minStepsTo1(int n){
	queue<point> q;
	q.push({n, 0});
	
	set<int> seen;
	
	while(!q.empty()){
		auto temp = q.front();
		q.pop();
		
		if(temp.data == 1) return temp.steps;
		
		if(seen.find(temp.data-1) == seen.end()){
			q.push({temp.data-1, temp.steps+1});
			seen.insert(temp.data-1);
		}
		
		for(int i = 2; i*i <= temp.data; i++){
			if(temp.data%i == 0 && (seen.find(temp.data/i) == seen.end())){
				q.push({temp.data/i, temp.steps+1});
				seen.insert(temp.data/i);
			}
		}
	}
	
	return -1;
}

// main function
int main(){
	cout << minStepsTo1(100) << "\n";
	return 0;
}