#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers arr and a window of size k, print out the median
of each window of size k starting from the left and moving right by one position each time.

For example, given the following array and k = 3:

[-1, 5, 13, 8, 2, 3, 3, 1]

Your function should print out the following:

5 <- median of [-1, 5, 13]
8 <- median of [5, 13, 8]
8 <- median of [13, 8, 2]
3 <- median of [8, 2, 3]
3 <- median of [2, 3, 3]
3 <- median of [3, 3, 1]

Recall that the median of an even-sized list is the average of the two middle numbers.
*/

float getMedian(vector<int>& arr){
	sort(arr.begin(), arr.end());
	if(arr.size()%2){
		return arr[arr.size()/2];
	}
	else{
		return (arr[arr.size()/2] + arr[arr.size()/2-1])/2;
	}
}

vector<float> medianSlidingWindow(vector<int> arr, int k){
	vector<float> ans;
	
	for(int i=0; i<=arr.size()-k; i++){
		vector<int> median_arr;
		for(int j=0; j<k; j++){
			median_arr.push_back(arr[i+j]);
		}
		ans.push_back(getMedian(median_arr));
	}
	
	return ans;
}

// main function
int main(){
	for(auto f : medianSlidingWindow({-1, 5, 13, 8, 2, 3, 3, 1}, 3)){
		cout << f << "\n";
	}
	return 0;
}