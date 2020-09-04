#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array of integers, find the
length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2],
the longest consecutive element sequence
is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

int longestConsecutiveSeq(vector<int> arr){
	unordered_set<int> numbers(arr.begin(), arr.end());
	int max_len = 1;

    for(int i : arr){
        if(numbers.find(i-1) == numbers.end()){
            int j = i;
            while(numbers.find(j) != numbers.end()) j++;
            max_len = max(max_len, j-i);
        }
    }
	
	return max_len;
}

// main function
int main(){
	cout << longestConsecutiveSeq({100, 4, 200, 1, 3, 2}) << "\n";
	return 0;
}