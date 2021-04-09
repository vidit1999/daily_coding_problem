#include <bits/stdc++.h>
using namespace std;

/*
Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.
*/

int gcd(int a, int b, unordered_map<string, int>& seen){
	if(b == 0) return a;
	
	string find_string = to_string(a) + "$" + to_string(b);
	if(seen.find(find_string) != seen.end()) return seen[find_string];
	
	int ans = gcd(b, a%b, seen);
	seen[find_string] = ans;
	return ans;
}

int greatestCommonDenominator(vector<int> arr){
	int ans = 0;
	unordered_map<string, int> seen;
	
	for(int i : arr){
		ans = gcd(i, ans, seen);
	}
	
	return ans;
}

// main function
int main(){
	cout << greatestCommonDenominator({42, 56, 14}) << "\n";
	return 0;
}