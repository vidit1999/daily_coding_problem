#include <bits/stdc++.h>
using namespace std;

/*
iven a list of words, find all pairs of unique indices such that
the concatenation of the two words is a palindrome.

For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)].
*/

bool isPalinDrome(string s){
	int start = 0, end = s.length()-1;
	
	while(end > start){
		if(s[start++] != s[end--])
			return false;
	}
	
	return true;
}

vector<pair<int, int>> palindromePairs(vector<string> words){
	vector<pair<int, int>> pairs = {};
	
	for(int i=0;i<words.size();i++){
		for(int j=0;j<words.size();j++){
			if(i != j)
				if(isPalinDrome(words[i]+words[j]))
					pairs.push_back(make_pair(i,j));
		}
	}
	
	return pairs;
}

// main function
int main(){
	for(auto it : palindromePairs({"code", "edoc", "da", "d"}))
		cout << it.first << " " << it.second << "\n";
	return 0;
}