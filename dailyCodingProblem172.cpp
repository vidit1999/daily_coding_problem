#include <bits/stdc++.h>
using namespace std;

/*
Given a string s and a list of words words, where each word is the same length,
find all starting indices of substrings in s that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"],
return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return []
since there are no substrings composed of "dog" and "cat" in s.

The order of the indices does not matter.
*/

vector<int> startingIndices(string s, vector<string> words){
	int word_len = words[0].length();
	int word_count = words.size();
	int n = word_len*word_count;
	
	if(n > s.length()) return {};
	
	vector<int> res;
	
	unordered_map<string, int> umap;
	
	for(string word : words) umap[word]++;
	
	for(int i=0; i<=s.length()-n; i++){
		unordered_map<string, int> hash_map = umap;
		int j = i, count = word_count;
		
		while(j < i+n){
			string word = s.substr(j, word_len);
			if(umap.find(word) == umap.end() || hash_map[word] == 0)
				break;
			else{
				hash_map[word]--;
				count--;
			}
			j += word_len;
		}
		
		if(count == 0) res.push_back(i);
	}
	
	return res;
}


// main function
int main(){
	for(int i : startingIndices("barfoobazbitbyte", {"cat", "dog"}))
		cout << i << "\n";
	return 0;
}