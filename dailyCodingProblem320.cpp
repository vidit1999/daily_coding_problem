#include <bits/stdc++.h>
using namespace std;

/*
Given a string, find the length of the smallest
window that contains every distinct character.
Characters may appear more than once in the window.

For example, given "jiujitsu", you should return 5,
corresponding to the final five letters.
*/

int minLength(string s){
	int uniq_count = unordered_set<char>(s.begin(), s.end()).size();
	
	int start = 0, count = 0, min_len = INT_MAX;
	unordered_map<char, int> char_count;
	
	for(int i=0;i<s.length();i++){
		char_count[s[i]]++;
		if(char_count[s[i]] == 1) count++;
		
		if(count == uniq_count){
			while(char_count[s[start]] > 1){
				char_count[s[start]]--;
				start++;
			}
			
			min_len = min(min_len, i - start + 1);
		}
	}
	return min_len;
}

// main function
int main(){
	cout << minLength("jiujitsu") << "\n";
	return 0;
}