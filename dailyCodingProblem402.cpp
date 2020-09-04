#include <bits/stdc++.h>
using namespace std;

/*
A strobogrammatic number is a positive number that appears the same after being rotated 180 degrees.
For example, 16891 is strobogrammatic.

Create a program that finds all strobogrammatic numbers with N digits.
*/

vector<string> helper(int n, int len){
	if(n == 0) return {""};
	if(n == 1) return {"0", "1", "8"};
	
	auto middles = helper(n-2, len);
	
	vector<string> res;
	
	for(string s : middles){
		if(n != len) res.push_back("0" + s + "0");
		res.push_back("1" + s + "1");
		res.push_back("6" + s + "9");
		res.push_back("8" + s + "8");
		res.push_back("9" + s + "6");
	}
	
	return res;
}

vector<string> getAllStrobogrammatic(int n){
	return helper(n, n);
}

// main function
int main(){
	for(auto s : getAllStrobogrammatic(4))
		cout << s << "\n";
	return 0;
}