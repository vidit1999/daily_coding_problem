#include <bits/stdc++.h>
using namespace std;

/*
Given a word W and a string S, find all starting indices in S which are anagrams of W.
For example, given that W is "ab", and S is "abxaba", return 0, 3, and 4.
*/

// return true if umap2 contains all the keys of umap1 with respective values
// and all other keys of umap2 are with  value zero
bool areSame(unordered_map<char, int> umap1, unordered_map<char,int> umap2){
	for(auto it : umap1){
		if(umap2[it.first] == 0)
			if(it.second != 0)
				return false;
		else{
			if(it.second != umap2[it.first])
				return false;
		}
	}
	return true;
}

vector<int> findAnagramIndices(string w, string s){
	unordered_map<char, int> wordMap; // stores the characters of word with their respective counts
	unordered_map<char, int> stringMap; // stores the characters in the window of string with their respective counts
	vector<int> indices = {}; // stores the starting indices of anagrams
	
	for(int i=0;i<w.length();i++){
		wordMap[w[i]]++;
		stringMap[s[i]]++;
	}
	
	for(int i=w.length();i<s.length();i++){
		if(areSame(wordMap, stringMap))
			indices.push_back(i-w.length());
		stringMap[s[i]]++;
		stringMap[s[i-w.length()]]--;
	}
	
	if(areSame(wordMap,stringMap))
		indices.push_back(s.length()-w.length());
	return indices;
}


// main function
int main(){
	vector<int> indices = findAnagramIndices("ab","abxaba");
	for(int i : indices)
		cout << i << "\n";
	return 0;
}