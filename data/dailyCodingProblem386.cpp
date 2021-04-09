#include <bits/stdc++.h>
using namespace std;

/*
Given a string, sort it in decreasing order based on the frequency of characters.
If there are multiple possible solutions, return any of them.

For example, given the string tweet, return tteew. eettw would also be acceptable.
*/

string sortDecFreq(string s){
	unordered_map<char, int> charCount; // stroes the coutn of every char
	map<int, vector<char>, greater<int>> countChar; // stores the count wrt the chars
	
	for(char c : s) charCount[c]++;
	
	for(auto it : charCount)
		countChar[it.second].push_back(it.first);
	
	string ans = "";
	
	for(auto it : countChar){
		for(char c : it.second){
			for(int i=0;i<it.first;i++)
				ans += c;
		}
	}
	
	return ans;
}

// main function
int main(){
	cout << sortDecFreq("tweet") << "\n";
	return 0;
}