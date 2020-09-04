#include <bits/stdc++.h>
using namespace std;

/*
Given an integer list where each number represents the number of hops you can make,
determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns True while [1, 1, 0, 1] returns False.
*/

bool isEndReachable(vector<int> arr){
	for(int i=0;i<arr.size();i += arr[i]){
		if(i == arr.size()-1)
			return true;
		if((arr[i] == 0 && i != arr.size()-1) || i + arr[i] >= arr.size())
			return false;
	}
	
	return true;
}

// main function
int main(){
	if(isEndReachable({1, 1, 0, 1}))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}