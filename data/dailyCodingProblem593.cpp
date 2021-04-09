#include <bits/stdc++.h>
using namespace std;

/*
You are given an array representing the heights of neighboring buildings on a city street,
from east to west. The city assessor would like you to write an algorithm that returns
how many of these buildings have a view of the setting sun, in order to properly value the street.

For example, given the array [3, 7, 8, 3, 6, 1], you should return 3,
since the top floors of the buildings with heights 8, 6, and 1
all have an unobstructed view to the west.

Can you do this using just one forward pass through the array?
*/

// O(n) time | O(1) space
int countSunView(vector<int> heights){
	int max_height = INT_MIN, count = 0;
	
	for(int i=heights.size()-1; i>=0; i--){
		if(heights[i] > max_height){
			cout << heights[i] << " ";
			max_height = heights[i];
			count++;
		}
	}
	cout << "\n";
	return count;
}

int countsunFacingUtil(int index, vector<int>& heights, int& count){
	if(index == heights.size())
		return INT_MIN;
	
	int max_upto = countSunView(index+1, heights, max_height, count);
	if(heights[index] > max_upto){
		count++;
		return heights[index];
	}
	return max_upto;	
}

int countsunFacing(vector<int> heights){
	int count = 0;
	countsunFacingUtil(0, heights, count);
	return count;
}

// main function
int main(){
	cout << countSunView({3, 7, 8, 3, 6, 1}) << "\n";
	return 0;
}