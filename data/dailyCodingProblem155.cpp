#include <bits/stdc++.h>
using namespace std;

/*
Given a list of elements, find the majority element, which appears more than
half the time (> floor(len(lst) / 2.0)).

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0],
return 1.
*/

int majorityElement(vector<int> arr){
	unordered_map<int, int> num_count;
	
	for(int i : arr){
		if(++num_count[i] >= arr.size()/2)
			return i;
	}
	
	return -1;
}

// main function
int main(){
	cout << majorityElement({1, 2, 1, 1, 3, 4, 0}) << "\n";
	cout << majorityElement({1, 8, 7, 4, 1, 2, 2, 2, 2, 2, 2}) << "\n";
	cout << majorityElement({3, 3, 4, 2, 4, 4, 2, 2, 3}) << "\n";
	cout << majorityElement({3, 3, 4, 2, 4, 4, 2, 4, 4}) << "\n";
	return 0;
}