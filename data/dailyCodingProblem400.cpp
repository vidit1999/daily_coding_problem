#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers L, implement a method sum(i, j) which returns the sum from
the sublist L[i:j] (including i, excluding j).

For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]), which is 5.

You can assume that you can do some pre-processing. sum() should be optimized over the pre-processing step
*/

vector<int> sumArray(vector<int> arr){
	int runningSum = 0;
	vector<int> sumPreprocess;
	
	for(int i=0;i<arr.size();i++){
		sumPreprocess.push_back(runningSum);
		runningSum += arr[i];
	}
	sumPreprocess.push_back(runningSum);
	return sumPreprocess;
}

vector<int> L = {1, 2, 3, 4, 5}, preProcessed = sumArray(L);

int sum(int i, int j){
	i = max(0, i);
	j = min(j, int(L.size()));
	
	return preProcessed[j] - preProcessed[i];
}

// main function
int main(){
	cout << sum(1, 3) << "\n";
	cout << sum(1, 5) << "\n";
	return 0;
}