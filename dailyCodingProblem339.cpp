#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers and a number k, determine if there are three entries in the array which
add up to the specified number k. For example, given [20, 303, 3, 4, 25] and k = 49,
return true as 20 + 4 + 25 = 49.
*/

bool isSumThree(int arr[], int n, int k){
	for(int i=0;i<n;i++){
		unordered_set<int> s;
		int sum = k-arr[i];
		for(int j=i;j<n;j++){
			if(s.find(sum-arr[j]) != s.end())
				return true;
			s.insert(arr[j]);
		}
	}
	return false;
}

// main function
int main(){
	int arr[] = {20, 303, 3, 4, 25};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	if(isSumThree(arr, n, 49))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}