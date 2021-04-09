#include <bits/stdc++.h>
using namespace std;

/*
There are M people sitting in a row of N seats, where M < N.
Your task is to redistribute people such that there are no
gaps between any of them, while keeping overall movement to a minimum.

For example, suppose you are faced with an input of
[0, 1, 1, 0, 1, 0, 0, 0, 1], where 0 represents an
empty seat and 1 represents a person. In this case,
one solution would be to place the person on the right
in the fourth seat. We can consider the cost of a
solution to be the sum of the absolute distance each
person must move, so that the cost here would be five.

Given an input such as the one above, return the lowest
possible cost of moving people to remove all gaps.
*/

int getMedian(vector<int>& v){
	return (v.size()%2 != 0)? v[v.size()/2] : v[v.size()/2 - 1];
}

int lowestCost(vector<int> arr){
	vector<int> v;

	for(int i=0; i<arr.size(); i++){
		if(arr[i]) v.push_back(i);
	}

	if(v.empty()) return 0;

	int cost = 0;

	// get cost for left part of median
	int index = getMedian(v);
	int curr_index = index;

	while(curr_index >= 0){
		if(arr[curr_index]){
			cost += abs(index - curr_index);
			index--;
		}
		curr_index--;
	}

	// get cost for right part of median
	index = getMedian(v)+1;
	curr_index = index;

	while(curr_index < arr.size()){
		if(arr[curr_index]){
			cost += abs(index - curr_index);
			index++;
		}
		curr_index++;
	}

	return cost;
}

// main function
int main(){
	cout << lowestCost({0, 1, 1, 0, 1, 0, 0, 0, 1}) << "\n";
	cout << lowestCost({0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0}) << "\n";
	return 0;
}