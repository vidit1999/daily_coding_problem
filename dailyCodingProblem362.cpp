#include <bits/stdc++.h>
using namespace std;

/*
A strobogrammatic number is a positive number that appears the same after being rotated 180 degrees.
For example, 16891 is strobogrammatic.

Create a program that finds all strobogrammatic numbers with N digits.
*/

vector<string> strobogrammaticHelper(int n, int length){
	if(n == 0) return {""};
	if(n == 1) return {"0", "1", "8"};
	
	auto middle = strobogrammaticHelper(n-2, length);
	vector<string> res;
	
	for(string s : middle){
		if(n != length) res.push_back("0" + s + "0");
		res.push_back("1" + s + "1");
		res.push_back("8" + s + "8");
		res.push_back("9" + s + "6");
		res.push_back("6" + s + "9");
	}
	
	return res;
}

vector<string> strobogrammaticNumber(int n){
	return strobogrammaticHelper(n, n);
}

// main function
int main(){
	for(string s : strobogrammaticNumber(3))
		cout << s << "\n";
	return 0;
}