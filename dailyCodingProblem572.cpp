#include <bits/stdc++.h>
using namespace std;

/*
Given a number represented by a list of digits, find the next greater permutation of a number,
in terms of lexicographic ordering. If there is not greater permutation possible,
return the permutation with the lowest value/ordering.

For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3].
The list [3,2,1] should return [1,2,3].

Can you perform the operation without allocating extra memory (disregarding the input memory)?

Input:  n = "218765"
Output: "251678"

Input:  n = "1234"
Output: "1243"

Input: n = "4321"
Output: "Not Possible"

Input: n = "534976"
Output: "536479"
*/

void next_greater(vector<int>& number){
	int pivot = 0;
	
	for(int i=number.size()-1;i>0;i--){
		if(number[i] > number[i-1]){
			pivot = i;
			break;
		}
	}
	
	if(pivot == 0){
		reverse(number.begin(), number.end());
		return;
	}
	
	int smaller_than = pivot;
	for(int i=pivot;i<number.size();i++){
		if(number[pivot-1] < number[i] && number[i] < number[smaller_than])
			smaller_than = i;
	}
	
	swap(number[smaller_than], number[pivot-1]);
	reverse(number.begin()+pivot, number.end());
}

// main function
int main(){
	vector<vector<int>> numbers = {
		{2,1,8,7,6,5},
		{1,2,3,4},
		{4,3,2,1},
		{5,3,4,9,7,6}
	};
	for(int i=0;i<numbers.size();i++){
		next_greater(numbers[i]);
		for(int j : numbers[i])
			cout << j << " ";
		cout << "\n";
	}
	return 0;
}