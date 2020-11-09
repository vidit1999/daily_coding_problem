#include <bits/stdc++.h>
using namespace std;

/*
That is, given a string of length N and a pattern of length k,
write a program that searches for the pattern in the string
with less than O(N * k) worst-case time complexity.

If the pattern is found, return the start index
of its location. If not, return False.
*/

void computeLPS(int lps[], int m, string& pat){
	int len = 0;
	lps[0] = 0;
	int i = 1;
	
	while(i < m){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len != 0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

vector<int> kmpAlgorithm(string s, string pat){
	int m = pat.length();
	int n = s.length();
	
	int lps[m];
	
	computeLPS(lps, m, pat);
	
	int i = 0;
	int j = 0;
	vector<int> ans;
	
	while(i < n){
		if(s[i] == pat[j]){
			i++;
			j++;
		}
		
		if(j == m){
			ans.push_back(i-j);
			j = lps[j-1];
		}
		else if(i < n && pat[j] != s[i]){
			if(j != 0)
				j = lps[j-1];
			else
				i = i + 1;
		}
	}
	
	return ans;
}

// main function
int main(){
	for(int i : kmpAlgorithm("THIS IS A TEST TEXT", "TEST")){
		cout << i << "\n";
	}
	
	cout << "\n";
	
	for(int i : kmpAlgorithm("AABAACAADAABAABA", "AABA")){
		cout << i << "\n";
	}
	
	return 0;
}