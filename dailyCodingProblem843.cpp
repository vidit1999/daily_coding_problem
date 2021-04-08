#include <bits/stdc++.h>
using namespace std;

/*
Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string.
For example, given the string "abracadabra" and the pattern "abr", you should return [0, 7].
*/

vector<int> startingIndices(string text, string pat){
	vector<int> v = {};
	for(int i=0;i<text.length();i++){
		if(text.substr(i, pat.length()) == pat)
			v.push_back(i);
	}
	
	return v;
}

// main function
int main(){
	for(int i : startingIndices("abracadabra", "abr"))
		cout << i << "\n";
	return 0;
}