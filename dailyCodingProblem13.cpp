#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
Given an integer k and a string s, find the length of the
longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2,
the longest substring with k distinct characters is "bcb".
*/

bool isValid(int count[], int k){
	int unique_count = 0;
	for(int i=0; i<ALPHABET_SIZE; i++){
		if(count[i] > 0)
			unique_count++;
	}
	return (k >= unique_count);
}

int longestUniqueSubStr(string s, int k){
	int n = s.length(), curr_start = 0, curr_end = 0, max_window_size = 0, count[ALPHABET_SIZE];
	memset(count, 0, sizeof(count));
	count[s[0]-'a']++;
	
	for(int i=1; i<n; i++){
		count[s[i]-'a']++;
		curr_end++;
		
		while(!isValid(count, k)){
			count[s[curr_start]-'a']--;
			curr_start++;
		}
		
		max_window_size = max(max_window_size, curr_end-curr_start+1);
	}
	
	return max_window_size;
}

// main function
int main(){
	// cout << longestUniqueSubStr("abcba", 2) << "\n";
	cout << longestUniqueSubStr("abcbbbaa", 2) << "\n";
	return 0;
}