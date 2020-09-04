#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers of length N,
find both the minimum and maximum using less than 2 * (N - 2) comparisons.
*/

pair<int, int> minMax1(vector<int> arr){
	if(arr.size() == 0) return {INT_MIN, INT_MAX};
	
	pair<int, int> ans; // {min, max}
	
	int i = 0;
	if(arr.size()%2 == 0){
		if(arr[0] > arr[1]){
			ans.first = arr[1];
			ans.second = arr[0];
		}
		else{
			ans.first = arr[0];
			ans.second = arr[1];
		}
		i += 2;
	}
	else{
		ans.first = arr[0], ans.second = arr[0];
		i++;
	}
	
	while(i<arr.size()-1){
		if(arr[i] < arr[i+1]){
			if(arr[i] < ans.first) ans.first = arr[i];
			if(arr[i+1] > ans.second) ans.second = arr[i+1];
		}
		else{
			if(arr[i+1] < ans.first) ans.first = arr[i+1];
			if(arr[i] > ans.second) ans.second = arr[i];
		}
		i += 2;
	}
	
	return ans;
}

pair<int, int> minMax2(vector<int> arr){
	auto ans = minmax_element(arr.begin(), arr.end());
	return {*(ans.first), *(ans.second)};
}

// main function
int main(){
	auto ans = minMax1({1000, 11, 445, 1, 330, 3000});
	cout << ans.first << ", " << ans.second << "\n";
	return 0;
}