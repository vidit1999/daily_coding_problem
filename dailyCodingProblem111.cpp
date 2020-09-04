#include <bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

/*
Given a word W and a string S, find all
starting indices in S which are anagrams of W.

For example, given that W is "ab",
and S is "abxaba", return 0, 3, and 4.
*/

bool compareCount(int arr1[], int arr2[]){
	for(int i=0; i<ALPHABET_SIZE; i++){ 
		if(arr1[i] != arr2[i]){
			return false;
		}
	}
	return true;
}

vector<int> startOccurences(string s, string w){
	int n = s.length(), m = w.length();
	int arr1[ALPHABET_SIZE] = {0}, arr2[ALPHABET_SIZE] = {0};
	vector<int> ans;
	
	for(int i=0; i<m; i++){
		arr1[s[i]-'a']++;
		arr2[w[i]-'a']++;
	}
	
	for(int i=m; i<n; i++){
        if(compareCount(arr1, arr2)) ans.push_back(i-m);

		arr1[s[i]-'a']++;
		arr1[s[i-m]-'a']--;
	}
	
    if(compareCount(arr1, arr2)) ans.push_back(n-m);
    
	return ans;
}

// main function
int main(){
	for(int i : startOccurences("abxaba", "ab"))
		cout << i << "\n";
	return 0;
}