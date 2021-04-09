#include <bits/stdc++.h>
using namespace std;

/*
Given a string, find the length of the smallest window
that contains every distinct character.
Characters may appear more than once in the window.

For example, given "jiujitsu", you should return 5,
corresponding to the final five letters.
*/

int smallestWindow(string s){
	int n = s.length();
	int unique_count = unordered_set<char>(s.begin(), s.end()).size();
	int start = 0, min_len = INT_MAX, count = 0;
	unordered_map<int, int> char_count;
	
	for(int i=0; i<n; i++){
		if(++char_count[s[i]] == 1) count++;
		
		if(count == unique_count){
			while(char_count[s[start]] > 1){
				if(char_count[s[start]] > 1)
					char_count[s[start]]--;
				start++;
			}
			min_len = min(min_len, i-start+1);
		}
	}
	
	return min_len;
}

// main function
int main(){
	cout << smallestWindow("jiujitsu") << "\n";
	return 0;
}