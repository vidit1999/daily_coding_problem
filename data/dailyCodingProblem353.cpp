#include <bits/stdc++.h>
using namespace std;

/*
You are given a histogram consisting of rectangles of different heights.
These heights are represented in an input list, such that [1, 3, 2, 5]
corresponds to the following diagram:

      x
      x  
  x   x
  x x x
x x x x

Determine the area of the largest rectangle that can be formed only
from the bars of the histogram. For the diagram above, for example,
this would be six, representing the 2 x 3 area at the bottom right.
*/

int countArea(int arr[], int n){
	stack<int> s;
	int max_area = 0, i = 0;
	
	while(i < n){
		if(s.empty() || arr[s.top()] <= arr[i]){
			s.push(i++);
		}
		else{
			int t = s.top(); s.pop();
			max_area = max(
				max_area,
				arr[t]*(s.empty()? i : i-s.top()-1)
			);
		}
	}
	
	while(!s.empty()){
		int t = s.top(); s.pop();
		max_area = max(
			max_area,
			arr[t]*(s.empty()? i : i-s.top()-1)
		);
	}
	
	return max_area;
}

// main function
int main(){
	int arr[] = {1, 3, 2, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << countArea(arr, n) << "\n";
	return 0;
}