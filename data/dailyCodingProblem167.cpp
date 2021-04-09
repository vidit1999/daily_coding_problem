#include <bits/stdc++.h>
using namespace std;

/*
Given a list of words, find all pairs of unique indices such that the concatenation
of the two words is a palindrome.

For example, given the list ["code", "edoc", "da", "d"],
return [(0, 1), (1, 0), (2, 3)].

Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
*/

bool isPalindrome(string s){
	int l = 0, r = s.length()-1;
	
	while(l <= r){
		if(s[l++] != s[r--])
			return false;
	}
	
	return true;
}

string getReverse(string s){
	reverse(s.begin(), s.end());
	return s;
}

vector<pair<int, int>> palindromeIndices(vector<string> words){
	vector<pair<int, int>> res;
	
	if(words.size() <= 1) return res;
	
	unordered_map<string, int> string_indices;
	
	for(int i=0; i<words.size(); i++) string_indices[words[i]] = i;

	for(int i=0; i<words.size(); i++){
		for(int j=0; j<words[i].length(); j++){
			string s1 = words[i].substr(0, j);
			string s2 = words[i].substr(j);
			
			if(isPalindrome(s1)){
				string rev_s2 = getReverse(s2);
				if(string_indices.find(rev_s2) != string_indices.end() && string_indices[rev_s2] != i){
					res.push_back({i, string_indices[rev_s2]});
				}
			}
			if(isPalindrome(s2)){
				string rev_s1 = getReverse(s1);
				if(string_indices.find(rev_s1) != string_indices.end() && string_indices[rev_s1] != i){
					res.push_back({i, string_indices[rev_s1]});
				}
			}
		}
	}
	
	return res;
}

// main function
int main(){
	for(auto it : palindromeIndices({"abcd", "dcba", "lls", "s", "sssll"}))
		cout << it.first << ", " << it.second << "\n";
	return 0;
}