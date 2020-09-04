#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element
sequence is [1, 2, 3, 4]. Return its length: 4.
*/

int longestConsecutiveSeq(vector<int> arr){
	unordered_set<int> s(arr.begin(), arr.end());
	int ans = 0;
	
	for(int i : arr){
		if(s.find(i-1) == s.end()){
			int j = i;
			while(s.find(j) != s.end())
				j++;
			ans = max(ans, j-i);
		}
	}
	
	return ans;
}

// main function
int main(){
	cout << longestConsecutiveSeq({100, 4, 200, 1, 3, 2}) << "\n";
	return 0;
}