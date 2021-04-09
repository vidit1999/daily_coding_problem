#include <bits/stdc++.h>
using namespace std;

/*
Given a list of strictly positive integers, partition the list into 3 contiguous partitions
which each sum up to the same value. If not possible, return null.

For example, given the following list:

[3, 5, 8, 0, 8]

Return the following 3 partitions:

[[3, 5],
[8, 0],
[8]]

Which each add up to 8.
*/

vector<vector<int>> partitionSumThree(vector<int> arr){
	int sum = 0;
	for(int i : arr) sum += i;
	
	if(sum % 3 != 0) return {};
	
	int indx1 = -1, indx2 = -1, s1 = sum/3, s2 = 2*s1;
	sum = 0;
	
	for(int i=0;i<arr.size();i++){
		sum += arr[i];
		if(sum == s1 && indx1 == -1)
			indx1 = i;
		else if(sum == s2 && indx1 != -1){
			indx2 = i;
			break;
		}
	}
	
	if(indx1 == -1 || indx2 == -1) return {};
	
	vector<vector<int>> ans(3, vector<int>());
	
	for(int i=0;i<arr.size();i++){
		if(i <= indx1) ans[0].push_back(arr[i]);
		else if(i <= indx2) ans[1].push_back(arr[i]);
		else ans[2].push_back(arr[i]);
	}
	
	return ans;
}

// main function
int main(){
	for(auto v : partitionSumThree({3, 5, 8, 0, 8})){
		for(int i : v)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}