#include <bits/stdc++.h>
using namespace std;

/*
Given a string s and a list of words words, where each word is
the same length, find all starting indices of substrings in s
that is a concatenation of every word in words exactly once.

For example, given s = "dogcatcatcodecatdog" and words = ["cat", "dog"],
return [0, 13], since "dogcat" starts at index 0 and "catdog" starts at index 13.

Given s = "barfoobazbitbyte" and words = ["dog", "cat"],
return [] since there are no substrings composed of
"dog" and "cat" in s.

The order of the indices does not matter.
*/

vector<int> concatenationWordIndices(string s, vector<string> words){
	if(words.empty()) return {};
	
	int word_size = words[0].size();
	int total_size = word_size * words.size();
	
	unordered_map<string, int> word_count;
	vector<int> ans;
	
	for(string word : words){
		word_count[word]++;
	}
	
	for(int i=0; i<=s.length()-total_size; i++){
		unordered_map<string, int> temp_word_count;
		
		for(int j=i; j<i+total_size; j+=word_size){
			string word = s.substr(j, word_size);
			if(word_count.find(word) == word_count.end())
				break;
			if(++temp_word_count[word] > word_count[word])
				break;
		}
		
		if(temp_word_count == word_count)
			ans.push_back(i);
	}
	
	return ans;
}

// main function
int main(){
	for(int i : concatenationWordIndices("barfoothefoobarman", {"foo", "bar"})){
		cout << i << "\n";
	}
	return 0;
}