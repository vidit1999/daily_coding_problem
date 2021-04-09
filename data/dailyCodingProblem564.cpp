#include <bits/stdc++.h>
using namespace std;

/*
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers.
Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10,
since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

int largestSum(vector<int> arr){
	if(arr.empty()) return -1;
	
	int incl = arr[0], excl = 0, excl_new;
	
	for(int i=1;i<arr.size();i++){
		excl_new = max(incl, excl);
		incl = excl + arr[i];
		excl = excl_new;
	}
	
	return max(incl, excl);
}

// main function
int main(){
	cout << largestSum({2, 4, 6, 2, 5}) << "\n";
	return 0;
}