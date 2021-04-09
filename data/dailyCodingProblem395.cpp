#include <bits/stdc++.h>
using namespace std;

/*
Given an array of strings, group anagrams together.

For example, given the following array:

['eat', 'ate', 'apt', 'pat', 'tea', 'now']
Return:

[['eat', 'ate', 'tea'],
 ['apt', 'pat'],
 ['now']]
*/

bool isAnagram(string s1, string s2){
	if(s1.length() != s2.length()) return false;
	
	unordered_map<char, int> charCount;
	
	for(int i=0;i<s1.length();i++){
		charCount[s1[i]]++;
		charCount[s2[i]]--;
	}
	
	for(auto it : charCount)
		if(it.second != 0)
			return false;
	
	return true;
}


vector<vector<string>> groupAnagrams(vector<string> strs){
	unordered_map<string, vector<string>> anagrams;
	
	for(string s : strs){
		bool isPresent = false;
		for(auto it : anagrams){
			if(isAnagram(it.first, s)){
				anagrams[it.first].push_back(s);
				isPresent = true;
				break;
			}
		}
		if(!isPresent){
			anagrams[s].push_back(s);
		}
	}
	
	vector<vector<string>> ans;
	
	for(auto it : anagrams)
		ans.push_back(it.second);
	
	return ans;
}

// main function
int main(){
	for(auto v : groupAnagrams({"eat", "ate", "apt", "pat", "tea", "now"})){
		for(auto s : v)
			cout << s << " ";
		cout << "\n";
	}
	return 0;
}