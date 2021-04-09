#include <bits/stdc++.h>
using namespace std;

/*
Given a string and a set of characters, return the shortest substring containing all the characters in the set.
For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".
If there is no substring containing all the characters in the set, return null.
*/

string minWindow(string s, unordered_set<char> chrs){
	if(s.length() < chrs.size()) return "";
	int start = 0, start_index = -1, minLength = INT_MAX, count = 0;
	unordered_map<char, int> strMap;
	
	for(int i=0;i<s.length();i++){
		strMap[s[i]]++;
		if(
			strMap[s[i]] == 1 && // the char is taken into account only once
			(chrs.find(s[i]) != chrs.end()) // if the char is present in pattern
		){
			count++;
		}
		if(count == chrs.size()){
			while(
				strMap[s[start]] > 1 || // the key is present more than once in the interval
				(chrs.find(s[start]) == chrs.end()) // then char is not in the pattern
			){
				if(strMap[s[start]] > 1) strMap[s[start]]--;
				start++;
			}
			
			int winLen = i - start + 1;
			if(minLength > winLen){
				minLength = winLen;
				start_index = start;
			}
		}
	}
	
	if(start_index == -1) return "";
	return s.substr(start_index, minLength);
}

// main function
int main(){
	cout << minWindow("figehaeci", {'a', 'e', 'i'}) << "\n";
	return 0;
}