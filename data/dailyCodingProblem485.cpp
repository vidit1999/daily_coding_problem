#include <bits/stdc++.h>
#define MAX_CHARS 26
using namespace std;

/*
Given an integer k and a string s,
find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2,
the longest substring with k distinct characters is "bcb"
*/

bool isValid(int count[], int k){
	int val = 0;
	for(int i=0;i<MAX_CHARS;i++)
		if(count[i] > 0)
			val++;
	return k >= val;
}

int longestSubstringK(string s, int k){
	int u = 0;
	int n = s.length();
	int count[MAX_CHARS] = { 0 };
	
	// count the number of unique characters
	for(int i=0;i<n;i++){
		if(count[s[i]-'a']==0)
			u++;
		count[s[i]-'a']++;
	}
	// not enough unique characters so return 0
	if(u < k)
		return 0;
	
	int curr_start = 0, curr_end = 0;
	int max_window_size = 1, max_window_start = 0;
	
	// clear the count array
	for(int i=0;i<MAX_CHARS;i++)
		count[i] = 0;
	
	count[s[0]-'a']++;
	
	for(int i=1;i<n;i++){
		count[s[i]-'a']++;
		curr_end++;
		
		while(!isValid(count, k)){
			count[s[curr_start]-'a']--;
			curr_start++;
		}
		
		if(curr_end-curr_start+1 > max_window_size){
			max_window_size = curr_end-curr_start+1;
			max_window_start = curr_start	;
		}
	}
	
	cout << s.substr(max_window_start, max_window_size) << "\n";
	return max_window_size;
}

// main function
int main(){
	string s = "aabacbebebe";
	int k = 3;
	cout << longestSubstringK(s, k) << "\n";
	return 0;
}