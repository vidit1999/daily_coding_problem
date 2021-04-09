#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, return a new array where each element in the new array
is the number of smaller elements to the right of that element in the original input array.

For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

There is 1 smaller element to the right of 3
There is 1 smaller element to the right of 4
There are 2 smaller elements to the right of 9
There is 1 smaller element to the right of 6
There are no smaller elements to the right of 1
*/

vector<int> rightSmaller(vector<int> arr){
	int n = arr.size();
	vector<int> ans;
	set<int> s;
	
	for(int i=n-1; i>=0; i--){
		auto it = s.insert(arr[i]).first;
		ans.push_back(distance(s.begin(), it));
	}
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

// main function
int main(){
	for(int i : rightSmaller({3, 4, 6, 3, 9, 6, 1}))
		cout << i << "\n";
	return 0;
}