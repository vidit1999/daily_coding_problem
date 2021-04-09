#include <bits/stdc++.h>
using namespace std;

/*
Given a list of integers and a number K, return which contiguous elements of the list sum to K.
For example, if the list is [1, 2, 3, 4, 5] and K is 9,
then it should return [2, 3, 4], since 2 + 3 + 4 = 9.
*/

vector<int> contiguousSum(vector<int> arr, int sum){
	int curr_sum = 0;
	unordered_map<int, int> sumIndex;
	
	for(int i=0;i<arr.size();i++){
		curr_sum += arr[i];
		
		if(curr_sum == sum){
			return vector<int>(arr.begin(), arr.begin()+i+1);
		}
		
		if(sumIndex.find(curr_sum - sum) != sumIndex.end()){
			return vector<int>(arr.begin()+sumIndex[curr_sum-sum]+1, arr.begin()+i+1);
		}
		sumIndex[curr_sum] = i;
	}
	
	return {};
}

// main function
int main(){
	
	for(int i : contiguousSum({1, 2, 3, 4, 5}, 9))
		cout << i << "\n";
	return 0;
}