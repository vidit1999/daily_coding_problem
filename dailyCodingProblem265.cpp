#include <bits/stdc++.h>
using namespace std;

/*
MegaCorp wants to give bonuses to its employees based on how many lines of codes
they have written. They would like to give the smallest positive amount to each
worker consistent with the constraint that if a developer has written more
lines of code than their neighbor, they should receive more money.

Given an array representing a line of seats of employees at MegaCorp,
determine how much each one should get paid.

For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1].
*/

vector<int> bonusArray(vector<int> line_of_codes){
	vector<int> ans(line_of_codes.size(), 1);
	
	for(int i=0;i<line_of_codes.size();i++){
		if(
			(i > 0 && line_of_codes[i] > line_of_codes[i-1]) ||
			(i < n-1 && line_of_codes[i] < line_of_codes[i+1])
		){
			ans[i] += min(
				((i > 0)? line_of_codes[i-1] : 0),
				((i < n-1)? line_of_codes[i+1] : 0)
			);
		}
	}
	
	return ans;
}

// main function
int main(){
	return 0;
}