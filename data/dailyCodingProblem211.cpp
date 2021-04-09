#include <bits/stdc++.h>
using namespace std;

/*
Given a string and a pattern, find the starting indices of all occurrences of the pattern in the string.
For example, given the string "abracadabra" and the pattern "abr", you should return [0, 7].
*/

vector<int> startingIndices(string s, string pattern){
	int n1 = s.length(), n2 = pattern.length();
	vector<int> ans;
	
	for(int i=0; i<=n1-n2; i++){
		if(s.substr(i, pattern.length()) == pattern)
			ans.push_back(i);
	}
	
	return ans;
}

// main function
int main(){
	for(int i : startingIndices("abracadabra", "abr"))
		cout << i << "\n";
	return 0;
}