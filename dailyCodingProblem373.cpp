#include <bits/stdc++.h>
using namespace std;

/*
Given a list of integers L, find the maximum length of a sequence of consecutive numbers
that can be formed using elements from L.

For example, given L = [5, 2, 99, 3, 4, 1, 100], return 5 as we can build a sequence
[1, 2, 3, 4, 5] which has length 5.
*/

int longestConsSeq(vector<int> arr){
	unordered_set<int> s(arr.begin(), arr.end());
	int length = 1;
	
	for(int i : arr){
		if(s.find(i-1) == s.end()){
			int j = i;
			while(s.find(j) != s.end()) j++;
			length = max(length, j-i);
		}
	}
	
	return length;
}

// main function
int main(){
	cout << longestConsSeq({5, 2, 99, 3, 4, 1, 100}) << "\n";
	return 0;
}